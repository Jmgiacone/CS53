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

void removeIndex(Customer list[], const int index, const int size);
int main()
{
  srand(time(NULL));
  
  int numCustomers = 0, numCycles = 0;
  string custName, store;
  Customer list[NUM_OF_CUSTOMERS];
  ifstream custlist("CustomerList.txt");

  Business MoesBar("Moe's Bar", 0 ,"MoeBar.txt"), CBGStore("Comic Book Guy's Store", 0, "CBGStore.txt");

  for (int i = 0; i < NUM_OF_CUSTOMERS; i++)
  {
    getline(custlist,custName,',');
    list[i].setName(custName);
    getline(custlist,store,'\n');
    
    if (store == " -1")
    {
      list[i].setInclination(MOES_BAR);
    }
    else if (store == " 1")
    {
      list[i].setInclination(COMIC_BOOK_STORE);
    }
    else
    {
      cout << "Something is very broken!" << endl;
    }
    
    numCustomers++;
  }

  while(numCustomers > 1 && numCycles < 20)
  {
    for(int i = 0; i < numCustomers; i++)
    {
      if(list[i].getInclination() == MOES_BAR)
      {
        MoesBar.addCustomer(list[i]);
      }
      else if(list[i].getInclination() == COMIC_BOOK_STORE)
      {
        CBGStore.addCustomer(list[i]);
      }
    }
    
    numCustomers = 0;

    MoesBar.sell_stuff();
    CBGStore.sell_stuff();

    numCustomers += MoesBar.customers_leave(list, 0);
    numCustomers += CBGStore.customers_leave(list, NUM_OF_CUSTOMERS - numCustomers);  
 
    random_shuffle(&list[0], &list[NUM_OF_CUSTOMERS]);
 
    Customer other;
    for(int i = 0; i < numCustomers; i++)
    {
      other = list[rand() % numCustomers];

      if(list[i].hasSameInclination(other))
      {
        list[i].rob(other);
      }
      else
      {
        list[i].throwSomething(other);
      }
    }
    
    for(int i = numCustomers - 1; i > 0; i--)
    {
      if(list[i].getHappiness() < 10 || list[i].getHappiness() > 90)
      {
        removeIndex(list, i, numCustomers);
        numCustomers--;
        cout << list[i].getName() << " is gone. There are now " << numCustomers << " people left." << endl;
      }
    }

    numCycles++;
  }
  
  /*while ((desperateCustomers != 19) && (cycles != 20))
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
      for(int j = 0; j < desperateCustomers; j++)
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
  }*/
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

void removeIndex(Customer list[], const int index, const int size)
{
  for(int i = index; i < size - 1; i++)
  {
    list[i] = list[i + 1]; 
  }
}
