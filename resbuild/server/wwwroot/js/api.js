// The server's REST API. A failed request throws an Error carrying the HTTP status (none when the
// server could not be reached) and the server's own message when it gave one.
async function request(method, url, body) {
  const options = { method };
  if (body !== undefined) {
    options.headers = { 'Content-Type': 'application/json' };
    options.body = JSON.stringify(body);
  }

  const response = await fetch(url, options);
  if (!response.ok) {
    let message = `${response.status} ${response.statusText}`;
    try {
      message = (await response.json()).error ?? message;
    } catch {
      // Not JSON: keep the status line.
    }
    throw Object.assign(new Error(message), { status: response.status });
  }
  return response.status === 204 ? null : response.json();
}

export const api = {
  state: () => request('GET', '/api/state'),
  exportStatus: () => request('GET', '/api/export'),
  setText: text => request('PUT', '/api/font/text', { text }),
  setTiles: tiles => request('PUT', '/api/font/tiles', { tiles }),
  createImage: () => request('POST', '/api/images', {}),
  renameImage: (id, name) => request('PATCH', `/api/images/${id}`, { name }),
  setPixels: (id, width, height, pixels) => request('PUT', `/api/images/${id}/pixels`, { width, height, pixels }),
  deleteImage: id => request('DELETE', `/api/images/${id}`),
};

/** True when retrying might help: the server was unreachable or failed, rather than refusing. */
export function isRetryable(error) {
  return !(error.status < 500);
}
