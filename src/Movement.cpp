



#include "Movement.hpp"
#include "Eagle/Interpolate.hpp"




void Movement::OnSetAnimationPercent() {
   current.orient.SetTheta(Interpolate(prev.orient.Theta() , dest.orient.Theta() , animation_percent));
}



void Movement::OnLoopComplete() {
   current = dest;
   prev = current;
}



void Movement::SetLocation(Vec3 pos) {
   prev.pos = dest.pos;
   dest.pos = pos;
   current.pos = Interpolate(prev.pos , dest.pos , animation_percent);
}



void Movement::SetCompassAndGaze(COMPASS_DIRECTION dir , GAZE_DIRECTION pitch) {
   dir = (COMPASS_DIRECTION)(dir % NUM_COMPASS_DIRECTIONS);
   pitch = (GAZE_DIRECTION)(pitch % NUM_GAZES);
   prev.orient = Orient(Vec3(YawFromDirection(heading) , PitchFromGaze(gaze) , 0.0));
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
      0,M_PI/2.0,M_PI,3.0*M_PI/2.0
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




