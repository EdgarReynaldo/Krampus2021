



#ifndef FACE_HPP
#define FACE_HPP


#include "Eagle/Color.hpp"
#include <GL/gl.h>
#include "Location.hpp"


enum FACE_DIRECTION {
   FACE_UP = 0,///< Face on the ceiling
   FACE_N  = 1,///< Face on the north wall
   FACE_E  = 2,///< Face on the east wall
   FACE_DN = 3,///< Face on the floor
   FACE_S  = 4,///< Face on the south wall
   FACE_W  = 5,///< Face on the west wall
   NUM_FACE_DIRECTIONS = 6
};

enum FACE_CORNER {
   CORNER_BL = 0,
   CORNER_BR = 1,
   CORNER_TR = 2,
   CORNER_TL = 3,
   NUM_CORNERS = 4
};





class Face {
public :
   FACE_DIRECTION facedir;
   bool show;
   bool solid;
   EagleColor vcolor;
   Location location;
   
   Face();
   Face(FACE_DIRECTION dir , Location loc);

};





#endif // FACE_HPP





