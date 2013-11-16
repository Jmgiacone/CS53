#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
const int THREE_IN_A_ROW_WINNINGS = 30, TWO_IN_A_ROW_WINNINGS = 1, 
          LOSE_WINNINGS = -5;

/*
 * Description: Transfers funds from the Bank to the user's game balance
 * Pre: bankBalance and gameBalance must be greater than 0
 * Params:
    - bankBalance: The current balance in the bank
    - gameBalance: The amount of money the user has transferred into the game
 * Post:
    - Text is output to the screen
    - The params bankBalance and gameBalance are passed by reference. Therefore
      they will be changed inside the function
 * Return: None
 */
void transferFunds(int& bankBalance, int& gameBalance);

/*
 * Description: Displays the Bank and Game balances to the screen
 * Pre: None
 * Params:
    - bankBalance: The balance of money in the users bank
    - gameBalance: The balance of money in the game
 * Post: Text is output to the screen
 * Return: None
 */
void displayBalances(const int bankBalance, const int gameBalance);

/*
 * Description: Generates a random number between 200 and 1000
 * Pre: None
 * Params: None
 * Post: None
 * Return: Returns a random  number between 200 and 1000
 */
int generateBankBalance();

/*
 * Description: Calculates how much money is won based on 3 spins
 * Pre: None
 * Params:
    - spin1: The first spin
    - spin2: The second spin
    - spin3: The third spin
 * Post: None
 * Return: The dollar amount that the 3 spins generated
 */
int calculateWinnings(const char spin1, const char spin2, const char spin3);

/*
 * Description: Generates a single spin of the slot machine
 * Pre: None
 * Params: None
 * Post: None
 * Return: A char between 'A' and 'D' inclusive
 */
char generateSpin();

/*
 * Description: Displays the results of the 3 spins
 * Pre: None
 * Params:
    - winnings: The winnings to be displayed. Usually the result of the 
                calculateWinnings() function
    - spin1: The first spin
    - spin2: The second spin
    - spin3: The third spin
 * Post: Text is output to the screen
 * Return: None
 */
void displayResults(const int winnings, 
                    const char spin1, const char spin2, const char spin3);

/*
 * Description: Plays one round of roulette
 * Pre: bankBalance must be > 1
 * Params: 
    - bankBalance: The players game balance
 * Post: 
    - Text is output to the screen
    - gameBalance is passed by reference and will be changed
 * Return: None
 */
void playGame(int& gameBalance);

/*
 * Description: Plays one round of the game FAIRLY
 * Pre: gameBalance should be > 0
 * Params:
    - gameBalance: The players in-game balance
 * Post:
    - gameBalance is passed by reference and will be changed
    - Text is output to the screen
 * Return: None
 */
void playFairly(int& gameBalance);

/*
 * Description: Helps Moe cheat when the player wins too much
 * Pre: gameBalance should be  > 0
 * Params: 
    - gameBalance: The player's in-game balance
 * Post: 
    - gameBalance is passed by reference and will change
    - Text is output to the screen
 * Return: None
 */
void moeCheats(int& gameBalance);
#endif
