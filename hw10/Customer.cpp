#include <iostream>
#include "Customer.h"

using namespace std;

bool Customer::purchase(const Product item)
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
    //cout << m_purchases[i] << (i == m_numPurchases - 1 ? "" : ", ");
  } 
  
  cout << "]";
}
