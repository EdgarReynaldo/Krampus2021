



#ifndef SCENE_HPP
#define SCENE_HPP



#include "Eagle/Events.hpp"



enum SCENE_STATUS {
   SCENE_NOTREADY = 0,
   SCENE_READY = 1,
   SCENE_RUNNING = 2,
   SCENE_COMPLETE = 3
};



class Scene {
public :
//   Scene();
   SCENE_STATUS status;
   Scene() :
         status(SCENE_NOTREADY)
   {}
   virtual ~Scene() {}
   
   virtual SCENE_STATUS Init()=0;/// returns SCENE_READY or SCENE_NOTREADY
   
   virtual SCENE_STATUS HandleEvent(EagleEvent e)=0;
   virtual SCENE_STATUS Update(double dt)=0;
   virtual void Display()=0;
   
   SCENE_STATUS GetStatus() {return status;}
};

#endif // SCENE_HPP
