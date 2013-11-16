/*
 * Name: GIACONE, JORDAN
 * Date: 11-3-13
 * Class and Section: CS53, Section C
 * Description: The file containing function definitions for the fable program 
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "fableHeader.h"

using namespace std;

void makeFable(ofstream& outputFile)
{
  char temp[NTCA_SIZE], 
       word1[NTCA_SIZE], 
       word2[NTCA_SIZE], 
       replace1[NTCA_SIZE], 
       replace2[NTCA_SIZE], 
       append;
  ifstream input;
  bool replaceNext = false;
  input.open(FABLES[rand() % NUM_FABLES].c_str());
  
  getRandomLine(replace1, LISTS[0]);
  getRandomLine(replace2, LISTS[1]);

  for(int i = 1; input; i++)
  {
    input >> temp;
    
    //Replace words 2 and 5 with random words
    switch(i)
    {
      case FIRST_WORD:
        strcpy(word1, temp);
        strcpy(temp, replace1);
        break;
      case SECOND_WORD:
        strcpy(word2, temp);
        strcpy(temp, replace2);
        break;
    }
   
    //Remove any non-alpha characters 
    append = delimitWord(temp);
    if(strcmp(temp, word1) == 0)
    {
      strcpy(temp, replace1);
    }
    else if(strcmp(temp, word2) == 0)
    {
      strcpy(temp, replace2);
    }
    else if(i > 5 && replaceNext) 
    {
      getRandomLine(temp, LISTS[1]);
    }
    outputFile << temp << append << (append == ' ' ? "" : " ");
    
    replaceNext = strcmp(temp, WORD1) == 0 || 
                  strcmp(temp, WORD2) == 0 || 
                  strcmp(temp, WORD1_CAPS) == 0  || 
                  strcmp(temp, WORD2_CAPS) == 0;     
    if(append == '.' || append == '?' || append == '!')
    {
      //1/4 chance to rant
      getRandomLine(temp, MOE_RANTS);
      outputFile << (rand() % NTCA_SIZE < RANT_PERCENT ? temp : "") << " ";
    }

    //Clear temp
    strcpy(temp, "");
  }

  getRandomLine(temp, MOE_RALS);
  outputFile << "\nThe Moe-rale of this story is: " << temp << endl << endl;
  input.close();
}

void getRandomLine(char replacementWord[], const string fileName)
{
  int randomLine;
  ifstream list;
  list.open(fileName.c_str());
  
  //Random line in [1, last line]
  randomLine = (rand() % getNumLinesInFile(fileName)) + 1;
   
  for(int i = 0; i < randomLine; i++)
  {
    list.getline(replacementWord, 1000);
  }
  list.close();
}

int getNumLinesInFile(const string fileName)
{
  ifstream file;
  file.open(fileName.c_str());
  int count = 0;
  char garbage[NTCA_SIZE];

  while(file)
  {
    //useless NTCA solely to please getline()
    file.getline(garbage, 1000);
    count++;
  }

  file.close();
  //Make allotments for invisible newline
  return --count;
}

char delimitWord(char word[])
{
  char found = ' ';

  //Could easily be a while-loop
  for(int i = 0; word[i] != '\0'; i++)
  {
    if(!isalpha(word[i]) && word[i + 1] == '\0')
    {
      //Found a non-alpha at the end
      found = word[i];
      word[i] = '\0';
    }
  }
  return found;
}
