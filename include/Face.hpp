



#ifndef FACE_HPP
#define FACE_HPP

enum FACE_DIRECTION {
   FACE_UP = 0,
   FACE_N  = 1,
   FACE_E  = 2,
   FACE_DN = 3,
   FACE_S  = 4,
   FACE_W  = 5,
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
   inline Location North() {return Location(x,y-1,z);}
   inline Location South() {return Location(x,y+1,z);}
   inline Location East() {return Location(x+1,y,z);}
   inline Location West() {return Location(x-1,y,z);}
};

#include <GL/gl.h>

class Face {
public :
   FACE_DIRECTION facedir;
   bool show;
   bool solid;
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
   WALL_DIRECTION walldir;
   FACE facepos;/// N, E, or UP
   FACE faceneg;/// S, W, or DN
   
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
            facepos = Face(FACE_UP , loc);
            faceneg = Face(FACE_DN , loc);
            break;
         case WALL_NS :
            facepos = Face(FACE_N , loc);
            faceneg = Face(FACE_S , loc);
            break;
         case WALL_EW :
            facepos = Face(FACE_E , loc);
            faceneg = Face(FACE_W , loc);
            break;
         default :
            throw -1;
   }
};


struct Inventory;





class Room {
public :
   Wall walldown;
   Wall wallsouth;
   Wall wallwest;

   Wall* pwall[NUM_FACE_DIRECTIONS];
   
   Location location;
   
   Inventory inventory;
   
   Room(Location loc);
   Room(Location loc) :
         walldown(WALL_UD , loc),
         wallsouth(WALL_NS , loc),
         wallwest(WALL_EW , loc)
         pwall(),
         location(loc),
         inventory()
   {
      pwall[FACE_DN] = &walldown;
      pwall[FACE_W] = &wallwest;
      pwall[FACE_S] = &wallsouth;
   }
   
   
};


#include <vector>

class Maze {
public :
   std::vector<Room> rooms;/// 3D vector of rooms
   size_t SIZE_UD;/// Depth,z
   size_t SIZE_NS;/// Height,y
   size_t SIZE_EW;/// Width,x

   
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
      rooms.resize((depth+2)*(height+2)*(width+2) , Room());
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





