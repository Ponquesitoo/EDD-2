#include <iostream>
#include "TDAlistaDeListas.hpp"
using namespace std;

#define MAXSIZE 1000000

//tListadeListas


tListadeListas::tListadeListas(){
    maxSize = MAXSIZE;
    listSize = 0;
    curr = 0;
    listArray = new tLista[maxSize];
}

tListadeListas::~tListadeListas(){
    delete[] listArray;
}
  


void tListadeListas::clear(){
    for (int i = 0; i < listSize; i++) {
        listArray[i].clear();
    }

    delete[] listArray;
    listArray = nullptr;
    listSize = curr = 0;
}

int tListadeListas::insert(tLista &lista){
    int i, mayor;
    if (listSize >= maxSize){
        return -1;
    }


    for (i = listSize; i > curr; i--){
        listArray[i] = listArray[i-1];
    }


    if (listArray[i].length() <= lista.length()){
        mayor = lista.length();
    } else {
        mayor = listArray[i].length();
    }
    listSize++;
    lista.moveToStart();
    for (int a = 0; a < mayor; a++){
        int pos = lista.currPos();
        tElem nuevo = lista.getValue();
        listArray[i].Cambiar_valor(nuevo, pos);
        lista.Next();
    }
    return i;
}

int tListadeListas::Length_block() {
    int largo = 1;
    for (int i = 0; i < listSize; i++) {
        largo += listArray[i].length();
    }
    cout << largo << endl;
    return largo;
}


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
    //cout<<"1";
    return retorno;
}

int tListadeListas::append(tLista &lista){
    if (listSize >= maxSize){
        return 0;
    }
    int i = listSize + 1;
    listArray[i] = lista;
    listSize++;
    return 1;
}

void tListadeListas::moveToStart(){
    curr = 0;
}

void tListadeListas::moveToEnd(){
    curr = listSize;
}

void tListadeListas::moveToPos(int pos){
    curr = pos;
}

void tListadeListas::next(){
    if (curr > listSize){
        curr++;
    }
}

void tListadeListas::prev(){
    if (curr != 0){
        curr--;
    }
}

int tListadeListas::Length(){
    return listSize;
}

/*
int tListadeListas::Length_block(){
    int largo = 0;
    for (int i = 0; i < listSize; i++){
        largo += listArray[i].length();
    }
    return largo;
}
*/

int tListadeListas::currPos(){
    return curr;
}

tLista* tListadeListas::GetValue(){
    if (curr >= 0 && curr <= listSize){
        return &listArray[curr];
    }
    else {
    	return nullptr;
    }
}

tElem tListadeListas::GetValue_block(int pos){
    int cont = 0;
    tElem elem;

    int largo = 0;
    for (int i = 0; i < listSize; i++) {
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
            break;
        } else {
            cont = cont + listArray[i].length();
        }
    }
    return elem;
}

void tListadeListas::print(){
    for (int i = 0; i < listSize; i++) {
        cout << "Lista: " << i << endl;
        listArray[i].print();   
    }
}

    
