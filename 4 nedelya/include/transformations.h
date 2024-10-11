#pragma once
#include "utils.h"

color color_to_rgb(const color& input_color);
color gradient_vertical(const color& color_start, const color& color_end, int x, int y);
color gradient_horizontal(const color& color_start, const color& color_end, int x, int y);
color invert_color(const color& color);
color color2bw(const color& color);