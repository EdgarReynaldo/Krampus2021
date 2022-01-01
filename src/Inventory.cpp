


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



Inventory CreateGameInventory() {
   Inventory inv;
   inv.AddItem(Item("Gold Coin" , "A shiny gold coin" , "A gold coin with bull horns engraved on it" , 10));
   inv.AddItem(Item("Silver Coin" , "A bright silver coin" , "A silver coin with santa engraved on it" , 25));
   inv.AddItem(Item("Copper Coin" , "A dull copper coin" , "A plain copper coin that is blank" , 100));
   inv.AddItem(Item("Cloth slippers" , "A pair of cloth slippers" , "Slippers, quite quiet on stone halls" , 1));
   inv.AddItem(Item("Trumpet" , "A shiny brass trumpet" , "A trumpet that makes very loud noises, sure to get attention" , 1));
   inv.AddItem(Item("Flute" , "A little wooden flute" , "A soothing flute sure to calm the angriest of beasts" , 1));
   inv.AddItem(Item("Patchouli" , "A vial of patchouli oil" , "Patchouli oil, good for masking scent" , 5));
   return inv;
};






