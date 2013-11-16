/*
 * Name: GIACONE, JORDAN
 * Date: 11-11-13
 * Class and Section: CS53, Section C
 * Description: A header file that contains class definitions and prototypes 
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Customer.h"

using namespace std;

#ifndef BUSINESS_H
#define BUSINESS_H

const int MAX_WARES = 10, MAX_CUSTOMERS = 10, ITEM_PRICE = 40;

class Business
{
  private:
    string m_name, m_wares[MAX_WARES];
    float m_money;
    Customer m_customers[MAX_CUSTOMERS];
    short m_numWares, m_numCustomers;
  
  public:
    
    /*
     * Description: Constructor for Business. 
         - Name defaults to ""
         - Money defaults to 0
         - fileName defaults to ""
         - The number of items in the shop defaults to 0
         - The number of customers defaults to 0
     * Pre: None
     * Params: 
         - name: The name of the Business
         - money: The amount of money that they Business has
         - fileName: The file from which to read the stock  
     * Post: The object is constructed
     * Return: None
     */
    Business(const string name = "", const float money = 0, string fileName = "") : 
             m_name(name), m_money(money), m_numWares(0), m_numCustomers(0)
    {
      if(fileName != "")
      {
        ifstream input;
        char temp[100];

        input.open(fileName.c_str());
      
        for(int i = 0; input; i++)
        {
          input.getline(temp, 100);
          m_wares[i] = temp;
          m_numWares++;
        }
        
        m_numWares--;
        input.close();
      }
    };

    /*
     * Description: Prits out pertinent information for the Business
     * Pre: None
     * Params: None
     * Post: Text is output to the screen
     * Return: None
     */
    void print() const;
    
    /*
     * Description: Adds a Customer to the Business
     * Pre: None
     * Params: 
         - c: The Customer to be added to the Business
     * Post: A Customer is added to the Customer[]
     * Return: A boolean denoting whether or not the Customer has been added
     */
    bool addCustomer(Customer& c);
    
    /*
     * Description: Iterates through the lsit of Customers and has them 
                    purchase a random item
     * Pre: None
     * Params: None
     * Post: Each Customer will have made a transaction
     * Return: None
     */
    void make_a_sale();
};
#endif
