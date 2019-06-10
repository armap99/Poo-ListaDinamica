#ifndef NODE_H
#define NODE_H

#include "cancion.h"
class Node
{
private:
    Cancion data;
    Node* next;
public:
    Node();
    Node(const Cancion&);

    Cancion getData()const;
    Node *getNext() const;
    void setData(const Cancion&);
    void setNext(Node*);
};

#endif // NODE_H
