/*
 * Name: GIACONE, JORDAN
 * Date: 11-3-13
 * Class and Section: CS53, Section C
 * Description: The header file that contains prototypes for the fable program 
 */

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef FABLE_HEADER_H
#define FABLE_HEADER_H
const int NUM_FABLES = 5, RANT_PERCENT = 25, NTCA_SIZE = 100, FIRST_WORD = 2,
          SECOND_WORD = 5;
const string FABLES[] = 
             {"fable1.txt", 
              "fable2.txt", 
              "fable3.txt", 
              "fable4.txt", 
              "fable5.txt"}, 
             LISTS[] = {"list1.txt", "list2.txt"};
const string MOE_RALS = "Moe-rals.txt", MOE_RANTS = "Moe-rants.txt", 
             FABLE_OUTPUT = "moeFables.txt";
const char WORD1[] = "a", WORD2[] = "the", WORD1_CAPS[] = "A", 
           WORD2_CAPS[] = "The";

/*
 * Description: Undergoes the process of creating a fable and outputting it via
                the given output stream
 * Pre: outputFile must be opened to a file
 * Params:
    - outputFile: The stream that will write to the generated fable
 * Post: outputFile will be brought to EOF
 * Return: None
 */
void makeFable(ofstream& outputFile);

/*
 * Description: Gets a random line from within the file with the given name 
                and stores it into the given NTCA
 * Pre: 
    - fileName must be a file that exists
    - replacementWord must be large enough to fit any given line in said file
 * Params:
    - replacementWord: The NTCA to be set to a random line
    - fileName: The name of the file from which the line will be grabbed
 * Post: replacementWord will be changed to a random line in the file
 * Return: None
 */
void getRandomLine(char replacementWord[], const string fileName);

/*
 * Description: Gets the number of lines in the given file
 * Pre: fileName must be a file that exists 
 * Params:
    - fileName: The name of the file to get the number of lines from
 * Post: None
 * Return: The number of lines in the file
 */
int getNumLinesInFile(const string fileName);

/*
 * Description: Delimits the given word for characters at the end and 
                returns the found character
 * Pre: word MUST BE null-terminated
 * Params: 
    - word: The word to be delimited
 * Post: word will be delimited
 * Return: The character that was delimited, a ' ' otherwise
 */
char delimitWord(char word[]);
#endif
