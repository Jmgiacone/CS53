//Hello World!
#include <iostream>
#include "Business.h"

using namespace std;

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
