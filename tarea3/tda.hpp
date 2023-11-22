//tda hashing
#include <string>
#include <iostream>
using namespace std;
#define M 1000000
#define VACIA -1
#define VALORINVALIDO -2

typedef int tipoClave;
typedef string tipoInfo;
struct ranura{
    tipoClave clave;
    tipoInfo info;
};
class Hash {
    
    private:
        void clear(); //funcion auxiliar de el destructor
    public:
        Hash();
        ~Hash();
        int hashInsert(ranura HT[], tipoClave k, tipoInfo I);
        tipoInfo hashDelete(ranura HT[], tipoClave k);
        tipoInfo hashSearch(ranura HT[], tipoClave k);
        int h(tipoClave k);
        int p(tipoClave k, int i);
};

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
    for(x = 1;HT[posicion].clave != VACIA && HT[posicion].clave != k; x++) {
        posicion = (inicio + p(k,x))%M;
    }
    if(HT[posicion].clave == k) return 0; //insercion no exitosa
    else{
        HT[posicion].clave = k;
        HT[posicion].info = I;
        return 1; //insersion exitosa
    }
}
//tipoInfo Hash::hashDelete(ranura HT[], tipoClave k){}

tipoInfo Hash::hashSearch(ranura HT[], tipoClave k) {
    int inicio;
    int posicion = inicio = h(k);
    for(int x = 1; HT[posicion].clave != VACIA && HT[posicion].clave != k; x++) {
        posicion = (inicio + p(k,x))%M;
    }
    if(HT[posicion].clave == k) return HT[posicion].info;
    else {
        return VALORINVALIDO; //esto creo que esta mal pero pasarlo por chatgpt
    }
}

//******************************************************************
int main() {

    Hash funcion;
    int pw, numero;
    string inf;
    cout << "ingrese numero de claves a ingresar" << endl;
    cin >> numero;
    int contador = 0
    while(contador < numero) {
        cout <<\t"(" << contador+1 << ") " << endl;
        cout << "ingrese clave asociada" << endl;
        cin >> pw;
        cout << "ingrese informacion asociada" << endl;
        cin >> inf;
        cout << "*********************************************" << endl;
        //prueba de las funciones
    }
    return 0;
}
