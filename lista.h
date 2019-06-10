#ifndef LISTA_H
#define LISTA_H


#include <iomanip>

#include "node.h"
#include "error.h"

class Lista
{
private:
    Node *playlist;//ancla
    bool isValidPos(const Node*)const;

public:
    Lista();
    Lista(const Lista&);
    ~Lista();
    void CopyAll(const Lista&);
    bool Vacia() const;
    void Inserta(Node *, const Cancion&);
    void Borrar(Node *);
    Cancion Recupera(Node*);
    Node* getPrimero()const;
    Node* getUltimo()const;
    Node* getSeguiente(Node*)const;
    Node* getAnterior(Node*)const;
    void Anula();
    void Mostrar();
    Node* busquedaLineal(const Cancion&);

};

#endif // LISTA_H
