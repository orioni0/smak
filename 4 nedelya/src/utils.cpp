#include "utils.h"
#include "hit.h"
#include "transformations.h"

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>

void write_color(std::ostream& out, const color& pixel_color)
{
    out << color_to_rgb(pixel_color).print();
}

void write_image(Camera camera)
{
    std::string path("image.ppm");
    std::ofstream os(path);
    unsigned WIDTH = camera.image_width;
    unsigned HEIGHT = camera.get_image_height();
    os << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";

    for (int j = 0; j < HEIGHT; j++)
    {
        std::clog << "\rScanlines remaining: " << (HEIGHT - j) << ' ' << std::flush;
        for (int i = 0; i < WIDTH; i++)
        {
            vec3 viewport_upper_left = camera.get_viewport_upper_left();

            ray r = camera.get_ray_to_pixel(i, j);
            vec3 color = ray_color(r);

            write_color(os, color);
            os << '\n';
        }
    }
    std::clog << "\rDone.\n";
}

color ray_color(const ray& r)
{
    Sphere sp(1, vec3(0, 0, -3));
    Sphere sp_big(100, vec3(0, -100.5, -1));
    Hittable_List world = {&sp, &sp_big};
    vec3 hit_point;
    hit_record rec;
    if(world.hit(r, 0, 100, rec))
    {
        vec3 normal = rec.normal;
        return color(normal);
    }
    vec3 unit_direction = r.get_b() * magn(r.get_b());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

