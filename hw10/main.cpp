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
  bool theifOrPitcher;
  int unluckyPerson;
  int customersRemaining;
  int desperateCustomers = 0;
  int cycles = 0;
  string custName;
  string store;
  Customer list[NUM_OF_CUSTOMERS];
  Customer listOfDesperation[NUM_OF_CUSTOMERS];
  ifstream custlist;
  custlist.open("CustomerList.txt");
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
      cout << "Something is very broken!" << list[i].getName()
           << list[i].getInclination() << endl;
    list[i].setInclination(store);
  }
  customersRemaining = MoeBar.getNumCustomers() + CBGStore.getNumCustomers();
  while ((customersRemaining != 1) && (cycles != 20))
  {
    MoeBar.sell_stuff();
    CBGStore.sell_stuff();
    MoeBar.customers_leave(list, MoeBar.getNumCustomers());
    CBGStore.customers_leave(list, CBGStore.getNumCustomers());
    random_shuffle(&list[0], &list[customersRemaining]);
    for (int i = 0; i < customersRemaining; i++)
    {
      unluckyPerson = (rand() % customersRemaining);
      theifOrPitcher = list[i].hasSameInclination(list[unluckyPerson]);
      if (theifOrPitcher)
        list[i].rob(list[unluckyPerson]);
      else
        list[i].throwSomething(list[unluckyPerson]);
    }
    for (int i = 0; i < customersRemaining; i++)
    {
      if (desperateCustomers == 19)
        cycles = 19;
      else if (list[i].getHappiness() < 10)
      {
        cout << list[i].getName() << " falls desperately hopeless at level "
             << list[i].getHappiness()
             << " and is shipped to Shelbyville House of Desperation." << endl;
        listOfDesperation[desperateCustomers] = list[i];
        desperateCustomers++;
      }
      else if (list[i].getHappiness() > 90)
      {
        cout << list[i].getName() << " reaches nirvana at level "
             << list[i].getHappiness()
             << " and goes to lead Shelbyville House of Desperation." << endl;
        listOfDesperation[desperateCustomers] = list[i];
        desperateCustomers++;
      }
      else if (list[i].getInclination() == MOES_BAR)
        MoeBar.addCustomer(list[i]);
      else if (list[i].getInclination() == COMIC_BOOK_STORE)
        CBGStore.addCustomer(list[i]);
      else
	cout << "Something is broken!" << endl;
    }
    cycles++;
  }
  return 0;
}
