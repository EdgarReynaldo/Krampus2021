



#include "Maze.hpp"




size_t Maze::RoomIndex(Location l) {
   int index = l.z*SIZE_NS*SIZE_EW + l.y*SIZE_EW + l.x;
   EAGLE_ASSERT(index >= 0 && index < rooms.size());
   return (size_t)index;
}




