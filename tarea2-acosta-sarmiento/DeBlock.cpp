#include <iostream>
#include "TDADeBlock.hpp"
#include "TDAlistaDeListas.hpp"
using namespace std;

/*****
* DeBlock NombreFunción
******
* Constructor de la clase. Divide el arreglo y lo almacena en una lista de listas.
******
* Input:
* tElem elems : arreglo que almacena elementos de tipo
* int n : largo del arreglo
* int b : tamaño máximo de las sublistas.
******
* Returns:
* No tiene retorno.
*****/
DeBlock::DeBlock(tElem* elems, int n, int b) {
    int cant_listas = n / b;
    if (n % b != 0) {
        cant_listas += 1;
    }
    cant_elems = n;

    int i = 0;
    int e = 0;
    while (e < cant_listas) {
        tLista Lista;
        for (int j = 0; j < b && i <= n; j++){
            tElem valor = elems[i];
            Lista.append(valor);
            i++;
            if (i > n){
                break;
            }
        }
        L.append(Lista);
        e++;
    }
}


/*****
* void clear
******
* Vacía la lista.
******
* Input:
* No recibe parametros.
* .......
******
* Returns:
* Tipo void. No tiene retorno.
*****/

void DeBlock::clear(){
    L.clear();
}

/*****
* DeBlock
******
* Destructor de la clase. Reinicializa la lista.
******
* Input:
* No recibe parámetros.
* .......
******
* Returns:
* No tiene retorno.
*****/

DeBlock::~DeBlock(){
    cant_elems = 0;
    L.clear();
}

/*****
* int insert
******
* Llamada a la funcion Insert_block.
* Inserta un elemento en una posicion determinada.
******
* Input:
* int pos : Posicion en al que se desea insertar el elemento
* tElem elem : Elemento a insertar
******
* Returns:
* int; retorna lo que devuelve la funcion Insert_Block.
*****/

int DeBlock::insert(int pos, tElem elem){
    int a = L.Insert_block(pos, elem);
    cant_elems++;
    return a;
}

/*****
* tElem get_value
******
* Llamada a la funcion GetValue_block.
* Obtiene el elemento que se encuentra en determinada posicion 
******
* Input:
* int pos : Posicion de la que se quiere obtener el valor almacenado.
* .......
******
* Returns:
* tElem; lo que retorna la funcion GetValue_block
*****/

tElem DeBlock::get_value(int pos){
    tElem elem;
    elem = L.GetValue_block(pos);
    return elem;
}

/*****
* int length
******
* Cantidad de elementos en la lista de listas
******
* Input:
* No requiere input
* .......
******
* Returns:
* int; cantidad de elementos en la lista de listas.
*****/

int DeBlock::length(){
    return cant_elems;
}

