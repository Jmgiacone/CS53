//Names:        MURTISHAW, AARON
//              GIACONE, JORDAN
//              LONG, JACOB
//Class:        CS 53, Section C
//Date:         4 December 2013
//Description:  Defines functions related to the Business class

#include <iostream>
#include "Business.h"

using namespace std;

Business::Business(const string name, const float money, 
                   string fileName) 
{
  m_name = name;
  m_money = money;
  m_numWares = 0;
  m_numCustomers = 0;
    
  if(fileName != "")
  {
    Product p;
    ifstream input;
    char temp[100];
    input.open(fileName.c_str());
      
    for(int i = 0; input; i++)
    {
      //Get up to the :
      input.getline(temp, 100, SEPARATOR);
      p.m_name = temp;
        
      //Get up to the \n
      input.getline(temp, 100);
          
      //String -> float function
      p.m_price = atof(temp);
      m_wares[i] = p;
      m_numWares++;

      //Start with "clean" variables for each iteration
      strcpy(temp, "");
      p.m_name = "";
      p.m_price = 0;
    }
       
    //Some sort of blank line at EOF. Getting rid of it (kind of) 
    m_numWares--;
    input.close();
  }      
}

void Business::print() const
{
  cout << "Business Name: " << m_name <<  endl;
  cout << "Cash in register: $" << m_money << endl;
  cout << "Customers: ";

  for(int i = 0; i < m_numCustomers; i++)
  {
    cout << "\n  -";
    cout << m_customers[i] << endl;
  }

  cout << endl;
  cout << "Wares: [";

  for(int i = 0; i < m_numWares; i++)
  {
    cout << m_wares[i] << (i == m_numWares - 1 ? "" : ", ");
  }
  
  cout << "]";
}

bool Business::addCustomer(Customer& c)
{
  if(m_numCustomers < MAX_CUSTOMERS)
  {
    m_customers[m_numCustomers] = c;
    m_numCustomers++;
    return true;
  }
  
  return false;
}

void Business::sell_stuff()
{
  Product p;
  for(int i = 0; i < m_numCustomers; i++)
  {
    p = m_wares[rand() % m_numWares];

    if(m_customers[i].buy_something(p))
    {
      m_money += p.m_price;
    }
  }
}

short Business::customers_leave(Customer customers[], const int numCustomers)
{
  short count = 0;
  int streetIndex = numCustomers;
  for(int customerIndex = 0; m_numCustomers > 0; customerIndex++)
  {
    cout << "Swapping index " << customerIndex << " of " << m_name << " into index " << streetIndex << " of the street Array" << endl;
    customers[streetIndex] = m_customers[customerIndex];
    m_numCustomers--;
    count++;
    streetIndex++;
  } 

  return count;
}
