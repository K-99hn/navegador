#include <iostream>
#include "listapag.h"
using namespace std;

int main()
{   string url;
    ListaPag lista;
    lista.lector("paginas/historial.txt");
    lista.mostrar();


    cout << "Escriba el DNI de la persona a buscar" << endl;
    cin >> url;
    if(lista.buscarPorURL(url))
        cout << "Si se encuentra" << endl;
    else
        cout << "No se encuentra" << endl;




  
}
