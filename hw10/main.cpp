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
  bool here;
  int unluckyPerson;
  int desperateCustomers = 0;
  int cycles = 0;
  string custName;
  string store;
  Customer temporary; //Used for sorting
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
      cout << "Something is very broken!" << endl;
    list[i].setInclination(store);
  }
  while ((desperateCustomers != 19) && (cycles != 20))
  {
    MoeBar.sell_stuff();
    CBGStore.sell_stuff();
    for (int i=0; i < NUM_OF_CUSTOMERS; i++)
      cout << list[i] << endl;
    MoeBar.customers_leave(list, MoeBar.getNumCustomers());
    CBGStore.customers_leave(list, CBGStore.getNumCustomers());
  //  random_shuffle(&list[0], &list[NUM_OF_CUSTOMERS]);
    for (int i = 0; i < NUM_OF_CUSTOMERS; i++)
    {
      here = true;
      for(int j=0; j<desperateCustomers; j++)
      {
        if (list[i].getName()==listOfDesperation[j].getName())
          here = false;
      }
      if (!here);
      else
      {
        do
        {
          here = true;
          unluckyPerson = (rand() % NUM_OF_CUSTOMERS);
          for (int j=0; j<desperateCustomers; j++)
          {
            if (list[unluckyPerson].getName() == listOfDesperation[j].getName())
              here = false;
          }
        } while (!here);
        theifOrPitcher = list[i].hasSameInclination(list[unluckyPerson]);
        if (theifOrPitcher)
          list[i].rob(list[unluckyPerson]);
        else
          list[i].throwSomething(list[unluckyPerson]);
      }
    }
    for (int i = 0; i < NUM_OF_CUSTOMERS; i++)
    {
      here = true;
      for(int j=0; j<desperateCustomers; j++)
      {
        if (list[i].getName()==listOfDesperation[j].getName())
          here = false;
      }
      if (!here);
      else
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
          list[i].setInclination("Sadness");
         }
        else if (list[i].getHappiness() > 90)
        {
          cout << list[i].getName() << " reaches nirvana at level "
               << list[i].getHappiness()
               << " and goes to lead Shelbyville House of Desperation." << endl;
          listOfDesperation[desperateCustomers] = list[i];
          desperateCustomers++;
          list[i].setInclination("Sadness");
         }
        else if (list[i].getInclination() == MOES_BAR)
          MoeBar.addCustomer(list[i]);
        else if (list[i].getInclination() == COMIC_BOOK_STORE)
          CBGStore.addCustomer(list[i]);
      }
    }
    cycles++;
  }
  //Sorting
  
/*  for (int j=0; j < NUM_OF_CUSTOMERS; j++)
  {
    for (int i=0; i < (NUM_OF_CUSTOMERS-1); i++)
    {
      if (list[i].getHappiness() < list[i+1].getHappiness())
      {
        temporary = list[i];
        list[i] = list[i+1];
        list[i+1] = temporary;
      }
    }
  }
  for (int i=0; i<NUM_OF_CUSTOMERS; i++)
  {
    cout << list[i] << endl;
  }*/
  return 0;
}
