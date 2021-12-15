



#ifndef FACE_HPP
#define FACE_HPP

enum FACE_DIRECTION {
   FACE_UP = 0,///< Face on the ceiling
   FACE_N  = 1,///< Face on the north wall
   FACE_E  = 2,///< Face on the east wall
   FACE_DN = 3,///< Face on the floor
   FACE_S  = 4,///< Face on the south wall
   FACE_W  = 5,///< Face on the west wall
   NUM_FACE_DIRECTIONS = 6
};

enum WALL_DIRECTION {
   WALL_NS = 0,
   WALL_EW = 1,
   WALL_UD = 2,
   NUM_WALL_DIRECTIONS = 3
};

class Maze;

class Location {
public :
   int x,y,z;
   
   Location(int zpos , int ypos , int xpos);
   Location(int zpos , int ypos , int xpos) :
         x(xpos),
         y(ypos),
         z(zpos)
   {}
   
   bool ValidForMaze(Maze* m);
   bool ValidForMaze(Maze* m) {
      if (x < 1) {return false;}
      if (y < 1) {return false;}
      if (z < 1) {return false;}
      if (x >= m->SIZE_EW) {return false;}
      if (y >= m->SIZE_NS) {return false;}
      if (z >= m->SIZE_UD) {return false;}
      return true;
   }
   
   inline Location Up() {return Location(x,y,z+1);}
   inline Location Down() {return Location(x,y,z-1);}
   inline Location North() {return Location(x,y+1,z);}
   inline Location South() {return Location(x,y-1,z);}
   inline Location East() {return Location(x+1,y,z);}
   inline Location West() {return Location(x-1,y,z);}
};

#include <GL/gl.h>

class Face {
public :
   FACE_DIRECTION facedir;
   bool show;
   bool solid;
   EagleColor vcolor;
   GLuint facetex;
   Location location;
   
   Face(FACE_DIRECTION dir , Location loc);
   Face(FACE_DIRECTION dir , Location loc) :
         facedir(dir),
         show(true),
         solid(true),
         facetex(GLuint(-1)),
         location(loc)
   {}
};

class Wall {
public :
   WALL_DIRECTION walldir;/// Wall connects two rooms
   FACE facepos;/// N, E, or UP, Positive face
   FACE faceneg;/// S, W, or DN, Negative face
   
   Wall();
   Wall() :
         walldir(NUM_WALL_DIRECTIONS),
         facepos(NUM_FACE_DIRECTIONS),
         faceneg(NUM_FACE_DIRECTIONS)
   {}
   Wall(WALL_DIRECTION dir , Location loc);
   Wall(WALL_DIRECTION dir , Location loc) :
         walldir(dir),// floor tile
         facepos(NUM_FACE_DIRECTIONS),
         faceneg(NUM_FACE_DIRECTIONS)
   {
      switch(walldir) :
         case WALL_UD :
            faceneg = Face(FACE_DN , loc);/// Floor in this room
            facepos = Face(FACE_UP , loc.Down());/// Ceiling beneath us
            break;
         case WALL_NS :
            faceneg = Face(FACE_S , loc);/// South face of this room
            facepos = Face(FACE_N , loc.South());/// North face of room south of us
            break;
         case WALL_EW :
            faceneg = Face(FACE_W , loc);/// West face of this room
            facepos = Face(FACE_E , loc.West());/// East face of the room to the west
            break;
         default :
            throw -1;
   }
   
   bool Solid() {
      return facepos.solid && faceneg.solid;
   }
   bool Oneway() {
      return ((!facepos.solid && faceneg.solid) || (facepos.solid && !faceneg.solid));
   }
   bool Twoway() {
      return (!facepos.solid && !faceneg.solid);
   }
   
   
};

struct ItemDescription {
   std::string name;
   std::string shortdesc;
   std::string longdesc;
   EagleImage* icon;
};


class Item {
   ItemDescription desc;
   int quantity;
}

class ItemSorter {
   int operator()(const Item& i1 , const Item& i2) {
      return (i1.desc.name.compare(i2.desc.name));
   }
}

class Inventory {
   std::map<std::string , Item , ItemSorter> items;
   
   Inventory();
   Inventory() :
         items()
   {}
   
   AddItem
}

extern Inventory masterinventory;

Inventory masterinventory;

class Maze;

class Room {
public :
   /// Each room has 3 "REAL" walls, the other 3 are from another room because they're shared.
   Wall walldown;
   Wall wallsouth;
   Wall wallwest;

   Wall* pwall[NUM_FACE_DIRECTIONS];/// Each room has 6 walls
   
   Location location;
   
   Inventory inventory;
   
   Room();
   Room() :
         walldown(),
         wallsouth(),
         wallwest(),
         pwall(),
         location(-1,-1,-1),
         inventory()
   {}
   
   
   void SetupRoom(Maze* m , Location loc);
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
   
   
};


#include <vector>

class Maze {
public :
   std::vector<Room> rooms;/// 3D vector of rooms
   size_t SIZE_UD;/// Depth,z, valid rooms go from 1 to SIZE_UD
   size_t SIZE_NS;/// Height,y, valid rooms go from 1 to SIZE_NS
   size_t SIZE_EW;/// Width,x, valid rooms go from 1 to SIZE_EW

   
   Maze();
   Maze() :
      rooms(),
      SIZE_UD((size_t)-1),
      SIZE_NS((size_t)-1),
      SIZE_EW((size_t)-1)
   {}
   void GenerateMaze(size_t depth , size_t height , size_t width)
   {
      SIZE_UD = depth;
      SIZE_NS = height;
      SIZE_EW = width;
      rooms.resize((SIZE_UD+2)*(SIZE_NS+2)*(SIZE_EW+2) , Room());
      
      for (unsigned int zz = 1 ; zz <= SIZE_UD ; ++zz) {
         for (unsigned int yy = 1 ; yy <= SIZE_NS ; ++yy) {
            for (unsigned int xx = 1 , xx <= SIZE_EW ; ++xx) {
               Room* room = &rooms[Location(zz,yy,xx)];
               room->SetupRoom(this , Location(zz,yy,xx));
            }
         }
      }
   }
};

class Game {
   
   Maze maze;
   Player* player;
   AIPlayer* minotaur;
};


class PlayerBase {
   Inventory inventory;
   
   virtual void React(EagleEvent e)=0;
}




#endif // FACE_HPP





