     #include "vec3.h"
     #include <cmath>
     #include <sstream>

     vec3::vec3() : e{0, 0, 0} {}
     vec3::vec3(double x, double y, double z) : e{x, y, z} {}

     double vec3::x() const { return e[0]; }
     double vec3::y() const { return e[1]; }
     double vec3::z() const { return e[2]; }
     double vec3::get(int idx) const { return e[idx]; }

     vec3& vec3::add(const vec3& other) {
         e[0] += other.x();
         e[1] += other.y();
         e[2] += other.z();
         return *this;
     }

     vec3& vec3::sub(const vec3& other) {
         e[0] -= other.x();
         e[1] -= other.y();
         e[2] -= other.z();
         return *this;
     }

     vec3& vec3::scale(double scalar) {
         e[0] *= scalar;
         e[1] *= scalar;
         e[2] *= scalar;
         return *this;
     }

     double vec3::dot(const vec3& other) const {
         return e[0] * other.x() + e[1] * other.y() + e[2] * other.z();
     }

     vec3 vec3::cross(const vec3& other) const {
         return vec3(
             e[1] * other.z() - e[2] * other.y(),
             e[2] * other.x() - e[0] * other.z(),
             e[0] * other.y() - e[1] * other.x()
         );
     }

     double vec3::length() const {
         return std::sqrt(length_squared());
     }

     double vec3::length_squared() const {
         return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
     }

     std::string vec3::print() const {
         std::stringstream ss;
         ss << e[0] << " " << e[1] << " " << e[2];
         return ss.str();
     }
     
