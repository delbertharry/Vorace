// Vorace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int InputArray[5] = { 3,4,1,6,2 };
const int START = 0;
const int MAXLIST = sizeof(InputArray)/sizeof(START);

std::string output; 

std::string AGauche(int index, int key)
{
    int CurrentIndex = index;

    --index;
    if ((index >= START) && (InputArray[index] <= key))
    {
        //output = output + std::to_string(InputArray[index]);
        output = output + AGauche(index, key);
        //AGauche(index, key);
    }
    else
    {
        index = CurrentIndex;
    }

    return std::to_string(InputArray[index]);
}

std::string ADroigt(int index, int key)
{
    int CurrentIndex = index;

    ++index;
    if ((index >= START)  && (InputArray[index] <= key))
    {
        //output = output + std::to_string(InputArray[index]);
        output = output + ADroigt(index, key);
    }
    else
    {
        index = CurrentIndex;
    }
    return std::to_string(InputArray[index]);
}

std::string Vorace(int index)
{
    if (index >= START)
    {
        //output + std::to_string(InputArray[index]);
        output = AGauche(index, InputArray[index]);
    }
    
    if (index <= MAXLIST)
    {
        //output + std::to_string(InputArray[index]);
       output =  ADroigt(index, InputArray[index]);
    }

    /*return std::string("");*/
    return std::to_string(InputArray[index]);
}


int main()
{
    for (int i = START; i <= MAXLIST; i++)
    {
        output = output + Vorace(i);
        std::cout << output << std::endl;
        output = std::string("");
    }
    std::cout << "Hello World!\n";
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
