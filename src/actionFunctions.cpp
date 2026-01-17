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
* <file with action function implementations>
*
*/

#include "actionFunctions.h"
#include "printFunctions.h"
#include "validators.h"
#include "helpers.h"
#include "fileHandlers.h"


int getMainMenuChoice()
{
    printMainMenu();
    return validateMenuChoice();
}

int chooseDifficulty()
{
    printDifficultyChoices();
    return validateInput(EASY, HARD);
}

int chooseAction()
{
    printActionChoices();
    return validateActionChoice();
}

int chooseStudyOption()
{
    printStudyChoices();
    return validateInput(MIN_ACTION, MAX_STUDY_ACTION);
}

int chooseEatingOption()
{
    printEatingChoices();
    return validateInput(MIN_ACTION, MAX_EAT_ACTION);
}

int choosePartyOption()
{
    printPartyChoices();
    return validateInput(MIN_ACTION, MAX_PARTY_ACTION);
}

int chooseRestOption()
{
    printRestChoices();
    return validateInput(MIN_ACTION, MAX_REST_ACTION);
}

int chooseWorkOption()
{
    printWorkChoices();
    return validateInput(MIN_ACTION, MAX_WORK_ACTION);
}

int chooseReturnOption()
{
    printReturnChoices();
    return validateReturnChoice();
}

bool study(Player* player, int& studyType)
{
    studyType = chooseStudyOption();
    bool isSuccessful = false;

    switch (studyType)
    {
    case 1:
        isSuccessful = applyEffects(player, COST_ARR[0], COST_ARR[3],
            COST_ARR[3], GAIN_ARR[4]);
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
    case 10:
        return false;
        break;
    default:
        break;
    }
    return isSuccessful;
}

bool eat(Player* player, int& eatType)
{
    eatType = chooseEatingOption();
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

bool party(Player* player, int& partyType)
{
    partyType = choosePartyOption();
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

bool rest(Player* player, int& restType)
{
    restType = chooseRestOption();
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

bool work(Player* player, int& workType)
{
    workType = chooseWorkOption();
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

    printStatChange(moneyChange, energyChange, psycheChange, knowledgeChange);

    if (!player->energy)
        player->skipNextDay = true;
    return true;
}

