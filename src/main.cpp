/**
*
* Solution to course project # 11
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2025/2026
*
* @author Nikola Stoyanov
* @idnumber 3MI0600561* @compiler VS
*
* <file with main function>
*
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

const int EASY = 1;
const int MEDIUM = 2;
const int HARD = 3;

struct Player {
    int money;
    int energy;
    int psyche;
    int knowledge;
    int passedExams;
    int currentDay;
    bool skipNextDay;
};


int validateInput(int min, int max)
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (input < min || input > max || std::cin.fail())
        {
            std::cout << "Invalid input! Try again!";
        }
        else
            return input;
    }
}

void printChoices()
{
    std::cout << "Choose difficulty: " << std::endl;
    std::cout << "[1] Easy" << std::endl;
    std::cout << "[2] Normal" << std::endl;
    std::cout << "[3] Hard" << std::endl;
    std::cout << "> ";
}

int chooseDifficulty()
{
    printChoices();
    return validateInput(EASY, HARD);
}


int main()
{
    chooseDifficulty();
}