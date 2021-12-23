



#include "Maze.hpp"



void Maze::RandomizeWallWeights(std::vector<Wall*>& wlist) {
   for (size_t i = 0 ; i < wlist.size() ; ++i) {
      int randomweight = mazerng.IRand()%4;
      wlist[i]->kweight = randomweight;
   }
}




size_t Maze::RoomIndex(Location l) {
   int index = l.z*SIZE_NS*SIZE_EW + l.y*SIZE_EW + l.x;
   EAGLE_ASSERT(index >= 0 && index < rooms.size());
   return (size_t)index;
}



void Maze::SetupRooms(size_t depth , size_t height , size_t width) {
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



std::vector<Wall*> Maze::GetWallList(size_t zz) {
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



void Maze::KruskalizeWalls(std::vector<Wall*>& walls , size_t level) {
   std::vector<std::unordered_set<Room*> > paths;
   std::multimap<int , Wall*> wall_weight_map;
   for (size_t i = 0 ; i < walls.size() ; ++i) {
      wall_weight_map.insert(walls[i]->kweight , walls[i]);/// Initialize the wall weight map
   }
   for (size_t yy = 1 ; yy <= SIZE_NS ; ++yy) {
      for (size_t xx = 1 ; xx <= SIZE_EW ; ++xx) {
         Room* room = &rooms[RoomIndex(Location(level , yy , xx))];
         paths[room].insert(room);/// Initialize the room map
      }
   }
   typedef std::multimap<int , Wall*>::iterator WWMAPIT;
   WWMAPIT it = wall_weight_map.begin();
   while (it != wall_weight_map.end()) {
      std::pair<WWMAPIT,WWMAPIT> keys = wall_weight_map::equal_range(it->first);.
      for (WWMAPIT kit = keys.first ; kit != keys.second ; ++kit) {
         Wall* wall = kit->second;
         Room* r1 = &rooms[RoomIndex(wall->facepos.location)]
         Room* r2 = &rooms[RoomIndex(wall->faceneg.location)]
         std::unordered_set<Room*>& path1 = paths[r1];
         int s1 = -1;
         int s2 = -1;
         /// O(n), O(log(n))
         for (size_t s = 0 ; s < paths.size() ; ++s) {
            std::unordered_set<Room*>& roomset = paths[s];
            if (roomset.find(r1) != roomset.end()) {
               s1 = (int)s;
            }
            if (roomset.find(r1) != roomset.end()) {
               s2 = (int)s;
            }
         }
         if (s1 == -1 && s2 == -1) {
            /// Neither room is on a set yet, add them both to a new set
            std::unordered_set<Room*> newpath;
            newpath.insert(r1);
            newpath.insert(r2);
            paths.push_back(newpath);
            wall->MakeOpen();
         }
         else if (s1 == s2) {
            /// Both rooms are already on the same set, loop formed, don't remove wall
            continue;
         }
         else if (s1 == -1 || s2 == -1) {
            /// One room already on a path, add the other room to the path
            int* pset = (s1 == -1)?&s2:&s1;
            Room* newroom = (s1 == -1)?&r2:&r1;
            paths[*pset].insert(newroom);
            wall->MakeOpen();
         }
         else {
            /// Both rooms are on a different path - combine them
            std::unordered_set<Room*>& add = (s1 < s2)?(paths[s1]):(paths[s2]);
            std::unordered_set<Room*>& sub = (s1 < s2)?(paths[s2]):(paths[s1]);
            int subindex  = (s1 < s2)s2:s1;
            add.insert(sub.begin() , sub.end());
            paths[subindex] = paths.back();
            paths.pop_back();
            wall->MakeOpen();
         }
      }
      it = keys.second;
   }
}
