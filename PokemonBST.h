#ifndef POKEMONBST_H
#define POKEMONBST_H

#include <string>

#include "Pokemon.h"

using namespace std;

class PokemonBST
{
private:

    struct Node
    {
        Pokemon data;
        Node * left;
        Node * right;
    };

    Node * root;

    void insert(Node *& current,
                const Pokemon & pokemon);

    bool search(Node * current,
                const string & name) const;

    Pokemon findPokemon(Node * current,
                        const string & name) const;

    void displayInOrder(Node * current) const;

    void destroyTree(Node * current);

public:

    PokemonBST();

    ~PokemonBST();

    void insertPokemon(const Pokemon & pokemon);

    bool searchPokemon(const string & name) const;

    Pokemon getPokemon(const string & name) const;

    void displayPokemon() const;
};

#endif
