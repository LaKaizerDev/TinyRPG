#include <iostream>
#include "Character/Character.h"
#include "Battle/Battle.h"

int main(){
    Character Knight("Knight",200,25);
    Character Dark_Mage("Dark Mage",120,50);

    BattleResult outcome = battle(Knight,Dark_Mage);

    if(outcome == BattleResult::Victory){
        std::cout << "The Player was victorious" << std::endl;
    }
    else if (outcome == BattleResult::Defeat){
        std::cout << "The Player was slain" << std::endl;
    }
    else{
        std::cout << "You managed to flee with your life" << std::endl;
    }

    return 0;

}