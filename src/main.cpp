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
#include "main.h"


const int EASY = 1, MEDIUM = 2, HARD = 3;

const int MIN_ACTION = 1, MAX_ACTION = 5, MAX_MENU_CHOICE = 2, MAX_STUDY_ACTION = 4, MAX_EAT_ACTION = 3,
          MAX_PARTY_ACTION = 3, MAX_REST_ACTION = 3, MAX_WORK_ACTION = 3;

const int EXIT_CODE = 11, RETURN_CODE = 10, 
    SAVE_CODE = 9, NEW_GAME_CODE = 1, LOAD_GAME_CODE = 2;;

const int EASY_KNOWLEDGE = 70, MID_KNOWLEDGE = 50, HARD_KNOWLEDGE = 35;
const int EASY_STAT = 100, MID_STAT = 80, HARD_STAT = 50;

const int EXAM_COUNT = 5;

const int SCHEDULE[EXAM_COUNT] = {8, 17, 26, 0, 45};

const int LINE_WIDTH = 35;
const int MAX_USERNAME_LENGTH = 32;

const int SESSION_LENGTH = 45;

const int MIN_STAT = 0, MAX_STAT = 100;

const int GAIN_ARR[] = { 0,5,10,20,25,30,40,50 };
const int COST_ARR[] = { 0,-5,-10,-20,-25,-30,-40,-50 };
const int EXAM_ENERGY_COST = 10, EXAM_PSYCHE_PENALTY = 20;

struct Player {
    int money;
    int energy;
    int psyche;
    int knowledge;
    int passedExams;
    int currentDay;
    bool skipNextDay;
};

int keepInRange(int min, int max, int value)
{
    if (value > max)
        return max;
    if (value < min)
        return min;

    return value;
}

int validateInput(int min, int max)
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (input == SAVE_CODE)
        {
            return input;
        }
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

int validateDifficultyChoice()
{
    int input;
    while (true)
    {
        std::cin >> input;
        if (input == RETURN_CODE)
        {
            return input;
        }

        if (input < EASY || input > HARD || std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Invalid input! Try again: > ";
        }
        else
            return input;
    }
}

