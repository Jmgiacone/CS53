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
