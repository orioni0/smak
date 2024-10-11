#pragma once
#include "vec3.h"
#include "ray.h"
#include <initializer_list>
#include <vector>

struct hit_record
{
    vec3 hit_point;
    vec3 normal;
    double t;
    bool front_face;
    void set_face_normal(const ray& r, const vec3& outward_normal);
};

class Hittable
{
public:
    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

class Sphere : public Hittable
{
public:
    Sphere(double r, vec3 c);
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;
    double radius;
    vec3 center;
};

class Hittable_List : public Hittable
{
public:
    Hittable_List();
    Hittable_List(std::initializer_list<Hittable*> lst);
    void clear();
    void add(Hittable* object);
    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override;
private:
    std::vector<Hittable*> objects;
};