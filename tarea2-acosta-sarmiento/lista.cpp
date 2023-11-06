#include <iostream>
#include "TDAlista.hpp"
using namespace std;

/*****
* tLista
******
* Constructor de la clase. Inicializa la lista.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* No tiene retorno.
*****/
tLista::tLista(){
    head = tail = curr = new tNodo;
    listSize = 0; pos = 0;
};

/*****
* tLista
******
* Destructor de la clase. Elimina la informacion relacionada a la lista.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* No tiene retorno.
*****/

tLista:: ~tLista(){
    tNodo* aux = head;
    while (aux != nullptr && aux->next != nullptr){
        curr = aux;
        aux = curr->next;
        delete curr;
    };
    delete tail;
    head = tail = curr = nullptr;
    listSize = 0; pos = 0;   
}

/*****
* void clear
******
* Vacia la lista.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* No tiene retorno.
*****/

void tLista::clear(){
    tNodo* aux = head;
    while (aux != nullptr && aux->next != nullptr){
        curr = aux;
        aux = curr->next;
        delete curr;
    };
    delete tail;
    head = tail = curr = nullptr;
    listSize = 0; pos = 0;
};

/*****
* void insert
******
* Inserta un elemento en al posicion actual.
******
* Input:
* tElem item : Elemento a insertar.
* .......
******
* Returns:
* void, no retorna
*****/

void tLista :: insert(tElem item){
    tNodo* aux = curr->next;
    curr->next = new tNodo;
    curr->next->info = item;
    curr->next->next = aux;
    if (curr == tail){
        tail = curr->next;
    }
    listSize++;
}

/*****
* void append
******
* Inserta un elemento en la ultima posicion de la lista.
******
* Input:
* tElem item : Elemento a insertar.
* .......
******
* Returns:
* void, no retorna
*****/

void tLista :: append(tElem item){
    tNodo* elem = new tNodo;
    elem->info = item;
    tail->next = elem;
    elem->next = nullptr;
    tail = elem;
    listSize++;
}

/*****
* void moveToStart
******
* Mueve la posicion actual al inicio de la lista.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* void, no retorna.
*****/

void tLista :: moveToStart(){
    curr = head;
    pos = 0;
};

/*****
* void moveToEnd
******
* Mueve la posicion actual al final de la lista.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* void, no retorna.
*****/

void tLista :: moveToEnd(){
    curr = tail;
    pos = listSize;
};

/*****
* void Next
******
* Mueve la posicion actual hacia el siguiente elemento
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* void, no retorna.
*****/

void tLista :: Next(){
    if (curr != tail){
        curr= curr-> next;
        pos++;
    }
}

/*****
* void Prev
******
* Mueve la posicio actual hacia el elemento anterior.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* void, no retorna.
*****/

void tLista :: Prev(){
    if (curr == head){
        return;
    }
    int Pos = pos -1;
    curr = head;
    for (int i = 0; i < Pos; i++){
        curr = curr->next;
    }
    pos--;
}

/*****
* int length
******
* largo de la lista.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* int, entrega el largo de la lista.
*****/

int tLista :: length(){
    return listSize;
}

/*****
* void currPos
******
* Posicion actual.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* int, posicion actual.
*****/

int tLista :: currPos(){
    return pos;

}

/*****
* void moveToPos
******
* Mueve la posicion actual a una determianda posicion.
******
* Input:
* unsigned int posicion : Posicion a la que se desea mover la posicion actual.
* .......
******
* Returns:
* void, no retorna.
*****/

void tLista :: moveToPos(unsigned int posicion){
    unsigned int i;
    if (posicion > listSize){
        return;
    }
    curr = head;
    pos = 0;
    for (i = 0; i < posicion; i++){
        curr = curr->next;
        pos++;
    }
}

/*****
* tElem getValue
******
* Valor almacenado en la posicion actual.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* tElem, valor almacenado en la posicion actual
*****/

tElem tLista :: getValue(){
    tElem dato;
    dato = curr->next->info;
    return dato;
}

/*****
* void Cambiar_valor
******
* Cambia la informacion almacenada en una determinada posicion-
******
* Input:
* tElem info_nueva : Nueva informacion que se desea almacenar
* unsigned int pos : Posicion en la que se encuentra el elemento a actualizar.
******
* Returns:
* void, no retorna.
*****/

void tLista::Cambiar_valor(tElem info_nueva, unsigned int pos){
    if (pos >= listSize){
        return;
    }
    
    tNodo* curr = head;
    unsigned int i = 0;
    while (i < pos) {
        curr = curr->next;
        i++;
    }
    curr->info = info_nueva;
}
