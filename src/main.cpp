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

const int EASY_KNOWLEDGE = 70, MID_KNOWLEDGE = 50, HARD_KNOWLEDGE = 35;
const int EASY_STAT = 100, MID_STAT = 80, HARD_STAT = 50;

const int EXAM_COUNT = 5;

const int SCHEDULE[EXAM_COUNT] = {8, 17, 26, 0, 45};
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
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid input! Try again: > ";
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

void createPlayer(Player* player, int diff)
{
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

int randNumInRange(int min, int max)
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

void printPlayerStats(const Player* player) {
    std::cout << "================================" << std::endl;

    std::cout << "| PLAYER CONDITION             |" << std::endl;
    std::cout << "|                              |" << std::endl;

    std::cout << "| Current Day:    " << player->currentDay;
    std::cout << "            |" << std::endl;

    std::cout << "| Money:         " << player->money;
    std::cout << "            |" << std::endl;

    std::cout << "| Energy:        " << player->energy;
    std::cout << "            |" << std::endl;

    std::cout << "| Psyche:        " << player->psyche;
    std::cout << "            |" << std::endl;

    std::cout << "| Knowledge:     " << player->knowledge;
    std::cout << "            |" << std::endl;

    std::cout << "| Exams Passed:  " << player->passedExams << " / " << EXAM_COUNT;
    std::cout << "         |" << std::endl;

    std::cout << "================================" << std::endl;
}


int main()
{
    srand(time(nullptr));

    Player player;
    int examSchedule[EXAM_COUNT];

    int diff = chooseDifficulty();

    createPlayer(&player, diff);

    generateExamSchedule(examSchedule, EXAM_COUNT);

    printPlayerStats(&player);
}