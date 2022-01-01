


#include "Vec3D.hpp"


#include <cmath>
#include "Eagle/Exception.hpp"


/// -----------------------------     Vec3D     ---------------------------------




Vec3D::Vec3D() :
      x(0.0),
      y(0.0),
      z(0.0)
{}



Vec3D::Vec3D(double xpos , double ypos , double zpos) : 
      x(xpos),
      y(ypos),
      z(zpos)
{}



void Vec3D::SetXYZ(double xpos , double ypos , double zpos) {
   x = xpos;
   y = ypos;
   z = zpos;
}



Vec3D Vec3D::operator+(const Vec3D& v) const {
   return Vec3D(x + v.x , y + v.y , z + v.z);
}



Vec3D Vec3D::operator-(const Vec3D& v) const {
   return operator+(-v);
}



Vec3D Vec3D::operator-() const {
   return Vec3D(-x,-y,-z);
}



Vec3D Vec3D::operator*(double factor) const {
   return Vec3D(x*factor , y*factor , z*factor);
}



Vec3D Vec3D::operator/(double quotient) const {
   EAGLE_ASSERT(quotient != 0.0);
   return operator*(1.0/quotient);
}



double Vec3D::Magnitude() {
   return sqrt(x*x + y*y + z*z);
}



Vec3D& Vec3D::Normalize() {
   *this = *this/Magnitude();
   return *this;
}

   

Vec3D operator-(const Vec3D& v1 , const Vec3D& v2) {
   Vec3D v3 = v2 +- v1;
   return v3;
}

   
   
