#include <iostream>
#include "Customer.h"

using namespace std;

void Customer::print() const
{
  cout << m_name << " has $" << m_money << " and purchases: [";
  
  for(int i = 0; i < m_numPurchases; i++)
  {
    //cout << m_purchases[i] << (i == m_numPurchases - 1 ? "" : ", ");
  } 
  
  cout << "]";
}

bool Customer:: buy_something(const Product p)
{
  //Returns 1 or 0 which maps to true and false respectively
  if(rand() % 2)//It's a 1
  {
    if(m_money >= p.m_price && m_numPurchases < MAX_PURCHASES)
    {
      m_money -= p.m_price;
      m_purchases[m_numPurchases] = p;
      m_numPurchases++;
  
      return true; 
    }
  }

  return false;
}
bool Customer::throwSomething(Customer c)
{
  return true;
}
bool Customer::rob(Customer c)
{
  return true;
}
