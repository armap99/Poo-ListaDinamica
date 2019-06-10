#include "lista.h"

Lista::Lista():playlist(nullptr){}

Lista::Lista(const Lista &l):playlist(nullptr){
    CopyAll(l);
}

Lista::~Lista()
{
    Anula();
}

void Lista::CopyAll(const Lista&l)
{
    Node* aux(l.playlist);
    Node* ultimo(nullptr);
    Node* Nuevo;
    while (aux != nullptr) {
        Nuevo = new Node(aux->getData());
        if(Nuevo == nullptr){
            throw Error("Memoria no disponible,CopyAll");
        }
        if(ultimo == nullptr){
            playlist = Nuevo;
        }
        else {
            ultimo->setNext(Nuevo);
        }
        ultimo = Nuevo;
        aux = aux->getNext();
    }
}

bool Lista::isValidPos(const Node *p) const
{
    Node* aux(playlist);
    while(aux != nullptr){
        if(aux == p){
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}

bool Lista::Vacia() const
{
    return playlist == nullptr;
}


void Lista::Inserta(Node *p, const Cancion &e)
{
    if(p != nullptr and !isValidPos(p)){
        throw Error("Posicion in valida,insertar");
    }
    Node *aux(new Node(e));
    if(aux == nullptr){
        throw Error("Memoria no disponible,insertar");
    }
    if(p == nullptr){//insertar al inicio
        aux->setNext(playlist);
        playlist = aux;
    }
    else{//insertar en cualquier otra posicion
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
}

void Lista::Borrar(Node *pos)
{
    if(!isValidPos(pos)){
        throw Error("Posicion no valida,Borrar");
    }
    if(pos == playlist){//Eliminar primero
        playlist = playlist->getNext();
    }
    else{
        getAnterior(pos)->setNext(pos->getNext());
    }
    delete pos;
}

Cancion Lista::Recupera(Node *pos)
{
    if(!isValidPos(pos)){
            throw Error("Posicion invalida,recupera");
    }
    return pos->getData();
}

Node* Lista::getPrimero() const
{
    return playlist;
}

Node* Lista::getUltimo() const
{
    if(Vacia()){
        return nullptr;
    }
    Node* aux(playlist);
    while(aux->getNext() != nullptr){
        aux = aux->getNext();
    }
    return aux;
}

Node* Lista::getSeguiente(Node *p) const
{
    if(!isValidPos(p)){
        return nullptr;
    }
    return p->getNext();
}

Node* Lista::getAnterior(Node *p) const
{
    if(Vacia() or p == playlist){
        return nullptr;
    }
    Node* aux(playlist);
    while(aux != nullptr and aux->getNext() != p){
        aux = aux->getNext();
    }
    return aux;
}

void Lista::Anula()
{
    Node* aux;
    while(playlist != nullptr){
        aux = playlist;
        playlist = playlist->getNext();
        delete aux;
    }
}

void Lista::Mostrar()
{
    int j(0);
    if(Vacia()){
        throw Error("Datos insuficientes,mostrar");
    }
    cout << left;
    cout << setw(7) << "Numero" << " | "
         << setw(25) << "Cancion" << " | "
         << setw(15) << "Autor" << " | "
         << setw(17) << "Interprete" << " | "
         << setw(4) << "Duracion"
         << endl;
    Node* i(playlist);
    while (i != nullptr){
        j++;
        cout << setw(7)<< j << " | "
             << setw(25)<< i->getData().getNombre() << " | "
             << setw(15) << i->getData().getAutor() << " | "
             << setw(17) << i->getData().getInterprete() << " | "
             << setw(4) << i->getData().getDuracion()
             << endl;
        i = i->getNext();
    }
}

Node *Lista::busquedaLineal(const Cancion&c)
{
    Node* aux(playlist);
    while(aux != nullptr and aux->getData().getNombre() != c.getNombre()){
        aux = aux->getNext();
    }
    return aux;
}
