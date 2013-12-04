//Names:        MURTISHAW, AARON
//              GIACONE, JORDAN
//              LONG, JACOB
//Class:        CS 53, Section C
//Date:         4 December 2013
//Description:  Defines the Customer class and related constants

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <cstdlib>
#include "Product.h"

using namespace std;
const int MAX_PURCHASES = 20, MAX_HAPPINESS = 100, MIN_HAPPINESS = 0,
          PURCHASE_SUCCESS = 15, PURCHASE_FAIL = -10, ROB_THIEF_SUCCESS = 25, 
          ROB_VICTIM_SUCCESS = -20, ROB_FAIL = -5, THROW_BULLY_SUCCESS = 5, 
          THROW_VICTIM_SUCCESS = -20, THROW_FAIL = -25;
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
    
    //Purpose: A default constructor
    //Pre: None
    //Post: The object is constructed
    Customer();

    //Purpose:  Sets the Customer's name
    //Pre:      None
    //Post:     Sets m_name to s
    void setName(const string s) {m_name = s;};

    //Purpose:  Sets the Customer's inclination
    //Pre:      None
    //Post:     Sets m_inclination to s
    void setInclination(const string s) {m_inclination = s;};

    //Purpose:  Gets the Customer's name
    //Pre:      None
    //Post:     Returns m_name(string)
    string getName() const {return m_name;};
    
    //Purpose:  Gets the amount of money the Customer has
    //Pre:      None
    //Post:     Returns m_money(float)
    float getMoney() const {return m_money;};
    
    //Purpose:  Gets the Customer's inclination
    //Pre:      None
    //Post:     Returns m_inclination(string)
    string getInclination() {return m_inclination;};
    
    //Purpose:  Gets the Customer's happiness
    //Pre:      None
    //Post:     Returns m_happiness(short)
    short getHappiness() const {return m_happiness;};
    
    //Purpose:  Adds to the Customer's happiness
    //Pre:      None
    //Post:     The variable m_happiness is changed
    void addHappiness(short s);

    //Purpose:  Sets the Customer's money
    //Pre:      None
    //Post:	Sets m_money to m
    void setMoney(const float m) {m_money = m;};
    
    //Purpose:  Prints out information about the Customer
    //Pre:      None
    //Post:     Outputs information about the Customer to the screen
    void print() const;
    
    //Purpose:  Decides if Customer buys a product. 
    //		If it does, the price is deducted from its money
    //Pre:	None
    //Post:	Returns true if the customer bought something
    bool buy_something(const Product& p);
    
    //Purpose:  Customer tries to throw an item at another customer
    //Pre:      None
    //Post:     If the customer has an item, it will throw it at the other one
    //		  The thrower will gain happiness, victim will lose happiness
    //          If the customer doesn't have an item, it will become sad
    bool throwSomething(Customer& c);
    
    //Purpose:  Customer tries to steal an item from another customer
    //Pre:  	None
    //Post:	If the other customer has an item, the theif will take one
    //            The theif will gain happiness, victim will lose happiness
    //		  The theif will also gain the item, victim will lose it
    //		If the other customer doesn't have an item, the theif will
    //		  become sad
    bool rob(Customer& c);
    
    //Purpose:  Checks to see if Customer has the same inclination as another
    //Pre:      None
    //Post:	Returns true if customers have the same inclination
    //		Returns false if customers have differing inclinations
    bool hasSameInclination(const Customer& other);
    
    //Purpose:  Be able to use the << operator on the Customer class
    //Pre:	None
    //Post:	Prints information about the Customer to the screen
    //		  Name, Money, Happiness, and Purchases
    friend ostream& operator << (ostream& out, const Customer& c);
};
#endif
