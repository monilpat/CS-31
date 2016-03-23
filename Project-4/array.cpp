//
//  main.cpp
//  CS31Project4
//
//  Created by Monil Patel on 10/30/15.
//  Copyright © 2015 Monil Patel. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>
using namespace std;
int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter);
string getArray(string a[], int n);

int main()
{
    /*
     //LOOKUP TESTER
    string people[5] = { "hillary", "jeb", "rand", "ben", "john" };
    int i = lookup(people, 0, "hillary");
    cout<<i<<endl;
     //POSITIONOFMAXTESTER
     string cand[6] = { "E", "e", "", "", "", "" };
     int k = positionOfMax(cand, 3);   // returns 3, since  marco  is latest
     cout <<k<<endl;
     // ROTATELEFT
     string cand[6] = { "E", "e", "",};
     int k = rotateLeft(cand, 0,0);   // returns 3, since  marco  is latest
     cout <<k<<endl;
     cout <<getArray(cand, 3);
     // COUNTRUNS
     string cand[6] = {};
     int k = countRuns(cand,0);   // returns 3, since  marco  is latest
     cout <<k<<endl;
     // FLIP
     string people[5] = { "hillary", "jeb", "rand", "ben", "john" };
     int i = flip(people, 0);
     cout <<i<<endl;
     cout <<getArray(people, 0)
     
     // DIFFER
     string folks[6] = { "chris", "marco", "", "ben", "donald", "john" };
     string group[5] = { "chris", "marco", "john", "", "carly" };
     int r = differ(folks, 6, group, 5);  //  returns 2
     int s = differ(folks, 2, group, 1);  //  returns 1
     cout <<r<<endl<<s;
     //Subsequence
     string folks[3] = { "food","food", "run"};
     string group[2] = { "food","run"};
     int r =subsequence(folks, 3, group, 2);
     cout <<getArray(folks, 3);
     cout<<r<<endl;
     // SPLIT
     string folks[6] = { "b","d","e","c"};
     int r=split(folks, 6, "a");
     cout <<getArray(folks, 4);
     cout<<r<<endl;
     
     string folks[10] = { "food","food", "run"};
     string group[10] = { "food","run"};
     int r =subsequence(folks, 3, group, 2);
     cout <<getArray(folks, 3);
     cout<<r<<endl;

    */
    /*
    string h[7] = { "bernie", "hillary", "donald", "jeb", "", "carly", "ben" };
    assert(lookup(h, 7, "carly") == 5);
    assert(lookup(h, 7, "donald") == 2);
    assert(lookup(h, 2, "donald") == -1);
    assert(positionOfMax(h, 7) == 3);
    
    string g[4] = { "bernie", "hillary", "jeb", "carly" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "bernie?" && g[3] == "carly?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "jeb?" && g[3] == "hillary?");
    
    string e[4] = { "donald", "jeb", "", "carly" };
    assert(subsequence(h, 7, e, 4) == 2);
    
    string d[5] = { "hillary", "hillary", "hillary", "ben", "ben" };
    assert(countRuns(d, 5) == 2);
    
    string f[3] = { "jeb", "donald", "marco" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "marco" && f[2] == "jeb");
    
    assert(split(h, 7, "carly") == 3);
    
    cout << "All tests succeeded" << endl;
    */
    //string h[7] = { "bernie", "hillary", "donald", "jeb", "", "carly", "ben" };
    //cout << appendToAll(h, 0, " ");
    //cout << getArray(h,7);
    //cout <<lookup(h, 0, "donald")<< endl;
    //cout << positionOfMax(h, 7) << endl;
    //string g[4] = { "bernie", "hillary", "jeb", "carly" };
  //  cout << rotateLeft(g, 4, 0)<< endl;
   // cout << getArray(g,4);
    //string n[5] = { "bernie", "hillary", "jeb", "carly",""};

    //string d[10] = {"ben", "chris", "marco", "marco", "donald", "donald", "donald", "marco", "marco","donald"};
  //  int p = countRuns(d, 10);  //  returns 5
    //cout<<p<<endl;
    
    //flip(d,5);
    //string g[5] = { "bernie", "hillary", "jeb", "carly","" };
   // cout << differ(n, 5, g, 5);
   // cout << getArray(d,4);
    //string f[3] = { "jeb", "donald", "marco" };
    //cout << lookupAny(h, 7, f, 1);
    //assert(flip(f, 3) == 3 && f[0] == "marco" && f[2] == "jeb");
    //string cand2[4] = { "donald", "hillary", "jeb", "ben" };
    //int y = split(cand2, 4, "donald");  //  returns 1
    //cout <<y<<endl;
    //cout << getArray(cand2, 4)<< endl;
    //string names[10] = { "ted", "hillary", "rand", "bernie", "mike", "jeb" };
    //string names1[10] = { "hillary", "rand", "bernie" };
    //int t = subsequence(names, 6, names1, 3);  // returns 1
    //string names2[10] = { "ted", "bernie" };
    //int u = subsequence(names, 5, names2, 2);  // returns -1
    //cout <<"t "<<t<<endl<<"u "<<u;
    /*
    
    string d[5] = { "hillary", "hillary", "hillary", "ben", "ben" };
    assert(countRuns(d, 5) == 2);
    
    cout << "All tests succeeded" << endl; 
     */
}
// Returns a string representation of the specified array
string getArray(string a[], int n)
{
    string result="[ \n";
    for (int i=0; i<n; i++)
    {
        result+=a[i]+", \n";
    }
    result+=" ]";
    return result;
}
// Appends a specific string to n elements of a specified array
int appendToAll(string a[], int n, string value)
{
    if(n<0) // Checks for invalid input
    {
        return -1;
    }
    for(int i=0; i<n;i++) // Adds value to the end of each element of the array
    {
        a[i]+=value;
    }
    return n;
}
// Finds the first instance of a specific string and returns its position
int lookup(const string a[], int n, string target)
{
    if(n<0) // Checks for invalid input
    {
        return -1;
    }
    for (int i=0; i<n; i++)
    {
        if(a[i]==target) // Checks to see if element is equal to target
        {
            return i;
        }
    }
    return -1;
}
// Finds the position of the string that is greater than or equal to all other string
int positionOfMax(const string a[], int n)
{
    int maxPos=0,currentPos=0;
    string max="";
    
    if(n<=0) // Checks for invalid input
    {
        return -1;
    }
    for (int i=0; i<n; i++) // Checks if max is true max through comparing it to the rest of the elements of the array
    {
        if(a[i]>max)
        {
            currentPos=i;
        }
        if(currentPos>maxPos)
        {
            maxPos=currentPos;
            max=a[maxPos];
            currentPos=0;
        }
    }
    return maxPos;
}
// Rotates the array to the left by moving element at a specified position to the end of the array and sliding the rest over and returns the position
int rotateLeft(string a[], int n, int pos)
{
    if(n<=0 || pos<0 ||pos>=n) // Checks for invalid input
    {
        return -1;
    }
    string rotatedWord=a[pos]; // Placeholder to set to last element of the array
    
    for(int i=pos; i<n-1; i++)
    {
        a[i]=a[i+1];
    }
    a[n-1]=rotatedWord; // sets last element to value of rotated word
    
    return pos;
}
// Returns the number of sequences of one or more consecutive identical items in a specified array.
int countRuns(const string a[], int n)
{
    int runs=0;
    string b[325000]={};
    
    if(n<0) // Checks for invalid input
    {
        return -1;
    }
    for (int i=0; i<n; i++)
    {
        b[i]=to_string(lookup(a, n, a[i])); // Finds first instance of each word
    }
    //cerr <<getArray(b, n);

    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if(b[i]==b[j]) // while the continuous elements are the same word change it to the empty string except the original one
            {
                b[j]="";
            }
            else
            {
                break;
            }
        }
    }
    //cerr <<getArray(b, n);
    for (int r=0; r<n; r++)
    {
        if(b[r]!="") // Counts the number of numbers or runs left
        {
            runs++;
        }
    }
    return runs;
    }

