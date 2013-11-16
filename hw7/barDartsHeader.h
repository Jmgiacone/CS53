/*
 * Name: GIACONE, JORDAN
 * Class and Section: CS53, Section C
 * Date: 10/17/13
 * Description: The header file that includes all constants and protypes for 
                Moe's dart game
 */

#ifndef BARDARTSHEADER__H
#define BARDARTSHEADER_H

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

const float DEGREES_TO_RADIANS = .017453;

const int MIN_BEERS = 3, 
          MAX_BEERS = 16, 
          FIRING_ANGLE_CONSTANT = 2, 
          GUN_TO_WALL = 13, 
          SHOTS_IN_ROUND = 14;

const string SOUNDS[] = {"ding ding ding!", 
                         "buuurrrrppp!", 
                         "Hey hey!", 
                         "Hmmmmmmm", 
                         "DOH!"};

/*
 * Description: Computes the distance between the ceter of the board (0,0)
                and the given x and y coordinates using the distance formula.
 * Pre: None
 * Param:
    - xCoord: The X Coordinate of the point
    - yCoord: The Y Coordinate of the point
 * Post: The result of the distance formula is returned
 * Return: The result of the distance formula
 */
float computeDistanceToBullseye(const float xCoord, const float yCoord);

/*
 * Description: Converts the given degree measurement into radians
 * Pre: None
 * Param:
    - degrees: The degree measurement to be converted
 * Post: The converted measurement is returned
 * Return: The converted measurement
 */
float convertDegreesToRadians(const float degrees);

/*
 * Description: Generates a random angle in [-2 * numBeers, 2 * numBeers].
                The return value of this function is IN RADIANS
 * Pre: numBeers must be > 0
 * Param:
    - numBeers: The number of beers the patron has drunk
 * Post: Returns a random measure in radians
 * Return: A random measure in radians
 */
float generateFiringAngle(const int numBeers);

/*
 * Description: Computes the X coordinate of a shot using the given angle
 * Pre: horizAngle must be in radian measure
 * Param:
    - horizAngle: The horizontal angle of the shot
 * Post: Returns the calculated X coordinate
 * Return: The calculated X coordinate
 */
float computeXCoord(const float horizAngle);

/*
 * Description: Computes the Y coordinate of a shot using 2 given angles
 * Pre: horizAngle and verticalAngle must be in radian measure
 * Param:
    - horizAngle: The horizontal angle of shooting
    - verticalAngle: The vertical angle of shooting
 * Post: Returns the calculated Y coordinate
 * Return: The calclated Y coordinate
 */
float computeYCoord(const float horizAngle, const float verticalAngle);

/*
 * Description: Prompts the user for how many beers they have drank
 * Pre: None
 * Param: None
 * Post: Returns the user inputted number of beers
 * Return: The number of beers the user drank
 */
int getNumBeers();

/*
 * Description: Presents the score for a player who has drank less than the
                minumum number of beers
 * Pre: numBeers be greater than 0
 * Param:
    - numBeers: The number of beers that the user has consumed
 * Post: Text is output to the screen
 * Return: None
 */
void presentScore(const int numBeers);

/*
 * Description: Presents the score for a player who has drank between
                the min and max number of beers.
 * Pre: 
    - numBeers be greater than 0
    - scores be at least SHOTS_IN_ROUND elements long
 * Param:
    - scores: An array that holds all of the players scores
    - numBeers: The number of beers that the user drank
 * Post: Text is output to the screen
 * Return: None
 */
void presentScore(const float scores[], const int numBeers);

/*
 * Description: Presents the score for a player who is too intoxicated to even
                play the game.
 * Pre: scores be at least SHOTS_IN_ROUND elements long
 * Param:
    - scores: An array that holds all of the players scores
 * Post: Text is output to the screen
 * Return:
 */
void presentScore(const float scores[]);

/*
 * Description: Simulates the user actually playing the dart game.
 * Pre:
    - sounds be at least 5 elements long
    - scores be at least SHOTS_IN_ROUND elements long
    - numBeers be greater than 0
 * Param: 
    - sounds: An array of funny sounds to be output
    - scores: An array to be filled with the players scores
    - numBeers: The number of beers that the user has drank
 * Post: 
    - Text is output to the screen
    - scores is passed "by reference" and will be filled with scores     
 * Return: None
 */
void play(const string sounds[], float scores[], const int numBeers);

/*
 * Description: Moe makes up scores for the user since they are too intoxicated
                to play.
 * Pre: score be SHOTS_IN_ROUND elements long
 * Param:
    - scores: An array to be filled with the players scores
 * Post: scores is passed "by reference" and will be filled with scores
 * Return: None
 */
void play(float scores[]);

/*
 * Description: Computes the average of the first <length> elements in scores
 * Pre: 
    - scores be at least <length> elements long
    - length be greater than 0
 * Param:
    - scores: The array of the users scores
    - length: The length to compute the average up to
 * Post: None
 * Return: The average of all elements up to <length> in scores
 */
float computeAverage(const float scores[], const int length);
#endif
