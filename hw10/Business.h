//Names:        MURTISHAW, AARON
//              GIACONE, JORDAN
//              LONG, JACOB
//Class:        CS 53, Section C
//Date:         4 December 2013
//Description:  Defines the Business class and related constants

#ifndef BUSINESS_H
#define BUSINESS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "Product.h"
#include "Customer.h"

using namespace std;

const int MAX_WARES = 10, MAX_CUSTOMERS = 10, ITEM_PRICE = 40;
const char SEPARATOR = ':';

class Business
{
  private:
    string m_name;
    float m_money;
    Customer m_customers[MAX_CUSTOMERS];
    Product m_wares[MAX_WARES];
    short m_numWares, m_numCustomers;
  
  public:
    Business(const string name = "", const float money = 0, 
             const string fileName = "");

    //Purpose:  Prints out information about the business
    //Pre:      None
    //Post:  	Outputs information about the business to the screen
    void print() const;
    
    //Purpose:  Adds a customer to the business
    //Pre:      None
    //Post:     Returns true if the number of customers < MAX_CUSTOMERS
    bool addCustomer(Customer& c);
    
    //Purpose:  Business tries to sell stuff to each customer
    //Pre: 	None
    //Post:	Customer will possibly buy a random item
    void sell_stuff();
    
    //Purpose:  Gets rid of customers in a business
    //Pre:	numCustomers <= size of customers[]
    //Post:	Puts customers into customers[]
    //		Returns number of customers that left
    short customers_leave(Customer customers[], const int numCustomers); 
    
    //Purpose:  Gets the number of customers the Business has
    //Pre:      None
    //Post:     Returns m_numCustomers(short)
    short getNumCustomers() {return m_numCustomers;};
};
#endif
