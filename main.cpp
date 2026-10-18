#include <iostream>
#include "Character.h"

int main(){
    Character Knight("Knight",200,25);
    Character Dark_Mage("Dark Mage",120,50);

    bool alternateTurn = true;

    while (Knight.isAlive() && Dark_Mage.isAlive()){
        Knight.displayStats();
        Dark_Mage.displayStats();

        if (alternateTurn){
            Knight.attack(Dark_Mage);
        }
        else{
            Dark_Mage.attack(Knight);
        }
        alternateTurn = !alternateTurn;
    }

    if (Knight.isAlive()){
        std::cout << "The Knight is the ultimate victor" << std::endl;
    }
    else if (Dark_Mage.isAlive()){
        std::cout << "The Dark Mage is the ultimate victor" << std::endl;
    }

}