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
* <file with print function definitions>
*
*/


#include "constants.h"

#ifndef PRINTFUNCTIONS_H
#define PRINTFUNCTIONS_H


void printMainMenu();
void printDifficultyChoices();
void printActionChoices();
void printStudyChoices();
void printEatingChoices();
void printPartyChoices();
void printRestChoices();
void printWorkChoices();
void printReturnChoices();
void printStatLine(const char* label, int value);
void printPlayerStats(const Player* player);


#endif