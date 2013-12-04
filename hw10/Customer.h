#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <cstdlib>
#include "Product.h"

using namespace std;
const int MAX_PURCHASES = 20, MAX_HAPPINESS = 100, MIN_HAPPINESS = 0;
const float MIN_MONEY = 4.0, MAX_MONEY = 250;
const string MOES_BAR = "Bar Attendee", 
             COMIC_BOOK_STORE = "Comic Book Enthusiast";

class Customer
{
  private:
    string m_name, m_inclination;
    Product m_purchases[MAX_PURCHASES];
    float m_money;
    short m_numPurchases, m_happiness;    

  public:
    Customer();
    void setName(const string s) {m_name = s;};
    void setInclination(const string s) {m_inclination = s;};
    string getName() const {return m_name;};
    float getMoney() const {return m_money;};
    string getInclination() {return m_inclination;};
    short getHappiness() const {return m_happiness;};
    void setHappiness(short s) {m_happiness =(s < 0 ? 0 : (s > 100 ? 100 : s));};
    void setMoney(const float m) {m_money = m;};
    void print() const;
    bool buy_something(const Product& p);
    bool throwSomething(Customer& c);
    bool rob(Customer& c);
    bool hasSameInclination(const Customer& other);
    friend ostream& operator << (ostream& out, const Customer& c);
};
#endif
