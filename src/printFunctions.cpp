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
* <file with print function implementations>
*
*/


#include "printFunctions.h"
#include "helpers.h"
#include "iostream"

void printMainMenu()
{
    std::cout << std::endl;
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
    std::cout << std::endl;
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
    std::cout << std::endl;
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
    std::cout << std::endl;
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
    std::cout << std::endl;
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
    std::cout << std::endl;
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
    std::cout << std::endl;
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
    std::cout << std::endl;
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
    std::cout << std::endl;
    std::cout << "Leaving game. Do you wish to save progress?" << std::endl;
    std::cout << "[1] Yes" << std::endl;
    std::cout << "[2] No" << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

void printStatLine(const char* label, const int value)
{
    if (!label)
        return;

    int index = 0;
    std::cout << "| ";
    index += 2;
    std::cout << label << ": ";
    index += (myStrLen(label) + 2);
    std::cout << value;
    if (value < 0)
        index++;
    index += getLength(value);
    while (index < LINE_WIDTH - 1)
    {
        std::cout << " ";
        index++;
    }
    std::cout << "|" << std::endl;
}

void printStringLine(const char* label)
{
    if (!label)
        return;

    int index = 0;
    std::cout << "| ";
    index += 2;
    std::cout << label;
    index += myStrLen(label);
    while (index < LINE_WIDTH - 1)
    {
        std::cout << " ";
        index++;
    }
    std::cout << "|" << std::endl;
}

void printPlayerStats(const Player* player)
{
    std::cout << std::endl;
    std::cout << "===================================" << std::endl;

    printStringLine("PLAYER CONDITION");
    printStringLine(" ");

    printStatLine("Current Day", player->currentDay);
    printStatLine("Money", player->money);
    printStatLine("Energy", player->energy);
    printStatLine("Psyche", player->psyche);
    printStatLine("Knowledge", player->knowledge);
    printStatLine("Exams passed", player->passedExams);

    printStringLine(" ");
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;
}

void printStatChange(const int moneyChange, const int energyChange,
    const int psycheChange, const int knowledgeChange)
{
    std::cout << std::endl;
    std::cout << "===================================" << std::endl;
    printStringLine("STAT CHANGES");
    printStringLine(" ");
    printStatLine("Money", moneyChange);
    printStatLine("Energy", energyChange);
    printStatLine("Psyche", psycheChange);
    printStatLine("Knowledge", knowledgeChange);
    printStringLine(" ");
    std::cout << "===================================" << std::endl;
    std::cout << std::endl;
}

void printFailMessage(const Player* player, const char* message)
{
    std::cout << std::endl;
    std::cout << "===================================" << std::endl;
    printStringLine("EXAM SESSION FAILED");
    printStringLine(" ");
    printStringLine(message);
    printStatLine("Exams passeed", player->passedExams);
    printStringLine(" ");
    std::cout << "===================================" << std::endl;
}

void printEndMessage(const Player* player)
{
    std::cout << std::endl;
    std::cout << "===================================" << std::endl;
    printStringLine(" ");
    if (player->passedExams <= 1)
        printStringLine("YOU FAILED AND DROPPED OUT!");
    else if (player->passedExams <= 4)
        printStringLine("YOU'LL GET THEM SOME DAY!");
    else if (player->passedExams == 4)
        printStringLine("YOU NAILED THE SESSION!");

    printStatLine("Exams passeed", player->passedExams);
    printStatLine("Final knowlege", player->knowledge);
    printStringLine(" ");
    std::cout << "===================================" << std::endl;
}