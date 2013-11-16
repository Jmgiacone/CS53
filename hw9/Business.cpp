/*
 * Name: GIACONE, JORDAN
 * Date: 11-11-13
 * Class and Section: CS53, Section C
 * Description: A .cpp file containing function definitions for Business 
 */

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

void Business::make_a_sale()
{
  if(m_numCustomers != 0 && m_numWares != 0)
  {
    for(int i = 0; i < m_numCustomers; i++)
    {
      if(m_customers[i].purchase(m_wares[rand() % m_numWares]) && 
         m_customers[i].getMoney() >= ITEM_PRICE)
      {
        m_customers[i].setMoney(m_customers[i].getMoney() - ITEM_PRICE);
        m_money += ITEM_PRICE;
      }
    }
  }
}
