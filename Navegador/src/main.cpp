#include <iostream>
#include "listapag.h"
#include "Pag.h"
#include <ctime>

using namespace std;

string obtenerFechaHora() {
    time_t ahora = time(0);
    tm* tiempo = localtime(&ahora);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempo);
    
    return string(buffer);
}

int main()
{   
    string fechaHora = obtenerFechaHora();
    string URL;
    string date = fechaHora.substr(0, 10);  
    string time = fechaHora.substr(11, 8);
    string cate;
    Pag f;
    char opcion;
  
    // ingreso de historial
    ListaPag lista;
    lista.lector("paginas/historialdata.txt");
    while (true) {
        cout << "\n Bienvenido a FireFox" << endl;
        cout << "[b] Barra de busqueda\n[h] Mostrar Historial\n[c] Borrar Historial\n[e] Salir de FireFox\n";
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 'b') {
            cout << "Inserte Link o Direccion tipo https//... : ";
            cin >> URL;
            cout << "Etiqueta o marcador: ";
            cin >> cate;
            f.setPag(URL, date, time, cate);
            lista.insertarFinal(f);
            cout << endl;
        
            lista.mostrarPaginaActual();
        
            char n;
            while (true) {  // Se mantiene en este bucle hasta que el usuario decida salir de la navegación
                cout << "[a] Desea ir hacia atrás\n[d] Desea ir hacia adelante\n[s] Salir de la navegación\n";
                cin >> n;
        
                if (n == 'a') {  
                    if (lista.puedeRetroceder()) { 
                        lista.retroceder();
                        lista.mostrarPaginaActual();
                    } else {
                        cout << "No puedes retroceder más." << endl;
                    }
                } else if (n == 'd') {  
                    if (lista.puedeAvanzar()) { 
                        lista.avanzar();
                        lista.mostrarPaginaActual();
                    } else {
                        cout << "No puedes avanzar más." << endl;
                    }
                } else if (n == 's') {  // Opción para salir de la navegación
                    break;  // Sale del bucle y regresa al menú principal
                } else {
                    cout << "Opción no válida. Inténtalo de nuevo." << endl;
                }
            }
        
        
                
        } else if (opcion == 'h') {
            lista.mostrar();
        } else if (opcion == 'c') {
            while(true){
                char x;
                cout<< "Gestor de borrado de historial"<< endl;
                cout<< "[s] Buscar pagina espesifica\n[p] Borrar una pagina especifica \n[c] Borrar todo el Historial \n[e] Regresar a inicio\n";
                cin>> x;

                if ( x == 'b') {
                    string https_;
                    cout << "Ingrese su direccion https a buscar: ";
                    cin >> https_;

                    if(lista.buscarPorURL(https_)){
                        cout << "Si se encuentra" << endl;
                    } else {
                        cout << "No se encuentra" << endl;
                    }

                } else if( x == 'p') {
                    string https;
                    cout << "Ingrese su direccion https a eliminar: " << endl;
                    cin >> https;
                    if(lista.eliminarPorURL(https)) {
                        cout << "Pagina borrada del historial" << endl;
                        lista.mostrar();
                    } else {
                        cout << "Pagina no encontrada" << endl;
                    }

                } else if (x == 'c') {
                    char d;
                    cout << "Usted desea borra todo su historial de Navegacion [s/n]...";
                    cin >> d;
                    if (d == 's' || d == 'S') {
                        lista.eleminarhistorial();
                        cout << "Historial eliminado." << endl;
                    }
                } else if (x == 'e') {
                    cout << endl;
                    break;
                }
            }
        } else if (opcion == 'e') {
            cout << endl;
            lista.disco("paginas/historialdata.txt");
            break;
        } else {
            cout << "Opción inválida." << endl;
        }
    }
    return 0;
}



