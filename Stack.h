#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class Stack
{
private:

    struct Node
    {
        string data;
        Node * next;
    };

    Node * top;

public:

    Stack();

    ~Stack();

    bool isEmpty() const;

    void push(const string & action);

    string pop();

    string peek() const;
};

#endif