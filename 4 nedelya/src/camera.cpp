#include "camera.h"

Camera::Camera
(
    int image_width,
    double viewport_height,
    double focal_length,
    double aspect_ratio,
    vec3 camera_center
) : 
    image_width(image_width),
    viewport_height(viewport_height),
    focal_length(focal_length),
    aspect_ratio(aspect_ratio),
    camera_center(camera_center)
{}

int Camera::get_image_height()
{
    int image_height = int(image_width / aspect_ratio);
    return (image_height < 1) ? 1 : image_height;
}

double Camera::get_viewport_width()
{
    return viewport_height * (double(image_width) / get_image_height());
}

vec3 Camera::get_viewport_u()
{
    return vec3(get_viewport_width(), 0, 0);
}

vec3 Camera::get_viewport_v()
{
    return vec3(0, -viewport_height, 0);
}

vec3 Camera::get_pixel_delta_u()
{
    return get_viewport_u().scale(1.0/image_width);
}

vec3 Camera::get_pixel_delta_v()
{
    return get_viewport_v().scale(1.0/get_image_height()); 
}

vec3 Camera::get_viewport_upper_left()
{
    return camera_center.sub(vec3(0, 0, focal_length)).sub(get_viewport_u().scale(0.5)).sub(get_viewport_v().scale(0.5));
}

vec3 Camera::get_pixel00_loc()
{
    return get_viewport_upper_left().add((get_pixel_delta_u().add(get_pixel_delta_v())).scale(0.5));
}

ray Camera::get_ray_to_pixel(int i, int j)
{
    vec3 pixel00 = get_pixel00_loc();
    vec3 du = get_pixel_delta_u();
    vec3 dv = get_pixel_delta_v();
    return ray(camera_center, pixel00 + (du * i + dv * j));
}