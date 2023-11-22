#define M 1000000
#define VACIA -1
#define VALORINVALIDO 0
#include <string>
using namespace std;
//vamos a hacer hashing lineal y que pasaaaa
typedef int tipoClave;
typedef string tipoInfo;

class Hash{

    private:
        struct ranura {
            tipoClave clave;
            tipoInfo info;
        };
        ranura HT[M];
        //funciones aux
        void clear(); //funcion aux del destructor.
    public:
        Hash();
        ~Hash();
        int hashInsert(ranura HT[], tipoClave k, tipoInfo I); //retorna 1 si se inserto correctamente y 0 si no
        tipoInfo hashDelete(ranura HT[], tipoClave k); //elimina la clave y retornar la info, sino retornar valor invalido
        tipoInfo hashSearch(ranura HT[], tipoClave k); //retorna informacion asociada a la clave
        int h(tipoClave k); //retorna pos dentro de la tabla hash
        int p(tipoClave k, int i);
};  