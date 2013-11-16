/*
 * Name: GIACONE, JORDAN
 * Date: 11-11-13
 * Class and Section: CS53, Section C
 * Description: A header file containing all classes and prototypes  
 */

#include <string>
#include <cstdlib>

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

const int MAX_PURCHASES = 20;
const float MIN_MONEY = 4.0, MAX_MONEY = 250;
class Customer
{
  private:
    string m_name, m_purchases[MAX_PURCHASES];
    float m_money;
    short m_numPurchases;
  
  public:
    
    /*
     * Description: A Constructor for Customer.
        - name defaults to ""
        - money defaults to a random value in [MIN_MONEY, MAX_MONEY]
     * Pre: None
     * Params:
        - name: The name of the Customer
        - money: The amount of money the Customer currently has
     * Post: The object is constructed
     * Return: None
     */
    Customer(const string name = "", const float money = 
             ((rand() % static_cast<int>((100 * (MAX_MONEY - MIN_MONEY + 1) + MIN_MONEY))) / 100.0)) : 
             m_name(name), m_money(money), m_numPurchases(0) {};
    /*
     * Description: Has the Customer 'purchase' the given item
     * Pre: None
     * Params: 
        - item: The Item to be purchased
     * Post: The item may be added to the string[]
     * Return: A boolean denoting whether or not the purchase was successful
     */
    bool purchase(const string item);
    
    /*
     * Description: Gets the name of the Customer
     * Pre: None
     * Params: None
     * Post: None
     * Return: The name of the Customer
     */
    string getName() const {return m_name;};
    
    /*
     * Description: Gets the amount of money the Customer has
     * Pre: None
     * Params: None
     * Post: None
     * Return: The amount of money the Customer has
     */
    float getMoney() const {return m_money;};
    
    /*
     * Description: Sets the Customer's money to the given value
     * Pre: None
     * Params:
        - m: The amount for the money to be set to
     * Post: None
     * Return: None
     */
    void setMoney(const float m) {m_money = m;};
    
    /*
     * Description: Prints out all pertinent information about the Customer
     * Pre: None
     * Params: None
     * Post: Text is output to the screen
     * Return: None
     */
    void print() const;
};

#endif
