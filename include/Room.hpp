



#ifndef ROOM_HPP
#define ROOM_HPP

#include "Face.hpp"
#include "Wall.hpp"
#include "Cube.hpp"
#include "Location.hpp"
#include "Inventory.hpp"


class EagleImage;
class EagleGraphicsContext;

class Maze;

class Room {
public :
   /// Each room has 3 "REAL" walls, the other 3 are from another room because they're shared.
   Wall walldown;
   Wall wallsouth;
   Wall wallwest;

   Wall* pwall[NUM_FACE_DIRECTIONS];/// Each room has 6 walls
   Face* pfaces[NUM_FACE_DIRECTIONS];
   EagleImage* ptextures[NUM_FACE_DIRECTIONS];
   EagleColor colors[NUM_FACE_DIRECTIONS];
   
   Location location;
   int scent;
   
   Inventory inventory;
   
   Room();
   void SetupRoom(Maze* m , Location loc);
//   void Texture(EagleImage*tex[NUM_FACE_DIRECTIONS]);
   void Texture(EagleImage*tex[NUM_FACE_DIRECTIONS]) {
      ptextures[FACE_UP] = tex[FACE_UP];
      ptextures[FACE_N] = tex[FACE_N];
      ptextures[FACE_E] = tex[FACE_E];
      ptextures[FACE_DN] = tex[FACE_DN];
      ptextures[FACE_S] = tex[FACE_S];
      ptextures[FACE_W] = tex[FACE_W];
   }
   
   
//   void DrawRoom(EagleGraphicsContext* win);
   void DrawRoom(EagleGraphicsContext* win);
};



#endif // ROOM_HPP
