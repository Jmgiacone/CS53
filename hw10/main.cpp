//Names:        MURTISHAW, AARON
//		GIACONE, JORDAN
//		LONG, JACOB
//Class:	CS 53, Section C
//Date:         4 December 2013
//Description:  Twenty customers read-in from a file, buy stuff, and then 
//		throw stuff at each other or steal stuff from each other
//		until all but one person has left or until twenty rounds
//              have passed.

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

//Purpose:  Removes a Customer from the Customer array list[]
//Pre:      Size <= the size of list[]
//Post:     Removes a Customer from the array
void removeIndex(Customer list[], const int index, const int size);

//Purpose:  Displays the entire Customer array list[]
//Pre:      listSize <= the size of the array
//Post:     Outputs information about all customers in list[]
void displayArray(ostream& stream, Customer list[], const int listSize);

int main()
{
  srand(time(NULL));
  
  int numCustomers = 0, numCycles = 0, numParticipants = 0, MoeHap = 0, CBGHap = 0;
  string custName, store;
  Customer list[NUM_PARTICIPANTS];
  Customer participants[NUM_PARTICIPANTS];
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
    cout << endl << "Round " << numCycles + 1 << ":" << endl << endl;
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
        cout << list[numCustomers - 1].getName() << " went into the comic store!" << endl;
        numCustomers--;
      }
      else 
      {
        cout << "We have another problem" << endl;
      }
    }
  
    cout << endl; 
    MoesBar.sell_stuff();
    CBGStore.sell_stuff();

    numCustomers = 0;

    numCustomers += MoesBar.customers_leave(list, numCustomers);
 
    numCustomers += CBGStore.customers_leave(list, numCustomers);  
 
    random_shuffle(&list[0], &list[numCustomers]);

    cout << endl; 
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
   
    cout << endl; 
    for(int i = numCustomers - 1; i >= 0; i--)
    {
      if(list[i].getHappiness() < 10 || list[i].getHappiness() > 90)
      {
        cout << list[i].getName() << (list[i].getHappiness() < 10 ? 
                                     " has fallen into despair " : 
                                     " has reached Nirvana ") 
             << "and went to Shelbyville" << ". There are now " 
             << numCustomers - 1 << " people left." << endl;
        participants[i] = list[i];
        removeIndex(list, i, numCustomers);
        numCustomers--;
        numParticipants++;
      }
    }

    cout << endl;
    displayArray(cout, list, numCustomers);
    numCycles++;
  }
  participants[numParticipants] = list[0];
  for (int i = 0; i < NUM_PARTICIPANTS; i++)
  {
    if (list[i].getInclination() == MOES_BAR)
      MoeHap += list[i].getHappiness();
    else if (list[i].getInclination() == COMIC_BOOK_STORE)
      CBGHap += list[i].getHappiness();
  }
  if (MoeHap > CBGHap)
    cout << "The " << MOES_BAR << "s win with a combined happiness of "
         << MoeHap << "," << endl << " beating the " << COMIC_BOOK_STORE
         << "s with a combined happiness of " << CBGHap << "." << endl;
  else if (MoeHap < CBGHap)
    cout << "The " << COMIC_BOOK_STORE << "s win with a combined happiness of "
         << CBGHap << "," << endl << " beating the " << MOES_BAR
         << "s with a combined happiness of " << MoeHap << "." << endl;
  else if (MoeHap == CBGHap)
    cout << "The " << MOES_BAR << "s and the " << COMIC_BOOK_STORE
         << "s both suck with each having a combined happiness of " << MoeHap
         << endl;
  return 0;
}


//FUNCTION DEFINITIONS
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
