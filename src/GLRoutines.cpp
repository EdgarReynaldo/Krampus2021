



#include "GLRoutines.hpp"

#include "Eagle/Logging.hpp"
#include "Eagle/StringWork.hpp"

#include "GL/gl.h"
#include "GL/glu.h"





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


