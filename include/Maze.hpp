



#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>



class Maze {
public :
   std::vector<Room> rooms;/// 3D vector of rooms
   size_t SIZE_UD;/// Depth,z axis, valid rooms go from 1 to SIZE_UD
   size_t SIZE_NS;/// Height,y axis, valid rooms go from 1 to SIZE_NS
   size_t SIZE_EW;/// Width,x axis, valid rooms go from 1 to SIZE_EW
   MTRNG mazerng;

   void RandomizeWallWeights(std::vector<Wall*>& wlist);/// Uses rng


public :



   unsigned int RoomIndex(Location l);
   
   
   Maze();
   Maze() :
      rooms(),
      SIZE_UD((size_t)-1),
      SIZE_NS((size_t)-1),
      SIZE_EW((size_t)-1),
      mazerng()
   {
      mazerng.Seed(0);
   }

   void SetupMaze(size_t depth , size_t height , size_t width);
   void SetupMaze(size_t depth , size_t height , size_t width) {
      SetupRooms(depth , height , width);
      std::vector<std::vector<Wall*> > wallvecs;
      wallvecs.resize(depth , std::vector<Wall*>());
      for (size_t i = 1 ; i < SIZE_UD ; ++i) {
         wallvecs[i] = GetWallList(i);
         RandomizeWallWeights(wallvecs[i]);/// uses rng
      }
      for (size_t i = 1 ; i < size_UD ; ++i) {
         KruskalizeWalls(wallvecs[i]);/// uses rng
      }
   }
   
   void SetupRooms(size_t depth , size_t height , size_t width);
   std::vector<Wall*> GetWallList(size_t zz);
   void KruskalizeWalls(std::vector<Wall*>& walls , size_t level);
};






#endif // MAZE_HPP






