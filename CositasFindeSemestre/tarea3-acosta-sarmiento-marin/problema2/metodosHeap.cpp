/***
Tarea 3
Problema 2: Comandos - TDA heap, funciones método
***/

#include "tda.hpp"
using namespace std;

/*****
* heap::heap
******
* Constructor de la clase heap. 
Genera un array de tamaño maxsize donde se soportará la cola de prioridad, e inserta el elemento pivote. 
******
* Input:
*   int maxsize: indica el tamaño máximo del heap, es decir, el tamaño del arreglo
* .......
*****/

heap::heap(int maxsize){
    maxSize = maxsize;
    heapSize = 1; // incluyendo el elemento pivote
    curr = 0;
    heapArray = new comando[maxSize];

    heapArray[0].ID = "pivote";
    heapArray[0].priority = 0;
    heapArray[0].instruction = " ";
}


/*****
* void heap::clearColaP
******
* Reinicia la cola de prioridad, dejandola vacía
******
* Input:
*   void, no recibe parámetros
* .......
******
* Returns:
*   void, solo modifica la estructura
*****/

void heap::clearColaP(){
    delete[] heapArray;     
    heapArray = new comando[maxSize];
    heapSize = curr = 0;
}


/*****
* comando heap::findMax
******
* Encuentra el elemento de mayor prioridad del conjunto
******
* Input:
*   void, no recibe parámetros
* .......
******
* Returns:
*   comando, retorna el elemento que se encuentra en la raíz de la cola de prioridad
*****/

comando heap::findMax(){
    return heapArray[1];
}


/*****
* int heap::sizeColaP
******
* Entrega la cantidad de elementos en la cola prioridad
******
* Input:
*   void, no recibe parámetros
* .......
******
* Returns:
*   int, retorna el tamaño del heap sin contar el elemento pivote
*****/

int heap::sizeColaP(){
    return heapSize - 1;
}


/*****
* int heap::maxSizeColaP
******
* Entrega la cantidad máxima de elementos que puede poseer la cola de prioridad
******
* Input:
*   void, no recibe parámetros
* .......
******
* Returns:
*   int, retorna el tamaño del arreglo
*****/

int heap::maxSizeColaP(){
    return maxSize;
}


/*****
* void heap::removeMax
******
* Elimina el elemento de máxima prioridad del conjunto
******
* Input:
*   void, no recibe parámetros
* .......
******
* Returns:
*   void, solo modifica la estructura
*****/

void heap::removeMax(){
    heapArray[1] = heapArray[heapSize - 1];  // intercambia la raiz por la ultima hoja
    heapSize--;
    // heapArray[heapSize - 1]; borrar

    // hundir
    int nodo, izq, der, min;
    for(int i = 1; 2*i+1 <= heapSize && (heapArray[i].priority > heapArray[i*2].priority || heapArray[i].priority > heapArray[2*i+1].priority) ; i = min){
        nodo = heapArray[i].priority;
        izq = heapArray[i*2].priority;
        der = heapArray[2*i+1].priority;

        if (izq < der) min = i*2;
        else min = i*2+1;

        comando aux = heapArray[i];
        heapArray[i] = heapArray[min];
        heapArray[min] = aux;
    }
}

 
/*****
* void heap::insertColaP
******
* Inserta el elemento “item” en la cola de prioridad
******
* Input:
*   comando item: comando a insertar, corresponde a un struct de tres componentes, un identificador, su prioridad correspondiente, y la instrucción a ejecutar
* .......
******
* Returns:
*   void, solo modifica la estructura
*****/

void heap::insertColaP(comando item){
    if (heapSize == maxSize) return;
    
    heapArray[heapSize] = item;

    int i = heapSize;
    while (heapArray[i].priority < heapArray[i/2].priority & i != 1){
        comando aux = heapArray[i];
        heapArray[i] = heapArray[i/2];
        heapArray[i/2] = aux;

        i = i/2;
    }
    
    heapSize++;
    return;
}


/*****
* void heap::resizeColaP
******
* Aumenta el tamaño del arreglo en la cantidad de unidades indicada
* Traslada el arreglo actual a uno nuevo de mayor tamaño, para posteriormente eliminar el antiguo
******
* Input:
*   int nuevasCeldas: cantidad de celdas a agregar al tamaño máximo del arreglo
* .......
******
* Returns:
*   void, solo modifica la estructura
*****/

void heap::resizeColaP(int nuevasCeldas){
    maxSize = maxSize + nuevasCeldas;
    comando aux[maxSize]; // almacena el arreglo anterior
    
    delete[] heapArray;     
    heapArray = nullptr;
    heapArray = new comando[maxSize];

    for (int i = 0 ; i < heapSize; i++){
        heapArray[i].ID = aux[i].ID;
        heapArray[i].priority = aux[i].priority;
        heapArray[i].instruction = aux[i].instruction;
    }
    
}

/*****
* heap::~heap
******
* Destructor de la clase heap.  
Elimina el arreglo que soporta la cola de prioridad, devolviendo la memoria correspondiente, y reinicia el valor de los atributos del objeto
******
* Input:
*   void, no recibe parámetros
*****/

// destructor de la clase
heap::~heap(){
    delete[] heapArray;     
    heapArray = nullptr;
    
    maxSize = heapSize = curr = 0;
}   

