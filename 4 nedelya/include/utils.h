#pragma once

#include "vec3.h"
#include "ray.h"
#include "camera.h"

using color = vec3;

vec3 normal_to_sphere(const vec3& center, const vec3& point);
bool hit_sphere(const vec3& center, double radius, const ray& r, vec3& hit_point);
vec3 closest_point_on_ray(ray r, vec3 p);
color ray_color(const ray& r);
void write_color(std::ostream& out, const color& pixel_color);
void write_image(Camera camera);