#include <vector>
#include <iostream>
#include "window.hh"
using namespace std;

using pro2::Colors;

const int WIDTH = 256, HEIGHT = 240;
const int ZOOM = 2;

const int _ = -1;
const int r = Colors::red;
const int s = 0xecc49b;
const int b = 0x5e6ddc;
const int y = Colors::yellow;
const int h = Colors::black;
const int g = 0xaaaaaa;
const int w = 0x8d573c;

// clang-format off
const vector<vector<int>> mario_sprite = {
    {_, _, _, r, r, r, r, r, _, _, _, _},
    {_, _, r, r, r, r, r, r, r, r, r, _},
    {_, _, h, h, h, s, s, h, s, _, _, _},
    {_, h, s, h, s, s, s, h, s, s, s, _},
    {_, h, s, h, h, s, s, s, h, s, s, s},
    {_, h, h, s, s, s, s, h, h, h, h, _},
    {_, _, _, s, s, s, s, s, s, s, _, _},
    {_, _, r, r, b, r, r, r, _, _, _, _},
    {_, r, r, r, b, r, r, b, r, r, r, _},
    {r, r, r, r, b, b, b, b, r, r, r, r},
    {g, g, r, b, y, b, b, y, b, r, g, g},
    {g, g, g, b, b, b, b, b, b, g, g, g},
    {g, g, b, b, b, b, b, b, b, b, g, g},
    {_, _, b, b, b, _, _, b, b, b, _, _},
    {_, w, w, w, _, _, _, _, w, w, w, _},
    {w, w, w, w, _, _, _, _, w, w, w, w},
};
// clang-format on

const char arrow_up = 17;
const char arrow_down = 18;
const char arrow_left = 20;
const char arrow_right = 19;

void put_sprite(pro2::Window& window, pro2::Pt orig, const vector<vector<int>>& sprite) {
    for (int i = 0; i < sprite.size(); i++) {
        const vector<int>& line = sprite[i];
        for (int j = 0; j < line.size(); j++) {
            if (line[j] >= 0) {
                window.set_pixel({orig.x + j, orig.y + i}, line[j]);
            }
        }
    }
}

int main() {
    pro2::Window window("Mario Bros", WIDTH, HEIGHT, ZOOM);

    int x = WIDTH / 2 - 6;
    int y = WIDTH / 2 - 6;

    window.clear();
    //put_sprite(window, {x + 40, y}, mario_sprite);
    while (window.next_frame()) {
        window.sleep(10);
        //W 119
        if (window.is_key_pressed(84) and (y-2) > 0) y -= 2;
        //A
        else if (window.is_key_pressed(70) and (x-2) > 0) x -= 2;
        //S
        else if (window.is_key_pressed(71) and (y+16) < HEIGHT)    y += 2;
        //D
        else if (window.is_key_pressed(72) and (x+20) < WIDTH)    x += 2;

        window.clear();
        put_sprite(window, {x, y}, mario_sprite);
    }
}