



#include "Room.hpp"
#include "Maze.hpp"
#include "Eagle/Image.hpp"
#include "Eagle/GraphicsContext.hpp"



Room::Room() :
      walldown(),
      wallsouth(),
      wallwest(),
      pwall(),
      pfaces(),
      location(-1,-1,-1),
      scent(0),
      inventory()
{}


void Room::SetupRoom(Maze* m , Location loc) {
   location = loc;
   walldown = Wall(WALL_UD , loc);
   wallsouth = Wall(WALL_NS , loc);
   wallwest = Wall(WALL_EW , loc);
   pwall[FACE_DN] = &walldown;
   pwall[FACE_S] = &wallsouth;
   pwall[FACE_W] = &wallwest;
   pwall[FACE_UP] = &(m->rooms[m->RoomIndex(loc.Up())].walldown);
   pwall[FACE_N] = &(m->rooms[m->RoomIndex(loc.North())].wallsouth);
   pwall[FACE_E] = &(m->rooms[m->RoomIndex(loc.East())].wallwest);
   pfaces[FACE_DN] = &(pwall[FACE_DN]->faceneg);
   pfaces[FACE_S] = &(pwall[FACE_S]->faceneg);
   pfaces[FACE_W] = &(pwall[FACE_W]->faceneg);
   pfaces[FACE_UP] = &(pwall[FACE_UP]->facepos);
   pfaces[FACE_N] = &(pwall[FACE_N]->facepos);
   pfaces[FACE_E] = &(pwall[FACE_E]->facepos);
   colors[FACE_DN] = m->colors[FACE_DN];
   colors[FACE_S] = m->colors[FACE_S];
   colors[FACE_W] = m->colors[FACE_W];
   colors[FACE_UP] = m->colors[FACE_UP];
   colors[FACE_N] = m->colors[FACE_N];
   colors[FACE_E] = m->colors[FACE_E];
   ptextures[FACE_UP] = m->textures[FACE_UP];
   ptextures[FACE_N] = m->textures[FACE_N];
   ptextures[FACE_E] = m->textures[FACE_E];
   ptextures[FACE_DN] = m->textures[FACE_DN];
   ptextures[FACE_S] = m->textures[FACE_S];
   ptextures[FACE_W] = m->textures[FACE_W];
}
