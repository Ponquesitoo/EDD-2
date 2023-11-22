//funciones del tda
#include <iostream>
#include <string>
#include "tda.hpp"

#define M 1000000
#define VACIA -1
#define VALORINVALIDO -2


//constructor
Hash::Hash() {

}
//destructor aux
void Hash::clear() {

}
//destructor
Hash::~Hash() {
    clear();
}

//las funciones solicitadas en la tarea
int Hash::p(tipoClave k, int i) {
    return i;
}
int Hash::h(tipoClave k) {
    int posicion = VACIA;
    for(int i = 0; i < M; i++) {
        if(HT[i].clave == k) {
            posicion = i;
            break
        }
    }
}

int Hash::hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
    int inicio, x;
    int posicion = inicio = h(k);
    for(x = 1; )
}