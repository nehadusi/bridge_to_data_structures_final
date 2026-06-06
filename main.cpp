#include <cstdlib>
#include <ctime>
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

    srand(time(NULL));

    pokedex.insertPokemon(
        Pokemon("Pikachu",
                "Electric",
                100,
                30,
                15,
                20));

    pokedex.insertPokemon(
        Pokemon("Charmander",
                "Fire",
                90,
                28,
                12,
                18));

    pokedex.insertPokemon(
        Pokemon("Bulbasaur",
                "Grass",
                95,
                25,
                18,
                15));

    pokedex.insertPokemon(
        Pokemon("Squirtle",
                "Water",
                110,
                24,
                22,
                12));

    pokedex.insertPokemon(
        Pokemon("Eevee",
                "Normal",
                100,
                26,
                16,
                17));

    while (choice != 7)
    {
        cout << endl;
        cout << "Pokemon Battle Arena" << endl;
        cout << endl;

        cout << "1. Display Available Pokemon" << endl;
        cout << "2. Build Team" << endl;
        cout << "3. View Team" << endl;
        cout << "4. Search Pokemon" << endl;
        cout << "5. Battle CPU" << endl;
        cout << "6. View Battle History" << endl;
        cout << "7. Exit" << endl;

        cout << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            pokedex.displayPokemon();
        }
        else if (choice == 2)
        {
            string pokemonName;

            cout << endl;
            cout << "Enter Pokemon name: ";
            cin >> pokemonName;

            if (pokedex.searchPokemon(pokemonName))
            {
                Pokemon selectedPokemon =
                    pokedex.getPokemon(pokemonName);

                playerTeam.insertPokemon(selectedPokemon);

                cout << pokemonName
                     << " added to team."
                     << endl;
            }
            else
            {
                cout << "Pokemon not found." << endl;
            }
        }
        else if (choice == 3)
        {
            playerTeam.displayTeam();
        }
        else if (choice == 4)
        {
            string pokemonName;

            cout << endl;
            cout << "Enter Pokemon name: ";
            cin >> pokemonName;

            if (pokedex.searchPokemon(pokemonName))
            {
                Pokemon foundPokemon =
                    pokedex.getPokemon(pokemonName);

                foundPokemon.displayPokemon();
            }
            else
            {
                cout << "Pokemon not found." << endl;
            }
        }
        else if (choice == 5)
        {
            if (playerTeam.getSize() == 0)
            {
                cout << "Build a team first." << endl;
            }
            else
            {
                int teamChoice = 0;

                playerTeam.displayTeam();

                cout << endl;
                cout << "Choose team position starting at 0: ";
                cin >> teamChoice;

                Pokemon playerPokemon =
                    playerTeam.getPokemonAt(teamChoice);

                if (playerPokemon.getName() == "")
                {
                    cout << "Invalid team position." << endl;
                }
                else
                {
                    int randomChoice = rand() % 5;

                    Pokemon enemyPokemon;

                    if (randomChoice == 0)
                    {
                        enemyPokemon =
                            pokedex.getPokemon("Pikachu");
                    }
                    else if (randomChoice == 1)
                    {
                        enemyPokemon =
                            pokedex.getPokemon("Charmander");
                    }
                    else if (randomChoice == 2)
                    {
                        enemyPokemon =
                            pokedex.getPokemon("Bulbasaur");
                    }
                    else if (randomChoice == 3)
                    {
                        enemyPokemon =
                            pokedex.getPokemon("Squirtle");
                    }
                    else
                    {
                        enemyPokemon =
                            pokedex.getPokemon("Eevee");
                    }

                    battleSystem.startBattle(playerPokemon,
                                             enemyPokemon);

                    if (battleSystem.getLastPlayerWon())
                    {
                        playerTeam.addWinToPokemon(
                            playerPokemon.getName());

                        cout << playerPokemon.getName()
                             << " earned one win."
                             << endl;

                        cout << "Every 3 wins earns a medal."
                             << endl;
                    }
                }
            }
        }
        else if (choice == 6)
        {
            battleSystem.displayBattleHistory();
        }
        else if (choice == 7)
        {
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
