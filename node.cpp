#include "node.h"

Node::Node():next(nullptr){}

Node::Node(const Cancion &e):data(e), next(nullptr){}

Cancion Node::getData() const
{
    return data;
}

Node* Node::getNext() const
{
    return next;
}

void Node::setData(const Cancion &e)
{
    data = e;
}

void Node::setNext(Node *p)
{
    next = p;
}
