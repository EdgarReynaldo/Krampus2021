



#include "Items.hpp"
#include "Eagle/Exception.hpp"



/// ---------------------------    ItemDescription    --------------------------------------



ItemDescription::ItemDescription() :
      name("Invalid item"),
      shortdesc("This is an invalid item"),
      longdesc("As stated before this shouldn't be possible, but this is an invalid item")
{
   throw EagleException("Invalid item created");
}



ItemDescription::ItemDescription(std::string itemname , std::string shortitemdesc , std::string longitemdesc) :
      name(itemname),
      shortdesc(shortitemdesc),
      longdesc(longitemdesc)
{}



/// ---------------------------    Item    --------------------------------------



Item::Item() :
      desc(),
      quantity(-1)
{}



Item::Item(ItemDescription itemdesc , int num) :
      desc(itemdesc),
      quantity(num)
{}



Item::Item(std::string name , std::string shortdesc , std::string longdesc , size_t num) :
      desc(name , shortdesc , longdesc),\
      quantity(num)
{}



Item Item::TakeFrom(int num) {
   if (num < 0 || num > quantity) {/// Takke all if num is negative
      num = quantity;
      quantity = 0;
      return Item(desc , num);
   }
   int left = quantity - num;
   
   if (left >= 0) {
      quantity = left;
      return Item(desc , num);
   }
   return Item(desc , 0);/// Not possible
}



Item& Item::AddTo(size_t num) {
   quantity += num;
   return *this;
}



void Item::SetQuantity(size_t numleft) {
   quantity = numleft;
}



