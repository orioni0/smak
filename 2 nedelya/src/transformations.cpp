   #include "transformations.hpp"

   color gradient_vertical(const color& color_start, const color& color_end) {
       return color_start; // Упростим для примера
   }

   color gradient_horizontal(const color& color_start, const color& color_end) {
       return color_start; // Упростим для примера
   }

   color invert_color(const color& c) {
       return color(1.0 - c.x(), 1.0 - c.y(), 1.0 - c.z());
   }

   color color2bw(const color& c) {
       double gray = 0.3 * c.x() + 0.59 * c.y() + 0.11 * c.z();
       return color(gray, gray, gray);
   }
   
