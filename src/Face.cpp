



#include "Face.hpp"

Face::Face() :
      facedir(NUM_FACE_DIRECTIONS),
      show(true),
      solid(true),
      vcolor(),
      location(-1,-1,-1)
{}



Face::Face(FACE_DIRECTION dir , Location loc) :
      facedir(dir),
      show(true),
      solid(true),
      location(loc)
{}
