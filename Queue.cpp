#include "Queue.h"

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

bool Queue::isEmpty() const
{
    return front == NULL;
}

void Queue::enqueue(const Pokemon & pokemon)
{
    Node * newNode = new Node;

    newNode->data = pokemon;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

Pokemon Queue::dequeue()
{
    if (isEmpty())
    {
        return Pokemon();
    }

    Node * temp = front;

    Pokemon removedPokemon = front->data;

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    delete temp;

    return removedPokemon;
}

Pokemon Queue::peek() const
{
    if (isEmpty())
    {
        return Pokemon();
    }

    return front->data;
}

int Queue::getSize() const
{
    int count = 0;

    Node * current = front;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}
