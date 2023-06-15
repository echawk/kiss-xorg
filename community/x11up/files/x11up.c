#include <X11/Xlib.h>

int main() {
  return XOpenDisplay(NULL) ? 0 : 1;
}
