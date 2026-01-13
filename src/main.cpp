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

const int MIN_ACTION = 1, MAX_ACTION = 5, MAX_STUDY_ACTION = 4, MAX_EAT_ACTION = 3, 
    MAX_PARTY_ACTION = 3;

const int EXIT_CODE = 11, RETURN_CODE = 10;

const int EASY_KNOWLEDGE = 70, MID_KNOWLEDGE = 50, HARD_KNOWLEDGE = 35;
const int EASY_STAT = 100, MID_STAT = 80, HARD_STAT = 50;

const int EXAM_COUNT = 5;

const int SCHEDULE[EXAM_COUNT] = {8, 17, 26, 0, 45};

const int LINE_WIDTH = 35;

const int SESSION_LENGTH = 45;

const int MIN_STAT = 0, MAX_STAT = 100;

const int GAIN_ARR[] = { 0,5,10,20,25,30,40,50 };
const int COST_ARR[] = { 0,-5,-10,-20,-25,-30,-40,-50 };

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
        if (input == EXIT_CODE)
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
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "[11] Exit Game" << std::endl;
    std::cout << "> ";
}

int chooseAction()
{
    printActionChoices();
    return validateInput(MIN_ACTION, MAX_ACTION);
}

void printStudyChoices()
{
    std::cout << "Please Choose How You Plan on Studying:  " << std::endl;
    std::cout << "[1] Go to the lectures" << std::endl;
    std::cout << "[2] Study at home" << std::endl;
    std::cout << "[3] Study with friends" << std::endl;
    std::cout << "[4] Study at library/cafe" << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[] " << std::endl;
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "[11] Exit Game" << std::endl;
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
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "[11] Exit Game" << std::endl;
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
    std::cout << "[10] Go Back" << std::endl;
    std::cout << "[11] Exit Game" << std::endl;
    std::cout << "> ";
}

int choosePartyOption()
{
    printPartyChoices();
    return validateInput(MIN_ACTION, MAX_PARTY_ACTION);
}

bool applyEffects(Player* player, int moneyChange, int energyChange, int psycheChange, int knowledgeChange)
{
    if (player->knowledge + knowledgeChange < MIN_STAT)
    {
        std::cout << "You are pretty dumb, go study instead!" << std::endl;
        return false;
    }
    if (player->energy + energyChange < MIN_STAT) 
    {
        std::cout << "You are about to pass out, you need rest!" << std::endl;
        return false;
    }
    if (player->psyche + psycheChange < MIN_STAT) 
    {
        std::cout << "Do not go crazy, please! Do something fun to cheer yourself up!" << std::endl;
        return false;
    }
    if (player->money + moneyChange < MIN_STAT) 
    {
        std::cout << "Ha! You're broke! Go work, lazy!" << std::endl;
        return false;
    }

    player->knowledge += knowledgeChange;
    player->energy += energyChange;
    player->psyche += psycheChange;
    player->money += moneyChange;

    player->knowledge = keepInRange(MIN_STAT, MAX_STAT, player->knowledge);
    player->energy = keepInRange(MIN_STAT, MAX_STAT, player->energy);
    player->psyche = keepInRange(MIN_STAT, MAX_STAT, player->psyche);
    player->money = keepInRange(MIN_STAT, MAX_STAT, player->money);

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
                COST_ARR[3], GAIN_ARR[3]);
            break;
        case 2:
            isSuccessful = applyEffects(player, COST_ARR[0], COST_ARR[2],
                COST_ARR[2], GAIN_ARR[2]);
            break;
        case 3:
            isSuccessful = applyEffects(player, COST_ARR[0], COST_ARR[1],
                GAIN_ARR[1], GAIN_ARR[1]);
            break;
        case 4:
            isSuccessful = applyEffects(player, COST_ARR[1], COST_ARR[0],
                COST_ARR[1], GAIN_ARR[1]);
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
            GAIN_ARR[3], COST_ARR[0]);
        break;
    case 3:
        isSuccessful = applyEffects(player, COST_ARR[6], GAIN_ARR[5],
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
        
        bool isSuccessful = false;
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
                case 5:
                    std::cout << "Action chosen. Not yet implemented" << std::endl;
                    isSuccessful = true;
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

int main()
{
    srand(time(nullptr));

    Player player;
    int examSchedule[EXAM_COUNT];

    int diff = chooseDifficulty();
    if (diff == EXIT_CODE || diff == RETURN_CODE)
        return 0;

    createPlayer(&player, diff);

    generateExamSchedule(examSchedule, EXAM_COUNT);

    gameLoop(&player, examSchedule);
}