#include <stdio.h>
#include <stdlib.h>
#include "..\misc.h"
#include <raylib.h>
#include <time.h>

const float refreshRate = 0.02;
const int zoom = 3;
bool cols80 = false;

byte* TILE_TABLE_ADDRESS;
byte* PIXEL_TABLE_ADDRESS;
byte* pixelBank, *colourBank;


byte* baseFont;


Color* colorMap;


void initSystem( bool _cols80)
{
	cols80 = _cols80;

	SetConfigFlags(FLAG_VSYNC_HINT);

	if (cols80)
	{
		InitWindow((80 * 8) * zoom, (24 * 10)* 2 * zoom, "Microbee 128k (winver)");

		TILE_TABLE_ADDRESS = malloc(80*24);
		memset(TILE_TABLE_ADDRESS, 32, 80*24);

		colourBank = malloc(80 * 24);
		memset(colourBank, 0x07, 80 * 24);

	}
	else
	{
		InitWindow(512 * zoom, 512 * zoom, "Microbee 128k (winver)");

		TILE_TABLE_ADDRESS = malloc(0x800);
		memset(TILE_TABLE_ADDRESS, 32, 0x800);

		colourBank = malloc(0x800);
		memset(colourBank, 0x07, 0x800);
	}

	pixelBank = malloc(128 * 16);
	memset(pixelBank, 0, 128 * 16);

	PIXEL_TABLE_ADDRESS = pixelBank;
	

	colorMap = malloc( sizeof(Color)*16);
	colorMap[0] = BLACK;
	colorMap[1] = CLITERAL(Color) { 0xc0, 0, 0, 255 };
	colorMap[2] = CLITERAL(Color) { 0, 0xc0, 0, 255 };
	colorMap[3] = CLITERAL(Color) { 0xc0, 0xc0, 0, 255 };
	colorMap[4] = CLITERAL(Color) { 0, 0, 0xc0, 255 };
	colorMap[5] = CLITERAL(Color) { 0xc0, 0, 0xc0, 255 };
	colorMap[6] = CLITERAL(Color) { 0, 0xc0, 0xc0, 255 };
	colorMap[7] = CLITERAL(Color) { 255, 255, 255, 255 };
	colorMap[8] = CLITERAL(Color) { 96, 96, 96, 255 };
	colorMap[9] = CLITERAL(Color) {255, 0, 0, 255 };
	colorMap[10] = CLITERAL(Color) { 0, 255, 0, 255 };
	colorMap[11] = CLITERAL(Color) { 255, 255, 0, 255 };
	colorMap[12] = CLITERAL(Color) { 0, 0, 255, 255 };
	colorMap[13] = CLITERAL(Color) { 255, 0, 255, 255 };
	colorMap[14] = CLITERAL(Color) { 0, 255, 255, 255 };
	colorMap[15] = CLITERAL(Color) { 255, 255, 255, 255 };

	int ds = 4096;
	baseFont= LoadFileData( "charrom.bin", &ds);


	SetTraceLogLevel(LOG_ALL);
	//for (int i = 0; i < 16; i++)
	//{
	//	TraceLog(0, "%d %d %d: %f", colorMap[i].r, colorMap[i].g, colorMap[i].b, colorMap[i].r * 0.2126 + colorMap[i].g * 0.7152 + colorMap[i].b * 0.0722);
	//}
}

bool isKeyDown(uint8_t key)
{
	return IsKeyPressed(key);
}

void vduColor(void)
{
	PIXEL_TABLE_ADDRESS = colourBank;
}

void vduPixels(void)
{
	PIXEL_TABLE_ADDRESS = pixelBank;
}

int lastClockSample = 0;

int sampleClock(void)
{
	time_t t = time(NULL);
	struct tm *t2= localtime(&t);

	int nt = t2->tm_sec + t2->tm_min * 60 + t2->tm_hour * 60 * 60;

	if (lastClockSample == 0)
	{
		lastClockSample = nt;
		return 0;
	}
	else
	{
		int t= nt - lastClockSample;
		lastClockSample = nt;
		return t;
	}
}

void vBlank()
{
	double st= GetTime();

	BeginDrawing();
	ClearBackground(BLUE);

	if (cols80)
	{
		for (int x = 0; x < 80; x++)
		{
			for (int y = 0; y < 24; y++)
			{
				int cp = x + y * 80;
				int ch = TILE_TABLE_ADDRESS[cp];
				Color fg = colorMap[colourBank[cp] & 0xf];
				Color bg = colorMap[colourBank[cp] >> 4 & 0xf];

				for (int yy = 0; yy < 10; yy++)
				{
					int ln;

					if (ch < 128)
						ln = baseFont[ch * 16 + yy + 2048];
					else
						ln = pixelBank[(ch - 128) * 16 + yy];


					for (int xx = 0; xx < 8; xx++)
					{
						int v = (ln >> (7 - xx)) & 0x1;

						Color col = v > 0 ? fg : bg;
						DrawRectangle((x * 8 * zoom) + (xx * zoom), (y * 10 * 2 * zoom) + (yy * 2 * zoom), zoom, zoom * 2, col);
					}
				}
			}
		}
	}
	else
	{
		for (int x = 0; x < 64; x++)
		{
			for (int y = 0; y < 16; y++)
			{
				int cp = x + y * 64;
				int ch = TILE_TABLE_ADDRESS[cp];
				Color fg = colorMap[colourBank[cp] & 0xf];
				Color bg = colorMap[colourBank[cp] >> 4 & 0xf];

				for (int yy = 0; yy < 16; yy++)
				{
					int ln;

					if (ch < 128)
						ln = baseFont[ch * 16 + yy];
					else
						ln = pixelBank[(ch - 128) * 16 + yy];


					for (int xx = 0; xx < 8; xx++)
					{
						int v = (ln >> (7 - xx)) & 0x1;

						Color col = v > 0 ? fg : bg;
						DrawRectangle((x * 8 * zoom) + (xx * zoom), (y * 16 * 2 * zoom) + (yy * 2 * zoom), zoom, zoom * 2, col);
					}
				}
			}
		}
	}


	EndDrawing();

	if (WindowShouldClose())
		exit(1);

	while (GetTime() < (st + refreshRate));
}