   #include "utils.h"
   #include <fstream>
   #include <iostream>

   void write_image(const std::string& path, int width, int height)
   {
       std::ofstream os(path);
       os << "P3\n" << width << ' ' << height << "\n255\n";

       for (int j = 0; j < height; j++)
       {
           std::clog << "\rScanlines remaining: " << (height - j) << ' ' << std::flush;
           for (int i = 0; i < width; i++)
           {
               auto r = double(i) / (width-1);
               auto g = double(j) / (height-1);
               auto b = 0.0;

               int ir = int(255.999 * r);
               int ig = int(255.999 * g);
               int ib = int(255.999 * b);

               os << ir << ' ' << ig << ' ' << ib << '\n';
           }
       }
       std::clog << "\rDone.                 \n";
   }
   
