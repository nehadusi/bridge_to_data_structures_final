#include "Stack.h"

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    Node * current = top;
    Node * temp = NULL;

    while (current != NULL)
    {
        temp = current;
        current = current->next;

        delete temp;
    }
}

bool Stack::isEmpty() const
{
    return top == NULL;
}

void Stack::push(const string & action)
{
    Node * newNode = new Node;

    newNode->data = action;
    newNode->next = top;

    top = newNode;
}

string Stack::pop()
{
    if (isEmpty())
    {
        return "";
    }

    Node * temp = top;

    string removedAction = top->data;

    top = top->next;

    delete temp;

    return removedAction;
}

string Stack::peek() const
{
    if (isEmpty())
    {
        return "";
    }

    return top->data;
}
