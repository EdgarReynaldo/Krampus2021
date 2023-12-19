



#include "GLRoutines.hpp"



void CheckGL() {
   int err = GL_NO_ERROR;
   do {
      err = glGetError();
      if (err != GL_NO_ERROR) {
         EagleLog() << StringPrintF("GL reports error %d (%s)" , err , gluErrorString(err)) << std::endl;
      }
      else {
         EagleLog() << "GL reports no error." << std::endl;
      }
   } while (err != GL_NO_ERROR);
}



GLuint GetOpenGLTexture(EagleImage* img) {
   return al_get_opengl_texture(GetAllegroBitmap(img));
}


