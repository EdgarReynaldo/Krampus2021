



#ifndef INVENTORY_HPP
#define INVENTORY_HPP




typedef std::map<std::string , Item> ITEMMAP;
typedef ITEMMAP::iterator ITEMIT;

class Inventory {
   std::map<std::string , Item> items;
   
   Inventory();
   Inventory() :
         items()
   {}
   
   AddItem(Item item);
   AddItem(Item item) {
      ITEMIT it = items.find(item.name);
      if (it != items.end()) {
         it->quantity += item.quantity;
      }
      else {
         items.insert(item);
      }
   }
   Item TakeItem(std::string iname , quantity);
   Item TakeItem(std::string iname , quantity) {
      ITEMIT it = items.find(iname);
      if (it != items.end()) {
         Item item = items[iname];
         if (item.quantity >= quantity) {
            item.quantity -= quantity;
            if (item.quantity = 0) {items.erase(item.desc.name);}
            
            return Item(item.desc , item.quantity - quantity);
         }
      }
   }
}

Inventory CreateGameInventory {
   Inventory inv;
   inv.AddItem(Item("Gold Coin" , "A shiny gold coin" , "A gold coin with bull horns engraved on it" , 10));
   inv.AddItem(Item("Silver Coin" , "A bright silver coin" , "A silver coin with santa engraved on it" , 25));
   inv.AddItem(Item("Copper Coin" , "A dull copper coin" , "A plain copper coin that is blank" , 100));
};





#endif // INVENTORY_HPP
