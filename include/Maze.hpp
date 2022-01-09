



#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>
#include "Eagle/Random.hpp"
#include "Room.hpp"

class EagleGraphicsContext;
class Wall;

class Maze {
public :
   std::vector<Room> rooms;/// 3D vector of rooms
   size_t SIZE_UD;/// Depth,z axis, valid rooms go from 1 to SIZE_UD
   size_t SIZE_NS;/// Height,y axis, valid rooms go from 1 to SIZE_NS
   size_t SIZE_EW;/// Width,x axis, valid rooms go from 1 to SIZE_EW
   MTRNG mazerng;

   EagleImage* textures[NUM_FACE_DIRECTIONS];
   EagleColor colors[NUM_FACE_DIRECTIONS];
   
   void RandomizeWallWeights(std::vector<Wall*>& wlist);/// Uses mazerng


public :



   size_t RoomIndex(Location l);
   
   
//   Maze();
   Maze() :
      rooms(),
      SIZE_UD((size_t)-1),
      SIZE_NS((size_t)-1),
      SIZE_EW((size_t)-1),
      mazerng(),
      textures(),
      colors()
   {
      mazerng.Seed(0);
      colors[FACE_UP] = EagleColor(255,255,255,255);
      colors[FACE_N] = EagleColor(0,0,255,255);
      colors[FACE_E] = EagleColor(0,255,255,255);
      colors[FACE_DN] = EagleColor(127,127,127,255);
      colors[FACE_S] = EagleColor(255,255,0,255);
      colors[FACE_W] = EagleColor(127,127,255);
   }

//   void SetupMaze(size_t depth , size_t height , size_t width);
   void SetupMaze(size_t depth , size_t height , size_t width) {
      SetupRooms(depth , height , width);
      std::vector<std::vector<Wall*> > wallvecs;
      wallvecs.resize(depth , std::vector<Wall*>());
      for (size_t i = 1 ; i < SIZE_UD ; ++i) {
         wallvecs[i] = GetWallList(i);
         RandomizeWallWeights(wallvecs[i]);/// uses mazerng
      }
      for (size_t i = 1 ; i < SIZE_UD ; ++i) {
         KruskalizeWalls(wallvecs[i]);/// uses mazerng
      }
      
   }
   
   void SetupRooms(size_t depth , size_t height , size_t width);
   std::vector<Wall*> GetWallList(size_t zz);
   void KruskalizeWalls(std::vector<Wall*>& walls);/// Uses mazerng
   
   void DrawLevel(EagleGraphicsContext* win , size_t level);
};






#endif // MAZE_HPP






