#include <iostream>
#include "TDADeBlock.hpp"
using namespace std;

//>, <

int main() {
    
    tElem elems[10] = {1, 2, 3, 4, 6, 7, 8, 9, 10, 8};
    DeBlock List(elems, 10, 3);
    List.insert(2, 5);
    //List.get_value(5);
    List.length();
    return 0;
}

/*
g++ DeBlock.cpp ListaDeListas.cpp lista.cpp prueba.cpp -Wall -o prueba-comp
.\prueba-comp
g++ -g DeBlock.cpp ListaDeListas.cpp lista.cpp prueba.cpp -Wall -o depurado
*/