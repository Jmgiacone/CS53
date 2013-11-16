/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS53, Section C
 * Date: 10/17/13
 * Description: The function definition file that includes all function 
                definitions for Moe's dart game
 */

#include "barDartsHeader.h"
#include <cmath>
#include <cstdlib>
#include <iostream>

using namespace std;

float computeDistanceFromBullseye(const float xCoord, const float yCoord)
{
  return sqrt(xCoord * xCoord + yCoord * yCoord);
}

float convertDegreesToRadians(const float degrees)
{
  return degrees * DEGREES_TO_RADIANS;
}

float generateFiringAngle(const int numBeers)
{
  int minValue = -1 * numBeers * FIRING_ANGLE_CONSTANT, 
      maxValue = numBeers * FIRING_ANGLE_CONSTANT;

  return convertDegreesToRadians(
           (rand() % (maxValue - minValue + 1) + minValue));
}

float computeXCoord(const float horizAngle)
{
  return GUN_TO_WALL * sin(horizAngle) / cos(horizAngle);
}

float computeYCoord(const float horizAngle, const float verticalAngle)
{
  return GUN_TO_WALL * 
         sin(verticalAngle) / 
         cos(verticalAngle) * 
         cos(horizAngle);
}

int getNumBeers()
{
  int numBeers;

  do
  {
    cout << "How many beers have you had tonight? ";
    cin >> numBeers;

    if(numBeers < 0)
    {
      cout << "Please enter a number greater than or equal to zero" << endl;
    }
  }while(numBeers < 0);

  return numBeers;
}

void presentScore(const int numBeers)
{
  //Integer division
  cout << "Your Score: " << numBeers / 2 << endl;
}

void presentScore(const float scores[], const int numBeers)
{
  float average = 0;

  for(int i = 0; i < SHOTS_IN_ROUND; i++)
  {
    average += scores[i];
  }
 
  average /= SHOTS_IN_ROUND;
  cout << "Your Score: " << average / numBeers << endl;
}

float computeAverage(const float scores[], const int length)
{
  float total = 0;

  for(int i = 0; i < length; i++)
  {
    total += scores[i];
  }

  //float / int -> float
  return total / length;
}

void presentScore(const float scores[])
{
  float total = 0, average = computeAverage(scores, SHOTS_IN_ROUND);
  for(int i = 0; i < SHOTS_IN_ROUND; i++)
  {
    total += pow(average - scores[i], 2);  
  }
  cout << "Your Handicapped Score: " << (1.0 / SHOTS_IN_ROUND) * total << endl;  
}

void play(const string sounds[], float scores[], const int numBeers)
{
  float horizAngleRadians, verticalAngleRadians, xCoord, yCoord;
  
  for(int i = 0; i < SHOTS_IN_ROUND; i++)
  {
    horizAngleRadians = generateFiringAngle(numBeers);
    verticalAngleRadians = generateFiringAngle(numBeers);
    
    xCoord = computeXCoord(horizAngleRadians); 
    yCoord = computeYCoord(horizAngleRadians, verticalAngleRadians);

    cout << "X: " << xCoord << " Y: " << yCoord << " -> ";
    scores[i] = computeDistanceFromBullseye(xCoord, yCoord);

    cout << scores[i] << endl;  
    if(scores[i] <= 1)
    {
      cout << sounds[0];
    }
    else if(scores[i] <= 2)
    {
      cout << sounds[1];
    }  
    else if(scores[i] <= 3)
    {
      cout << sounds[2];
    }
    else if(scores[i] <= 4)
    {
      cout << sounds[3];
    }
    else
    {
      cout << sounds[4];
    }

    cout << "\n" << endl;
  }  
}

void play(float scores[])
{
  for(int i = 0; i < SHOTS_IN_ROUND; i++) 
  {
    scores[i] = (rand() % 56) / 10.0;
  }
}
