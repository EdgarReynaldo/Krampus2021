



#ifndef VEC3D_HPP
#define VEC3D_HPP




class Vec3D {
public :
   double x,y,z;
   
   Vec3D();
   Vec3D(double xpos , double ypos , double zpos);
   
   void SetXYZ(double xpos , double ypos , double zpos);
   
   Vec3D operator+(const Vec3D& v);
   Vec3D operator-(const Vec3D& v);
   Vec3D operator-() const;
   Vec3D operator*(double factor);
   Vec3D operator/(double quotient);

   double Magnitude();
   Vec3D& Normalize();
};



inline Vec3D CrossProduct(const Vec3D& a , const Vec3D& b) {
   return Vec3D(a.y*b.z - a.z*b.y , a.z*b.x - a.x*b.z , a.x*b.y - a.y*b.x);
}

inline Vec3D GetNormal(const Vec3D& a , const Vec3D& b , const Vec3D& c) {
   const Vec3D A = a-b;
   const Vec3D B = c-a;
   Vec3D C = CrossProduct(A,B);
   C.Normalize();
   return C;
}

#endif // VEC3D_HPP






