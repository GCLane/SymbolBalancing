//Author Grant Lane
//Date: 1/18/2022
//Class: IT 279
/*Implements the Stack files of Program 1 to help balance 
Symbols*/

#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

//private method that checks for case 1 either returns true or ends the program
bool symbolsMatch(Stack theStack, char sym, int line);

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cerr << "Correct usage: " << argv[0] << "<name of .txt file>" << endl;
        exit(1);
    }   


    ifstream inFile;
    inFile.open(argv[1]);

    //Check for error
    if(inFile.fail())
    {
        cerr << "File was not able to be opened" << endl;
        exit(1);
    }

    //Create a string and string list that holds all of the data from the file
    string input;
    list<string> inputList;
    
    //insert the data into the list
    while(getline(inFile, input))
        inputList.push_back(input);
    //create an iterator to navigate the list
    list<string>::const_iterator iter = inputList.begin();
    //create a stack that holds chars
    Stack charStack;
    char slash = ' ';
    char aster = ' ';
    //create an int that keeps track of the line number
    int line = 0;
    //Run a while loop through the list
    while(iter != inputList.end())
    {
        string curStr = *iter;
        //Run a for loop through each string in the list
        for(int i = 0; i < curStr.length(); i++)
        {
            //Set sym1 to the current char we're looking at
            char sym1 = curStr.at(i);
            bool test = ((sym1 == '(') || (sym1 =='[') || (sym1 == '{'));
            //cout << sym1 << " " << test << endl;
            char sym2 = ' '; //created for the comment symbol

            //Special case for checking the comment slash is actually for comments
            if(sym1 == '/' || sym1 == ' ')
            {
                slash = sym1; //runs case for when sym1 is a slash or sets it back to space when sym1 is a space
            }
            if(sym1 == '*' || sym1 == ' ')
            {
                aster = sym1; //runs case for when sym1 is a * or sets it back to space when sym1 is a space
            }

            //push the chars onto the stack if they match
            if(slash == '/' && sym1 == '*')
            {
                charStack.push(sym1);
            }
            else if((sym1 == '(') || (sym1 =='[') || (sym1 == '{'))
            {
                charStack.push(sym1);
            }

            //Comment case for checking cases and removing
            if(aster == '*' && sym1 == '/')
            {
                if(charStack.isEmpty())
                {
                    cout << aster << sym1 << " on line " << line << " has no matching opening symbol." << endl;
                    exit(1);
                }
                //Checks for if they symbols match
                if(charStack.top() == '*')
                {
                    charStack.pop();
                }
                else
                {
                    cout << charStack.top() << " does not match */ on line" << line << endl;
                    exit(1);
                }
            }
            else if((sym1 == ')') || (sym1 ==']') || (sym1 == '}')) //other case checker
            {
                //runs case 3
                if(charStack.isEmpty())
                {
                    cout << sym1 << " on line " << line << " has no matching opening symbol." << endl;
                    exit(1);
                }
                //enters the bool method symbols Match 
                if(symbolsMatch(charStack, sym1, line)) //when false case 1 will run
                {
                    charStack.pop();
                }
            }
        }
        iter++; //iterates the string list
        line++;
    }
    //checks if all symbols are correctly balanced
    if(charStack.isEmpty())
        cout << "All symbols correctly balanced." << endl;
    else //runs if chars are still in the stack case 2
        cout << "End of program reached with unmatched " << charStack.top() << endl;
    
    return 0;
}


//private symbols match method to help reduce complexity in main
bool symbolsMatch(Stack theStack, char sym, int line)
{
    bool symMatch = false; //create a bool that is automatically false
    if(sym == ')')
        symMatch = theStack.top() == '('; //goes to true if they match
    else if(sym == ']')
        symMatch = theStack.top() == '['; //goes to true if they match
    else if(sym == '}')
        symMatch = theStack.top() == '{'; // goes to true if they match
    
    if(symMatch == false) //runs case1 if false and exits the program
    {
        cout << theStack.top() << " does not match " << sym << " on line " << line << endl;
        exit(1);
    }

    return symMatch; //returns the result
}



