



#ifndef MAZE_HPP
#define MAZE_HPP

#include <vector>



class Maze {
public :
   std::vector<Room> rooms;/// 3D vector of rooms
   size_t SIZE_UD;/// Depth,z axis, valid rooms go from 1 to SIZE_UD
   size_t SIZE_NS;/// Height,y axis, valid rooms go from 1 to SIZE_NS
   size_t SIZE_EW;/// Width,x axis, valid rooms go from 1 to SIZE_EW

   unsigned int RoomIndex(Location l);
   
   Maze();
   Maze() :
      rooms(),
      SIZE_UD((size_t)-1),
      SIZE_NS((size_t)-1),
      SIZE_EW((size_t)-1)
   {}

   void SetupMaze(size_t depth , size_t height , size_t width);
   void SetupMaze(size_t depth , size_t height , size_t width) {
      SetupRooms(depth , height , width);
      
   }
   
   void SetupRooms(size_t depth , size_t height , size_t width);
   void SetupRooms(size_t depth , size_t height , size_t width) {
   {
      rooms.clear();
      SIZE_UD = depth;
      SIZE_NS = height;
      SIZE_EW = width;
      rooms.resize((SIZE_UD+2)*(SIZE_NS+2)*(SIZE_EW+2) , Room());
      
      /// Setup all the rooms
      for (unsigned int zz = 1 ; zz <= SIZE_UD ; ++zz) {
         for (unsigned int yy = 1 ; yy <= SIZE_NS ; ++yy) {
            for (unsigned int xx = 1 , xx <= SIZE_EW ; ++xx) {
               Room* room = &rooms[RoomIndex(Location(zz,yy,xx))];
               room->SetupRoom(this , Location(zz,yy,xx));/// This setups the rooms pwall array
            }
         }
      }
   }
   std::vector<Wall*> GetWallList(size_t zz) {
   std::vector<Wall*> GetWallList(size_t zz) {
      std::vector<Wall*> wlist;
      for (unsigned int yy = 1 ; yy <= SIZE_NS ; ++yy) {
         for (unsigned int xx = 1 , xx <= SIZE_EW ; ++xx) {
            Room* room = &rooms[RoomIndex(Location(zz,yy,xx))];
            wlist.push_back(room->pwall[FACE_N]);
            wlist.push_back(room->pwall[FACE_E]);
         }
      }
      wlist.pop_back();
      wlist.pop_back();
      return wlist;
   }
};






#endif // MAZE_HPP






