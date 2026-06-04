#include <iostream>
#include <string>

#include "BattleSystem.h"

using namespace std;

BattleSystem::BattleSystem()
{
}

int BattleSystem::calculateDamage(
    const Pokemon & attacker,
    const Pokemon & defender)
{
    int damage =
        attacker.getAttack()
        - defender.getDefense();

    if (damage < 1)
    {
        damage = 1;
    }

    return damage;
}

void BattleSystem::recordBattleAction(
    const string & action)
{
    battleHistory.push(action);
}

void BattleSystem::startBattle(
    Pokemon playerPokemon,
    Pokemon enemyPokemon)
{
    if (
        playerPokemon.getSpeed()
        >= enemyPokemon.getSpeed())
    {
        battleQueue.enqueue(
            playerPokemon);

        battleQueue.enqueue(
            enemyPokemon);
    }
    else
    {
        battleQueue.enqueue(
            enemyPokemon);

        battleQueue.enqueue(
            playerPokemon);
    }

    int playerHp =
        playerPokemon.getHp();

    int enemyHp =
        enemyPokemon.getHp();

    cout << endl;
    cout << "Battle Start!" << endl;
    cout << playerPokemon.getName()
         << " VS "
         << enemyPokemon.getName()
         << endl;

    while (
        playerHp > 0
        &&
        enemyHp > 0)
    {
        Pokemon attacker =
            battleQueue.dequeue();

        if (
            attacker.getName()
            ==
            playerPokemon.getName())
        {
            int damage =
                calculateDamage(
                    playerPokemon,
                    enemyPokemon);

            enemyHp =
                enemyHp - damage;

            string action =
                playerPokemon.getName()
                +
                " attacked "
                +
                enemyPokemon.getName();

            recordBattleAction(
                action);

            cout << action
                 << endl;

            if (enemyHp > 0)
            {
                battleQueue.enqueue(
                    playerPokemon);
            }
        }
        else
        {
            int damage =
                calculateDamage(
                    enemyPokemon,
                    playerPokemon);

            playerHp =
                playerHp - damage;

            string action =
                enemyPokemon.getName()
                +
                " attacked "
                +
                playerPokemon.getName();

            recordBattleAction(
                action);

            cout << action
                 << endl;

            if (playerHp > 0)
            {
                battleQueue.enqueue(
                    enemyPokemon);
            }
        }
    }

    cout << endl;

    if (playerHp > 0)
    {
        cout
            << playerPokemon.getName()
            << " wins!"
            << endl;
    }
    else
    {
        cout
            << enemyPokemon.getName()
            << " wins!"
            << endl;
    }
}

void BattleSystem::displayBattleHistory()
{
    Stack tempStack;

    while (
        !battleHistory.isEmpty())
    {
        string action =
            battleHistory.pop();

        cout
            << action
            << endl;

        tempStack.push(
            action);
    }

    while (
        !tempStack.isEmpty())
    {
        battleHistory.push(
            tempStack.pop());
    }
}