



#ifndef ROOM_HPP
#define ROOM_HPP

#include "Face.hpp"
#include "Wall.hpp"
#include "Location.hpp"
#include "Inventory.hpp"



class Maze;

class Room {
public :
   /// Each room has 3 "REAL" walls, the other 3 are from another room because they're shared.
   Wall walldown;
   Wall wallsouth;
   Wall wallwest;

   Wall* pwall[NUM_FACE_DIRECTIONS];/// Each room has 6 walls
   Face* pfaces[NUM_FACE_DIRECTIONS];
   
   Location location;
   int scent;
   
   Inventory inventory;
   
   Room();
   void SetupRoom(Maze* m , Location loc);
};



#endif // ROOM_HPP
