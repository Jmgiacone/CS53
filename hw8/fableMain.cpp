/*
 * Name: GIACONE, JORDAN
 * Date: 11-3-13
 * Class and Section: CS53, Section C
 * Description: The main file that runs the fable program  
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include "fableHeader.h"

using namespace std;

int main()
{
  srand(time(NULL));
  char answer;
  ofstream fableOutput;
  fableOutput.open(FABLE_OUTPUT.c_str());
  do
  {
    cout << "So Moe, are you ready to create a fable(y/n)? ";
    cin >> answer;
    if(answer != 'y' && answer != 'n')
    {
      cout << "You must type \'y\' or \'n\'." << endl; 
    }
  }while(answer != 'y' && answer != 'n');

  while(answer == 'y')
  {
    makeFable(fableOutput);
    do
    {
      cout << "Would you like to go again(y/n)? ";
      cin >> answer;
     
      if(answer != 'y' && answer != 'n')
      {
        cout << "You must type \'y\' or \'n\'." << endl; 
      }
    }while(answer != 'y' && answer != 'n');
  }
 
  cout << "Thank you for generating fables!" << endl; 
  fableOutput.close();
  return 0;
}
