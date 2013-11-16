#include "header.h"

int main()
{
  srand(time(NULL));
  int choice, bankBalance = -1, gameBalance = -1;
  
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
          bankBalance = bankBalance == -1 ? generateBankBalance() : bankBalance;
          displayBalances(bankBalance, gameBalance);
        }
        else
        {
          cout << "You're broke dude. Get over it.\n" << endl;
        }
        break;
      case 2:
        transferFunds(bankBalance, gameBalance);
        break;
      case 3:
          if(gameBalance >= 5)
          {
            playGame(gameBalance);            
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
