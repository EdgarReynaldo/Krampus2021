



#ifndef GLROUTINES_HPP
#define GLROUTINES_HPP

#include "Eagle.hpp"
#include "Eagle/backends/Allegro5Backend.hpp"

#include "GL/gl.h"
#include "GL/glu.h"



void CheckGL();

class EagleImage;
GLuint GetOpenGLTexture(EagleImage* img);



#endif // GLROUTINES_HPP



