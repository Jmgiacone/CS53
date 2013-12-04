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
void displayArray(ostream& stream, Customer list[], const int listSize);

int main()
{
  srand(time(NULL));
  
  int numCustomers = 0, numCycles = 0;
  string custName, store;
  Customer list[NUM_PARTICIPANTS];
  ifstream custlist("CustomerList.txt");

  Business MoesBar("Moe's Bar", 0 ,"MoeBar.txt"), CBGStore("Comic Book Guy's Store", 0, "CBGStore.txt");

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
  }
  for (int i = 0; i < NUM_PARTICIPANTS; i++)
    cout << list[i] << endl;
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
   
    MoesBar.sell_stuff();
    CBGStore.sell_stuff();

    numCustomers += MoesBar.customers_leave(list, 0);
 
    numCustomers += CBGStore.customers_leave(list, numCustomers);  
 
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
    
    for(int i = numCustomers - 1; i >= 0; i--)
    {
      if(list[i].getHappiness() < 10 || list[i].getHappiness() > 90)
      {
        cout << list[i].getName() << " is at happiness level " << list[i].getHappiness() << ". There are now " << numCustomers - 1 << " people left." << endl;
        removeIndex(list, i, numCustomers);
        numCustomers--;
      }
    }

    displayArray(cout, list, numCustomers);
    numCycles++;
  }
  
  return 0;
}

void removeIndex(Customer list[], const int index, const int size)
{
  for(int i = index; i < size - 1; i++)
  {
    list[i] = list[i + 1]; 
  }
}

void displayArray(ostream& stream, Customer list[], const int listSize)
{
  for(int i = 0; i < listSize; i++)
  {
    stream << list[i] << endl;
  }
}
