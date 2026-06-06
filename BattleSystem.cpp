#include <iostream>
#include <string>

#include "BattleSystem.h"

using namespace std;

BattleSystem::BattleSystem()
{
    lastPlayerWon = false;
    turnNumber = 1;
}

int BattleSystem::calculateDamage(const Pokemon & attacker,
                                  const Pokemon & defender)
{
    int damage = attacker.getAttack() - defender.getDefense();

    if (damage < 1)
    {
        damage = 1;
    }

    return damage;
}

void BattleSystem::recordBattleAction(const string & action)
{
    battleHistory.push(action);
}

void BattleSystem::clearQueue()
{
    while (!battleQueue.isEmpty())
    {
        battleQueue.dequeue();
    }
}

void BattleSystem::startBattle(Pokemon playerPokemon,
                               Pokemon enemyPokemon)
{
    clearQueue();

    lastPlayerWon = false;
    turnNumber = 1;

    if (playerPokemon.getSpeed() >= enemyPokemon.getSpeed())
    {
        battleQueue.enqueue(playerPokemon);
        battleQueue.enqueue(enemyPokemon);
    }
    else
    {
        battleQueue.enqueue(enemyPokemon);
        battleQueue.enqueue(playerPokemon);
    }

    int playerHp = playerPokemon.getHp();
    int enemyHp = enemyPokemon.getHp();

    cout << endl;
    cout << "Battle Start!" << endl;

    cout << playerPokemon.getName()
         << " VS "
         << enemyPokemon.getName()
         << endl;

    while (playerHp > 0 && enemyHp > 0)
    {
        Pokemon attacker = battleQueue.dequeue();

        if (attacker.getName() == playerPokemon.getName())
        {
            int damage = calculateDamage(playerPokemon,
                                         enemyPokemon);

            enemyHp = enemyHp - damage;

            string action =
                "Turn "
                + to_string(turnNumber)
                + ": "
                + playerPokemon.getName()
                + " attacked "
                + enemyPokemon.getName()
                + " for "
                + to_string(damage)
                + " damage.";

            recordBattleAction(action);

            cout << action << endl;

            if (enemyHp > 0)
            {
                battleQueue.enqueue(playerPokemon);
            }
        }
        else
        {
            int damage = calculateDamage(enemyPokemon,
                                         playerPokemon);

            playerHp = playerHp - damage;

            string action =
                "Turn "
                + to_string(turnNumber)
                + ": "
                + enemyPokemon.getName()
                + " attacked "
                + playerPokemon.getName()
                + " for "
                + to_string(damage)
                + " damage.";

            recordBattleAction(action);

            cout << action << endl;

            if (playerHp > 0)
            {
                battleQueue.enqueue(enemyPokemon);
            }
        }

        turnNumber++;
    }

    clearQueue();

    cout << endl;

    if (playerHp > 0)
    {
        lastPlayerWon = true;

        cout << playerPokemon.getName()
             << " wins!"
             << endl;
    }
    else
    {
        lastPlayerWon = false;

        cout << enemyPokemon.getName()
             << " wins!"
             << endl;
    }
}

bool BattleSystem::getLastPlayerWon() const
{
    return lastPlayerWon;
}

void BattleSystem::displayBattleHistory()
{
    if (battleHistory.isEmpty())
    {
        cout << endl;
        cout << "No battle history yet." << endl;
        return;
    }

    Stack tempStack;

    while (!battleHistory.isEmpty())
    {
        tempStack.push(battleHistory.pop());
    }

    cout << endl;
    cout << "Battle History" << endl;
    cout << "--------------" << endl;

    while (!tempStack.isEmpty())
    {
        string action = tempStack.pop();

        cout << action << endl;

        battleHistory.push(action);
    }
}
