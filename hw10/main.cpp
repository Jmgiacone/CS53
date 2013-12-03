#include "Business.h"
#include "Customer.h"
#include "Product.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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
  for (int i=0; i<NUM_OF_CUSTOMERS; i++)
  {
    getline(custlist,custName,',');
    list[i].setName(custName);
    getline(custlist,store,'\n');
    if (store == " -1")
    {
      MoeBar.addCustomer(list[i]);
      store = MOES_BAR;
    }
    else if (store == " 1")
    {
      CBGStore.addCustomer(list[i]);
      store = COMIC_BOOK_STORE;
    }
    else
      cout << "Something is very broken!" << endl;
    list[i].setInclination(store);
  }
  MoeBar.sell_stuff();
  CBGStore.sell_stuff();
  MoeBar.customers_leave(list, MoeBar.getNumCustomers());
  CBGStore.customers_leave(list, CBGStore.getNumCustomers());
  random_shuffle(&list[0], &list[NUM_OF_CUSTOMERS]);
  return 0;
}
