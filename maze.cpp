//
//  main.cpp
//  CS31Project3
//
//  Created by Monil Patel on 10/19/15.
//  Copyright © 2015 Monil Patel. All rights reserved.
//
#define NDEBUG

#include <iostream>
#include "grid.h"
#include <cctype>
#include  <cassert>
using namespace std;

bool isRouteWellFormed(string route);
int navigateSegment(int r, int c, char dir, int maxSteps);
int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps);
bool isValidPos(int r, int c);
bool isValidDirection(char c);
int stepsTraveled(int &r, int &c, string route, int &max);
void changePos(int &row, int &col, char d, int number);
int main()
{
   
    setSize(5,5);
   // setWall(1,4);
    setWall(2,2);
 //   setWall(3,2);
    draw(2,5,1,2);
    
    int nsteps=99;
    
    int answer=navigateRoute(3, 2, 3, 2, "s03", nsteps);
    cerr << "The output is: "<< answer<< endl;
    if(answer==1)
    {
        cerr <<"route didn't end where it was supposed to."<< endl;
    }
    else if(answer==0)
    {
        cerr << "route ended where it was supposed to. "<< endl;
    }
    else if(answer==3)
    {
        cerr << "part of route not possible"<<endl;
    }
    else
    {
        cerr << "starting or ending position or route is not valid"<< endl;
    }
    cerr<< "nsteps = "<<nsteps<<endl;
   // int l=stepsTraveled(1, 1,"s3e5s2", max);
   //cout <<"The stepstraveled: "<<l<<endl;
   //cout <<"The max steps: " <<max<<endl;
    //cout << "Row: "<<row<<endl;
    //cout << "Col: "<<col<<endl;

}
/*
    Checks if an inputted position is valid and therefore on the grid.
 */
bool isValidPos(int r, int c)
{
    if(r>0 && c>0 && r<=getRows() && c<=getCols() && !isWall(r, c)) // Checks to see if given position is valid
    {
        return true;
    }
    else
    {
        return false;
    }
}
/*
    Checks to see if the inputted direction is one of the 4 cardinal directions.
 */
bool isValidDirection(char c)
{
    if(c!='n' && c!='s' && c!='e' && c!='w' && c!='N' && c!='S' && c!='E' && c!='W') // Checks to see if given direction is valid
    {
        return false;
    }
    else
    {
        return true;
    }
}
/*
 Changes the position of the row and col by moving the further possible in a specified cardinal direction.
 */
void changePos(int &row, int &col, char d, int number)
{
    if(d=='n' || d=='N')
    {
        row-=number;
    }
    else if(d=='s' || d=='S')
    {
        row+=number;
    }
    else if(d=='e' || d=='E')
    {
        col+=number;
    }
    else if(d=='w' || d=='W')
    {
        col-=number;
    }
}
/*
 Checks to see if an inputted route is valid and follows all the stringent rules for what constitutes a route.
 */
bool isRouteWellFormed(string route)
{
    int lengthOfRoute=0;
    
    for(int g=0; g<route.size();g++)
    {
        if(!isValidDirection(route[g]) && !isdigit(route[g])) //weeds out non-alphanumeric routes
        {
            return false;
        }
    }
    if(route=="") //empty string case
    {
        return true;
    }
    else if(isValidDirection(route[0]) && route.size()==1) //singular case
    {
        return true;
    }
    else if(isValidDirection(route[0]) && isdigit(route[1]) && route.size()==2) //one letter one digit case
    {
        return true;
    }
    else
    {
        int j=0,i;
        int digLeg=0;
        
        for(i=0;i<route.size()-2;i++)
        {
            j=0;
            while(isValidDirection(route[j]))
            {
                j++;
                lengthOfRoute++;
            }
            while(isdigit(route[j]))
            {
                j++;
                lengthOfRoute++;
                digLeg++;
            }

            if(digLeg>2) // In case more than 2 digits
            {
                return false;
            }
            else
            {
                digLeg=0;
            }
        }
        i=j;
    }
    
    if(lengthOfRoute<route.size()) // if number of valid segments doesn't equal route then whole route isn't valid
    {
        return false;
    }
    return true;
  }
