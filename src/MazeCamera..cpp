



#include "MazeCamera.hpp"



MazeCamera::MazeCamera() :
      mv(),
      loc(0,0,0),
      hfov(2.0*M_PI/3.0),
      aspect(1.6),
      clipnear(1),
      clipfar(25)
{
   mv.SetLocation(Vec3(-1,-1,1));
   mv.SetTheta(Vec3(M_PI/4.0,0,0));
   mv.Finish();
}



void MazeCamera::TurnLeft() {
   SetCompassAndGaze((COMPASS_DIRECTION)((mv.heading + 3)%NUM_COMPASS_DIRECTIONS) , mv.gaze);
}



void MazeCamera::TurnRight() {
   SetCompassAndGaze((COMPASS_DIRECTION)((mv.heading + 1)%NUM_COMPASS_DIRECTIONS) , mv.gaze);
}



void MazeCamera::LookUp() {
   SetCompassAndGaze(mv.heading , (GAZE_DIRECTION)((mv.gaze + 1)%NUM_GAZES));
}



void MazeCamera::LookDown() {
   SetCompassAndGaze(mv.heading , (GAZE_DIRECTION)((mv.gaze + 4)%NUM_GAZES));
}



void MazeCamera::GoForward() {
   SetLocation(Forward(loc , mv.heading));
}

#include "allegro5/allegro.h"

void MazeCamera::Setup3D(bool ortho) {
   ALLEGRO_TRANSFORM proj,view,rot;

   al_identity_transform(&proj);
   al_identity_transform(&view);
   al_identity_transform(&rot);
   
   double w = tan(hfov/2.0);
   double left = -w;
   double right = w;
   double ht = w/aspect;
   
   if (ortho) {
      al_orthographic_transform(&proj , -clipfar , clipfar , -clipfar , clipfar , -clipfar , clipfar);
   }
   else {
      al_perspective_transform(&proj , left , ht/2.0 , clipnear , right , -ht/2.0 , clipfar);
   }
   al_use_projection_transform(&proj);
   
   Vec3 campos = mv.current.pos - mv.current.orient.fw*1.5*clipnear;
   Vec3 eyepos = campos + mv.current.orient.fw;
   Vec3 uppos = mv.current.orient.up;
   al_build_camera_transform(&view , campos.x , campos.y , campos.z , eyepos.x , eyepos.y , eyepos.z , uppos.x , uppos.y , uppos.z);
   al_rotate_transform_3d(&rot , 1.0 , 0.0 , 0.0 , M_PI/2.0);
//   al_compose_transform(&view , &rot);
   al_compose_transform(&rot , &view);
   al_use_transform(&rot);
}



void MazeCamera::SetLocation(Location location) {
   loc = location;
   mv.SetLocation(Vec3(loc.x , loc.y , loc.z) + Vec3(0.5,0.5,0.5) - mv.current.orient.Fw()*1.5);
   FinishMove();
}



void MazeCamera::SetCompassAndGaze(COMPASS_DIRECTION dir , GAZE_DIRECTION pitch) {
   mv.SetCompassAndGaze(dir , pitch);
}



void MazeCamera::FinishMove() {
   mv.Finish();
}


#include "GL/gl.h"



void MazeCamera::SetViewport(int x , int y , int w , int h) {
   glViewport(x,y,w,h);
}



void MazeCamera::Setup2D(int x , int y , int w , int h) {
   SetViewport(x,y,w,h);
   winview.SetArea(x,y,w,h);
   ALLEGRO_TRANSFORM ortho;
   al_identity_transform(&ortho);
   al_use_transform(&ortho);
//   al_orthographic_transform(&ortho , -w/2.0f , -h/2.0f , -1.0f , w/2.0 , h/2.0f , 1.0f);
   al_orthographic_transform(&ortho , 0.0f , 0.0f , -1.0f , w , h , 1.0f);
   al_use_projection_transform(&ortho);
   
}



SpatialInfo MazeCamera::Info() {
   return mv.current;
}



