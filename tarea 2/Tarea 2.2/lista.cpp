#include <iostream>
#include "TDAlista.hpp"
using namespace std;

tLista::tLista(){
    head = tail = curr = new tNodo; //constructor
    listSize = 0; pos = 0;
};

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
} // destructor

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


void tLista :: append(tElem item){
    tNodo* elem = new tNodo;
    elem->info = item;
    tail->next = elem;
    elem->next = nullptr; // Asegura que el nuevo nodo sea el último
    tail = elem; // Actualiza la cola para apuntar al nuevo nodo
    listSize++;
}


tElem tLista :: erase(){
    tElem datos;
    tNodo* aux = curr->next;
    curr->next = curr->next->next;
    datos = aux->info; 
    pos--;
    listSize --;
    delete aux;
    return datos;
}

void tLista :: moveToStart(){
    curr = head;
    pos = 0;
};

void tLista :: moveToEnd(){
    curr = tail;
    pos = listSize;
};

void tLista :: Next(){
    if (curr != tail){
        curr= curr-> next;
        pos++;
    }
}

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

int tLista :: length(){
    return listSize;
}

int tLista :: currPos(){
    return pos;

}

void tLista :: moveToPos(unsigned int posicion){
    unsigned int i;
    if (posicion < 0 || posicion > listSize){
        return;
    }
    curr = head;
    pos = 0;
    for (i = 0; i < posicion; i++){
        curr = curr->next;
        pos++;
    }
}

tElem tLista :: getValue(){
    tElem dato = curr->next->info;
    return dato;
}

int tLista :: find(tElem dato){
    int i;
    tNodo* actual = head;
    for (i = 0; actual != tail; i++){
        if (actual->info == dato){
            return i;
        }
        actual = actual->next;
    }
    return -1;
}

void tLista :: print(){
    tNodo* actual = head->next;
    int i;
    for (i = 0; actual != tail; i++){
        cout<<"Elemento " <<i+1<< " : " <<actual->info<<endl;
        actual = actual->next;    
    }
    if (actual == tail){
        cout<<"Elemento " <<i+1<< " : " <<actual->info<<endl;
    }
}

void tLista::Cambiar_valor(tElem info_nueva, unsigned int pos) {
    if (pos < 0 || pos >= listSize) {
        return;  // Posición inválida
    }
    
    tNodo* curr = head;
    unsigned int i = 0;
    while (i < pos) {
        curr = curr->next;
        i++;
    }
    curr->info = info_nueva;
}

