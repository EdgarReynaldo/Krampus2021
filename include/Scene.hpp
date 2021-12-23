



#ifndef SCENE_HPP
#define SCENE_HPP


enum SCENE_STATUS {
   SCENE_NOTREADY = -1,
   SCENE_READY = 0,
   SCENE_RUNNING = 1,
   SCENE_COMPLETE = 2
};



class Scene {
   SCENE_STATUS status;
public :
   Scene();
   Scene() :
         status(SCENE_NOTREADY)
   {}
   
   
   
   virtual SCENE_STATUS HandleEvent(EagleEvent e)=0;
   virtual SCENE_STATUS Update(double dt)=0;
   virtual void Display()=0;
};

#endif // SCENE_HPP
