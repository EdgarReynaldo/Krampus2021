



#ifndef CUBE_HPP
#define CUBE_HPP


#include "Face.hpp"
#include <vector>
#include "Eagle/Color.hpp"
#include "Eagle/Image.hpp"


std::vector<float> MakeCubeInside(float radius);



extern const std::vector<float> unitcubeinside;


const float* GetInsideCubeFace(FACE_DIRECTION d);

//void QueueInsideFaceTriangles(FACE_DIRECTION d , Location loc , EagleColor col);
void QueueInsideFaceTrianglesTex(FACE_DIRECTION d , Location loc , EagleColor col , EagleImage* tex);

void DrawCubeInsides(Location loc , EagleColor face_colors[NUM_FACE_DIRECTIONS] , EagleImage* textures[NUM_FACE_DIRECTIONS]);





#endif // CUBE_HPP





