// h('button', { class: 'x', onclick: fn }, 'Label', child, ...) builds an element.
// "on..." props are listeners; value, checked, disabled and the like are set as properties.
const PROPERTIES = new Set(['value', 'checked', 'disabled', 'selected', 'hidden', 'title', 'tabIndex']);

export function h(tag, props, ...children) {
  const element = document.createElement(tag);
  for (const [key, value] of Object.entries(props ?? {})) {
    if (value == null || value === false) continue;
    if (key === 'class') element.className = value;
    else if (key.startsWith('on')) element.addEventListener(key.slice(2), value);
    else if (PROPERTIES.has(key)) element[key] = value;
    else element.setAttribute(key, value === true ? '' : value);
  }
  element.append(...children.flat(Infinity).filter(child => child != null && child !== false));
  return element;
}

/** True when the key event is meant for a text field rather than for shortcuts. */
export function isTyping(event) {
  const target = event.target;
  return target instanceof HTMLElement
    && (target.isContentEditable || ['INPUT', 'TEXTAREA', 'SELECT'].includes(target.tagName));
}
