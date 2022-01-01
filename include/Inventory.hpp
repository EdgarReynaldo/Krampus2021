



#ifndef INVENTORY_HPP
#define INVENTORY_HPP



#include <map>
#include <string>
#include "Items.hpp"



typedef std::map<std::string , Item> ITEMMAP;/// name , item map
typedef ITEMMAP::iterator ITEMIT;

class Inventory {
   ITEMMAP items;
public :
//   Inventory();
   Inventory() :
         items()
   {}

   int AddItem(Item item);
   int NumberOfItem(std::string itemname);
   Item TakeItem(std::string iname , size_t quantity);
   Item TakeItemAll(std::string itemname);

   ITEMMAP TakeAllItemsFromInventory();
   

};

Inventory CreateGameInventory();





#endif // INVENTORY_HPP
