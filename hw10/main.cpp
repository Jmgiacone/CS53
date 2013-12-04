#include "Business.h"
#include "Customer.h"
#include "Product.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int NUM_PARTICIPANTS = 20;

void removeIndex(Customer list[], const int index, const int size);
int main()
{
  srand(time(NULL));
  
  int numCustomers = 0, numCycles = 0;
  string custName, store;
  Customer list[NUM_PARTICIPANTS];
  ifstream custlist("CustomerList.txt");

  Business MoesBar("Moe's Bar", 0 ,"MoeBar.txt"), CBGStore("Comic Book Guy's Store", 0, "CBGStore.txt");

  cout << "Started reading from the file" << endl;
  for (int i = 0; i < NUM_PARTICIPANTS; i++)
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
    cout << "Customer #" << numCustomers << ": " << list[i] << "\n  Their inclination is: " << list[i].getInclination() << endl;
  }

  cout << "Started the while loop" << endl;
 
  while(numCustomers > 1 && numCycles < 20)
  {
    while(numCustomers - 1 >= 0)
    {
      if(list[numCustomers - 1].getInclination() == MOES_BAR)
      {
        MoesBar.addCustomer(list[numCustomers - 1]);
        cout << list[numCustomers - 1].getName() << " went into Moe's!" << endl;
        numCustomers--;
      }
      else if(list[numCustomers - 1].getInclination() == COMIC_BOOK_STORE)
      {
        CBGStore.addCustomer(list[numCustomers - 1]);
        cout << list[numCustomers - 1].getName() << " wants comics!" << endl;
        numCustomers--;
      }
      else 
      {
        cout << "We have another problem" << endl;
      }
    }
   
    cout << "Moe is selling stuff" << endl; 
    MoesBar.sell_stuff();
    cout << "Moe is done.\nCBG is selling stuff" << endl;
    CBGStore.sell_stuff();
    cout << "CBG is done." << endl;

    cout << "Shooing customers out of Moe's Bar" << endl;
    numCustomers += MoesBar.customers_leave(list, 0);
 
    cout << "Shooing done.\nShooing customers out of CBG's Store" << endl;
    numCustomers += CBGStore.customers_leave(list, numCustomers);  
    cout << "Shooing done" << endl;
 
    random_shuffle(&list[0], &list[NUM_PARTICIPANTS]);
 
    int other;
    for(int i = 0; i < numCustomers; i++)
    {
      other = rand() % numCustomers;

      if(list[i].hasSameInclination(list[other]))
      {
        list[i].rob(list[other]);
      }
      else
      {
        list[i].throwSomething(list[other]);
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
    for (int i=0; i < NUM_PARTICIPANTS; i++)
      cout << list[i] << endl;
    MoeBar.customers_leave(list, MoeBar.getNumCustomers());
    CBGStore.customers_leave(list, CBGStore.getNumCustomers());
  //  random_shuffle(&list[0], &list[NUM_PARTICIPANTS]);

    for (int i = 0; i < NUM_PARTICIPANTS; i++)
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
          unluckyPerson = (rand() % NUM_PARTICIPANTS);
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
    for (int i = 0; i < NUM_PARTICIPANTS; i++)
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
  
/*  for (int j=0; j < NUM_PARTICIPANTS; j++)
  {
    for (int i=0; i < (NUM_PARTICIPANTS-1); i++)
    {
      if (list[i].getHappiness() < list[i+1].getHappiness())
      {
        temporary = list[i];
        list[i] = list[i+1];
        list[i+1] = temporary;
      }
    }
  }
  for (int i=0; i<NUM_PARTICIPANTS; i++)
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
