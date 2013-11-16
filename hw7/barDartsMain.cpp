/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS53, Section C
 * Date: 10/17/13
 * Description: The main file that includes the main method for Moe's dart game
 */

#include "barDartsHeader.h"

int main()
{
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);
  
  srand(time(NULL));
  
  string answer = "yes";
  
  do
  {
    int numBeers = getNumBeers();
    float scoreArray[SHOTS_IN_ROUND];

    if(numBeers < MIN_BEERS)
    {
      presentScore(numBeers);
    }
    else if(numBeers >= MIN_BEERS && numBeers <= MAX_BEERS)
    {
      play(SOUNDS, scoreArray, numBeers);
      presentScore(scoreArray, numBeers);
      presentScore(scoreArray);
    }
    else
    {
      play(scoreArray);
      presentScore(scoreArray);
    }
    cout << "Would you like to play again? ";
    cin >> answer;
  }while(answer != "no");
}
