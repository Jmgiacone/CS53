//Name: GIACONE, JORDAN
//Date: 9-20-13
//Class and Section: CS53, Section C
//Description: Simulates a slot machine in Moe's Bar.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int THREE_IN_A_ROW = 30, TWO_IN_A_ROW = 1, NO_MATCH = -5;
const char FIRST_CHOICE = 'A';

int main()
{
  srand(time(NULL));
  int choice, bankBalance = -1, gameBalance = -1, transferAmount, winnings,
      numSpins;
  char spin1, spin2, spin3;
  
  do
  {
    cout << "OPTIONS\n"  
         << "--------\n"
         << "1. Check Bankk Balance\n"
         << "2. Transfer Funds to the Game\n"
         << "3. Play\n"
         << "4. Leave(Cash Out)\n"
         << "Choice: ";
    cin >> choice;
    
    cout << endl;
    switch(choice)
    {
      case 1:
        if(bankBalance + gameBalance >= 5 || bankBalance == -1)
        {
          bankBalance = bankBalance == -1 ? rand() % 800  + 200 : bankBalance;
          cout << "Bankk Balance: $" << bankBalance 
               << "\nGame Balance: $" << (gameBalance == -1 ? 0 : gameBalance) 
               << "\n" << endl;
        }
        else
        {
          cout << "You're broke dude. Get over it.\n" << endl;
        }
        break;
      case 2:
        if(bankBalance > 0)
        {
          gameBalance = gameBalance == -1 ? 0 : gameBalance;
          do
          {
            cout << "Please enter an amount between $1 and $" << bankBalance 
                 << " to transfer into the game.\n$";
            cin >> transferAmount;
          
            if(!(transferAmount > 0 && transferAmount <= bankBalance))
            {
              cout << "$" << transferAmount << " is an invalid input. Try again." 
                   << endl;
            }
          }while(!(transferAmount > 0 && transferAmount <= bankBalance));
        
          bankBalance -= transferAmount;
          gameBalance += transferAmount;

          cout << "Thank you for your transfer of $" << transferAmount << ".\n" 
               << endl;
        }
        else
        {
          if(bankBalance == -1) 
          {
            cout << "You must check your balance before you can transfer funds."
                 << "\nPlease choose option 1 and check your Bankk balance." 
                 << endl;
          }
          else
          {
            cout << "What's the use in transferring? You're out of money!" 
                 << endl;
          } 
        }
        break;
      case 3:
          if(gameBalance >= 5)
          {
            cout << "Okay, the rules are as follows:" 
                 << "\n3 of a kind is +$" << THREE_IN_A_ROW 
                 << "\n2 of a kind is +$"<< TWO_IN_A_ROW
                 << "\nNone of a kind is -$"<< -NO_MATCH 
                 << endl;
            
            do
            {
              cout << "How many spins would you like to make? ";
              cin >> numSpins;
              if(numSpins < 1)
              {
                cout << "You have to spin at least once" << endl; 
              
              }
              else if(gameBalance - (-NO_MATCH * numSpins) < 0)
              {
                cout << "You can't afford to lose $" << -NO_MATCH * numSpins 
                     << ". Try spinning "<< gameBalance / -NO_MATCH 
                     << " time" << (gameBalance / -NO_MATCH == 1 ? "" : "s")
                     << "." << endl;
              }
            }while(!(numSpins >= 1 && 
                    (gameBalance - (-NO_MATCH * numSpins) >= 0)));

            for(int i = 0; i < numSpins; i++)
            {
              //Add the random number to the character before 'A' to get random
              //characters
              spin1 = rand() % 4 + FIRST_CHOICE; 
              spin2 = rand() % 4 + FIRST_CHOICE;
              spin3 = rand() % 4 + FIRST_CHOICE;

              cout << spin1 << " " << spin2 << " " << spin3 << endl;
            
              //3 of a kind case
              if(spin1 == spin2 && spin1 == spin3)
              {
                cout << "3 of a kind! WHOO HOO!" << endl;
                winnings = THREE_IN_A_ROW;
              }
              //2 of a kind case
              else if(spin1 == spin2 || spin1 == spin3 || spin2 == spin3)
              {
                cout << "Two of a kind. Not too shabby." << endl;
                winnings = TWO_IN_A_ROW;  
              }
              else
              {
                cout << "None of the spinners match. Too bad, so sad." << endl;
                winnings  = NO_MATCH;
              } 

              gameBalance += winnings;
              cout << "\nYou have " << (winnings > 0 ? "won" : "lost") << " $" 
                   << (winnings < 0 ? -winnings : winnings) << " today.\n"
                   << "Your new balance is $" << gameBalance << ".\n" << endl; 
              winnings = 0;
            }
          }
          else
          {
            if(gameBalance < 0)
            {
              cout << "You must transfer funds to the game before you play.\n"
                   << "Please choose option 2 to transfer." << endl;
            }
            else
            {
              cout << "You don't have enough money to play the slots today."
                   << " Sorry, dude." << (bankBalance > 5 ? "" : "\n") << endl;
              if(bankBalance > 5 - gameBalance)
              {
                cout << "May I suggest tapping into the $" << bankBalance 
                     << " in your bankk?\n" << endl;
              }
            }
          }
        break;
      case 4:
        cout << "Thank you for playing the slots with Moe!" << endl;
        
        if(bankBalance >= 0 && gameBalance >= 0) 
        {
          cout << "You are leaving today with $" << bankBalance 
               << " in the bank and $" << gameBalance << " in winnings."
               << endl;
        }
        break;
      default:
        cout << choice << " is an invalid choice. Try again\n" << endl;
    }
  }while(!(choice == 4));  
  
  return 0;
}
