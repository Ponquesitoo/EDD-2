/***
Tarea 3
Problema 2: Comandos - TDA heap
***/

#include <string>
using namespace std;

struct comando{
    string ID;
    int priority;
    string instruction;
};

class heap{
    private:
        unsigned int maxSize; // tamaño máximo del heap
        unsigned int heapSize; // tamaño actual del heap
        unsigned int curr; // posición actual en el heap
        comando* heapArray; // arreglo con los elementos del heap

    public:
        heap(int maxsize);
        void clearColaP(); // elimina todos los elementos de una cola de prioridad, dejándola vacía
        comando findMax(); // encuentra el máximo elemento del conjunto
        int sizeColaP(); // cantidad de elementos en la cola prioridad
        int maxSizeColaP(); // cantidad máxima de elementos que puede poseer la cola de prioridad
        void removeMax(); // elimina el máximo elemento del conjunto
        void insertColaP(comando item); // inserta un elemento “item” en la cola de prioridad
        void resizeColaP(int nuevasCeldas); // aumenta el tamaño del arreglo en nuevasCeldas unidades
        ~heap();
};