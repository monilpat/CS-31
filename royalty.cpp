//
//  main.cpp
//  CS31Project2
//
//  Created by Monil Patel on 10/7/15.
//  Copyright © 2015 Monil Patel. All rights reserved.
//  The purpose of this program is to calculate the royalties incurred by a specific movie, which depends on the number of units shipped out, the base price, and whether the movie is a premium movie.

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int numUnits=0;
    string title, premium, output;
    double royalties=0,bPrice=0,royaltyRate2=0;
    const double royaltyRate1=.09; // constant regardless of input
    const double royaltyRate3=.14;
    
    // handle the 2 decimal points
    cout.setf(ios::fixed);
    cout.precision(2);
    
    cout << "Units sent: ";
    cin >> numUnits;
    
    cin.ignore(10000,'\n'); // Because switching from inputting number and string
    cout << "Title: ";
    getline(cin,title);
    
    cout << "Base price: ";
    cin >> bPrice;
    
    cin.ignore(10000,'\n'); // Because switching from inputting number and string
    cout << "Premium item? (y/n): ";
    getline(cin,premium);
    
    if (premium=="y")
    {
        royaltyRate2=.16;
    }
    
    else if (premium=="n")
    {
        royaltyRate2=.13;
    }
    
    if (numUnits<0) // ordered so that once first error noticed rest are ignored.
    {
        output="The number of units sent must be nonnegative.";
    }
    else if (title=="")
    {
        output="You must enter a title.";
    }
    else if(bPrice<0)
    {
        output="The base price must be nonnegative.";
    }
    else if (premium!="n" && premium!="y")
    {
        output="You must enter y or n.";
    }
    else // no errors then can proceed with the calculation
    {
        if(numUnits<=400)
        {
            royalties=(numUnits*(bPrice*royaltyRate1));
        }
        else if(numUnits<=1200)
        {
            royalties=(400*(bPrice*royaltyRate1))+((numUnits-400)*(bPrice*royaltyRate2));
        }
        else
        {
            royalties=(400*(bPrice*royaltyRate1))+(800*(bPrice*royaltyRate2)+((numUnits-1200)*(bPrice*royaltyRate3)));
        }
        output=title+" earned $";
        // Had to put royalties in cout line because otherwise more than 2 decimals points would be shown
        if(royalties==0) // handles if calculation is 0 as opposed to just being initialized to 0.
        {
            output+="0.00 in royalties.";
        }
    }
    
    cout << "---" << endl;
    
    if(royalties!=0)
    {
        cout << output << royalties << +" in royalties." << endl;
    }
    else
    {
        cout << output << endl;
    }
}