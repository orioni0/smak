     #ifndef VEC3_H
     #define VEC3_H

     class vec3 {
     public:
         vec3();
         vec3(double x, double y, double z);
         double x() const;
         double y() const;
         double z() const;
         double get(int idx) const;
         vec3& add(const vec3& other);
         vec3& sub(const vec3& other);
         vec3& scale(double scalar);
         double dot(const vec3& other) const;
         vec3 cross(const vec3& other) const;
         double length() const;
         double length_squared() const;
         std::string print() const;

     private:
         double e[3];
     };

     #endif
     
