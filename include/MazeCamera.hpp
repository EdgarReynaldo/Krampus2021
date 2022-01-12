



#ifndef MAZE_CAMERA_HPP
#define MAZE_CAMERA_HPP


#include "Movement.hpp"
#include "Location.hpp"

#include "Eagle/Area.hpp"



class MazeCamera {
   Movement mv;/// contains position, orientation, interpolated towards destination
   Location loc;
   Rectangle winview;
   
   double hfov;/// In radians (horizontal field of view)
   double aspect;/// Aspect of view width to height
   double clipnear;
   double clipfar;
   
public :
   MazeCamera();
   
   void SetLocation(Location location);
   void SetCompassAndGaze(COMPASS_DIRECTION dir , GAZE_DIRECTION pitch);
   void TurnLeft();
   void TurnRight();
   void LookUp();
   void LookDown();
   void GoForward();

   void FinishMove();

   void SetViewport(int x , int y , int w , int h);

   void Setup3D(bool ortho = false);

   void Setup2D(int x , int y , int w , int h);
   
   SpatialInfo Info();
};




#endif // MAZE_CAMERA_HPP





