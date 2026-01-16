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
* <file with action function definitions>
*
*/

#ifndef ACTIONFUNCTIONS_H
#define ACTIONFUNCTIONS_H
#include "constants.h"

int getMainMenuChoice();
int chooseDifficulty();
int chooseAction();
int chooseStudyOption();
int chooseEatingOption();
int choosePartyOption();
int chooseRestOption();
int chooseWorkOption();
int chooseReturnOption();

bool study(Player* player, int& studyType);
bool eat(Player* player, int& eatType);
bool party(Player* player, int& partyType);
bool rest(Player* player, int& restType);
bool work(Player* player, int& workType);

bool applyEffects(Player* player, const int moneyChange, const int energyChange,
	const int psycheChange, const int knowledgeChange);

#endif