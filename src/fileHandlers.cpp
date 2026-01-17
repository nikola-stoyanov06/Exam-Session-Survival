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
* <file with file handling function implementations>
*
*/

#include "fileHandlers.h"
#include "helpers.h"
#include <fstream>
#include <iostream>

bool saveGame(Player* player, const int examSchedule[], const char* username, const int diff)
{
    if (!player || !username)
        return false;

    char fileName[MAX_FILE_LENGTH];
    myStrCopy(fileName, "saves/");
    myStrCat(fileName, username);
    myStrCat(fileName, ".txt");

    std::ofstream file(fileName);
    if (!file.is_open())
    {
        std::cout << "Failed to save game." << std::endl;
        return false;
    }

    file << username << std::endl;
    file << diff << std::endl;
    file << player->currentDay << std::endl;
    file << player->passedExams << std::endl;
    file << player->money << std::endl;
    file << player->energy << std::endl;
    file << player->psyche << std::endl;
    file << player->knowledge << std::endl;

    for (int i = 0; i < EXAM_COUNT; i++)
        file << examSchedule[i] << " ";

    file.close();
    return true;
}

bool loadGame(Player* player, int examSchedule[], char* username, int& diff)
{
    if (!player || !username)
        return false;


    char fileName[MAX_FILE_LENGTH];
    myStrCopy(fileName, "saves/");
    myStrCat(fileName, username);
    myStrCat(fileName, ".txt");

    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cout << "Save file not found." << std::endl;
        return false;
    }

    char loadedName[MAX_USERNAME_LENGTH];
    file.getline(loadedName, MAX_USERNAME_LENGTH);

    file >> diff;
    file >> player->currentDay;
    file >> player->passedExams;
    file >> player->money;
    file >> player->energy;
    file >> player->psyche;
    file >> player->knowledge;
    player->skipNextDay = false;

    for (int i = 0; i < EXAM_COUNT; i++)
        file >> examSchedule[i];

    return true;
    file.close();
}
