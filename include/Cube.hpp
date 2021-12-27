



#ifndef CUBE_HPP
#define CUBE_HPP


#include "Face.hpp"



std::vector<float> MakeCubeInside(float radius);



extern const std::vector<float> unitcubeinside;


const float* GetInsideCubeFace(FACE_DIRECTION d);

void QueueInsideFaceTriangles(FACE_DIRECTION d , Location loc , EagleColor col);

void DrawCubeInsides(Location loc , EagleColor face_colors[NUM_FACE_DIRECTIONS]);
void DrawCubeInsides(Location loc , EagleColor face_colors[NUM_FACE_DIRECTIONS]) {
   QueueInsideFaceTriangles(FACE_DN , loc , face_colors[FACE_DN]);
   QueueInsideFaceTriangles(FACE_S  , loc , face_colors[FACE_S ]);
   QueueInsideFaceTriangles(FACE_W  , loc , face_colors[FACE_W ]);
   QueueInsideFaceTriangles(FACE_UP , loc , face_colors[FACE_UP]);
   QueueInsideFaceTriangles(FACE_N  , loc , face_colors[FACE_N ]);
   QueueInsideFaceTriangles(FACE_E  , loc , face_colors[FACE_E ]);
}

#endif // CUBE_HPP
