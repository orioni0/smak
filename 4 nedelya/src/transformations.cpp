#include "transformations.h"

color color_to_rgb(const color& input_color)
{
    int ir = int(255.999 * input_color.x());
    int ig = int(255.999 * input_color.y());
    int ib = int(255.999 * input_color.z());
    return color(ir, ig, ib);
}

color gradient_vertical(const color& color_start, const color& color_end, int x, int y, int HEIGHT)
{
    double t = double(y) / double(HEIGHT - 1);
    return color_end.scale(t).add(color_start.scale(1 - t)).scale(0.5);
}

color gradient_horizontal(const color& color_start, const color& color_end, int x, int y, int WIDTH)
{
    double t = double(x) / double(WIDTH - 1);
    return color_end.scale(t).add(color_start.scale(1 - t)).scale(0.5);
}

color invert_color(const color& input_color)
{
    return color{1, 1, 1}.sub(input_color);
}

color color2bw(const color& input_color)
{
    double sq3 = 1.73205080;
    double component = input_color.length()/sq3;
    return color(component, component, component);
}