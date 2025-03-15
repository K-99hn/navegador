#include "listapag.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ListaPag::ListaPag() : cabeza_(nullptr),actual_(nullptr) {}

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
    bool primeraPagina = (cabeza_ == nullptr);

    while (getline(archivo, URL, ',')) {
        getline(archivo, date, ',');
        getline(archivo, time, ',');
        getline(archivo, cate);

        Pag nuevaPagina(URL, date, time, cate);
        insertarFinal(nuevaPagina);
    }

    if (primeraPagina) // Si era la primera vez cargando datos
        actual_ = cabeza_;

    archivo.close();
}

void ListaPag::disco(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para escribir." << endl;
        return;
    }

    Nodo* actual = cabeza_;
    while (actual != 0) {  // Recorre la lista
        archivo << actual->getdato().getURL() << ","
                << actual->getdato().getdate() << ","
                << actual->getdato().gettime() << ","
                << actual->getdato().getcate() << endl;
        actual = actual->getsiguiente();
    }

    archivo.close();
}
void ListaPag::avanzar() {
    if (actual_ && actual_->getsiguiente()) {
        anterior_ = actual_;  // Guardamos el nodo actual como el anterior
        actual_ = actual_->getsiguiente();
        mostrarPaginaActual();
    } else {
        cout << "No hay más páginas adelante." << endl;
    }
}


void ListaPag::retroceder() {
    if (actual_ == nullptr || actual_ == cabeza_) {
        cout << "No hay más páginas atrás." << endl;
        return;
    }

    Nodo* temp = cabeza_;
    Nodo* nuevoAnterior = nullptr;  

    while (temp->getsiguiente() != actual_) {  
        nuevoAnterior = temp;
        temp = temp->getsiguiente();
    }

    anterior_ = nuevoAnterior;  
    actual_ = temp;  
    mostrarPaginaActual();
}
bool ListaPag::puedeRetroceder() {
    return actual_ != cabeza_;  // Se puede retroceder si `actual_` no es la cabeza
}

bool ListaPag::puedeAvanzar() {
    return (actual_ && actual_->getsiguiente() != nullptr);
}


void ListaPag::mostrarPaginaActual() {
    if (actual_) {
        cout << "Página actual: " << actual_->getdato().getURL() << endl;
    } else {
        cout << "No hay páginas en el historial." << endl;
    }
}

void ListaPag::insertarFinal(Pag dato)
{
    Nodo* nuevo = new Nodo(dato);
    if (cabeza_ == nullptr)
    {
        cabeza_ = nuevo;
        actual_ = nuevo;
    }
    else
    {
        Nodo* temp = cabeza_;
        while (temp->getsiguiente() != nullptr)
        {
            temp = temp->getsiguiente();
        }
        temp->setsiguiente(nuevo);
        actual_ = nuevo; // Nos aseguramos de mover `actual_` al último nodo
    }
}

void ListaPag::eleminarhistorial()
{
    while (cabeza_ != nullptr)
    {
        Nodo* temp = cabeza_;
        cabeza_ = cabeza_->getsiguiente();
        delete temp;
    }
    actual_ = nullptr; 
}

bool ListaPag::buscarPorURL(string URL)
{
    Nodo* actual = cabeza_;
    while (actual != nullptr)
    {
        if (actual->getdato().getURL() == URL){
          actual->getdato().baraddress();
         return true;
        }
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

    if (actual_ == actual)
        actual_ = (actual->getsiguiente() != nullptr) ? actual->getsiguiente() : cabeza_;

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