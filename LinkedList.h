#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Pokemon.h"

class LinkedList
{
private:

    struct Node
    {
        Pokemon data;
        Node * next;
    };

    Node * head;

public:

public:

    LinkedList();

    ~LinkedList();

    bool isEmpty() const;

    void insertPokemon(const Pokemon & pokemon);

    void displayTeam() const;

    bool searchTeam(const string & name) const;

    int getSize() const;

    Pokemon getPokemonAt(int position) const;
};

#endif