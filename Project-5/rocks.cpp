//
//  main.cpp
//  CS31Project5
//
//  Created by Monil Patel on 11/9/15.
//  Copyright © 2015 Monil Patel. All rights reserved.
//
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "utilities.h"
#include <cstring>
#include <cctype>
using namespace std;

int manageOneRound(const char words[][7], int nWords, int wordnum);
void calculateAverageMinMax(int score, double &avg, int &min, int &max, int &scoreSum,int roundNum);
int calculateNumOfRocks(const char probe[], const char secretWord[], bool &isAllRocks);
int calculateNumOfPebbles(const char probe[], const char secretWord[]);

const int MAXWORDS=10000;

int main()
{
    char word[MAXWORDS][MAXWORDLEN+1];
    int wordNum=0;
    int numOfRounds=0;
    int nWords=loadWords(word, MAXWORDS); // fills the array and returns number of words in array
    int min=100000,max=0,scoreSum=0;
    char secretWord[MAXWORDLEN+1];
    double avg=0;
    
    if (nWords<1)
    {
        cout << "No words were loaded, so I can't play the game.";
        return 0;
    }
    else if (nWords<=MAXWORDS) // If the number of words loaded less than the maximum words
    {
        cout<<"How many rounds do you want to play? ";
        cin>>numOfRounds;
        cin.ignore(10000,'\n'); // In order to prevent error when reading in strings later
        
        if(numOfRounds<=0)
        {
            cout <<"The number of rounds must be positive.";
            return 0;
        }
        
        for (int i =1; i<=numOfRounds; i++)
        {
            // How secret word is chosen
            wordNum=randInt(0, nWords-1);
            strcpy(secretWord, word[wordNum]);
            //secretWord[strlen(secretWord)]='\0';
            
            cout<<"\nRound "<<i<<endl;
            cout <<"The secret word is "<<strlen(secretWord)<<" letters long."<< endl;
            int score=manageOneRound(word, nWords, wordNum); // Calculates number of tries to correctly guess the secret word
            
            if (score==-1) // Handles if improper input to manageOneRound()
            {
                cout <<"Either the words in the array were not loaded, or the location of the secret word is above or below the number of words in the array.";
                return 0;
            }
            min=score;
            calculateAverageMinMax(score,avg,min,max,scoreSum,i);
            
            if (score==1)
            {
                cout << "You got it in "<<score<<" try."<<endl;
            }
            else
            {
                cout << "You got it in "<<score<<" tries."<<endl;
            }
            cout <<"Average: "<<avg<<", minimum: "<<min<<", maximum: "<<max<< endl;
        }
    }
}

//This functions plays one round of the game and returns the score for that round.
int manageOneRound(const char words[][MAXWORDLEN+1], int nWords, int wordnum)
{
    char secretWord[MAXWORDLEN+1];
    int numOfRocks=0, numOfPebbles=0, numOfTries=0;
    
    strcpy(secretWord, words[wordnum]); //sets secret word to random word in the word list
    secretWord[strlen(secretWord)]='\0';
    
    if (nWords<1 || wordnum<0 || wordnum>=nWords)
    {
        return -1;
    }
    for(;;)
    {
        bool isUpper=false, isAllRocks=false, isPresent=false, isAlpha=true;
        char probe[MAXWORDS+1];
        cout <<"Probe word: ";
        cin.getline(probe, MAXWORDS+1);
        //probe[strlen(probe)]='\0';
        
        for (int r=0; probe[r]!='\0'; r++) // checks to see if all are lower cased
        {
            if (isupper(probe[r]))
            {
                isUpper=true;
            }
            if (!isalpha(probe[r])) // checks to see if all characters are letters
            {
                isAlpha=false;
            }
        }
        
        for (int k=0; k<nWords; k++) // checks word list for probe word
        {
            if (strcmp(probe, words[k])==0)
            {
                isPresent=true;
                break;
            }
        }
        
        if(strlen(probe)<MINWORDLEN || strlen(probe)>MAXWORDLEN || isUpper || !isAlpha) // Makes sure probe is a valid guess
        {
            cout << "Your probe word must be a word of 4 to 6 lower case letters."<< endl;
            continue;
        }
        if (!isPresent) // Makes sure probe word is in the words.txt file
        {
            cout<<"I don't know that word."<<endl;
            continue;
        }
        if (strlen(probe)>=MINWORDLEN && strlen(probe)<=MAXWORDLEN && !isUpper && isPresent) // If valid adds to the score
        {
            numOfTries++;
        }
        
        numOfRocks=calculateNumOfRocks(probe,secretWord,isAllRocks);
        numOfPebbles=calculateNumOfPebbles(probe,secretWord);
        
        if (numOfRocks==strlen(secretWord) && isAllRocks) // Makes sure all in the same location and probe letter has all rocks so there is no bug where probe word same up til secretword size then different
        {
            break;
        }
        
        cout<<"Rocks: "<<numOfRocks<<", Pebbles: "<<numOfPebbles<<endl;
    }
    return numOfTries;
}
// Calculates the average, minimum, and maximum score for each round of the game.
void calculateAverageMinMax(int score, double &avg, int &min, int &max, int &scoreSum, int roundNum)
{
    cout.setf(ios::fixed);
    cout.precision(2); // Makes sure average is set to double precision.
    scoreSum+=score;
    avg=(double)scoreSum/roundNum;
    
    if(score>max)
    {
        max=score;
    }
    else if(score<min)
    {
        min=score;
    }
}
// Calculates the number of rocks, or pairings of a letter in the probe word and the same letter in the secret word in the same position.
int calculateNumOfRocks(const char probe[], const char secretWord[],bool &isAllRocks)
{
    int numOfRocks=0;
    for (int i=0; probe[i]!='\0'; i++)
    {
        if (probe[i]==secretWord[i])
        {
            numOfRocks++;
            continue;
        }
    }
    if (numOfRocks==strlen(probe))
    {
        isAllRocks=true;
    }
    else
    {
        isAllRocks=false;
    }
    
    return numOfRocks;
}
//  Calculates the number of pebbles, pairings between a letter in the probe word and the same letter in the secret word. However the pairings are not in the same position as in the probe word, provided the two letters are not involved in a rock or another pebble.
int calculateNumOfPebbles(const char probe[], const char secretWord[])
{
    char temp[7];
    strcpy(temp,secretWord);
    int numOfPebbles=0;
    for (int i=0; probe[i]!='\0'; i++)
    {
        for (int j=0; secretWord[j]!='\0'; j++)
        {
            if (probe[i]==temp[j] && i!=j && temp[j]!=probe[j] && temp[i]!=probe[i]) //provided the two letters are not involved in a rock or another pebble. use strcmp strcpy strcat strncmp compare character of 2 c strings strchr locates first occurence of character in string Take a look at the c strings functions
            {
                numOfPebbles++;
                temp[j]='#'; // change character at the position so pairing counted only once.
                break;
            }
        }
    }
    return numOfPebbles;
}