#include "listapag.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ListaPag::ListaPag() : cabeza_(nullptr) {}

ListaPag::~ListaPag()
{
    Nodo* actual = cabeza_;
    while (actual != nullptr)
    {
        Nodo* auxiliar = actual;
        actual = actual->getsiguiente();
        delete auxiliar;
    }
}
void ListaPag::lector(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    string URL, date, time, cate;
    while (getline(archivo, URL, ',')) {
        cout << "Leyendo URL: " << URL << endl;  // Mensaje de depuración
        
        getline(archivo, date, ',');
        cout << "Leyendo fecha: " << date << endl;  // Mensaje de depuración

        getline(archivo, time, ',');
        cout << "Leyendo hora: " << time << endl;  // Mensaje de depuración

        getline(archivo, cate);
        cout << "Leyendo categoría: " << cate << endl;  // Mensaje de depuración

        Pag nuevaPagina(URL, date, time, cate);
        insertarFinal(nuevaPagina);
    }

    archivo.close();
}

void ListaPag::insertarInicio(Pag dato)
{
    Nodo* nuevo = new Nodo(dato);
    nuevo->setsiguiente(cabeza_);
    cabeza_ = nuevo;
}

void ListaPag::insertarFinal(Pag dato)
{
    Nodo* nuevo = new Nodo(dato);
    if (cabeza_ == nullptr)
    {
        cabeza_ = nuevo;
    }
    else
    {
        Nodo* actual = cabeza_;
        while (actual->getsiguiente() != nullptr)
        {
            actual = actual->getsiguiente();
        }
        actual->setsiguiente(nuevo);
    }
}

bool ListaPag::buscarPorURL(string URL)
{
    Nodo* actual = cabeza_;
    while (actual != nullptr)
    {
        if (actual->getdato().getURL() == URL)
            return true;
        actual = actual->getsiguiente();
    }
    return false;
}

bool ListaPag::eliminarPorURL(string URL)
{
    if (cabeza_ == nullptr)
        return false;

    Nodo* actual = cabeza_, *anterior = nullptr;

    while (actual != nullptr && actual->getdato().getURL() != URL)
    {
        anterior = actual;
        actual = actual->getsiguiente();
    }

    if (actual == nullptr)
        return false;

    if (anterior == nullptr)
        cabeza_ = actual->getsiguiente();
    else
        anterior->setsiguiente(actual->getsiguiente());

    delete actual;
    return true;
}

void ListaPag::mostrar()
{
    Nodo* actual = cabeza_;
    while (actual != nullptr)
    {
        actual->getdato().baraddress();
        actual = actual->getsiguiente();
    }
    cout << endl;
}