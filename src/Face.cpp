



#include "Face.hpp"


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

static const float r = 0.5f;

const float[NUM_FACE_DIRECTIONS][NUM_CORNERS][3] cube_verts = {
   {{{-r,-r,r},{r,-r,r},{r,r,r},{-r,r,r}},/// FACE_UP - ceiling - aligned with north up
    {{-r,r,-r},{r,r,-r},{r,r,r},{-r,r,r}},/// FACE_N - north - aligned with up
    {{r,r,r},{r,r,r},{r,r,r},{r,r,r}},/// FACE_E - east - aligned with up
    {{r,r,r},{r,r,r},{r,r,r},{r,r,r}},/// FACE_DN - floor - aligned with south up
    {{r,r,r},{r,r,r},{r,r,r},{r,r,r}},/// FACE_S - south - aligned with up
    {{r,r,r},{r,r,r},{r,r,r},{r,r,r}} /// FACE_W - west - aligned with up
}
