#include "Customer.h"

using namespace std;

ostream& operator << (ostream& out, const Customer c)
{
  out << c.m_name << " has $" << c.m_money << ", a happiness of " 
      << c.m_happiness << ", and purchases: [";
  
  for(int i = 0; i < c.m_numPurchases; i++)
  {
    out << c.m_purchases[i] << (i == c.m_numPurchases - 1 ? "" : ", ");
  } 
  
  out << "]";

  return out;
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
      m_happiness += 15;
      return true; 
    }
  }
  
  m_happiness -= 10;
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