//Reverse the order of the elements of the array and return n.
int flip(string a[], int n)
{
    string b="";
    
    if(n<0) // Checks for invalid input
    {
        return -1;
    }
    
    for (int i=0; i<n/2; i++)
    {
        b=a[i]; // Uses temporary variable to switch first value with the last value
        a[i]=a[n-1-i];
        a[n-1-i]=b;
    }
   return n;
}
// Return the position of the first corresponding elements of a1 and a2 that are not equal.
int differ(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<0 || n2<0) // Checks for invalid input
    {
        return -1;
    }
    if(n1<=n2)
    {
        for (int i=0; i<n1; i++) // Finds the first point in the smaller array that differs
        {
            if(a1[i]!=a2[i])
            {
                return i;
            }
        }
        return n1;
    }
    else
    {
        for (int i=0; i<n2; i++) // Finds the first point in the larger array that differs
        {
            if(a1[i]!=a2[i])
            {
                return i;
            }
        }
        return n2;
    }
}
//If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins.
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
    int times=0;
    if(n1<0 || n2<0) // Checks for invalid input or if no elements
    {
        return -1;
    }
    else if(n1==0 || n2==0) // A sequence of 0 elements is a subsequence of any sequence even with no elements starting at position 0
    {
        return 0;
    }
        for (int j=0; j<=n1-n2; j++) // From position of first a2 element in a1 checks if all a2 elements present
        {
            times=0; //resets in case all elements of a2 aren't in a1
            for (int i=0; i<n2; i++)
            {
                if (a1[j+i]==a2[i]) //Slides block down and checks to see if starting position is the same
                {
                    times++;
                }
                else
                {
                    break;
                }
            }
            if(times==n2)
            {
                return j; // All of a2 elements are present
            }
        }
    //cerr <<"Times"<<endl;
    //cerr<<"POS "<<pos<<endl;
    //cerr<<times<<endl;
    return -1;
   }
