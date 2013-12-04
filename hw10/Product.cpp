//Names:        MURTISHAW, AARON
//              GIACONE, JORDAN
//              LONG, JACOB
//Class:        CS 53, Section C
//Date:         4 December 2013
//Description:  Defines an operator for the Product data type

#include "Product.h"

using namespace std;

ostream& operator << (ostream& out, const Product p)
{
  out << p.m_name << " ($" << p.m_price << ")";

  return out; 
} 
