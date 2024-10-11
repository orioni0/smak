#include "ray.h"
#include "vec3.h"

ray::ray() : m_A(vec3(0, 0, 0)), m_b(vec3(1, 0, 0)) {}

ray::ray(vec3 A, vec3 b) : m_A(A), m_b(b) {}

vec3 ray::at(double t) const
{
    return m_A.add(m_b.scale(t));
}

vec3 ray::get_A() const
{
    return m_A;
}

vec3 ray::get_b() const
{
    return m_b;
}
