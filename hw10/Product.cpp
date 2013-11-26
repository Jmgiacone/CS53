#include "Product.h"

using namespace std;

ostream& operator << (ostream& out, const Product p)
{
  out << p.m_name << " ($" << p.m_price << ")";

  return out; 
} 
