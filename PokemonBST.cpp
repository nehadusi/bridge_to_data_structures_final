#include <iostream>

#include "PokemonBST.h"

using namespace std;

PokemonBST::PokemonBST()
{
    root = NULL;
}

PokemonBST::~PokemonBST()
{
    destroyTree(root);
}

void PokemonBST::destroyTree(Node * current)
{
    if (current != NULL)
    {
        destroyTree(current->left);
        destroyTree(current->right);

        delete current;
    }
}

void PokemonBST::insertPokemon(
    const Pokemon & pokemon)
{
    insert(root, pokemon);
}

void PokemonBST::insert(
    Node *& current,
    const Pokemon & pokemon)
{
    if (current == NULL)
    {
        current = new Node;

        current->data = pokemon;

        current->left = NULL;
        current->right = NULL;
    }
    else if (pokemon.getName()
             < current->data.getName())
    {
        insert(current->left,
               pokemon);
    }
    else
    {
        insert(current->right,
               pokemon);
    }
}

bool PokemonBST::searchPokemon(
    const string & name) const
{
    return search(root, name);
}

bool PokemonBST::search(
    Node * current,
    const string & name) const
{
    if (current == NULL)
    {
        return false;
    }

    if (name == current->data.getName())
    {
        return true;
    }

    if (name < current->data.getName())
    {
        return search(current->left,
                      name);
    }

    return search(current->right,
                  name);
}

void PokemonBST::displayPokemon() const
{
    displayInOrder(root);
}

void PokemonBST::displayInOrder(
    Node * current) const
{
    if (current != NULL)
    {
        displayInOrder(current->left);

        current->data.displayPokemon();

        displayInOrder(current->right);
    }
}