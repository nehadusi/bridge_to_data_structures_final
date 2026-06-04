#include <iostream>
#include "Pokemon.h"

using namespace std;

Pokemon::Pokemon()
{
    name = "";
    type = "";
    hp = 0;
    attack = 0;
    defense = 0;
    speed = 0;
}

Pokemon::Pokemon(string newName,
                 string newType,
                 int newHp,
                 int newAttack,
                 int newDefense,
                 int newSpeed)
{
    name = newName;
    type = newType;
    hp = newHp;
    attack = newAttack;
    defense = newDefense;
    speed = newSpeed;
}

string Pokemon::getName() const
{
    return name;
}

string Pokemon::getType() const
{
    return type;
}

int Pokemon::getHp() const
{
    return hp;
}

int Pokemon::getAttack() const
{
    return attack;
}

int Pokemon::getDefense() const
{
    return defense;
}

int Pokemon::getSpeed() const
{
    return speed;
}

void Pokemon::setHp(int newHp)
{
    hp = newHp;
}

void Pokemon::displayPokemon() const
{
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Type: " << type << endl;
    cout << "HP: " << hp << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Speed: " << speed << endl;
}