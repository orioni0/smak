#pragma once

#include "vec3.h"
#include "ray.h"

struct Camera
{
    Camera
    (
        int image_width,
        double viewport_height,
        double focal_length,
        double aspect_ratio,
        vec3 camera_center
    );

    int get_image_height();
    double get_viewport_width();
    vec3 get_viewport_u();
    vec3 get_viewport_v();
    vec3 get_pixel_delta_u();
    vec3 get_pixel_delta_v();
    vec3 get_viewport_upper_left();
    vec3 get_pixel00_loc();

    ray get_ray_to_pixel(int i, int j);

    int image_width;
    double viewport_height;
    double focal_length;
    double aspect_ratio;
    vec3 camera_center;
};

