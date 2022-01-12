



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
   
   inline Location Up() {return Location(z+1,y,x);}
   inline Location Down() {return Location(z-1,y,x);}
   inline Location North() {return Location(z,y+1,x);}
   inline Location South() {return Location(z,y-1,x);}
   inline Location East() {return Location(z,y,x+1);}
   inline Location West() {return Location(z,y,x-1);}
};




#endif // LOCATION_HPP
