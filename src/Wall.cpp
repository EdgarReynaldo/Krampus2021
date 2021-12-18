



#include "Wall.hpp"



Wall::Wall() :
      walldir(NUM_WALL_DIRECTIONS),
      facepos(NUM_FACE_DIRECTIONS),
      faceneg(NUM_FACE_DIRECTIONS),
      kweight(-1)
{}



Wall::Wall(WALL_DIRECTION dir , Location loc) :
      walldir(dir),// floor tile
      facepos(NUM_FACE_DIRECTIONS),
      faceneg(NUM_FACE_DIRECTIONS)
{
   switch(walldir) :
      case WALL_UD :
         faceneg = Face(FACE_DN , loc);/// Floor in this room
         facepos = Face(FACE_UP , loc.Down());/// Ceiling beneath us
         break;
      case WALL_NS :
         faceneg = Face(FACE_S , loc);/// South face of this room
         facepos = Face(FACE_N , loc.South());/// North face of room south of us
         break;
      case WALL_EW :
         faceneg = Face(FACE_W , loc);/// West face of this room
         facepos = Face(FACE_E , loc.West());/// East face of the room to the west
         break;
      default :
         throw -1;
}



bool Wall::Solid() {
   return facepos.solid && faceneg.solid;
}



bool Wall::Oneway() {
   return ((!facepos.solid && faceneg.solid) || (facepos.solid && !faceneg.solid));
}



bool Wall::Twoway() {
   return (!facepos.solid && !faceneg.solid);
}



void Wall::MakeOneWay(bool positive_face_open) {
   if (positive_face_open) {
      facepos.solid = false;
      faceneg.solid = true;
   }
   else {
      facepos.solid = true;
      faceneg.solid = false;
   }
}



void Wall::MakeSolid() {
   faceneg.solid = true;
   facepos.solid = true;
}



void Wall::MakeOpen() {
   faceneg.solid = false;
   facepos.solid = false;
}



void Wall::MakeVisible() {
   facepos.show = true;
   faceneg.show = true;
}



void Wall::MakeInvisible() {
   facepos.show = false;
   faceneg.show = false;
}
