#include "Business.h"
#include "Customer.h"
#include "Product.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_OF_CUSTOMERS = 20;

int main()
{
  srand(time(NULL));
  string custName;
  string store;
  Customer list[NUM_OF_CUSTOMERS];
  ifstream custlist;
  custlist.open("Customer.dat");
  Business MoeBar("Moe's", 0 ,"MoeBar.txt");
  Business CBGStore("CBG's", 0, "CBGStore.txt");
  while (custlist)
  {
    for (int i=0; i<NUM_OF_CUSTOMERS; i++)
    {
      getline(custlist,custName,',');
      list[i].setName(custName);
      custlist.ignore(1,' ');
      getline(custlist,store);
      if (store == "-1")
        store = MOES_BAR;
      else if (store == "1")
        store = COMIC_BOOK_STORE;
      else
	cout << "Something is very broken!" << endl;
      list[i].setInclination(store);
    }
  }
/*  for (int i=0; i<NUM_OF_CUSTOMERS; i++)
  {
    store = ((list[i].getInclination).c_str());
    if (store==MOES_BAR)
      MoeBar.addCustomer(list[i]);
    else if (store==COMIC_BOOK_STORE)
      CBGStore.addCustomer(list[i]);
    else
      cout << "Something is broken!" << endl;
  }
  MoeBar.sell_stuff();
  CBGStore.sell_stuff();*/
  return 0;
}
