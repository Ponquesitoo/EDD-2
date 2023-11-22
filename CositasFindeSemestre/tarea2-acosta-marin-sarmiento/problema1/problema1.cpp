/*****
INF134 - estructuras de Datos 2023-1
Tarea 2, problema 01
*****/

#include "tda.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Funciones método del TDA listaNucleotidos

/*****
* listaNucleotidos
******
* constructor de la clase listaNucleotidos, inicializa los punteros como nulos y la lista como vacía
******
* Input:
*   void: no recibe parámetros
* .......
*****/

listaNucleotidos::listaNucleotidos(){ 
    head = nullptr; tail = nullptr; curr = nullptr; 
    size = 0; pos = 0;
}


/*****
* void listaNucleotidos::append
******
* Agrega un nodo en el final de la lista
******
* Input:
*   tElemlista n: nucleotido n a insertar en el campo de información del nodo
* .......
******
* Returns:
*   void: únicamente modifica la lista
*****/

void listaNucleotidos::append(tElemLista n){
    nodo *nodoN = new nodo;
    nodoN->nucleotido = n;
    nodoN->sig = nullptr;

    if (head == nullptr)                             // en caso de estar la lista está vacía
        head = curr = tail = nodoN;
    else{
        curr = tail;
        curr->sig = nodoN;
        tail = nodoN;
    }

    size++;
    return;
}


/*****
* void listaNucleotidos::clear
******
* Elimina todos los nodos de la lista, devolviendo su memoria solicitada y reinicializando la lista como vacía
******
* Input:
*   void: no recibe parámetros
* .......
******
* Returns:
*   void: únicamente modifica la lista
*****/

void listaNucleotidos::clear(){
    nodo* aux = head;
    while(aux != nullptr && aux->sig != nullptr){
        curr = aux;
        aux = curr->sig;
        delete curr;
    }
    delete aux;
    delete tail;                                  // no entra al while para evitar posibles segfaults, por lo que se elimina por separado
    head = tail = curr = nullptr; 
    size = 0; pos = 0;

    return;
}


/*****
* void listaNucleotidos::insertar
******
* Agrega un nuevo nodo a la lista, insertando el nucleótido n en la posición i de la secuencia
******
* Input:
*   int i: posición dentro de la secuencia donde se ha de insertar el elemento
*   tElemLista: nucleótido a insertar
* .......
******
* Returns:
*   void: únicamente modifica la lista
*****/

void listaNucleotidos::insertar(int i, tElemLista n){
    if(i == 0){
        // en caso de querer realizar la inserción en la cabeza de la lista, para ahorrar definiciones
        nodo *nodoN = new nodo;
        nodoN->nucleotido = n;
        nodoN->sig = head;
        head = nodoN;
        return;
    }
    else{
        curr = head;
        for(int j = 0 ; curr != nullptr && j < i - 1 ; j++){ // para evitar segfault en caso de insertar en el final de la lista
            curr = curr->sig;
        }

        if(curr == nullptr){
            // La posición i está más allá del final actual de la lista, por lo que se realiza un append
            nodo *nodoN = new nodo;
            nodoN->nucleotido = n;
            nodoN->sig = nullptr;

            if (head == nullptr)                             
            head = curr = tail = nodoN;
            else{
            curr = tail;
            curr->sig = nodoN;
            tail = nodoN;
            }

            size++;
            return;
        }

        nodo *aux = curr->sig;                  // aux, almacena el nodo que sigue a current para eventualmente conectarlo al nuevo nodo

        nodo *nodoN = new nodo;
        nodoN->nucleotido = n;
        nodoN->sig = aux;                      // modifica el campo sig para que el nuevo nodo conecte con el resto de la lista
        curr->sig = nodoN;                     // reconecta curr con el nuevo nodo

        if (curr == tail)  tail = nodoN;

        size++;
        return;
    }
}


/*****
* void listaNucleotidos::borrar
******
* Elimina el nodo que se encuentre en la posición i de la lista, liberando su respectiva memoria dinámica
******
* Input:
*   int i: posición dentro de la secuencia donde se ha de eliminar el nucleótido
* .......
******
* Returns:
*   void: únicamente modifica la lista
*****/

