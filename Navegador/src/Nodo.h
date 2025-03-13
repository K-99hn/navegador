#ifndef NODO_H
#define NODO_H
#include "Pag.h"
class Nodo{

private:
 Pag dato_;
 Nodo* siguiente;

public:
 Nodo(Pag dato);
 void setdato(Pag dato);
 void setsiguiente(Nodo* siguiente);
 Pag getdato();
 Nodo* getsiguiente();



};


#endif