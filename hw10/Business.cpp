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
    m_customers[i].print();
    cout << endl;
  }

  cout << endl;
  cout << "Wares: [";

  for(int i = 0; i < m_numWares; i++)
  {
    //cout << m_wares[i] << (i == m_numWares - 1 ? "" : ", ");
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

}

void customers_leave(Customer customers[], const int numCustomers)
{
  
}
