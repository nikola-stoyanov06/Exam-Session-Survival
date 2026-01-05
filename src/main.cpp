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

const int MIN_ACTION = 1, MAX_ACTION = 5;

const int EXIT_CODE = 11;

const int EASY_KNOWLEDGE = 70, MID_KNOWLEDGE = 50, HARD_KNOWLEDGE = 35;
const int EASY_STAT = 100, MID_STAT = 80, HARD_STAT = 50;

const int EXAM_COUNT = 5;

const int SCHEDULE[EXAM_COUNT] = {8, 17, 26, 0, 45};

const int LINE_WIDTH = 35;

const int SESSION_LENGTH = 45;

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
        if (input == EXIT_CODE)
        {
            return EXIT_CODE;
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

void printDifficultyChoices()
{
    std::cout << "Choose difficulty: " << std::endl;
    std::cout << "[1] Easy" << std::endl;
    std::cout << "[2] Normal" << std::endl;
    std::cout << "[3] Hard" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[11] Exit Game" << std::endl;
    std::cout << "> ";
}

int chooseDifficulty()
{
    printDifficultyChoices();
    return validateInput(EASY, HARD);
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
    std::cout << "[11] Exit Game" << std::endl;
    std::cout << "> ";
}

int chooseAction()
{
    printActionChoices();
    return validateInput(MIN_ACTION, MAX_ACTION);
}

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

int getLength(const char* str)
{
    int res = 0;
    if (!str)
        return res;

    while (*str)
    {
        res++;
        str++;
    }
    return res;
}

int getLength(int num)
{
    int res = 0;
    do
    {
        num /= 10;
        res++;
    } while (num);
    return res;
}

void printStatLine(const char* label, int value)
{
    if (!label)
        return;

    int index = 0;
    std::cout << "| ";
    index += 2;
    std::cout << label << ": ";
    index += (getLength(label) + 2);
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

void gameLoop(Player* player, int* examSchedule)
{
    bool isRunning = true;
    while (isRunning)
    {
        printPlayerStats(player);
        int action = chooseAction();
        switch (action)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                std::cout << "Action chosen. Not yet implemented" << std::endl;
                break;
            case 11:
                std::cout << "Exiting..." << std::endl;
                isRunning = false;
                break;
            default:
                std::cout << "Incorrect action" << std::endl;
                break;
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
    srand(time(nullptr));

    Player player;
    int examSchedule[EXAM_COUNT];

    int diff = chooseDifficulty();
    if (diff == EXIT_CODE)
        return 0;

    createPlayer(&player, diff);

    generateExamSchedule(examSchedule, EXAM_COUNT);

    gameLoop(&player, examSchedule);
}