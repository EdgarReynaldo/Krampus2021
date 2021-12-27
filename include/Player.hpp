



#ifndef PLAYERBASE_HPP
#define PLAYERBASE_HPP

#include "Eagle/Events.hpp"
#include "Inventory.hpp"



class PlayerBase {
   Inventory inventory;
   
   virtual ~PlayerBase() {}
//   PlayerBase();
   PlayerBase() :
         inventory()
   {}
   
   
   virtual void React(EagleEvent e)=0;
};


#endif // PLAYERBASE_HPP
