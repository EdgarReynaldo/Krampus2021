



#include "Room.hpp"
#include "Maze.hpp"



Room() :
      walldown(),
      wallsouth(),
      wallwest(),
      pwall(),
      location(-1,-1,-1),
      inventory()
{}


void SetupRoom(Maze* m , Location loc) :
{
   location = loc;
   walldown = Wall(WALL_UD , loc);
   wallsouth = Wall(WALL_NS , loc);
   wallwest = Wall(WALL_EW , loc);
   pwall[FACE_DN] = &walldown;
   pwall[FACE_S] = &wallsouth;
   pwall[FACE_W] = &wallwest;
   pwall[FACE_UP] = &(m->rooms[loc.Up()].walldown);
   pwall[FACE_N] = &(m->rooms[loc.North()].wallsouth);
   pwall[FACE_E] = &(m->rooms[loc.East()].wallwest;
}
