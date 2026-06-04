#include <iostream>

#include "Pokemon.h"
#include "PokemonBST.h"
#include "LinkedList.h"
#include "BattleSystem.h"

using namespace std;

int main()
{
    PokemonBST pokedex;
    LinkedList playerTeam;
    BattleSystem battleSystem;

    int choice = 0;

    pokedex.insertPokemon(
        Pokemon(
            "Pikachu",
            "Electric",
            100,
            30,
            15,
            20));

    pokedex.insertPokemon(
        Pokemon(
            "Charmander",
            "Fire",
            90,
            28,
            12,
            18));

    pokedex.insertPokemon(
        Pokemon(
            "Bulbasaur",
            "Grass",
            95,
            25,
            18,
            15));

    pokedex.insertPokemon(
        Pokemon(
            "Squirtle",
            "Water",
            110,
            24,
            22,
            12));

    pokedex.insertPokemon(
        Pokemon(
            "Eevee",
            "Normal",
            100,
            26,
            16,
            17));

    while (choice != 6)
    {
        cout << endl;
        cout << "Pokemon Battle Arena" << endl;
        cout << endl;

        cout << "1. Build Team" << endl;
        cout << "2. View Team" << endl;
        cout << "3. Search Pokemon" << endl;
        cout << "4. Battle CPU" << endl;
        cout << "5. View Battle History" << endl;
        cout << "6. Exit" << endl;

        cout << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            string pokemonName;

            cout << endl;
            cout << "Enter Pokemon name: ";
            cin >> pokemonName;

            if (
                pokedex.searchPokemon(
                    pokemonName))
            {
                Pokemon selectedPokemon =
                    pokedex.getPokemon(
                        pokemonName);

                playerTeam.insertPokemon(
                    selectedPokemon);

                cout
                    << pokemonName
                    << " added to team."
                    << endl;
            }
            else
            {
                cout
                    << "Pokemon not found."
                    << endl;
            }
        }
        else if (choice == 2)
        {
            playerTeam.displayTeam();
        }
        else if (choice == 3)
        {
            string pokemonName;

            cout << endl;
            cout
                << "Enter Pokemon name: ";

            cin >> pokemonName;

            if (
                pokedex.searchPokemon(
                    pokemonName))
            {
                Pokemon foundPokemon =
                    pokedex.getPokemon(
                        pokemonName);

                foundPokemon.displayPokemon();
            }
            else
            {
                cout
                    << "Pokemon not found."
                    << endl;
            }
        }
        else if (choice == 4)
        {
            if (
                playerTeam.getSize()
                == 0)
            {
                cout
                    << "Build a team first."
                    << endl;
            }
            else
            {
                Pokemon playerPokemon =
                    playerTeam.getPokemonAt(0);

                Pokemon enemyPokemon =
                    pokedex.getPokemon(
                        "Charmander");

                battleSystem.startBattle(
                    playerPokemon,
                    enemyPokemon);
            }
        }
        else if (choice == 5)
        {
            battleSystem.displayBattleHistory();
        }
        else if (choice == 6)
        {
            cout
                << "Goodbye!"
                << endl;
        }
        else
        {
            cout
                << "Invalid choice."
                << endl;
        }
    }

    return 0;
}