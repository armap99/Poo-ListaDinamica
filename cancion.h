#ifndef CANCION_H
#define CANCION_H


#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Cancion
{
private:
    unsigned int duracion;
    string nombre,autor,interprete;

public:
    Cancion();
    Cancion (const Cancion&);
    void setDuracion(const unsigned int&);
    void setNombre(const string&);
    void setAutor(const string&);
    void setInterprete(const string&);

    unsigned int getDuracion() const;
    string getNombre() const;
    string getAutor() const;
    string getInterprete() const;

    string toString() const;
    Cancion operator = (const Cancion&);
    bool operator == (const Cancion&) const;
    bool operator != (const Cancion&) const;
    bool operator < (const Cancion&) const;
    bool operator <= (const Cancion&) const;
    bool operator > (const Cancion&) const;
    bool operator >= (const Cancion&) const;

    friend ostream& operator << (ostream&os, Cancion&n){
        os << n.toString();
//        os << n.getNombre() << endl;
//        os << n.getAutor() << endl;
//        os << n.getInterprete() << endl;
//        os << n.getDuracion() << endl;
        return os;
    }
    friend istream& operator >> (istream&is, Cancion&n){
        cout << "Nombre: " << endl;
        getline(is,n.nombre);
        cout << "Autor: " << endl;
        getline(is,n.autor);
        cout << "Interprete: " << endl;
        getline(is,n.interprete);
        cout << "Duracion: " << endl;
        is>> n.duracion;
        cin.ignore();

        return is;
    }
};


#endif // CANCION_H
