#include "tdaHash.hpp"
#include <string>
#include <iostream>
using namespace std;

//constructor
Hash::Hash() {

    //revisar como inicializar struct vacio.

}

//hacer funcion void primero antes que el destructor
void Hash::clear() {



}
//destructor
Hash::~Hash() {

    clear();

}
//resto de funciones:
int Hash::p(tipoClave k, int i) {
    return i;
}
int Hash::h(tipoClave k) {
    int posicion = VACIA;
    for(int i = 0; i < M; i++) {
        if(HT[i].clave == k) {
            posicion = i;
            break;
        }
    }
    if(posicion != VACIA){
        return posicion;
    }
    else{
        return -2;
    }
}
int Hash::hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
    int inicio, x;
    int posicion = inicio = h(k);
    for(x = 1; HT[posicion].clave != VACIA && HT[posicion].clave != k; x++){

        posicion = (inicio + p(k, x))%M;    
    }
    if(HT[posicion].clave == k) return 0; //insersion no exitosa
    else {
        HT[posicion].clave = k;
        HT[posicion].info = I;
        return 1; //insercion exitosa
    }
}


tipoInfo Hash::hashDelete(ranura HT[], tipoClave k) {


}

tipoInfo Hash::hashSearch(ranura Ht[], tipoClave k) {
    int inicio;
    int posicion = inicio = h(k);
    for(int x = 1; HT[posicion].clave != VACIA && HT[posicion].clave != k; x++){
        posicion = (inicio + p(k, x))%M;
    }
    if(HT[posicion].clave == k) return HT[posicion].info;
    else{
        return VALORINVALIDO;
    }
}

