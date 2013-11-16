//Name: GIACONE, JORDAN
//Class and Section: CS 53 Section C
//Date: 9/1/13
//Description: Generates Phone numbers based on eye color, gender, and height

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

const int PNGF = 78;

int main()
{
  string firstName, lastName; 
  int eyeColor, gender, def;
  float height;
  cout << endl
       << "Hello! Welcome to the phone number Generator!" 
       << endl;
  
  cout << "First things first, please enter your first name: ";
  cin >> firstName;

  cout << "and your last name: ";
  cin >> lastName;

  cout << firstName 
       << ", please enter your eye color (475 for blue, 510 for green,"
       << " and  590 for orange): ";
  cin >> eyeColor;

  cout << firstName 
       << ", please enter your Gender (0 for male, 1 for female): ";
  cin >> gender;

  cout << firstName 
       << ", please enter your height in meters: ";
  cin >> height;

  cout << endl
       << "Name:                       " 
       << firstName 
       << " "
       << lastName 
       << endl;

  def = static_cast<int>(height * eyeColor) % 1000;
  cout << "Generated Phone Number:     1-" 
       << eyeColor 
       << "-" 
       << def / 100
       << (def % 100) / 10
       << def % 10
       << "-" 
       << static_cast<int>(
            (10 * eyeColor) + (PNGF * gender) + pow(height, 2)) 
       << endl
       << "My Motto:                  \"When life gives you lemons,"
       << " don't make lemonade.\n"
       << "                            Make life take the lemons back!\n"
       << "                            GET MAD!\n"
       << "                            I don't want your damn lemons!\n"
       << "                            What am I supposed to do with these?\n"
       << "                            Demand to see life's manager!\n"
       << "                            Make life rue the day it thought it"
       << " could give\n"
       << "                            CAVE JOHNSON lemons!\n"
       << "                            Do you know who I am?\n"
       << "                            I'm the man who's gonna burn your"
       << " house down!\n"
       << "                            With the lemons!\n"
       << "                            I'm gonna get my engineers to invent\n"
       << "                            a COMBUSTIBLE LEMON that burns your"
       << " house down!\"\n\n"   
       << "Thanks for using my phone number generator, have a great day!"
       << endl;
  
  return 0; 
}
