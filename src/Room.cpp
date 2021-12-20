



#include "Room.hpp"
#include "Maze.hpp"



Room() :
      walldown(),
      wallsouth(),
      wallwest(),
      pwall(),
      pfaces(),
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
   pwall[FACE_UP] = &(m->rooms[m->RoomIndex(loc.Up())].walldown);
   pwall[FACE_N] = &(m->rooms[m->RoomIndex(loc.North())].wallsouth);
   pwall[FACE_E] = &(m->rooms[m->RoomIndex(loc.East())].wallwest;
   pfaces[FACE_DN] = pwall[FACE_DN]->faceneg;
   pfaces[FACE_S] = pwall[FACE_S]->faceneg;
   pfaces[FACE_W] = pwall[FACE_W]->faceneg;
   pfaces[FACE_UP] = pwall[FACE_UP]->facepos;
   pfaces[FACE_N] = pwall[FACE_N]->facepos;
   pfaces[FACE_E] = pwall[FACE_E]->facepos;
}
