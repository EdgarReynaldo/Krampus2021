



#ifndef ITEMS_HPP
#define ITEMS_HPP


#include <string>



class ItemDescription {
public :
   std::string name;
   std::string shortdesc;
   std::string longdesc;
   ItemDescription();
      
   ItemDescription(std::string itemname , std::string shortitemdesc , std::string longitemdesc);
};


class Item {
public :
   ItemDescription desc;
   int quantity;

   Item();
   Item(ItemDescription itemdesc , int num = 1);
   Item(std::string name , std::string shortdesc , std::string longdesc , size_t num = 0);
   Item TakeFrom(int num = 1);
   Item& AddTo(size_t num = 1);
   void SetQuantity(size_t numleft);

}

//class ItemSorter {
//   int operator()(const Item& i1 , const Item& i2) {
//      return (i1.desc.name.compare(i2.desc.name));
//   }
//}



#endif // ITEMS_HPP
