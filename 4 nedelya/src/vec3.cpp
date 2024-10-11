#include "vec3.h"
#include <cassert>
#include <string>
#include <cmath>

vec3::vec3() : m_x(0), m_y(0), m_z(0) {}

vec3::vec3(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

double vec3::x() const
{
    return m_x;
}

double vec3::y() const
{
    return m_y;
}

double vec3::z() const
{
    return m_z;
}

double vec3::get(int idx) const
{
    switch (idx) {
        case 1:
            return m_x;
            break;
        case 2:
            return m_y;
            break;
        case 3:
            return m_z;
            break;
        default:
            assert(!"Invalid vec3 coordinate index.");
            break;
    }
}

vec3 vec3::add(const vec3& rhs) const
{
    return vec3(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z);
}

vec3 vec3::sub(const vec3& rhs) const
{
    return vec3(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z);
}

vec3 vec3::scale(double a) const
{
    return vec3(m_x * a, m_y * a, m_z * a);
}

double vec3::dot(const vec3& rhs) const
{
    return m_x * rhs.m_x + m_y * rhs.m_y + m_z * rhs.m_z; 
}

vec3 vec3::cross(const vec3& rhs) const
{
    return vec3
    (
        m_y * rhs.m_z - rhs.m_y * m_z,
        rhs.m_x * m_z - m_x * rhs.m_z,
        m_x * rhs.m_y - rhs.m_x * m_y
    );
}

std::string vec3::print() const
{
    return std::to_string(m_x) + " "
           + std::to_string(m_y) + " "
           + std::to_string(m_z);
}

double vec3::length() const
{
    return std::sqrt((*this).dot(*this));
}

double vec3::length_squared() const
{
    return (*this).dot(*this);
}

vec3 operator+ (const vec3& rhs, const vec3& lhs)
{
    return rhs.add(lhs);
}

vec3 operator- (const vec3& rhs, const vec3& lhs)
{
    return rhs.sub(lhs);
}

vec3 operator/ (const vec3& rhs, double lhs)
{
    return rhs.scale(1/lhs);
}

double dot(const vec3& rhs, const vec3& lhs)
{
    return rhs.dot(lhs);
}

double magn(const vec3& v)
{
    return v.length();
}

vec3 unit(const vec3& v)
{
    return v.scale(1/v.length());
}

vec3 operator* (const vec3& lhs, double a)
{
    return lhs.scale(a);
}

vec3 operator* (double a, const vec3& rhs)
{
    return rhs.scale(a);
}