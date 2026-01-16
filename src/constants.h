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
* <file with constants>
*
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

const int EASY = 1, MEDIUM = 2, HARD = 3;

const int MIN_ACTION = 1, MAX_ACTION = 5, MAX_MENU_CHOICE = 2, MAX_STUDY_ACTION = 4, MAX_EAT_ACTION = 3,
MAX_PARTY_ACTION = 3, MAX_REST_ACTION = 3, MAX_WORK_ACTION = 3, MAX_RETURN_CHOICE = 2;

const int RANDOM_EVENT_COUNT = 16;

const int EXIT_CODE = 11, RETURN_CODE = 10,
SAVE_CODE = 9, NEW_GAME_CODE = 1, LOAD_GAME_CODE = 2;;

const int EASY_KNOWLEDGE = 70, MID_KNOWLEDGE = 50, HARD_KNOWLEDGE = 35;
const int EASY_STAT = 100, MID_STAT = 80, HARD_STAT = 50;

const int EXAM_COUNT = 5;

const int SCHEDULE[EXAM_COUNT] = { 8, 17, 26, 0, 45 };

const int LINE_WIDTH = 35;
const int MAX_USERNAME_LENGTH = 32, MAX_FILE_LENGTH = 64;

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

struct RandomEvent
{
    int actionIndex;
    int subActionIndex;
    int moneyChange;
    int energyChange;
    int psycheChange;
    int knowledgeChange;
    const char* message;
};

const RandomEvent NULL_EVENT = { 0,0,0,0,0,0,"" };

#endif