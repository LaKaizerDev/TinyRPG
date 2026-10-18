#pragma once
#include "../Character/Character.h"

enum class BattleResult{Victory, Defeat, Retreat, None};

BattleResult battle(Character& player, Character& enemy);

//Displays the menu and returns the choice and 
//Handles all menu errors
int battleMenu();

//Handles all the actual
//attacks,blocks,etc
void battleActionHandler(Character& player, Character& enemy);

void clearScreen();