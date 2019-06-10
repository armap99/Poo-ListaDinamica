#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
    string op,buscada;
    Cancion aux,ABuscar;
    Lista mylist;
    while(true){
        cout << "Menu: " << endl
             << "1)Agregar una cancion al principio" << endl
             << "2)Agregar una cancion en una posicion especifica" << endl
             << "3)Eliminar cancion" << endl
             << "4)Buscar una cancion" << endl
             << "5)Cancion Anterior" << endl
             << "6)Cancion Siguiente" << endl
             << "7)Primera Cancion" << endl
             << "8)Ultima Cancion" << endl
             << "9)Salir" << endl;
        cin >> op;
        cin.ignore();
        if(op == "1"){
            cin >> aux;
            mylist.Inserta(nullptr,aux);
            system ("cls");
            mylist.Mostrar();

        }
        else if(op == "2"){
            cin >> aux;
            cout << "Despues de que cacion quiere ingresar: " << endl;
            getline(cin,buscada);
            cin.ignore();
            ABuscar.setNombre(buscada);
            mylist.Inserta(mylist.busquedaLineal(ABuscar),aux);
            system ("cls");
            mylist.Mostrar();

        }
        else if(op == "3"){
            cout << "Nombre de la cancion a eliminar: " << endl;
            getline(cin,buscada);
            cin.ignore();
            ABuscar.setNombre(buscada);
            mylist.Borrar(mylist.busquedaLineal(ABuscar));
            system ("cls");
            mylist.Mostrar();
        }
        else if(op == "4"){
            cout << "Nombre de la cancion a buscar: " << endl;
            getline(cin,buscada);
            cin.ignore();
            ABuscar.setNombre(buscada);
            if(mylist.busquedaLineal(ABuscar) == nullptr){
                cout << "No se encontro la cancion" << endl;
            }
            else{
                cout << mylist.busquedaLineal(ABuscar)->getData().toString() << endl;
            }
        }
        else if(op == "5"){
            cout << "Nombre de la cancion de la quiere saber el anterior: " << endl;
            getline(cin,buscada);
            cin.ignore();
            ABuscar.setNombre(buscada);
            if(mylist.getAnterior(mylist.busquedaLineal(ABuscar)) == nullptr){
                cout << "Lista vacia o no existe la cacion ingresada" << endl;
            }
            else{
                cout << mylist.getAnterior(mylist.busquedaLineal(ABuscar))->getData().toString();
            }
        }
        else if(op == "6"){
            cout << "Nombre de la cancion de la quiere saber el siguiente: " << endl;
            getline(cin,buscada);
            cin.ignore();
            ABuscar.setNombre(buscada);
            if(mylist.getSeguiente(mylist.busquedaLineal(ABuscar)) == nullptr){
                cout << "Lista vacia o no existe la cancion ingresada" << endl;
            }
            else{
                cout << mylist.getSeguiente(mylist.busquedaLineal(ABuscar))->getData().toString();
            }
        }
        else if(op == "7"){
            if(mylist.getPrimero() == nullptr){
                cout << "Lista vacia" << endl;
            }
            else{
                cout << mylist.getPrimero()->getData().toString();
            }
        }
        else if(op == "8"){
            if(mylist.getPrimero() == nullptr){
                cout << "Lista vacia" << endl;
            }
            else{
                cout << mylist.getUltimo()->getData().toString();
            }
        }
        else if(op == "9"){
            mylist.Anula();
            cout << "Adios";
            break;
        }
    }
}
