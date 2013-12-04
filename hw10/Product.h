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
  friend ostream& operator << (ostream& out, const Product p);
};
#endif
