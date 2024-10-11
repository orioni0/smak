#include "hit.h"
#include <cmath>

void hit_record::set_face_normal(const ray& r, const vec3& outward_normal)
{
    if(dot(r.get_b(), outward_normal) <= 0)
    {
        normal = outward_normal;
        front_face = true;
    }
    else 
    {
        normal = -1 * outward_normal;
        front_face = false;
    }
}

vec3 normal_to_sphere(const vec3& center, const vec3& point)
{
    return unit(point - center);
}

vec3 closest_point_on_ray(ray r, vec3 p)
{
    vec3 A = p - r.get_A();
    vec3 b = r.get_b();
    if (dot(A, b) <= 0)
        return r.get_A();
    double mbsq = b.length_squared();
    return (dot(A, b) / mbsq)*b;
}

Sphere::Sphere(double r, vec3 c) : radius(r), center(c) {}

bool Sphere::hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const 
{
    vec3 C = closest_point_on_ray(r, center);
    if(magn(center - C) <= radius)
    {
        if(magn(r.get_A() - center) >= radius)
        {
            vec3 tb = C - r.get_A();
            double delta_l = std::sqrt(radius*radius - (center - C).length_squared());
            vec3 hit_point = C - (unit(r.get_b())*delta_l);
            rec.hit_point = hit_point;
            rec.set_face_normal(r, normal_to_sphere(center, hit_point));
            rec.t = magn(hit_point - r.get_A()) / magn(r.get_b());
            if(rec.t >= ray_tmin && rec.t <= ray_tmax)
                return true;
            else
                return false;
        }
        else 
        {
            vec3 hit_point = vec3(0, 0, 0);
            //TODO: implement case when ray is starting inside
            return true;
        }
    }
    return false;
}

Hittable_List::Hittable_List() : objects() {}

Hittable_List::Hittable_List(std::initializer_list<Hittable*> lst)
{
    for(auto it = lst.begin(); it != lst.end(); ++it)
    {
        objects.push_back(*it);
    }
}

void Hittable_List::clear()
{
    objects.clear();
}

void Hittable_List::add(Hittable* object)
{
    objects.push_back(object);
}

bool Hittable_List::hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const 
{
    bool at_least_one = false;
    hit_record best;
    double t_best;
    for (auto it : objects)
    {
        hit_record tmprec;
        if(it->hit(r, ray_tmin, ray_tmax, tmprec))
        {
            if(!at_least_one || (t_best > tmprec.t))
            {
                at_least_one = true;
                t_best = tmprec.t;
                best = tmprec;
            }
        }
    }
    rec = best;
    if(at_least_one)
        return true;
    return false;
}
