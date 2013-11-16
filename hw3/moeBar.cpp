//Name: GIACONE, JORDAN
//Date: 9-11-13
//Class and Section: CS53 Section C
//Description: A greeter program for Moe's Bar. It will dismiss patrons based
//on a number of factors, including age and drink choice

#include <iostream>

using namespace std;

const float BEER_PRICE = 2, LIQUOR_PRICE = 4.25;
const int  LEGAL_DRINKING_AGE = 21, OLDEST_KNOWN_AGE = 122;
//122 is the age of the oldest known person I could find on Wikipedia

int main()
{
  string name, tempString, drinkChoice; 
  int numDrinks;
  float money, tempVar;
   
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
   
  do
  {
    cout << "\nHello stranger, what be your name? ";
    cin >> name;

    if(name == "Barney" || name == "barney")
    {    
      cout << "C'mon in, Barney!" << endl;
    }
    else
    {
      do
      {
        cout << "So, " << name << ", are you a teetotaler? ";
        cin >> tempString;

        if(!(tempString == "yes" || tempString == "no"))
        {
          cout << "Please enter \"yes\" or \"no\"" << endl;
        }     
      }
      while(!(tempString == "yes" || tempString == "no"));

      if(tempString == "yes")
      {
        cout << "GET OUT OF HERE, YOU FILTHY TEETOTALER!" << endl;
      }
      else
      {
        do
        {
          cout << "What's your age, " << name << "? ";
          cin >> tempVar;

          if(!(tempVar > 0 && tempVar <= OLDEST_KNOWN_AGE))
          {
            cout << "Please enter an age between 0 and " 
                 << OLDEST_KNOWN_AGE + 1 
                 << ", exclusive" << endl;
          }
        }while(!(tempVar > 0 && tempVar <= OLDEST_KNOWN_AGE));
 
        if(tempVar >= LEGAL_DRINKING_AGE)
        {
          do
          { 
            cout << name << ", do you intend on drinking soda, beer,"
                 << " or liquor? ";
            cin >> drinkChoice;
            
            if(!(drinkChoice == "liquor" ||
                 drinkChoice == "soda" ||
                 drinkChoice == "beer"))
            {
              cout << "Please enter either \"liquor\", \"soda\", or \"beer\"" 
                   << endl;
            }
          }while(!(drinkChoice == "liquor" || 
                   drinkChoice == "soda" || 
                   drinkChoice == "beer"));

          if(drinkChoice == "soda")
          {
            cout << "We don't soryv you sissies in dis place!" << endl;
          }     
          else
          {
            do
            {
              cout << "How much dough you got's on ya, " << name << "? $";
              cin >> money;

              if(!(money >= 0))
              {
                cout << "Please enter an amount greater than or equal to $0" 
                     << endl;
              }
            }while(!(money >= 0));
            
            if(money > 0)
            {
              if(drinkChoice == "beer")
              {
                tempVar = BEER_PRICE; 
                cout << name << ", you can buy " 
                     << static_cast<int>(money / BEER_PRICE) 
                     << " beers with $" << money << endl; 
              }
              else
              {
                tempVar = LIQUOR_PRICE;
                cout << name << ", you can buy " 
                     << static_cast<int>(money / LIQUOR_PRICE)
                     << " drinks with $" << money << endl;
              }

              do
              {
                cout << "How many would you like, " << name << "? ";
                cin >> numDrinks;
              
                if(!(numDrinks > 0))
                {
                  cout << "Please enter a positive amount of drinks" << endl;
                }
              }while(!(numDrinks > 0));
 
              if(money < tempVar)
              {
                cout << "Get outta here, ya bum!" << endl;
              }
              else if(numDrinks < static_cast<int>(money / tempVar))
              {
                cout << "Sorry, " << name 
                     << ". Come back when you want to spend" 
                     << " ALL your money!" << endl;
              }
              else if(numDrinks > static_cast<int>(money / tempVar))
              {
                cout << name << "! You don't have enough money for " 
                     << numDrinks << " drinks! Leave my store, you swine!" 
                     << endl;
              }
              else
              {
                cout << "C'mon in, " << name << ". Step up to the bar!" 
                     << " You will leave with $"
                     << static_cast<int>((money + .005) - numDrinks * tempVar)
                     << "." 
                     << static_cast<int> 
                        (((money + .005) - numDrinks * tempVar) * 10) % 10 
                     << static_cast<int>
                        (((money + .005) - numDrinks * tempVar) * 100) % 10    
                     << " in change." << endl;
             }
            }
            else
            {
              cout << "Get outta here, ya bum!" << endl;
            }    
          }
        }
        else
        {
          cout << "We don't serve minors here. Goodbye, " << name << ".\n";
        }
      }
    }
    
    do
    {  
      cout << "Anyone else there? ";
      cin >> tempString;

      if(!(tempString == "yes" || tempString == "no"))
      {
        cout << "Please enter either \"yes\" or \"no\"" << endl;
      }
    }while(!(tempString == "yes" || tempString == "no"));
  }while (tempString == "yes");
  
  cout << "\n" << name 
       << ", thank you very much for using Moe's Greeter Program!" << endl;
  
  return 0;
}
