



#ifndef SpatialInfo_HPP
#define SpatialInfo_HPP



#include "Vec3.hpp"
#include "Orient.hpp"


extern const Vec3 ORIGIN;




class SpatialInfo {
   
public :
   Vec3 pos;
   Orient orient;
   
   SpatialInfo() : pos() , orient() {}
   SpatialInfo(Vec3 p , Orient o) : pos(p) , orient(o) {}
};


extern const SpatialInfo START;


#endif // SpatialInfo_HPP
