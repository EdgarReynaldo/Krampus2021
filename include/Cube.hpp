



#ifndef CUBE_HPP
#define CUBE_HPP


#include "Face.hpp"
#include <vector>


std::vector<float> MakeCubeInside(float radius);



extern const std::vector<float> unitcubeinside;


const float* GetInsideCubeFace(FACE_DIRECTION d);

void QueueInsideFaceTriangles(FACE_DIRECTION d , Location loc , EagleColor col);

void DrawCubeInsides(Location loc , EagleColor face_colors[NUM_FACE_DIRECTIONS]);





#endif // CUBE_HPP





