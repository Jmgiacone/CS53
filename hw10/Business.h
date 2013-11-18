#ifndef BUSINESS_H
#define BUSINESS_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
             string fileName = "") : m_name(name), m_money(money), m_numWares(0)
             , m_numCustomers(0)
    {
      if(fileName != "")
      {
        Product p;
        ifstream input;
        char temp[100];

        input.open(fileName.c_str());
      
        for(int i = 0; input; i++)
        {
          //Get up to the :
          input.getline(temp, 100, SEPARATOR);
          p.m_name = temp;

          //Get up to the \n
          input.getline(temp, 100);
          
          //String -> float function
          p.m_price = atof(temp);
          m_wares[i] = p;
          m_numWares++;

          //Start with "clean" variables for each iteration
          strcpy(temp, "");
          p.m_name = "";
          p.m_price = 0;
        }
       
        //Some sort of blank line at EOF. Getting rid of it (kind of) 
        m_numWares--;
        input.close();
      }
    };

    void print() const;
    bool addCustomer(Customer& c);
    void sell_stuff();
    void customers_leave(Customer customers[], const int numCustomers); 
    
};
#endif
