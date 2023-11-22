typedef int tElem;

struct Nodo{

    tElem numero;
    Nodo* izquierdo;
    Nodo* derecho;

};

class Arbol{

    private:

        Nodo* raiz;
        tElem pos; 

        void insertarNodo(tElem, Nodo* &); 
        Nodo* crearNodo(tElem); 
        bool busqueda(tElem, Nodo*); 
        int encontrarNodo(tElem, Nodo*); 
        void clearHelp(Nodo*);
    
    public:

        Arbol();
        ~Arbol(); 
        void clear();
        void insert(tElem pos);
        bool find(tElem pos);
        int lower_bound(tElem pos);
};
