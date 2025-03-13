#include "Pag.h"
#include "Nodo.h"


Nodo::Nodo(Pag dato){
    dato_= dato;
     }

void Nodo::setdato(Pag dato) { 
    dato_ = dato; 
     }

void Nodo::setsiguiente(Nodo* siguiente) { 
    this->siguiente = siguiente;
 }

Pag Nodo::getdato() {
     return dato_; 
    }

Nodo* Nodo::getsiguiente() {
     return siguiente; 
    }