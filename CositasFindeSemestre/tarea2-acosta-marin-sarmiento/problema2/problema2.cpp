#include <iostream>
#include <string>
#include "funciones.cpp"
using namespace std;

struct Cola{

    int dato;
    Cola* siguiente;

};

/*****
* bool colaVacia
******
* lo que realiza la funcion es verificar si una cola esta "vacia", es decir, si existe o no existe la cola, es una funcion auxiliar que se creo para 
la funcion insertarCola.
******
* Input:
* Cola* frente : puntero hacia el "frente", indica el frente de la cola.
******
* Returns:
* bool, retorna true si no existe una cola, retorna false si existe.
*****/



bool colaVacia(Cola* frente){

    if(frente == NULL){

        return true;

    }
    else{

        return false;

    }
}

/*****
* void insertarCola
******
* es una funcion primero crea un nuevo nodo y luego mediante la funcion colaVacia, dependiendo del return de dicha funcion, se crea una nueva cola 
asignandole el "frente" al nodo o solo se inserta en la cola asignandole el "fin".
******
* Input:
* Cola* &frente : puntero por referencia de "frente", permite cambiar el valor de "frente", siendo "frente", el frente de una cola.
* Cola* &fin : puntero por referencia de "fin", permite cambiar el valor de "fin", siendo "fin", el fin de una cola.
* int elemento : "elemento" vendria siendo el dato guardado dentro del nodo de la cola.
*****/

void insertarCola(Cola* &frente, Cola* &fin, int elemento){

    Cola* nuevaCola = new Cola();
    nuevaCola->dato = elemento;
    nuevaCola->siguiente = NULL;

    if(colaVacia(frente)){

        frente = nuevaCola;

    }
    else{

        fin->siguiente = nuevaCola;

    }
    fin = nuevaCola;
}

/*****
*void mostrarYEliminarCola
******
* se encarga de imprimir por pantalla los elementos almacenados en la cola por la funcion insertarCola y luego eliminarlos para eliminar la cola
y finalmente liberar la memoria.
******
* Input:
* Cola* &frente : puntero por referencia hacia el "frente" de la cola.
* Cola* &fin : puntero por referencia hacia el "fin" de la cola.
*****/


void mostrarYEliminarCola(Cola* &frente, Cola* &fin){
    Cola* temporal = frente;
    while(temporal != NULL){
        Cola* auxiliar = temporal;
        cout << auxiliar->dato << endl;
        temporal = temporal->siguiente;
        delete auxiliar;
    }
    frente = NULL;
    fin = NULL;
}

int main(){

    Cola* frente = NULL;
    Cola* fin = NULL;


    Arbol funcion;
    int operacion, cant_postes = 0, valor, resultado, posicion;
    string completo, operacionSTR, posicionSTR;


    //seccion de codigo que se encarga de la entrada
    do{
        cout << "";
        getline(cin, completo);
        size_t espacio = completo.find(' ');
        if(espacio != string::npos){

            operacionSTR = completo.substr(0, espacio);
            posicionSTR = completo.substr(espacio + 1);
            posicion = stoi(posicionSTR);
            if(operacionSTR == "ENCENDER"){

                operacion = 1;

            }
            else if(operacionSTR == "CUANTOS_ENCENDER"){

                operacion = 2;

            }
        }
        else if(completo == "PARAR_PROGRAMA"){

            operacion = 3;

        }
        else{

            cout << "operacion invalida, intentelo nuevamente\n";

        }
        
        switch(operacion){

            //ENCENDER
            case 1:
            if(funcion.find(posicion) == true){

                
            }
            else{

                funcion.insert(posicion);
                cant_postes++;

            }
                
                break;
            //CUANTOS_ENCENDER
            case 2:
                resultado = funcion.lower_bound(posicion);
                if(resultado == -1){

                    valor = posicion + 1;

                }
                else{

                    valor = posicion - resultado;

                }
                insertarCola(frente, fin, valor);

                break;
        }

    }while(operacion != 3); //PARAR_PROGRAMA

    //seccion de codigo que se encarga de la salida del programa.
    cout << endl;
    mostrarYEliminarCola(frente, fin);
    cout << cant_postes << endl;

    return 0;
}