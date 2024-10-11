#pragma once
#include "vec3.h"

struct ray
{
    ray();
    ray(vec3 A, vec3 b);
    vec3 at(double t) const;
    vec3 get_A() const;
    vec3 get_b() const;

private:
    vec3 m_A;
    vec3 m_b;
};

