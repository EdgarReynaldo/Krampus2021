



#ifndef ITEMS_HPP
#define ITEMS_HPP


#include <string>



struct ItemDescription {
   std::string name;
   std::string shortdesc;
   std::string longdesc;
};


class Item {
public :
   ItemDescription desc;
   int quantity;
   Item(std::string name , std::string shortdesc , std::string longdesc , size_t num);
   Item(std::string name , std::string shortdesc , std::string longdesc , size_t num) :
         desc(name , shortdesc , longdesc),\
         quantity(num)
   {}
   Item& SetQuantity(size_t numleft);
   Item& SetQuantity(size_t numleft) {
      quantity = numleft;
      return *this;
   }
}

//class ItemSorter {
//   int operator()(const Item& i1 , const Item& i2) {
//      return (i1.desc.name.compare(i2.desc.name));
//   }
//}



#endif // ITEMS_HPP
