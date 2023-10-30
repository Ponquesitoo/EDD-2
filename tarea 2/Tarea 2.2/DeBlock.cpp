#include <iostream>
#include "TDADeBlock.hpp"
#include "TDAlistaDeListas.hpp"
using namespace std;
//>, <

DeBlock::DeBlock(tElem* elems, int n, int b) {
    int a = n / b;
    if (n % b != 0) {
        a += 1;
    }
    cant_elems = a;

    int i = 0;
    while (i < n) {
        tLista Lista;
        for (int j = 0; j < b; j++) {
            tElem valor = elems[i];
            Lista.append(valor);
            i++;
        }
        L.append(Lista);
    }
}

void DeBlock::print(){
    L.print();
}

void DeBlock::clear(){
    L.clear();
}

DeBlock::~DeBlock(){
    cant_elems = 0;
}


int DeBlock::insert(int pos, tElem elem){
    int a = L.Insert_block(pos, elem);
    //cout<<a<<endl;
    return a;
}

tElem DeBlock::get_value(int pos){
    tElem elem;
    elem = L.GetValue_block(pos);
    cout<<elem<<endl;
    return elem;
}

int DeBlock::length(){
    return L.Length_block();
}

