#ifndef LISTAPAG_H
#define LISTAPAG_H
#include "Pag.h"
#include "Nodo.h"

class ListaPag
{
private:
    Nodo* cabeza_;
    Nodo* actual_;
    Nodo* anterior_; 

public:
    ListaPag();
    ~ListaPag();
    void lector( const string &);
    void disco(const string &);
    void avanzar();
    void retroceder();
    void mostrarPaginaActual();
    void eleminarhistorial();
    void insertarInicio(Pag dato);
    void insertarFinal(Pag dato);
    bool puedeRetroceder();
    bool puedeAvanzar();
    bool buscarPorURL(string URL);
    bool eliminarPorURL(string URL);
    void mostrar();
};


#endif