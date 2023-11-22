/***** 
TDA listaNucleotidos
*****/

typedef char tElemLista;

class listaNucleotidos{
    private:        
        struct nodo{
            tElemLista nucleotido;
            struct nodo *sig;
        };
        nodo *head;
        nodo *tail;
        nodo *curr;
        unsigned size;
        unsigned pos;

    public:
        listaNucleotidos();
        ~listaNucleotidos();
        void append(tElemLista n);
        void clear();
        void insertar(int i, tElemLista n);
        void borrar(int i);
        void intercambiar(int i, tElemLista n);
        void exportToTextFile();
};