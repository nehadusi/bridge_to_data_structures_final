#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    Node * current = head;
    Node * temp = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->next;

        delete temp;
    }
}

bool LinkedList::isEmpty() const
{
    return head == NULL;
}

void LinkedList::insertPokemon(const Pokemon & pokemon)
{
    Node * newNode = new Node;

    newNode->data = pokemon;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node * current = head;

        while (current->next != NULL)
        {
            current = current->next;
        }

        current->next = newNode;
    }
}

void LinkedList::displayTeam() const
{
    if (head == NULL)
    {
        cout << endl;
        cout << "Your team is empty." << endl;
        return;
    }

    Node * current = head;

    cout << endl;
    cout << "Pokemon Team" << endl;
    cout << "------------" << endl;

    while (current != NULL)
    {
        current->data.displayPokemon();
        current = current->next;
    }
}

bool LinkedList::searchTeam(const string & name) const
{
    Node * current = head;

    while (current != NULL)
    {
        if (current->data.getName() == name)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

int LinkedList::getSize() const
{
    int count = 0;

    Node * current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

Pokemon LinkedList::getPokemonAt(int position) const
{
    if (position < 0)
    {
        return Pokemon();
    }

    int index = 0;

    Node * current = head;

    while (current != NULL)
    {
        if (index == position)
        {
            return current->data;
        }

        index++;
        current = current->next;
    }

    return Pokemon();
}

bool LinkedList::addWinToPokemon(const string & name)
{
    Node * current = head;

    while (current != NULL)
    {
        if (current->data.getName() == name)
        {
            current->data.addWin();

            if (current->data.getWins() % 3 == 0)
            {
                current->data.addMedal();
            }

            return true;
        }

        current = current->next;
    }

    return false;
}
