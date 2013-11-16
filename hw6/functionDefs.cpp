#include "header.h"
#include <iostream>

void transferFunds(int& bankBalance, int& gameBalance)
{ 
  int transferAmount;

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
}

void displayBalances(const int bankBalance, const int gameBalance)
{
  cout << "Bankk Balance: $" << bankBalance
       << "\nGame Balance: $" << (gameBalance == -1 ? 0 : gameBalance) 
       << "\n" << endl;
}

int generateBankBalance()
{
  return rand() % 800 + 200;
}


int calculateWinnings(const char spin1, const char spin2, const char spin3)
{
  if(spin1 == spin2 && spin2 == spin3)
  {
    return THREE_IN_A_ROW_WINNINGS;
  }
  else if(spin1 == spin2 || spin1 == spin3 || spin2 == spin3)
  {
    return TWO_IN_A_ROW_WINNINGS;
  }

  return LOSE_WINNINGS;
}

char generateSpin()
{
  return rand() % 4  + 'A';
}

void displayResults(const int winnings, 
                    const char spin1, const char spin2, const char spin3)
{
  cout << spin1 << " " << spin2 << " " << spin3 << endl;
  cout << "You " << (winnings > 0 ? "won" : "lost") 
       << " $" << (winnings > 0 ? winnings : -winnings) << "." << endl;   
}

void moeCheats(int& gameBalance)
{
  char spin1, spin2, spin3;
  int moneyWon;
  do
  {
    spin1 = generateSpin();
    spin2 = generateSpin();
    spin3 = generateSpin();
  }while(spin1 == spin2 || spin2 == spin3 || spin1 == spin3);

  moneyWon = calculateWinnings(spin1, spin2, spin3);
  gameBalance += moneyWon;

  displayResults(moneyWon, spin1, spin2, spin3);
}

void playFairly(int& gameBalance)
{
  char spin1 = generateSpin(), spin2 = generateSpin(), spin3 = generateSpin();
  int moneyWon = calculateWinnings(spin1, spin2, spin3);
  
  gameBalance += moneyWon;
  displayResults(moneyWon, spin1, spin2, spin3);
}

void playGame(int& gameBalance)
{
  int numSpins, startingMoney = gameBalance;

  cout << "You have $" << gameBalance << "." << endl;
  do
  {
    cout << "How many times would you like to spin? ";
    cin >> numSpins;    

    if(numSpins < 0)
    {
      cout << numSpins << " is an invalid number of spins."
           << " You must spin at least once." << endl;
    }
    else if(gameBalance < numSpins * -LOSE_WINNINGS)
    {
      cout << "You can't afford to lose " << numSpins << " times."
           << " Try spinning " << gameBalance / -LOSE_WINNINGS 
           << " times." << endl;
    }
  }while(numSpins < 0 || gameBalance < numSpins * -LOSE_WINNINGS);

  for(int i = 0; i < numSpins; i++)
  {
    //First 5 are fair play
    if(i < 5)
    {
      playFairly(gameBalance);  
    }
    else if(gameBalance <= startingMoney)
    {
      //Still fair play
      playFairly(gameBalance);
    }
    else
    {
      //Moe cheats now
      moeCheats(gameBalance);
    }
  }
  cout << "\nYou have $" << gameBalance << " after " << numSpins 
       << " spin" << (numSpins == 1 ? "" : "s") << ".\n" << endl;
}
