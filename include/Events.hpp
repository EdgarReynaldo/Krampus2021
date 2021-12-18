



#ifndef GAME_EVENTS_HPP
#define GAME_EVENTS_HPP


enum ACTION_EVENT_TYPE {
   ACTION_EVENT_NONE = -1,
   ACTION_EVENT_MOVE = 0,
   ACTION_EVENT_PICKUP = 1,
   ACTION_EVENT_DROP = 2,
   ACTION_EVENT_EQUIP = 3,
   ACTION_EVENT_USE = 4,
   ACTION_EVENT_EXAMINE = 5
};




#include "Eagle/Events.hpp"



class DataEvent {
   EagleEvent e;
   DataEvent(ACTION_EVENT_TYPE atype);
   DataEvent(ACTION_EVENT_TYPE atype) :
         e()
   {
      e.type = EAGLE_EVENT_USER_START;
      e.user.type = (int)atype;
      e.user.data = (void*)this;
   }
public :
      
   ACTION_EVENT_TYPE ActionType() {return (ACTION_EVENT_TYPE)e.user.type;}
   
   template <typename CastType>
   void GetData(CastType** store) {
      EAGLE_ASSERT(store);
      EAGLE_ASSERT(e.user.data);
      *store = dynamic_cast<CastType*>(e.user.data);
      EAGLE_ASSERT(*store);
   }
};

class MazeEvent : public DataEvent {
public :
   Maze* m;
   Location loc;
};



#endif // GAME_EVENTS_HPP
