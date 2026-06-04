#ifndef QUEUE_H
#define QUEUE_H

#include "Pokemon.h"

class Queue
{
    private: 

        struct Node
        {
            Pokemon data; 
            Node * next;
        };

        Node * front; 
        Node * rear; 
    
    public:
        Queue(); 

        ~Queue();

        bool isEmpty() const;

        void enqueue(const Pokemon & pokemon); 

        Pokemon dequeue();

        Pokemon peek() const; 
};

#endif 