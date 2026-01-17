/**
*
* Solution to course project # 11
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Nikola Stoyanov
* @idnumber 3MI0600561* @compiler VC
*
* <file with validator function implementations>
*
*/

#include "validators.h"
#include "constants.h"
#include <iostream>


int validateInput(int min, int max)
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (input == RETURN_CODE)
        {
            return input;
        }
        if (input < min || input > max || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid input! Try again: > ";
        }
        else
            return input;
    }
}

int validateMenuChoice()
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (input == EXIT_CODE)
        {
            return input;
        }

        if (input < MIN_ACTION || input > MAX_MENU_CHOICE || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid input! Try again: > ";
        }
        else
            return input;
    }
}

int validateReturnChoice()
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (input == RETURN_CODE)
        {
            return input;
        }

        if (input < MIN_ACTION || input > MAX_RETURN_CHOICE || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid input! Try again: > ";
        }
        else
            return input;
    }
}

int validateActionChoice()
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (input == RETURN_CODE)
        {
            return input;
        }
        if (input == SAVE_CODE)
        {
            return input;
        }
        if (input < MIN_ACTION || input > MAX_ACTION || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid input! Try again: > ";
        }
        else
            return input;
    }
}