//Return the smallest position in a1 of an element that is equal to any of the elements in a2.
int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
    if(n1<0 || n2<0) // Checks for invalid input
    {
        return -1;
    }
    else if(n1==0 && n2==0)
    {
        return 0;
    }
    for (int i=0; i<n1; i++)
    {
        for (int j=0; j<n2; j++) // Checks for first element of a2 in a1
        {
           if(a1[i]==a2[j])
           {
               return i;
           }
        }
    }
    return -1; // No element found
}
// Rearrange the elements of the array so that all the elements whose value is < splitter come before all the other elements, and all the elements whose value is > splitter come after all the other elements.
int split(string a[], int n, string splitter)
{
    string temp=""; //temp variable to
    int j=0;
    string b[325000]={}; // Magic number because can't set to n
    
    if(n<0) // Checks for invalid input
    {
        return -1;
    }
    for (int i=0; i<n; i++)
    {
        if (a[i]<splitter)
        {
            temp=a[i]; // Initializes beginning of b to values less than splitter
            b[j]=temp;
            //cerr <<a[i]<<endl;
            j++;
        }
    }
    for (int i=0; i<n; i++)
    {
         if(a[i]>=splitter) // Initializes next part of b to values greater than or equal to splitter
        {
            temp=a[i];
            //cerr <<a[i]<<endl;
            b[j]=temp;
            j++;
        }
    }
    //cerr << "Array: "<<getArray(b, 6);
    for (int i=0; i<n; i++) //sets array to temporary array
    {
        a[i]=b[i];
    }
    for (int i=0; i<n; i++)
    {
        if(a[i]>=splitter)
        {
            //cerr <<"Reached"<<endl;
            return i;
        }
    }
    return n;
}