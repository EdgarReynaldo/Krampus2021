



#ifndef LOCATION_HPP
#define LOCATION_HPP





class Maze;

class Location {
public :
   int x,y,z;
   
//   Location(int zpos , int ypos , int xpos);
   Location(int zpos , int ypos , int xpos) :
         x(xpos),
         y(ypos),
         z(zpos)
   {}
   
   bool ValidForMaze(Maze* m);
   
   inline Location Up() {return Location(x,y,z+1);}
   inline Location Down() {return Location(x,y,z-1);}
   inline Location North() {return Location(x,y+1,z);}
   inline Location South() {return Location(x,y-1,z);}
   inline Location East() {return Location(x+1,y,z);}
   inline Location West() {return Location(x-1,y,z);}
};




#endif // LOCATION_HPP
