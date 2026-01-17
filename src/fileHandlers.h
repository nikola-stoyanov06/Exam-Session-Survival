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
* <file with file handling function definitions>
*
*/

#ifndef FILEHANDLERS_H
#define FILEHANDLERS_H
#include "constants.h"

bool loadGame(Player* player, int examSchedule[], char* username, int& diff);

bool saveGame(Player* player, const int examSchedule[], const char* username, const int diff);

#endif