/*
    Checks the number of steps a robot can move in an inputted direction.
 */
int navigateSegment(int r, int c, char dir, int maxSteps)
{
    int totalSteps=0;
    int row=r;
    int col=c;
    char d=tolower(dir);
    
    if(maxSteps<0 || !isValidDirection(d) || !isValidPos(row,col)) // In case input is bad
    {
        return -1;
    }
            if(d=='n')
            {
                while (isValidPos(row-1,col)) // Checks to see if next position in direction is valid and not a wall
                {
                    row--;
                    totalSteps++;
                }
            }
            else if(d=='s')
            {
                while (isValidPos(row+1,col))
                {
                    row++;
                    totalSteps++;
                }
            }
            else if(d=='e')
            {
                while (isValidPos(row,col+1))
                {
                    col++;
                    totalSteps++;
                }
            }
            else if(d=='w')
            {
                while (isValidPos(row,col-1))
                {
                    col--;
                    totalSteps++;
                }
            }
    
    if(totalSteps>=maxSteps) // Only want to return the maximum number of steps the user wanted to move
    {
        return maxSteps;
    }
    else
    {
        return totalSteps;
    }
}
/*
    Calculates and returns the number of steps a robot can take on a valid route.
 */
int stepsTraveled(int &r, int &c, string route, int &max)
{
    int stepsTraveled=0;
    
    int digits=0;
    
    if (isRouteWellFormed(route))
    {
        string digitsPart="";
        char alphaPart = '\0';
        
        for (int i=0; i<route.length(); i++)
        {
            if(isalpha(route[i])) // Separates the directions from the digits
            {
                alphaPart=route[i];
                i++;
                
                while(isdigit(route[i]))
                {
                    digitsPart+=route[i];
                    i++;
                }
                i=i-1;
            }
            if(isalpha(route[i]) && !isalpha(i+1))
            {
                digitsPart="1";
            }
            
            digits=atoi(digitsPart.c_str()); // Converts the string into an int.
            digitsPart="";
            
            max+=digits;
            
            if(navigateSegment(r, c, alphaPart, digits)<digits || navigateSegment(r, c, alphaPart, digits)==-1 || navigateSegment(r, c, alphaPart, digits)==0) // If the robot cannot go the full distance returns total possible steps
            {
                stepsTraveled+=navigateSegment(r, c, alphaPart, digits);
                changePos(r, c, alphaPart,digits);
                max+=stepsTraveled;
                break;
            }
            else if(navigateSegment(r, c, alphaPart, digits)!=-1 && navigateSegment(r, c, alphaPart, digits)!=0 &&navigateSegment(r,c,alphaPart,digits)==digits) // If route segment valid continues with calculation
            {
                stepsTraveled+=navigateSegment(r, c, alphaPart, digits);
                changePos(r, c, alphaPart, digits);
            }
        }
    }
    return stepsTraveled;
   }

/*
 Checks to see if a given route gets from one location to another location. Returns the number of valid steps taken.
 */

int navigateRoute(int sr, int sc, int er, int ec, string route, int& nsteps)
{
    int maxSteps=0;
    
    if(!(isValidPos(sr, sc) && isValidPos(er, ec) && isRouteWellFormed(route)))
    {
        return 2; // doesnt change nsteps
    }
        nsteps=stepsTraveled(sr,sc,route,maxSteps);
    
    // No else statement needed because converse of if true
        if(nsteps<maxSteps) // part of route not possible
        {
            return 3;
        }
    
        if(sr==er && sc==ec) // route ended where it was supposed to.
        {
            
            return 0;
        }
        else
        {
            return 1; // route didn't end where it was supposed to.
        }
    }