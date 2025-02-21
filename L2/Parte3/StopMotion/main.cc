#include <vector>
#include "window.hh"

using pro2::ModKey, pro2::Colors;
using std::vector;

const int WIDTH = 40, HEIGHT = 4;
const int ZOOM = 40;

void blank_frame(pro2::Window& window) {
    window.clear();
    window.next_frame();
    window.sleep(200);
}

bool progress_bar_up(pro2::Window& window) {
    for (int i = 0; i < WIDTH; i++) {
        window.set_pixel({i, 0}, Colors::yellow);
        if (!window.next_frame()) {
            return false;
        }
        window.sleep(200);
    }
    return true;
}

bool pixel_down(pro2::Window& window) {
    for (int i = WIDTH - 1; i >= 0; i--) {
        // que no se limpian los pixeles
        window.clear();
        window.set_pixel({i, 0}, Colors::blue);
        if (!window.next_frame()) {
            return false;
        }
        window.sleep(80);
    }
    return true;
}

int main() {
    pro2::Window window("Stop Motion!", WIDTH, HEIGHT, ZOOM);
    blank_frame(window);
    if (!progress_bar_up(window)) {
        return 0;
    }
    blank_frame(window);
    if (!pixel_down(window)) {
        return 0;
    }
}