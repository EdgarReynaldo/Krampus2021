



#include "Game.hpp"
#include "Eagle/GraphicsContext.hpp"



void Game::TextureMaze(EagleImage* textures[NUM_FACE_DIRECTIONS]) {
   maze.textures[FACE_DN] = textures[FACE_DN];
   maze.textures[FACE_S] = textures[FACE_S];
   maze.textures[FACE_W] = textures[FACE_W];
   maze.textures[FACE_UP] = textures[FACE_UP];
   maze.textures[FACE_N] = textures[FACE_N];
   maze.textures[FACE_E] = textures[FACE_E];
}



SCENE_STATUS Game::Init() {
   SetupMaze(1 , 25 , 25);
   player.location = Location(1,1,1);
   minotaur.location = Location(1,25,25);
   
   inventory = CreateGameInventory();
   minotaur.inventory.AddItem(inventory.TakeItemAll("Gold Coin"));
   
   minotaur.pmaze = &maze;
   
   cam.SetLocation(Location(1,1,1));
   cam.SetCompassAndGaze(COMPASS_NORTH , GAZE_LEVEL);
   
   return status = SCENE_READY;
}



SCENE_STATUS Game::HandleEvent(EagleEvent e) {
   if (e.type == EAGLE_EVENT_DISPLAY_CLOSE) {return status = SCENE_COMPLETE;}
   if (e.type == EAGLE_EVENT_KEY_DOWN && e.keyboard.keycode == EAGLE_KEY_ESCAPE) {
      return status = SCENE_COMPLETE;
   }
   if (e.type == EAGLE_EVENT_KEY_DOWN) {
      if (e.keyboard.keycode == EAGLE_KEY_1) {
         cam.SetCompassAndGaze(COMPASS_NORTH , GAZE_HIGH);
//         cam.SetLocation(Location(3,-10,12));
         cam.SetLocation(Location(-2 , 12 , 12));
      }
      else if (e.keyboard.keycode == EAGLE_KEY_2) {
         cam.SetCompassAndGaze(COMPASS_SOUTH , GAZE_HIGH);
         cam.SetLocation(Location(-10,12,12));
      }
      else if (e.keyboard.keycode == EAGLE_KEY_3) {
         cam.SetCompassAndGaze(COMPASS_SOUTH , GAZE_LOW);
         cam.SetLocation(Location(3,-15,12));
      }
      else if (e.keyboard.keycode == EAGLE_KEY_4) {
         cam.SetCompassAndGaze(COMPASS_WEST , GAZE_LOW);
         cam.SetLocation(Location(3,12,-10));
      }
   }
   
   
   
   
//   player.React(e);
//   minotaur.React(e);
   return status = SCENE_RUNNING;
}



SCENE_STATUS Game::Update(double dt) {
   player.Update(dt);
   return status = SCENE_RUNNING;
}
#include "Eagle/Logging.hpp"
#include "Eagle/System.hpp"
#include "Eagle/Timer.hpp"
#include "Eagle/StringWork.hpp"

#include "GLRoutines.hpp"

#include "GL/gl.h"

void Game::Display(EagleGraphicsContext* win) {
//   player.SetupCamera();
//   glEnable(GL_CULL_FACE);
//   glCullFace(GL_BACK);
//   EagleLog() << "Before setup." << std::endl;
//   CheckGL();
//   glDisable(GL_CULL_FACE);
//   glEnable(GL_TEXTURE_2D);
//   glEnable(GL_BLEND);
//   glEnable(GL_DEPTH_TEST);
//   EagleLog() << "After setup." << std::endl;
   /// Brute force all of maze
//   glClear(GL_DEPTH_BUFFER_BIT);

   glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);

   cam.Setup3D(false);

   
//   glEnable(GL_DEPTH_TEST);
//   glClear(GL_DEPTH_BUFFER_BIT);
   CheckGL();
   maze.DrawLevel(win , 1);
   CheckGL();
   
   Vec3 r = RIGHT*20.0;
   Vec3 u = UP*20.0;
   Vec3 f = FORWARD*20.0;
   
   glBegin(GL_LINES);

   /// X Axis is red
   glColor3ub(127,0,0);
   glVertex3d(-r.x , -r.y , -r.z);
   glVertex3i(0,0,0);

   glColor3ub(255,0,0);
   glVertex3i(0,0,0);
   glVertex3d(r.x , r.y , r.z);

   /// Y Axis is green
   glColor3ub(0,127,0);
   glVertex3d(-u.x , -u.y , -u.z);
   glVertex3i(0,0,0);

   glColor3ub(0,255,0);
   glVertex3i(0,0,0);
   glVertex3d(u.x , u.y , u.z);

   /// Z Axis is blue
   glColor3ub(0,0,127);
   glVertex3d(-f.x , -f.y , -f.z);
   glVertex3i(0,0,0);

   glColor3ub(0,0,255);
   glVertex3i(0,0,0);
   glVertex3d(f.x , f.y , f.z);

   glEnd();
   
   cam.Setup2D(0,0,win->Width() , win->Height());
   glDisable(GL_CULL_FACE);
   glDisable(GL_DEPTH_TEST);
   glFrontFace(GL_CW);

   win->DrawTextString(win->DefaultFont() , StringPrintF("Hello Krampus Revenge %lf" , win->GetSystem()->GetSystemTimer()->TimePassed()) , 10 , 10 , EagleColor(127,64,0));
//   Orient* o = &player.movement.current.orient;
   SpatialInfo info = cam.Info();

   win->DrawTextString(win->DefaultFont() , StringPrintF("loc = %d,%d,%d , orient = %lf,%lf,%lf" , (int)info.pos.z , (int)info.pos.y , (int)info.pos.x , 
   info.orient.theta.yaw , info.orient.theta.pitch , info.orient.theta.roll) , 10 , 40 , EagleColor(255,0,64));
   
}



void Game::SetupMaze(size_t game_depth , size_t game_height , size_t game_width) {
   maze.SetupMaze(game_depth , game_height , game_width);
}
