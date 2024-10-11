#pragma once
#include <string>

struct vec3
{
private:
    double m_x, m_y, m_z;

public:
    vec3();
    vec3(double x, double y, double z);
    double x() const;
    double y() const;
    double z() const;
    double get(int idx) const;
    vec3 add(const vec3& rhs) const;
    vec3 sub(const vec3& rhs) const;
    vec3 scale(double a) const;
    double dot(const vec3& rhs) const;
    vec3 cross(const vec3& rhs) const;
    std::string print() const;
    double length() const;
    double length_squared() const;
};

vec3 operator+ (const vec3& rhs, const vec3& lhs);
vec3 operator- (const vec3& rhs, const vec3& lhs);
vec3 operator* (double a, const vec3& lhs);
vec3 operator* (const vec3& rhs, double a);
vec3 operator/ (const vec3& rhs, double lhs);
double dot(const vec3& rhs, const vec3& lhs);
double magn(const vec3& v);
vec3 unit(const vec3& v);