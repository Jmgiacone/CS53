#include "Customer.h"

using namespace std;

Customer::Customer()
{
  m_money = (rand() % static_cast<int>((100 * (MAX_MONEY - MIN_MONEY + 1) + MIN_MONEY))) / 100.0; 
  m_numPurchases = 0;
  m_happiness = rand() % (MAX_HAPPINESS - MIN_HAPPINESS + 1) + MIN_HAPPINESS;
}

ostream& operator << (ostream& out, const Customer& c)
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

bool Customer::buy_something(const Product& p)
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
bool Customer::throwSomething(Customer& c)
{
  if(m_numPurchases > 0)
  {
    m_happiness += 5;
    c.m_happiness -= 20;
 
    //Cut the last index off the array. Effectively 'removing' the last item
    m_numPurchases--;

    return true;
  }

  m_happiness -= 25;
  return false;
}

bool Customer::rob(Customer& c)
{
  if(m_numPurchases < MAX_PURCHASES && c.m_numPurchases > 0)
  {
    m_purchases[m_numPurchases] = c.m_purchases[c.m_numPurchases];
    c.m_numPurchases--;
    m_happiness += 25;
    c.m_happiness -= 20;
    return true;
  }
 
  m_happiness -= 5;
  return false;
}
