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
    void print() const;
    bool addCustomer(Customer& c);
    void sell_stuff();
    void customers_leave(Customer customers[], const int numCustomers); 
    
};
#endif
