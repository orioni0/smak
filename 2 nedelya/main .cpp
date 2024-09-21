#include <iostream>
#include <string>
#include <fstream>
#include "utils.h"
#include "vec3.h"
#include "transformations.hpp"

#ifndef WIDTH
#define WIDTH 480
#endif

#ifndef HEIGHT
#define HEIGHT 320
#endif

int main()
{
    std::string path("my_image.ppm");
    std::ofstream os(path);

    write_image("my_image.ppm", 480, 320);
       vec3 v1(1.0, 2.0, 3.0);
       vec3 v2(4.0, 5.0, 6.0);
     
     td::cout << "Dot product: " << v1.dot(v2) << std::endl;
    std::cout << "Cross product: " << v1.cross(v2).print() << std::endl;
    
    os << "P3\n" << WIDTH << ' ' << HEIGHT << "\n255\n";

    color color_start(1.0, 0.0, 0.0); // Красный
    color color_end(0.0, 0.0, 1.0);   // Синий

    // Пример использования вертикального градиента
    color vert_gradient = gradient_vertical(color_start, color_end);
    std::cout << "Vertical Gradient Color: " << vert_gradient.print() << std::endl;

    // Пример использования горизонтального градиента
    color horiz_gradient = gradient_horizontal(color_start, color_end);
    std::cout << "Horizontal Gradient Color: " << horiz_gradient.print() << std::endl;

    // Пример инверсии цвета
    color inverted_color = invert_color(color_start);
    std::cout << "Inverted Color: " << inverted_color.print() << std::endl;

    // Пример преобразования цвета в чёрно-белый
    color bw_color = color2bw(color_start);
    std::cout << "Black & White Color: " << bw_color.print() << std::endl;

    for (int j = 0; j < HEIGHT; j++)
    {
        std::clog << "\rScanlines remaining: " << (HEIGHT - j) << ' ' << std::flush;
        for (int i = 0; i < WIDTH; i++)
        {
            // transform [0, 1] to rgb color channels
            auto r = double(i) / (WIDTH-1);
            auto g = double(j) / (HEIGHT-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);
            // end of transform

            os << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::clog << "\rDone.                 \n";
}
