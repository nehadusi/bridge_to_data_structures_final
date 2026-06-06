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

    bool lastPlayerWon;

    int turnNumber;

    int calculateDamage(const Pokemon & attacker,
                        const Pokemon & defender);

    void recordBattleAction(const string & action);

    void clearQueue();

public:

    BattleSystem();

    void startBattle(Pokemon playerPokemon,
                     Pokemon enemyPokemon);

    bool getLastPlayerWon() const;

    void displayBattleHistory();
};

#endif
