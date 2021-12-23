



#include "Inventory.hpp"




void Inventory::AddItem(Item item) {
   ITEMIT it = items.find(item.name);
   if (it != items.end()) {
      it->quantity += item.quantity;
   }
   else {
      items.insert(item);
   }
}



int Inventory::NumberOfItem(std::string itemname) {
   ITEMIT it = items.find(itemname);
   if (it != items.end()) {
      return it->second.quantity;
   }
   return 0;
}



Item Inventory::TakeItem(std::string iname , quantity) {
   ITEMIT it = items.find(iname);
   if (it != items.end()) {
      return items[iname].TakeFrom(quantity);
   }
   return Item();
}



Item Inventory::TakeItemAll(std::string itemname) {
   EAGLE_ASSERT(NumberOfItem(itemname);
   return TakeItem(itemname , NumberOfItem(itemname));
}



ITEMMAP Inventory::TakeAllItemsFromInventory() {
   ITEMMAP taken_items = items;
   items.clear();
   return taken_items;
}







