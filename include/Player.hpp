



#ifndef PLAYERBASE_HPP
#define PLAYERBASE_HPP

#include "Eagle/Events.hpp"
#include "Inventory.hpp"
#include "Movement.hpp"
#include "Location.hpp"
#include "Camera.hpp"



class PlayerBase {
protected :

   
public :
   Inventory inventory;
   Movement movement;
   Location location;
   PlayerCamera pcam;

   virtual ~PlayerBase() {}
//   PlayerBase();
   PlayerBase() :
         inventory(),
         movement(),
         location(-1,-1,-1),
         pcam()
   {
      pcam.SetPlayer(this);
   }
   
   
   virtual void React(EagleEvent e)=0;
};


#include "Eagle/InputHandler.hpp"



class HumanPlayer : public PlayerBase {

protected :
   InputAssignment pkeys;
   InputGroup turnleft;
   InputGroup turnright;
   InputGroup lookup;
   InputGroup lookdown;
   
public :
   
   void TurnLeft();
   void TurnRight();
   void LookUp();
   void LookDown();
   
   
   void SetDefaultKeys(InputGroup turn_left , InputGroup turn_right , InputGroup look_up , InputGroup look_down);

   void Update(double dt);
   
   HumanPlayer();


   void SetupCamera();


   virtual void React(EagleEvent e) override;





};

#include "Location.hpp"


class Maze;
class Minotaur : public PlayerBase {
public :
   Location ctarget;
   Maze* pmaze;
   
   
//   Minotaur();
   Minotaur() :
         ctarget(-1,-1,-1),
         pmaze(0)
   {
      pcam.SetPlayer(this);
   }
   
   virtual void React(EagleEvent e) override;
};





#endif // PLAYERBASE_HPP






