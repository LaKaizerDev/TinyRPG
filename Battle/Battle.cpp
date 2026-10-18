#include <iostream>
#include <random>
#include "Battle.h"

int coinFlip(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> coin(0,1);
    return coin(gen);
}

BattleResult battle(Character& player, Character& enemy){
    BattleResult outcome = BattleResult::None;

    //Initial introduction for player
    std::cout << "In a dark plain, the battle begins." << std::endl;
    std::cout << "You come face to face with a Dark Mage" << std::endl;
    std::cout << "=====Let the Battle Begin=====" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Your Stats: " << std::endl;
    player.displayStats();
    std::cout << "The Mage's Stats: " << std::endl;
    enemy.displayStats();
    std::cout << "" << std::endl;
    std::cout << "Press any button to continue to battle" << std::endl;
    std::cin.get();
    clearScreen();

    
    
    //Battle Loop
    while(player.isAlive() && enemy.isAlive()){
        std::cout << "Please click any button to start your turn." << std::endl;
        std::cin.get();
        bool enemyTurn = false;
        int choice = battleMenu();
        clearScreen();
        switch(choice){
            case 1:
                player.attack(enemy);
                enemyTurn = true;
                break;
            
            case 2:
                player.toggleBlock();
                enemyTurn = true;
                break;
            
            case 3:
                player.displayStats();
                std::cout << "" << std::endl;
                enemy.displayStats();
                std::cout << "Press any button to continue to battle" << std::endl;
                std::cin.get();
                clearScreen();
                break;

            case 4:
                if (coinFlip()){
                    outcome = BattleResult::Retreat;
                }
                else{
                    std::cout << "You tried to flee, but to no avail." << std::endl;
                    enemyTurn = true;
                }
                break; 
        }

        if (outcome == BattleResult::Retreat){
            break;
        }

        if (enemy.isAlive() && enemyTurn){
            enemy.attack(player);
            enemyTurn = false;
        }

        player.displayStats();
        enemy.displayStats();
    }

    if (outcome == BattleResult::Retreat){
        return BattleResult::Retreat;
    }
    else if (player.isAlive()){
        return BattleResult::Victory;
    }
    else{
        return BattleResult::Defeat;
    }
}

int battleMenu(){
    int playerChoice;

    while (true){
        std::cout << "===== Player Actions =====" << std::endl;
        std::cout << "1. Attack" << std::endl;
        std::cout << "2. Block" << std::endl;
        std::cout << "3. View Your Stats" << std::endl;
        std::cout << "4. Flee" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Enter Your Choice: " << std::endl;
        std::cin >> playerChoice;

        if ((!std::cin) || (playerChoice>4) || (playerChoice<1)){
            std::cout << "Please only enter numbers in the given range." << std::endl;
            std::cin.clear();
            std::cin.ignore(100000, '\n');
        }
        else{
            std::cin.ignore(100000, '\n');
            break;
        }
    }
    return playerChoice;
}

void clearScreen(){
    std::cout << "\033[2J\033[H" << std::flush;
}

