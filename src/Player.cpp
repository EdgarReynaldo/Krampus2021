



#include "Player.hpp"



void HumanPlayer::TurnLeft() {
   movement.SetCompassAndGaze((COMPASS_DIRECTION)((movement.heading + 3)%NUM_COMPASS_DIRECTIONS) , movement.gaze);
}



void HumanPlayer::TurnRight() {
   movement.SetCompassAndGaze((COMPASS_DIRECTION)((movement.heading + 1)%NUM_COMPASS_DIRECTIONS) , movement.gaze);
}



void HumanPlayer::LookUp() {
   movement.SetCompassAndGaze(movement.heading , (GAZE_DIRECTION)((movement.gaze + 1)%NUM_GAZES));
}



void HumanPlayer::LookDown() {
   movement.SetCompassAndGaze(movement.heading , (GAZE_DIRECTION)((movement.gaze - 1)%NUM_GAZES));
}



void HumanPlayer::SetDefaultKeys(InputGroup turn_left , InputGroup turn_right , InputGroup look_up , InputGroup look_down) {
   pkeys["TurnLeft"] = turnleft = turn_left;//input_key_press(EAGLE_KEY_LEFT) && input_key_held(EAGLE_KEY_NO_MOD);
   pkeys["TurnRight"] = turnright = turn_right;//input_key_press(EAGLE_KEY_RIGHT) && input_key_held(EAGLE_KEY_NO_MOD);
   pkeys["LookUp"] = lookup = look_up;//input_key_press(EAGLE_KEY_UP) && input_key_held(EAGLE_KEY_NO_MOD);
   pkeys["LookDown"] = lookdown = look_down;//input_key_press(EAGLE_KEY_DOWN) && input_key_held(EAGLE_KEY_NO_MOD);
   
}



void HumanPlayer::Update(double dt) {
   movement.AdvanceAnimationTime(dt);
}



HumanPlayer::HumanPlayer() :
      PlayerBase(),
      pkeys(),
      turnleft(),
      turnright(),
      lookup(),
      lookdown()
{
   SetDefaultKeys(input_key_press(EAGLE_KEY_LEFT) && input_key_held(EAGLE_KEY_NO_MOD),
                  input_key_press(EAGLE_KEY_RIGHT) && input_key_held(EAGLE_KEY_NO_MOD),
                  input_key_press(EAGLE_KEY_UP) && input_key_held(EAGLE_KEY_NO_MOD),
                  input_key_press(EAGLE_KEY_DOWN) && input_key_held(EAGLE_KEY_NO_MOD));
}



void HumanPlayer::SetupCamera() {
   pcam.SetupViewPoint();
}



void HumanPlayer::React(EagleEvent e) {
   double dt = 0.0;
   if (e.type == EAGLE_EVENT_TIMER) {
      dt = e.timer.eagle_timer_source->SPT();
      Update(dt);
   }
   if (pkeys["TurnLeft"]) {
      TurnLeft();
   }
   else if (pkeys["TurnRight"]) {
      TurnRight();
   }
   else if (pkeys["LookUp"]) {
      LookUp();
   }
   else if (pkeys["LookDown"]) {
      LookDown();
   }
}



/// ---------------------------------    Minotaur     --------------------------------------




void Minotaur::React(EagleEvent e) {
   /// If no scent / hearing explore randomly
   /// Else if scent follow scent
   /// Else if sound follow sound
   /// Try to trick the player, and randomly drop a gold coin
}

