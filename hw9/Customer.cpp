/*
 * Name: GIACONE, JORDAN
 * Date: 11-11-13
 * Class and Section: CS53, Section C
 * Description: A .cpp file containing function definitions for Customer  
 */

#include <iostream>
#include "Customer.h"

using namespace std;

bool Customer::purchase(const string item)
{
  if(m_numPurchases < MAX_PURCHASES)
  {
    m_purchases[m_numPurchases] = item;
    m_numPurchases++;

    return true;
  }

  return false;
}
  
void Customer::print() const
{
  cout << m_name << " has $" << m_money << " and purchases: [";
  
  for(int i = 0; i < m_numPurchases; i++)
  {
    cout << m_purchases[i] << (i == m_numPurchases - 1 ? "" : ", ");
  } 
  
  cout << "]";
}
