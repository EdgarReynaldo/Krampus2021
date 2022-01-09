



#include "Movement.hpp"
#include "Eagle/Interpolate.hpp"




void Movement::OnSetAnimationPercent() {
   current.orient.SetTheta(Interpolate(prev.orient.Theta() , dest.orient.Theta() , animation_percent));
   current.pos = Interpolate(prev.pos , dest.pos , animation_percent);
   
}



void Movement::OnLoopComplete() {
   current = dest;
   prev = current;
   ResetAnimation();
}



void Movement::SetLocation(Vec3 pos) {
   dest.pos = pos;
}



void Movement::SetTheta(Vec3 angles) {
   dest.orient.SetTheta(angles);
   
}



void Movement::SetCompassAndGaze(COMPASS_DIRECTION dir , GAZE_DIRECTION pitch) {
   dir = (COMPASS_DIRECTION)(dir % NUM_COMPASS_DIRECTIONS);
   pitch = (GAZE_DIRECTION)(pitch % NUM_GAZES);
//   prev.orient = Orient(Vec3(YawFromDirection(heading) , PitchFromGaze(gaze) , 0.0));
   dest.orient = Orient(Vec3(YawFromDirection(dir) , PitchFromGaze(pitch) , 0.0));
}



double PitchFromGaze(GAZE_DIRECTION gdir) {
   static const double pitch[NUM_GAZES] = {
      -M_PI/2.0,
      -M_PI/4.0,
            0.0,
       M_PI/4.0,
       M_PI/2.0
   };
   return pitch[gdir];
}



double YawFromDirection(COMPASS_DIRECTION comdir) {
   static const double yaws[NUM_COMPASS_DIRECTIONS] = {
      M_PI/2.0,0.0,-M_PI/2.0,-M_PI
   };
   return yaws[comdir];
   /*
      N = 0,
      E = M_PI/2.0,
      S = M_PI,
      W = 3.0*M_PI/2.0,
   */
   /// East is 0, N is M_PI/2.0, W is M_PI, S is 3.0*M_PI/2.0
}



GAZE_DIRECTION GazeFromPitch(double pitch) {
   double pct = pitch/(2.0*M_PI);
   if (pct < 0.0) {
      pitch += (2.0*M_PI)*(abs(floor(pct) - 1));
   }
   else {
      pitch = fmod(pitch , 2.0*M_PI);
   }
   pitch -= 2.0*M_PI;
   if (pitch < -3.0*M_PI/8.0) {
      pitch = -M_PI/2.0;
      return GAZE_DOWN;
   }
   else if (pitch < -M_PI/8.0) {
      return GAZE_LOW;
   }
   else if (pitch < M_PI/8.0) {
      return GAZE_LEVEL;
   }
   else if (pitch < 3.0*M_PI/8) {
      return GAZE_HIGH;
   }
   return GAZE_UP;
}



COMPASS_DIRECTION DirectionFromYaw(double yaw) {
   /// East is zero degrees, positive goes ccw around y axis from top
   int n = yaw/2.0*M_PI;
   if (yaw < 0.0){
      yaw += (n+1)*2.0*M_PI;
   }
   else {
      yaw = 2.0*M_PI*(fmod(yaw , 2.0*M_PI));
   }
   /// We want a compass direction, and positive goes cw from north
   if (yaw < M_PI/4.0 || yaw >= 7.0*M_PI/4.0) {
      return COMPASS_EAST;
   else if (yaw < 3.0*M_PI/4.0) {
      return COMPASS_NORTH;
   }
   else if (yaw < 5.0*M_PI/4.0) {
      return COMPASS_WEST;
   }
   return COMPASS_SOUTH;
}




