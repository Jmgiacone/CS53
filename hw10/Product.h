//Names:        MURTISHAW, AARON
//              GIACONE, JORDAN
//              LONG, JACOB
//Class:        CS 53, Section C
//Date:         4 December 2013
//Description:  Defines the Product data type

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

using namespace std;
struct Product
{
  string m_name;
  float m_price;
  
  /*
   * Description: An overloaded '<<' operator for the Product struct
   * Pre: The output stream must be opened somewhere
   * Params:
      - out: The output stream to be used
      - p: The product to be output
   * Post: The output stream will be changed
   * Return: The given output stream
   */
  friend ostream& operator << (ostream& out, const Product p);
};
#endif
