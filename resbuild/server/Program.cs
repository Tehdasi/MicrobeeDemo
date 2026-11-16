using Resbuild.Server;

var builder = WebApplication.CreateBuilder(args);

// The database sits with the demo's other resources; the C goes straight into its src folder.
var dataDirectory = builder.Configuration["Resbuild:DataDirectory"] ?? @"c:\coding\mb2\res";
var exportDirectory = builder.Configuration["Resbuild:ExportDirectory"] ?? @"c:\coding\mb2\src";

builder.Services.AddSingleton(_ => new AssetStore(dataDirectory));
builder.Services.AddSingleton(services => new ExportService(
    services.GetRequiredService<AssetStore>(), exportDirectory, services.GetRequiredService<ILogger<ExportService>>()));
builder.Services.AddHostedService(services => services.GetRequiredService<ExportService>());

var app = builder.Build();

app.Use(async (context, next) =>
{
    try
    {
        await next(context);
    }
    catch (InvalidInputException ex)
    {
        context.Response.StatusCode = StatusCodes.Status400BadRequest;
        await context.Response.WriteAsJsonAsync(new { error = ex.Message });
    }
});

// Make browsers revalidate the page and its modules, so an update never leaves them running old code.
var revalidate = new StaticFileOptions
{
    OnPrepareResponse = context => context.Context.Response.Headers.CacheControl = "no-cache",
};
app.UseDefaultFiles();
app.UseStaticFiles(revalidate);

app.Logger.LogInformation("Asset database: {Path}", app.Services.GetRequiredService<AssetStore>().DatabasePath);

var api = app.MapGroup("/api");

api.MapGet("/state", (AssetStore store) =>
{
    var font = store.GetFont();
    return Results.Ok(new
    {
        palette = Microbee.Palette,
        font = new
        {
            firstCode = WavetextFont.FirstCode,
            lastCode = WavetextFont.LastCode,
            tileWidth = WavetextFont.TileWidth,
            tileHeight = WavetextFont.TileHeight,
            bitmapBytes = WavetextFont.BitmapBytes,
            maxTextLength = WavetextFont.MaxTextLength,
            text = font.Text,
            tiles = font.Tiles.ToDictionary(tile => tile.Key, tile => tile.Value.Select(row => (int)row)),
        },
        evlores = new
        {
            heightStep = Evlores.HeightStep,
            maxWidth = Evlores.MaxWidth,
            maxHeight = Evlores.MaxHeight,
        },
        images = store.GetImages().Select(ImageJson.From),
        // So the page can check a variable name the way the server will.
        names = new { maxLength = CNames.MaxLength, reserved = CNames.Reserved },
    });
});

api.MapGet("/export", (ExportService exports) => Results.Ok(exports.Status()));

api.MapPut("/font/text", (AssetStore store, ExportService exports, TextRequest request) =>
{
    var text = store.SetText(request.Text);
    exports.MarkDirty();
    return Results.Ok(new { text });
});

api.MapPut("/font/tiles", (AssetStore store, ExportService exports, TilesRequest request) =>
{
    store.SetTiles(request.Tiles ?? []);
    exports.MarkDirty();
    return Results.NoContent();
});

api.MapPost("/images", (AssetStore store, ExportService exports, NewImageRequest? request) =>
{
    var image = store.CreateImage(request?.Name, request?.Width, request?.Height);
    exports.MarkDirty();
    return Results.Created($"/api/images/{image.Id}", ImageJson.From(image));
});

api.MapPatch("/images/{id:long}", (AssetStore store, ExportService exports, long id, RenameRequest request) =>
{
    if (store.RenameImage(id, request.Name) is not { } image) return Results.NotFound();
    exports.MarkDirty();
    return Results.Ok(ImageJson.From(image));
});

api.MapPut("/images/{id:long}/pixels", (AssetStore store, ExportService exports, long id, PixelsRequest request) =>
{
    if (!store.SetPixels(id, request.Width, request.Height, request.Pixels)) return Results.NotFound();
    exports.MarkDirty();
    return Results.NoContent();
});

api.MapDelete("/images/{id:long}", (AssetStore store, ExportService exports, long id) =>
{
    if (!store.DeleteImage(id)) return Results.NotFound();
    exports.MarkDirty();
    return Results.NoContent();
});

// Unknown API routes are 404s; any other path is the page itself (routes live in the hash).
api.MapFallback(() => Results.NotFound());
app.MapFallbackToFile("index.html", revalidate);

app.Run();
