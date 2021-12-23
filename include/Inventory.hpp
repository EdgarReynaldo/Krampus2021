



#ifndef INVENTORY_HPP
#define INVENTORY_HPP




typedef std::map<std::string , Item> ITEMMAP;/// name , item map
typedef ITEMMAP::iterator ITEMIT;

class Inventory {
   ITEMMAP items;
   
   Inventory();
   Inventory() :
         items()
   {}
   
   int AddItem(Item item);
   int NumberOfItem(std::string itemname);
   Item TakeItem(std::string iname , quantity);
   Item TakeItemAll(std::string itemname);

   ITEMMAP TakeAllItemsFromInventory();


}

Inventory CreateGameInventory {
   Inventory inv;
   inv.AddItem(Item("Gold Coin" , "A shiny gold coin" , "A gold coin with bull horns engraved on it" , 10));
   inv.AddItem(Item("Silver Coin" , "A bright silver coin" , "A silver coin with santa engraved on it" , 25));
   inv.AddItem(Item("Copper Coin" , "A dull copper coin" , "A plain copper coin that is blank" , 100));
};





#endif // INVENTORY_HPP
