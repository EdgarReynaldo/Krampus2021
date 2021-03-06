



#ifndef VEC3D_HPP
#define VEC3D_HPP



#include <ostream>

class Vec3D {
public :
   double x,y,z;
   
   Vec3D();
   Vec3D(double xpos , double ypos , double zpos);
   
   void SetXYZ(double xpos , double ypos , double zpos);
   
   Vec3D operator+(const Vec3D& v) const;
   Vec3D operator-(const Vec3D& v) const;
   Vec3D operator-() const;
   Vec3D operator*(double factor) const;
   Vec3D operator/(double quotient) const;

   double Magnitude();
   Vec3D& Normalize();
   
   friend std::ostream& operator<<(std::ostream& os , const Vec3D& v);
};

//Vec3D operator-(const Vec3D& v1 , const Vec3D& v2);
Vec3D operator-(const Vec3D& v1 , const Vec3D& v2);

inline Vec3D CrossProduct(const Vec3D& a , const Vec3D& b) {
   return Vec3D(a.y*b.z - a.z*b.y , a.z*b.x - a.x*b.z , a.x*b.y - a.y*b.x);
}

inline Vec3D GetNormal(const Vec3D& a , const Vec3D& b , const Vec3D& c) {
   const Vec3D A = a+-b;
   const Vec3D B = c+-a;
   Vec3D C = CrossProduct(A,B);
   C.Normalize();
   return C;
}

inline std::ostream& operator<<(std::ostream& os , const Vec3D& v) {
   os << v.x << "," << v.y << "," << v.z;
   return os;
}
#endif // VEC3D_HPP






