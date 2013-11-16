/*
 * Name: GIACONE, JORDAN
 * Date: 11-11-13
 * Class and Section: CS53, Section C
 * Description: The main driver that is testing Customer and Business 
 */

#include <iostream>
#include <ctime>
#include "Customer.h"
#include "Business.h"

int main()
{
  srand(time(NULL));
  
  Business shop("Jordan's Awesome Business", 800, "wares.txt");
  Customer jordan("Jordan", 10), cole("Cole"), aaron("A-a-ron");

  shop.print();
  cout << endl;
  cout << "print() for Customer" << endl;
  jordan.print();
  cout << endl;
  cole.print();
  cout << endl;
  aaron.print();
  cout << endl;

  cout << "getName()" << endl;
  cout << jordan.getName() << endl;
  cout << cole.getName() << endl;
  cout << aaron.getName() << endl;
  
  cout << "getMoney()" << endl;
  cout << jordan.getMoney() << endl;
  cout << cole.getMoney() << endl;
  cout << aaron.getMoney() << endl;

  cout << "setMoney() 100 and 95" << endl;
  jordan.setMoney(1000);
  cole.setMoney(95);
  aaron.setMoney(41.3);

  cout << "getMoney()" << endl;
  cout << jordan.getMoney() << endl;
  cout << cole.getMoney() << endl;
  cout << aaron.getMoney() << endl;
  
  shop.addCustomer(jordan);
  shop.addCustomer(cole);
  shop.addCustomer(aaron);

  cout << "make_a_sale()" << endl;
  for(int i = 0; i < 5; i++)
  {
    shop.make_a_sale();
  }

  cout << "print()" << endl;
  jordan.print();
  cout << endl;
  cole.print();
  cout << endl;
  aaron.print();
  cout << endl;
  shop.print();
  cout << endl;

  return 0;
}
