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
#include <fstream>
#include <cstring>
#include "constants.h"
#include "printFunctions.h"
#include "helpers.h"
#include "actionFunctions.h"
#include "validators.h"

void createPlayer(Player* player, int diff)
{
    if (!player)
        return;

    player->passedExams = 0;
    player->currentDay = 1;
    player->skipNextDay = false;

    switch (diff)
    {
        case 1:
            player->knowledge = EASY_KNOWLEDGE;
            player->money = EASY_STAT;
            player->energy = EASY_STAT;
            player->psyche = EASY_STAT;
            break;
        case 2:
            player->knowledge = MID_KNOWLEDGE;
            player->money = MID_STAT;
            player->energy = MID_STAT;
            player->psyche = MID_STAT;
            break;
        case 3:
            player->knowledge = HARD_KNOWLEDGE;
            player->money = HARD_STAT;
            player->energy = HARD_STAT;
            player->psyche = HARD_STAT;
            break;
        default:
            std::cout << "Error in creating player: Incorrect difficulty";
            break;
    }
}

int randNumInRange(const int min, const int max)
{
    return min + rand() % (max - min + 1);
}

void generateExamSchedule(int arr[], int count)
{
    arr[0] = SCHEDULE[0];
    arr[1] = SCHEDULE[1];
    arr[2] = SCHEDULE[2];
    arr[3] = randNumInRange(SCHEDULE[2] + 1, SCHEDULE[4] - 1);
    arr[4] = SCHEDULE[4];
}

int getExamIndex(const int* arr, int currentDay)
{
    for (int i = 0; i < EXAM_COUNT; i++)
    {
        if (*arr == currentDay)
            return i;

        arr++;
    }

    return -1;
}

bool takeExam(Player* player, int index)
{
    if (player->energy <= EXAM_ENERGY_COST)
        return false;
    int luckFactor = randNumInRange(0, 100);
    int difficultyFactor = (index - 1) * 5;
    double successRate = player->knowledge * 0.75 + player->energy * 0.1 + player->psyche * 0.1
        + luckFactor * 0.2 - difficultyFactor;

    return successRate >= 75;
}

void applyExamChanges(Player* player, bool result)
{
    player->energy -= EXAM_ENERGY_COST;
    player->energy = keepInRange(MIN_STAT, MAX_STAT, player->energy);

    if (!player->energy)
        player->skipNextDay = true;
}

bool isStillPlaying(Player* player)
{
    if (player->energy <= MIN_STAT)
    {
        player->skipNextDay = true;
    }
    if (player->money <= MIN_STAT)
    {
        std::cout << "You've gone bankrupt!";
        return false;
    }
    if (player->psyche <= MIN_STAT)
    {
        std::cout << "You have gone crazy and have left FMI.";
        return false;
    }
    return true;
}
void skipDay(Player* player)
{
    std::cout << "You have tried too hard. You'll sleep it off tomorrow!" << std::endl;
    std::cout << std::endl;
    player->skipNextDay = false;
    player->currentDay++;
    player->energy += 5;
    player->energy = keepInRange(MIN_STAT, MAX_STAT, player->energy);
}

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

void gameLoop(Player* player, const int* examSchedule, const char* username, int diff)
{
    if (!examSchedule || !username)
        return;

    bool isRunning = true;
    while (isRunning)
    {
        printPlayerStats(player);

        bool isPlaying = isStillPlaying(player);

        if (!isPlaying)
        {
            isRunning = false;
            continue;
        }

        if (player->skipNextDay)
        {
            skipDay(player);
            continue;
        }
        
        bool isSuccessful = false;

        int index = getExamIndex(examSchedule, player->currentDay);

        if (index != -1)
        {
            std::cout << "Exam day!" << std::endl;
            std::cout << "Good luck with your result!" << std::endl;
            std::cout << std::endl;
           
            bool isTaken = takeExam(player, index);
            isSuccessful = true;
            if (!isTaken)
            {
                player->psyche -= EXAM_PSYCHE_PENALTY;
                player->psyche = keepInRange(MIN_STAT, MAX_STAT, player->energy);
            }
            else
            {
                player->passedExams++;
            }

            applyExamChanges(player, isTaken);
        }
        while (!isSuccessful)
        {
            int action = chooseAction();
            switch (action)
            {
                case 1:
                    isSuccessful = study(player);
                    break;
                case 2:
                    isSuccessful = eat(player);
                    break;
                case 3:
                    isSuccessful = party(player);
                    break;
                case 4:
                    isSuccessful = rest(player);
                    break;
                case 5:
                    isSuccessful = work(player);
                    break;
                case 9:
                    if (saveGame(player, examSchedule, username, diff))
                        std::cout << "Successfully saved to " << username << std::endl;
                    printPlayerStats(player);
                    isSuccessful = false;
                    break;
                case 10:
                {
                    int choice = chooseReturnOption();
                    if (choice == RETURN_CODE)
                    {
                        isSuccessful = false;
                        break;
                    }
                    if (choice == MIN_ACTION)
                    {
                        if (saveGame(player, examSchedule, username, diff))
                        {
                            std::cout << "Successfully saved to " << username << std::endl;
                            std::cout << std::endl;
                        }
                    }
                    isSuccessful = true;
                    isRunning = false;
                    break;
                }
                default:
                    std::cout << "Incorrect action" << std::endl;
                    break;
            }
        }
        

        player->currentDay++;
        if (player->currentDay > SESSION_LENGTH)
        {
            std::cout << "Session end reached";
            isRunning = false;
        }
    }
}

int main()
{ 
    Player player;
    int examSchedule[EXAM_COUNT];
    char username[MAX_USERNAME_LENGTH];
    srand(time(nullptr));

    while (true)
    {
        int mainMenuChoice = getMainMenuChoice();

        if (mainMenuChoice == EXIT_CODE)
            return 0;

        if (mainMenuChoice == NEW_GAME_CODE)
        {
            int diff = chooseDifficulty();
            if (diff == RETURN_CODE)
                continue;

            createPlayer(&player, diff);
            generateExamSchedule(examSchedule, EXAM_COUNT);
            inputUserName(username);
            if (!saveGame(&player, examSchedule, username, diff))
                continue;
            gameLoop(&player, examSchedule, username, diff);
        }
        else if (mainMenuChoice == LOAD_GAME_CODE)
        {
            inputUserName(username);
            int diff;
            if (loadGame(&player, examSchedule, username, diff))
            {
                gameLoop(&player, examSchedule, username, diff);
            }
            else
            {
                std::cout << "Error loading user!" << std::endl;
                continue;
            }
        }
    }
}