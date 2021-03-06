//Names:        MURTISHAW, AARON
//              GIACONE, JORDAN
//              LONG, JACOB
//Class:        CS 53, Section C
//Date:         4 December 2013
//Description:  Defines functions related to the Customer class

#include "Customer.h"

using namespace std;

Customer::Customer()
{
  m_money = (rand() % static_cast<int>(
                    (100 * (MAX_MONEY - MIN_MONEY + 1) + MIN_MONEY))) / 100.0; 
  m_numPurchases = 0;
  m_happiness = rand() % (MAX_HAPPINESS - MIN_HAPPINESS + 1) + MIN_HAPPINESS;
}

void Customer::addHappiness(short s)
{
  m_happiness += s;

  if(m_happiness > 100)
  {
    m_happiness = 100;
  }
  else if(m_happiness < 0)
  {
    m_happiness = 0;
  }
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
      addHappiness(PURCHASE_SUCCESS);
      cout << m_name << " bought " << p << " and their happiness is now " << m_happiness << endl;
      return true; 
    }
  }
  
  addHappiness(PURCHASE_FAIL);
  
  cout << m_name << " didn't buy " << p << " and their happiness is now " << m_happiness << endl;
  return false;
}
bool Customer::throwSomething(Customer& c)
{
  if(m_numPurchases > 0)
  {
    addHappiness(THROW_BULLY_SUCCESS);
    c.addHappiness(THROW_VICTIM_SUCCESS);
    
    cout << m_name  << " threw their " << m_purchases[m_numPurchases - 1] 
         << " at " << c.m_name << ". Their happiness is now " << m_happiness 
         << " and " << c.m_name << "'s happiness is now: " << c.m_happiness 
         << endl; 
    //Cut the last index off the array. Effectively 'removing' the last item
    m_numPurchases--;

    return true;
  }

  addHappiness(THROW_FAIL);
  cout << m_name << " didn't get a chance to throw anything at " << c.m_name 
       << " because they don't have anything to throw. Their happiness is now: " 
       << m_happiness << endl;
  
  return false;
}

bool Customer::rob(Customer& c)
{
  if(m_numPurchases < MAX_PURCHASES && c.m_numPurchases > 0)
  {
    m_purchases[m_numPurchases] = c.m_purchases[c.m_numPurchases - 1];
    c.m_numPurchases--;
    m_numPurchases++;
    addHappiness(ROB_THIEF_SUCCESS);
    c.addHappiness(ROB_VICTIM_SUCCESS);
    
    cout << m_name << " stole " << m_purchases[m_numPurchases - 1] 
         << " from " << c.m_name << ". Their happiness is now " << m_happiness 
         << " and " << c.m_name << "'s happiness is now: " << c.m_happiness 
         << endl;;

    return true;
  }
 
  addHappiness(ROB_FAIL);
  
  cout << m_name << " couldn't steal anything from " << c.m_name 
       << ". Their happiness is now: " << m_happiness << endl;
  return false;
}

bool Customer::hasSameInclination(const Customer& other)
{
  return m_inclination == other.m_inclination;
}
