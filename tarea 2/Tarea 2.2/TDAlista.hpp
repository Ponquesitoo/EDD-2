
//>, <

#include <iostream>

using namespace std;

#pragma once

typedef int tElem;

struct tNodo{
    tElem info;
    tNodo* next;
};

class tLista {  
    private:
        tNodo* head;    
        tNodo* tail;    
        tNodo* curr; //apunta al nodo anterior del actual    
        unsigned int listSize;    
        unsigned int pos; // posicion actual en la lista
    public:
        tLista();
        ~tLista();
        void clear();
        void insert(tElem item);
        void append(tElem item);
        tElem erase ();
        void moveToStart();
        void moveToEnd();
        void Next();
        void Prev();
        int length();
        int currPos();
        void moveToPos(unsigned int posicion);
        tElem getValue();
        int find(tElem info);
        void print();
        void Cambiar_valor(tElem info_nueva, unsigned int pos);
};

