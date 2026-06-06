#ifndef POKEMON_H
#define POKEMON_H

#include <string>

using namespace std;

class Pokemon
{
private:

    string name;
    string type;

    int hp;
    int attack;
    int defense;
    int speed;

    int wins;
    int medals;

public:

    Pokemon();

    Pokemon(string newName,
            string newType,
            int newHp,
            int newAttack,
            int newDefense,
            int newSpeed);

    string getName() const;
    string getType() const;

    int getHp() const;
    int getAttack() const;
    int getDefense() const;
    int getSpeed() const;

    int getWins() const;
    int getMedals() const;

    void setHp(int newHp);

    void addWin();
    void addMedal();

    void displayPokemon() const;
};

#endif
