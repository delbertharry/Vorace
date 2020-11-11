// Vorace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


int InputArray[5] = { 3,4,1,6,2 };
std::string output; 

std::string AGauche(int index, int key)
{
    if ((index > 1) && (InputArray[index] >= key))
    {
        output = output + std::to_string(InputArray[index]);
        AGauche(--index);
    }
}

std::string ADroigt(int index, int key)
{
    if ((index < 1)  && (InputArray[index] >= key))
    {
        output = output + std::to_string(InputArray[index]);
        ADroigt(++index);
    }
}

std::string Vorace(int index)
{
    if (index > 1)
    {
        output = output + std::to_string(InputArray[index]);
        AGauche(--index, InputArray[index]);
    }
    else if (index < 5) 
    {
        output = output + std::to_string(InputArray[index]);
        ADroigt(++index, InputArray[index]);
    }
    else
    {
        //Do Nothing
    }
}


int main()
{
    for (int i = 0; i < 5; i++)
    {
        output = Vorace(i);
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
