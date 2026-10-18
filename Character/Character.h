#pragma once
#include <string>

class Character{
    private:
        std::string name;
        int attkDamage;
        int health;
        int const totalHealth;
    
    public:
        Character(std::string name, int health, int attkDamage) : name(name), health(health), attkDamage(attkDamage) , totalHealth(health) {}

       std::string getName() const;

       int getHealth() const;

       int getAttackDamage() const;

       void setName(std::string name);

       void setAttackDamage (int attkDamage);

       void displayStats() const;

       void takeDamage (int damage);

       bool isAlive() const ;

       void attack(Character& enemy);

       void healthBarMaker() const;

};
