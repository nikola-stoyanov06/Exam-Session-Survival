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
* <file with print function implementations>
*
*/


#include "printFunctions.h"
#include "helpers.h"
#include "iostream"

void printMainMenu()
{
    std::cout << "===================================" << std::endl;
    std::cout << "|      EXAM SESSION SURVIVAL      |" << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;
    std::cout << "[1] New Game" << std::endl;
    std::cout << "[2] Load Game" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[11] Exit" << std::endl;
    std::cout << "> ";
}

void printDifficultyChoices()
{
    std::cout << "Choose difficulty: " << std::endl;
    std::cout << "[1] Easy" << std::endl;
    std::cout << "[2] Normal" << std::endl;
    std::cout << "[3] Hard" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

void printActionChoices()
{
    std::cout << "Please Choose an Action:  " << std::endl;
    std::cout << "[1] Study" << std::endl;
    std::cout << "[2] Eat" << std::endl;
    std::cout << "[3] Go Out" << std::endl;
    std::cout << "[4] Rest" << std::endl;
    std::cout << "[5] Work" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[9] Save Game" << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

void printStudyChoices()
{
    std::cout << "Please Choose Your Way to Study:  " << std::endl;
    std::cout << "[1] Go to the lectures" << std::endl;
    std::cout << "[2] Study at home" << std::endl;
    std::cout << "[3] Study with friends" << std::endl;
    std::cout << "[4] Study at library/cafe" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

void printEatingChoices()
{
    std::cout << "Please Choose Your Meal:  " << std::endl;
    std::cout << "[1] Ramen" << std::endl;
    std::cout << "[2] Doner" << std::endl;
    std::cout << "[3] KFC" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

void printPartyChoices()
{
    std::cout << "Please Choose Where to Go Out With Friends:  " << std::endl;
    std::cout << "[1] Studentski Stol 33" << std::endl;
    std::cout << "[2] The Cinema" << std::endl;
    std::cout << "[3] Club 33" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

void printRestChoices()
{
    std::cout << "Please Choose How to Sleep  " << std::endl;
    std::cout << "[1] A 5-min nap" << std::endl;
    std::cout << "[2] Watch reels/tiktok" << std::endl;
    std::cout << "[3] Pass out completely" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

void printWorkChoices()
{
    std::cout << "Please Choose Your Preffered Type of Work:  " << std::endl;
    std::cout << "[1] Tutor your nephew" << std::endl;
    std::cout << "[2] Do some freelance" << std::endl;
    std::cout << "[3] McDonalds is hiring" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

void printReturnChoices()
{
    std::cout << "Leaving game. Do you wish to save progress?" << std::endl;
    std::cout << "[1] Yes" << std::endl;
    std::cout << "[2] No" << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

void printStatLine(const char* label, int value)
{
    if (!label)
        return;

    int index = 0;
    std::cout << "| ";
    index += 2;
    std::cout << label << ": ";
    index += (myStrLen(label) + 2);
    std::cout << value;
    index += getLength(value);
    while (index < LINE_WIDTH - 1)
    {
        std::cout << " ";
        index++;
    }
    std::cout << "|" << std::endl;
}

void printPlayerStats(const Player* player)
{
    std::cout << "===================================" << std::endl;

    std::cout << "| PLAYER CONDITION                |" << std::endl;
    std::cout << "|                                 |" << std::endl;

    printStatLine("Current Day", player->currentDay);
    printStatLine("Money", player->money);
    printStatLine("Energy", player->energy);
    printStatLine("Psyche", player->psyche);
    printStatLine("Knowledge", player->knowledge);
    printStatLine("Exams passed", player->passedExams);

    std::cout << "===================================" << std::endl;
    std::cout << std::endl;
}