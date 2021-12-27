



#ifndef WALL_HPP
#define WALL_HPP


#include "Face.hpp"
#include "Location.hpp"


enum WALL_DIRECTION {
   WALL_NS = 0,
   WALL_EW = 1,
   WALL_UD = 2,
   NUM_WALL_DIRECTIONS = 3
};




class Wall {
public :
   WALL_DIRECTION walldir;/// Wall connects two rooms
   Face facepos;/// N, E, or UP, Positive face
   Face faceneg;/// S, W, or DN, Negative face
   int kweight;/// Kruskal edge weight for maze generation
   
   
   Wall();
   Wall(WALL_DIRECTION dir , Location loc);
   bool Solid();
   bool Oneway();
   bool Twoway();

   
   void MakeOneWay(bool positive_face_open);
   void MakeSolid();
   void MakeOpen();
   void MakeVisible();
   void MakeInvisible();
   
};


#endif // WALL_HPP
