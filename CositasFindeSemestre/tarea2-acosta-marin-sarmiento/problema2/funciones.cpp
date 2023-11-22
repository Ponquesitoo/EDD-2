#include "TDA.hpp"
using namespace std;

Nodo* arbol = nullptr;

/*****
*Arbol::Arbol
******
* es el constructor e inicializa dos variables.
*****/
Arbol::Arbol(){

    raiz = nullptr;
    pos = 0;

}

/* funciones auxiliares
A continuacion se encuentran las funciones auxiliares, las que posteriormente se utilizaran para las funciones solicitadas */

/*****
* Nodo* Arbol::crearNodo
******
* se encarga de crear un nuevo nodo.
******
* Input:
* tElem pos : Elemento que se desea insertar
******
* Returns:
* Nodo* : entrega un nuevo nodo.
*****/
Nodo* Arbol::crearNodo(tElem pos){

    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->numero = pos;
    nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr;

    return nuevoNodo;
}


/*****
* void Arbol::insertarNodo
******
* Insertar un nodo en la posicion "pos" del arbol
******
* Input:
* tElem pos : Elemento que se desea insertar
* Nodo* &arbol : Puntero que seniala al arbol
*****/

void Arbol::insertarNodo(tElem pos, Nodo* &arbol){

    if(arbol == nullptr){

        arbol = crearNodo(pos);

    }
    else{

        if(pos < arbol->numero){

            insertarNodo(pos, arbol->izquierdo);

        }
        else{

            if(pos > arbol->numero){

                insertarNodo(pos, arbol->derecho);
            }
        }
    }
}


/*****
* bool Arbol::busqueda
******
* Busca un elemento al elemento de posicion "pos"
******
* Input:
* tElem pos : Elemento que se desea buscar.
* Nodo* arbol: Puntero que seniala al arbol.
******
* Returns:
* bool: 'true' o 'false' dependiendo de si encuentra el elemento o no.
*****/

bool Arbol::busqueda(tElem pos, Nodo* arbol){

    if(arbol == nullptr){

        return false;

    }
    else{

        if(arbol->numero == pos){

            return true;
        }
        else{

            if(arbol->numero > pos){

                return busqueda(pos, arbol->izquierdo);
            }
            else{

                return busqueda(pos, arbol->derecho);
            }
        }
    }
}


/*****
* int Arbol::encontrarNodo
******
* Busca el primer elemento que sea mejor o igual al elemento 'pos'
******
* Input:
* tElem pos : Elemento del que se quiere su menor mas cercano o igual
* Nodo *arbol: Puntero que seniala al arbol
******
* Returns:
* int: El numero mas cercano que es menor o igual a pos, o -1.
*****/

int Arbol::encontrarNodo(tElem pos, Nodo *arbol) {
    if (arbol == nullptr) {
        return -1;
    }
    if (arbol->numero > pos) {
        return encontrarNodo(pos, arbol->izquierdo);
    }

    else{
        int num = encontrarNodo(pos, arbol->derecho);
        if (num == -1 || arbol->numero > num) {
        num = arbol->numero;
        }
    return num;
    }
}

/*****
* void Arbol::clearHelp
******
* Se encarga de eliminar el arbol, es la funcion auxiliar de clear.
******
* Input:
* Nodo* arbol : Puntero que seniala al arbol.
*****/

void Arbol::clearHelp(Nodo* arbol) {
    if (arbol == nullptr) return;
     
    clearHelp(arbol->izquierdo); 
    clearHelp(arbol->derecho); 
    delete arbol;
}

/* Funciones
Estas funciones son las que se solicitaron en el enunciado. El proposito de crear funciones auxiliares fue facilitar su desarrollo y luego crear
estas funciones principales, que llamarian a las auxiliares. De esta manera, las funciones principales solo tendrian el parametro requerido. */

/*****
* void Arbol::insert
******
* Llama a su funcion auxiliar para insertar un nodo en la posicion 'pos'.
******
* Input:
* tElem pos : Elemento que se desea insertar. Se utiliza como parametro en al funcion insertarNodo()
******
* Returns:
* void: Solo inserta el elemento
*****/

void Arbol::insert(tElem pos){

    insertarNodo(pos, arbol);

}

/*****
* bool Arbol::find
******
* Llama a su funcion auxiliar para buscar un elemento
******
* Input:
* tElem pos : Elemento que se desea buscar. Se utiliza como parametro en al funcion busqueda()
******
* Returns:
* bool:'true' o 'false' dependiendo si se encuentra o no
*****/

bool Arbol::find(tElem pos){

    return busqueda(pos, arbol);

}

/*****
* int Arbol::lower_bound
******
* Llama a su funcion auxiliar para encontrar el primer elemento que sea menor o igual al del parametro
******
* Input:
* tElem pos : Elemento del que se quiere su menor mas cercano o igual y se usara como parametro en la funcion encontrarNodo()
******
* Returns:
* int: El numero mas cercano que es menor o igual a pos, o -1(si entrega -1 significa que no se encontro).
*****/

int Arbol::lower_bound(tElem pos){

    return encontrarNodo(pos, arbol);

}

/*****
* void Arbol::clear
******
* Llama a su funcion auxiliar para eliminar todos los nodos del arbol.
*****/


void Arbol::clear(){

    clearHelp(arbol);

}

/*****
* Arbol::~Arbol
******
* Se encarga de destruir utilizando la funcion clear.
*****/
Arbol::~Arbol(){

    clear();

}