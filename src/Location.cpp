



#include "Location.hpp"
#include "Maze.hpp"



bool Location::ValidForMaze(Maze* m) {
   if (x < 1) {return false;}
   if (y < 1) {return false;}
   if (z < 1) {return false;}
   if (x >= (int)m->SIZE_EW) {return false;}
   if (y >= (int)m->SIZE_NS) {return false;}
   if (z >= (int)m->SIZE_UD) {return false;}
   return true;
}
