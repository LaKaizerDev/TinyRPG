#include <iostream>
#include "Character.h"

std::string Character::getName() const{
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getAttackDamage() const {
    return attkDamage;
}

void Character::setName(std::string name){
    this->name = name;
}

void Character::setAttackDamage (int attkDamage){
    this->attkDamage = attkDamage;
}

void Character::displayStats() const {
    std::cout << "===== Character Details =====" << std::endl;
    std::cout << "Character Name: " << name << std::endl;
    std::cout << "Character Health (" << health << "/" << totalHealth << "): " << std::endl;
    healthBarMaker();
    std::cout << "Character Attack Damage: " << attkDamage << std::endl;
}

void Character::takeDamage (int damage){
    if (damage<0){
        std::cout << "Invalid Damage" << std::endl;
    }
    else{
        this->health = (health-damage >= 0) ? (health-damage) : (0);
    }
}

bool Character::isAlive() const {
    if(health > 0)
        return true;
    else
        return false;
}

void Character::healthBarMaker() const {
    int fullSection = (static_cast<float>(health)/totalHealth)*10;
    int emptyStection = 10 - fullSection;

    std::cout << "  [";
    for(int i=0; i<fullSection; i++){
        std::cout << "=";
    }
    for (int i=0;i<emptyStection;i++){
        std::cout << " ";
    }
    std::cout << "]" << std::endl;

}

void Character::attack(Character& enemy){
    enemy.takeDamage(this->attkDamage);
    std::cout << "The " << this->name << " attacks the " << enemy.name << std::endl;
}