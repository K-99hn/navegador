#ifndef LISTAPAG_H
#define LISTAPAG_H
#include "Pag.h"
#include "Nodo.h"

class ListaPag
{
private:
    Nodo* cabeza_;

public:
    ListaPag();
    ~ListaPag();
    void lector( const string &);
    void insertarInicio(Pag dato);
    void insertarFinal(Pag dato);
    bool buscarPorURL(string URL);
    bool eliminarPorURL(string URL);
    void mostrar();
};


#endif