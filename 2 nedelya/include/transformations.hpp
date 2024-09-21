   #ifndef TRANSFORMATIONS_HPP
   #define TRANSFORMATIONS_HPP

   #include "vec3.h"

   color gradient_vertical(const color& color_start, const color& color_end);
   color gradient_horizontal(const color& color_start, const color& color_end);
   color invert_color(const color& c);
   color color2bw(const color& c);

   #endif
   