void listaNucleotidos::borrar(int i){
    curr = head;                             // almacenará el nodo a reconectar
    nodo* nodoN = head;                     // almacenará el nodo a borrar, inicializado para evitar posibles comportamientos indeseados
    for(int j = 0; nodoN != nullptr && (j < i); j++){
        curr = nodoN;
        nodoN = nodoN->sig;
    }

    if(i == 0){
        head = head->sig;
    }
    else if(nodoN->sig == nullptr){
        nodoN = tail;
        curr->sig = nullptr;
        tail = curr;
    }
    else{
        curr->sig = nodoN->sig;
    }

    delete nodoN;
    size--;
    return;
}


/*****
* void listaNucleotidos::intercambiar
******
* Intercambia el nucleótido de la posición i de la secuencia base por n
******
* Input:
*   int i: posición dentro de la secuencia donde se ha de intercambiar el elemento
*   tElemLista: nucleótido a intercambiar
* .......
******
* Returns:
*   void: únicamente modifica la lista
*****/

void listaNucleotidos::intercambiar(int i, tElemLista n){
    curr = head;
    for (int j = 0; j < i; j++){
        curr = curr-> sig;
    }
    curr->nucleotido = n;
    return;
}


/*****
* void listaNucleotidos::exportToTextFile
******
* Recibe las listas a imprimir en el archivo de salida, y las escribe en él mediante escritura con formato
******
* Input:
*   void: no recibe parámetros
* .......
******
* Returns:
*   void: únicamente modifica el archivo
*****/

void listaNucleotidos::exportToTextFile(){
    fstream rec;
    rec.open("secuencias-reconstruidas.txt", ios::app);

    curr = head;
    while (curr != nullptr) {
        rec << curr->nucleotido ;
        curr = curr->sig;
    }
    rec << "\n";
    rec.close();
}


/*****
* ~listaNucleotidos
******
* Destructor de la clase listaNucleotidos; llama a clear para reinicializar la lista como vacía y soltar la memoria solicitada
******
* Input:
*   void: no recibe parámetros
* .......
*****/

listaNucleotidos::~listaNucleotidos(){ 
    clear(); 
}; 
        

int main(){

    // apertura de archivos
    ifstream txt;
    txt.open("secuencias-nucleotidos.txt");
    if (!txt.is_open()){
        cerr << "No se pudo abrir el archivo de entrada" << endl;
        return 1;
    }

    fstream rec;
    rec.open("secuencias-reconstruidas.txt", ios::out);
    if (!rec.is_open()){
        cerr << "No se pudo abrir el archivo de salida" << endl;
        return 1;
    }
    rec.close();

    // declaración de variables
    int largo, k, mod, l, m, a, i; 
    string modificacion, temp;

    txt >> temp;
    largo = stoi(temp); 
    char secuenciaBase[largo], n;
    txt >> secuenciaBase;
    txt >> temp; 
    k = stoi(temp);

    // reconstrucción de secuencias
    for(a = 0; a < k; a++){
        // en cada iteración crea una nueva instancia; pues crear una base y reinicializarla resulta más costoso
        listaNucleotidos *secuencia = new listaNucleotidos();
        for(l = 0; l < largo; l++){    
            n = secuenciaBase[l];
            secuencia->append(n);
        }

        txt >> temp;
        mod = stoi(temp); 
        for(m = 0; m < mod; m++){
            txt >> modificacion; 
            if (modificacion=="INSERTAR"){
                txt >> temp;
                i = stoi(temp);
                txt >> n;
                secuencia->insertar(i, n);
            }
            else if (modificacion=="INTERCAMBIAR"){
                txt >> temp;
                i = stoi(temp);
                txt >> n;
                secuencia->intercambiar(i, n);
            }
            else{
                txt >> temp;
                i = stoi(temp); 
                secuencia->borrar(i);
            }
        }
        
        secuencia->exportToTextFile(); 
        secuencia->clear();
    }
    
    txt.close();
    return 0;
}