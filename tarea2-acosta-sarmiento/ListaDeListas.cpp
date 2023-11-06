#include <iostream>
#include "TDAlistaDeListas.hpp"
using namespace std;

#define MAXSIZE 1000000

/*****
* tListadeListas
******
* Constructor de la clase. Inicializa la lista de listas.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* No retorna.
*****/

tListadeListas::tListadeListas(){
    maxSize = MAXSIZE;
    listSize = 0;
    curr = 0;
    listArray = new tLista[maxSize];
}

/*****
* tListadeListas
******
* Destructor de la clase. Elimina la informacion relacionada a la lista.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* No retorna.
*****/

tListadeListas::~tListadeListas(){
    delete[] listArray;
}
  
/*****
* void clear
******
* Vacia la lista.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* Void, no retorna.
*****/

void tListadeListas::clear(){
    for (int i = 0; i < listSize; i++) {
        listArray[i].clear();
    }

    delete[] listArray;
    listArray = nullptr;
    listSize = curr = 0;
}

/*****
* int Inser_block
******
* Inserta un elemento en una determinada posicion.
******
* Input:
* int pos : Posicion en la que se desea insertar.
* tElem elem : Elemento que se desea insertar.
* .......
******
* Returns:
* int, retorna 1 o 0 si es que el elemento se inserto correctamente o no, respectivamente.
*****/

int tListadeListas::Insert_block(int pos, tElem elem){
    int cont = 0;
    int retorno;

    int largo = 0;
    for (int i = 0; i < listSize; i++) {
        largo += listArray[i].length();
    }

    if (pos < 0 || pos >= largo){
        retorno = 0;
    }
    for (int i = 0; i < largo; i++){
        if (pos <= cont + listArray[i].length()-1){
            int a = pos - cont;
            listArray[i].moveToPos(a);
            listArray[i].insert(elem);
            retorno = 1;
            break;
        }
        else {
            cont = cont + listArray[i].length();
        }  
    }
    return retorno;
}

/*****
* int append
******
* Agrega una lista en la ultima posicion de la lista de listas.
******
* Input:
* tLista lista : referencia a la lista que se desea insertar.
* .......
******
* Returns:
* int, retorna 1 o 0 si es que el elemento se inserto correctamente o no, respectivamente.
*****/

int tListadeListas::append(tLista &lista){
    if (listSize >= maxSize){
        return 0;
    }
    listSize++;
    for (int i = 0; i < lista.length(); i++) {
        tElem valor = lista.getValue();
        listArray[listSize].append(valor);
        lista.Next();
    }
    return 1;
}

/*****
* void moveToStart
******
* Mueve la posicion actual al inicio de la lista.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* Void, no retorna.
*****/

void tListadeListas::moveToStart(){
    curr = 0;
}

/*****
* void moveToEnd
******
* Mueve la posicion actual al final de la lista.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* Void, no retorna.
*****/

void tListadeListas::moveToEnd(){
    curr = listSize;
}

/*****
* void moveToPos
******
* Mueve la posicion actual a una posicion determinada.
******
* Input:
* int pos : Posicion a la que se desea mover la posicion actual.
* .......
******
* Returns:
* Void, no retorna.
*****/

void tListadeListas::moveToPos(int pos){
    curr = pos;
}

/*****
* void next
******
* Mueve la posicion actual a la siguiente posicion.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* Void, no retorna.
*****/

void tListadeListas::next(){
    if (curr > listSize){
        curr++;
    }
}

/*****
* int Length
******
* Largo actual de la lista.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* int, largo actual de la lista.
*****/

int tListadeListas::Length(){
    return listSize;
}

/*****
* int Length_block
******
* Cantidad actual de elementos totales en la lista.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* int, cantidad actual de elementos totales en la lista.
*****/

int tListadeListas::Length_block() {
    int largo = listArray[0].length();
    for (int i = 1; i < listSize; i++) {
        largo = largo + listArray[i].length();
    };
    return largo;
}

/*****
* tLista GetValue
******
* Información del elemento que se encuentra en la posicion actual.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* tLista*, puntero al elemento almacenado en la posicion actual. Puntero nulo en caso de no encontrarse.
*****/

tLista* tListadeListas::GetValue(){
    if (curr >= 0 && curr <= listSize){
        return &listArray[curr];
    }
    else {
    	return nullptr;
    }
}

/*****
* tElem GetValue_block
******
* Entrega el valor almacenado en una posicion determinada.
******
* Input:
* int pos : Posicion de la que se quiere obtener el elemento almacenado en ella.
* .......
******
* Returns:
* tElem, valor del elemento almacenado. -1 en caso de no encontrarse.
*****/

tElem tListadeListas::GetValue_block(int pos){
    int cont = 0;
    tElem elem;
    int largo = 1;


    for (int i = 0; i < listSize; i++){
        largo += listArray[i].length();
    }
    
    if (pos < 0 || pos >= largo){
        elem = -1;
    }
    
    for (int i = 0; i < largo; i++){
        if (pos <= cont + listArray[i].length()-1){
            int a = pos - cont;
            listArray[i].moveToPos(a);
            elem = listArray[i].getValue();
            return elem;
        } else {
            cont = cont + listArray[i].length();
        }
    }
    return elem;
}


    