void printMainMenu()
{
    std::cout << "===================================" << std::endl;
    std::cout << "| STUDENT QUEST: SESSION SURVIVAL |" << std::endl;
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

int getMainMenuChoice()
{
    printMainMenu();
    return validateMenuChoice();
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

int chooseDifficulty()
{
    printDifficultyChoices();
    return validateDifficultyChoice();
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

int chooseAction()
{
    printActionChoices();
    return validateInput(MIN_ACTION, MAX_ACTION);
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
    std::cout << "[9] Save Game" << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

int chooseStudyOption()
{
    printStudyChoices();
    return validateInput(MIN_ACTION, MAX_STUDY_ACTION);
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
    std::cout << "[9] Save Game" << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

int chooseEatingOption()
{
    printEatingChoices();
    return validateInput(MIN_ACTION, MAX_EAT_ACTION);
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
    std::cout << "[9] Save Game" << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

int choosePartyOption()
{
    printPartyChoices();
    return validateInput(MIN_ACTION, MAX_PARTY_ACTION);
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
    std::cout << "[9] Save Game" << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

int chooseRestOption()
{
    printRestChoices();
    return validateInput(MIN_ACTION, MAX_REST_ACTION);
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
    std::cout << "[9] Save Game" << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "> ";
}

int chooseWorkOption()
{
    printWorkChoices();
    return validateInput(MIN_ACTION, MAX_WORK_ACTION);
}

bool applyEffects(Player* player, const int moneyChange, const int energyChange, 
    const int psycheChange, const int knowledgeChange)
{
    player->knowledge += knowledgeChange;
    player->energy += energyChange;
    player->psyche += psycheChange;
    player->money += moneyChange;

    player->knowledge = keepInRange(MIN_STAT, MAX_STAT, player->knowledge);
    player->energy = keepInRange(MIN_STAT, MAX_STAT, player->energy);
    player->psyche = keepInRange(MIN_STAT, MAX_STAT, player->psyche);
    player->money = keepInRange(MIN_STAT, MAX_STAT, player->money);

    if (!player->energy)
        player->skipNextDay = true;
    return true;
}

bool study(Player* player)
{
    int studyType = chooseStudyOption();
    bool isSuccessful = false;

    switch (studyType)
    {
        case 1:
            isSuccessful = applyEffects(player, COST_ARR[0], COST_ARR[3],
                COST_ARR[3], GAIN_ARR[2]);
            break;
        case 2:
            isSuccessful = applyEffects(player, COST_ARR[0], COST_ARR[2],
                COST_ARR[4], GAIN_ARR[3]);
            break;
        case 3:
            isSuccessful = applyEffects(player, COST_ARR[0], COST_ARR[2],
                GAIN_ARR[2], GAIN_ARR[1]);
            break;
        case 4:
            isSuccessful = applyEffects(player, COST_ARR[2], COST_ARR[0],
                COST_ARR[1], GAIN_ARR[2]);
            break;
        case 11:
        case 10:
            return false;
            break; 
        default:
            break;
    }
    return isSuccessful;
}

bool eat(Player* player)
{
    int eatType = chooseEatingOption();
    bool isSuccessful = false;

    switch (eatType)
    {
    case 1:
        isSuccessful = applyEffects(player, COST_ARR[1], GAIN_ARR[1],
            GAIN_ARR[1], GAIN_ARR[0]);
        break;
    case 2:
        isSuccessful = applyEffects(player, COST_ARR[2], GAIN_ARR[2],
            GAIN_ARR[2], GAIN_ARR[0]);
        break;
    case 3:
        isSuccessful = applyEffects(player, COST_ARR[3], GAIN_ARR[3],
            GAIN_ARR[3], GAIN_ARR[0]);
        break;
    case 11:
    case 10:
        return false;
        break;
    default:
        break;
    }
    return isSuccessful;
}

bool party(Player* player)
{
    int partyType = choosePartyOption();
    bool isSuccessful = false;

    switch (partyType)
    {
    case 1:
        isSuccessful = applyEffects(player, COST_ARR[2], GAIN_ARR[1],
            GAIN_ARR[3], COST_ARR[0]);
        break;
    case 2:
        isSuccessful = applyEffects(player, COST_ARR[3], GAIN_ARR[2],
            GAIN_ARR[4], COST_ARR[1]);
        break;
    case 3:
        isSuccessful = applyEffects(player, COST_ARR[6], GAIN_ARR[2],
            GAIN_ARR[6], COST_ARR[4]);
        break;
    case 11:
    case 10:
        return false;
        break;
    default:
        break;
    }
    return isSuccessful;
}

bool rest(Player* player)
{
    int restType = chooseRestOption();
    bool isSuccessful = false;

    switch (restType)
    {
    case 1:
        isSuccessful = applyEffects(player, COST_ARR[0], GAIN_ARR[3],
            GAIN_ARR[2], COST_ARR[0]);
        break;
    case 2:
        isSuccessful = applyEffects(player, COST_ARR[0], GAIN_ARR[4],
            GAIN_ARR[3], COST_ARR[1]);
        break;
    case 3:
        isSuccessful = applyEffects(player, COST_ARR[0], GAIN_ARR[7],
            GAIN_ARR[3], COST_ARR[4]);
        break;
    case 11:
    case 10:
        return false;
        break;
    default:
        break;
    }
    return isSuccessful;
}

bool work(Player* player)
{
    int workType = chooseWorkOption();
    bool isSuccessful = false;

    switch (workType)
    {
    case 1:
        isSuccessful = applyEffects(player, GAIN_ARR[3], COST_ARR[2],
            COST_ARR[2], GAIN_ARR[1]);
        break;
    case 2:
        isSuccessful = applyEffects(player, GAIN_ARR[4], COST_ARR[4],
            COST_ARR[4], GAIN_ARR[1]);
        break;
    case 3:
        isSuccessful = applyEffects(player, GAIN_ARR[6], COST_ARR[6],
            COST_ARR[5], GAIN_ARR[1]);
        break;
    case 11:
    case 10:
        return false;
        break;
    default:
        break;
    }
    return isSuccessful;
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

int getExamIndex(const int* arr, int currentDay)
{
    for (size_t i = 0; i < EXAM_COUNT; i++)
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
    int successRate = player->knowledge * 0.75 + player->energy * 0.1 + player->psyche * 0.1
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

void gameLoop(Player* player, int* examSchedule)
{
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
                case 10:
                case 11:
                    std::cout << "Exiting..." << std::endl;
                    isSuccessful = true;
                    isRunning = false;
                    break;
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

void inputUserName(char name[])
{
    std::cin.ignore(100, '\n');
    std::cout << "Enter username: ";
    std::cin >> name;
}

bool loadGame()
{
    return true;
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
            gameLoop(&player, examSchedule);
            break;
        }
        else if (mainMenuChoice == LOAD_GAME_CODE)
        {
            inputUserName(username);
            
            if (loadGame())
            {
                gameLoop(&player, examSchedule);
                break;
            }
            else
            {
                std::cout << "Error loading user!" << std::endl;
                continue;
            }
        }
    }
}