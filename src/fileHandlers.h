#ifndef FILEHANDLERS_H
#define FILEHANDLERS_H
#include "constants.h"

bool loadGame(Player* player, int examSchedule[], char* username, int& diff);

bool saveGame(Player* player, const int examSchedule[], const char* username, const int diff);

#endif