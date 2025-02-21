#include <vector>
#include "window.hh"

using pro2::ModKey, pro2::Colors;
using std::vector;

const int WIDTH = 320, HEIGHT = 200;
const int ZOOM = 3;

void paint_line(pro2::Window& window, int i, int color) {
    for (int j = 0; j < HEIGHT; j++) {
        window.set_pixel({i, j}, color);
    }
}

int bar_position(int time) {
    int f = time % (WIDTH * 2);
    return (f >= WIDTH ? (2 * WIDTH - 1) - f : f);
}

int main() {
    pro2::Window window("Window Animation", WIDTH, HEIGHT, ZOOM);

    while (window.next_frame()) {
        // Al pressionar Escape es tanca la finestra
        if (window.is_key_pressed(27)) {
            break;
        }

        // Esborrem la pantalla (fondo negre per defecte)
        window.clear(Colors::black);

        // Pintem una barra vermella que va de dalt a baix
        int j = bar_position(window.frame_count());
        if (window.is_key_pressed(32))
            paint_line(window, j, Colors::red);

        // Pintem una barra a on es clica el ratolí
        if (window.is_mouse_pressed()) {
            pro2::Pt pos = window.mouse_pos();
            paint_line(window, pos.x, Colors::yellow);
        }
    }
}