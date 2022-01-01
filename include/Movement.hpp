



#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

enum COMPASS_DIRECTION {
   COMPASS_NORTH = 0,
   COMPASS_EAST = 1,
   COMPASS_SOUTH = 2,
   COMPASS_WEST = 3,
   NUM_COMPASS_DIRECTIONS = 4
};



enum GAZE_DIRECTION {
   GAZE_DOWN  = 0,
   GAZE_LOW   = 1,
   GAZE_LEVEL = 2,
   GAZE_HIGH  = 3,
   GAZE_UP    = 4,
   NUM_GAZES  = 5
};



#include "Location.hpp"
#include "Orient.hpp"
#include "SpatialInfo.hpp"

#include "Eagle/AnimationBase.hpp"



class Movement : public AnimationBase {

   void OnSetAnimationPercent();
   void OnLoopComplete();

public :
   SpatialInfo dest;
   SpatialInfo prev;
   SpatialInfo current;

   COMPASS_DIRECTION heading;
   GAZE_DIRECTION gaze;

public :
//   Movement();
   Movement() :
         dest(),
         prev(),
         current(),
         heading(COMPASS_NORTH),
         gaze(GAZE_LEVEL)
   {}
   void SetLocation(Vec3 pos);
   void SetCompassAndGaze(COMPASS_DIRECTION dir , GAZE_DIRECTION pitch);

};

double PitchFromGaze(GAZE_DIRECTION gdir);
double YawFromDirection(COMPASS_DIRECTION comdir);




#endif // MOVEMENT_HPP







