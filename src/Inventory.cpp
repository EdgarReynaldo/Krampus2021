


#include "Eagle/Exception.hpp"
#include "Inventory.hpp"




int Inventory::AddItem(Item item) {
   ITEMIT it = items.find(item.desc.name);
   if (it != items.end()) {
      it->second.quantity += item.quantity;
   }
   else {
      items.insert(std::pair<std::string , Item>(item.desc.name , item));
      return item.quantity;
   }
   return it->second.quantity;
}



int Inventory::NumberOfItem(std::string itemname) {
   ITEMIT it = items.find(itemname);
   if (it != items.end()) {
      return it->second.quantity;
   }
   return 0;
}



Item Inventory::TakeItem(std::string iname , size_t quantity) {
   ITEMIT it = items.find(iname);
   if (it != items.end()) {
      return items[iname].TakeFrom(quantity);
   }
   return Item();
}



Item Inventory::TakeItemAll(std::string itemname) {
   EAGLE_ASSERT(NumberOfItem(itemname));
   return TakeItem(itemname , NumberOfItem(itemname));
}



ITEMMAP Inventory::TakeAllItemsFromInventory() {
   ITEMMAP taken_items = items;
   items.clear();
   return taken_items;
}







