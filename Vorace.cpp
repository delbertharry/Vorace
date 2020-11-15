// Vorace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int InputArray[5] = { 3,4,1,6,2 };
const int START = 0;
const int MAXLIST = sizeof(InputArray)/sizeof(START);

std::string output; 

void AGauche(int index, int key, int &count)
{
    int CurrentIndex = index;

    --index;
    if ((index >= START) && (InputArray[index] <= key))
    {
        AGauche(index, key, count);
        ++count;
    }
    else
    {
        index = CurrentIndex;
    }
}

void ADroigt(int index, int key, int& count)
{
    int CurrentIndex = index;

    ++index;
    if ((index < MAXLIST)  && (InputArray[index] <= key))
    {
        ADroigt(index, key, count);
        ++count;
    }
    else
    {
        index = CurrentIndex;
    }
}

int  Vorace(int index)
{
    int count = 1;

    if (index >= START)
    {
        AGauche(index, InputArray[index], count);
    }
    
    if (index <= MAXLIST)
    {
       ADroigt(index, InputArray[index], count);
    }

    /*return std::string("");*/
    return count;
}


int main()
{
    for (int i = START; i <= MAXLIST; i++)
    {
       std::cout << std::to_string(Vorace(i)) << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
