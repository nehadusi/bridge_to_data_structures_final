#ifndef BATTLESYSTEM_H
#define BATTLESYSTEM_H

#include <string>

#include "Pokemon.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

class BattleSystem
{
private:

    Queue battleQueue;

    Stack battleHistory;

    int calculateDamage(
        const Pokemon & attacker,
        const Pokemon & defender);

    void recordBattleAction(
        const string & action);

public:

    BattleSystem();

    void startBattle(
        Pokemon playerPokemon,
        Pokemon enemyPokemon);

    void displayBattleHistory();
};

#endif