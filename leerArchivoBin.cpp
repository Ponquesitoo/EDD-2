#include <iostream>
#include <fstream>
using namespace std;

struct Naipe {
    int numero; // va del 0 al 13
    char palo;  // pica, corazón, diamante, trebol (C,D,P,T)
    char color; // rojo o negro (R, N)
};

int main() {
    ifstream archivo("baraja.dat", ios::binary);

    //Verificar que el archivo se haya abierto correctamente
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo\n\n";
        return -1; // No se pudo abrir el archivo
    }

    // Lee el número 52
    int cantidadNaipes;
    archivo.read(reinterpret_cast<char*>(&cantidadNaipes), sizeof(int));

    // Verifica si la cantidad de naipes coincide con 52
    if (cantidadNaipes != 52) {
        cout << "El archivo no tiene el número esperado de naipes.\n\n";
        archivo.close();
        return -1;
    }

    // Lee los naipes del archivo
    Naipe baraja[cantidadNaipes];
    archivo.read(reinterpret_cast<char*>(baraja), sizeof(baraja));

    // Cierra el archivo
    archivo.close();


    //pedazo de codigo que se encarga de mostrar lo que hay por pantalla
    //ya la variable cantidadNaipes contiene el 52 y el array baraja contiene
    //todo el array de naipes
    cout << cantidadNaipes << endl;
    for(int i = 0; i < cantidadNaipes; i++) {

        cout << baraja[i].numero << " " << baraja[i].palo << " " << baraja[i].color << endl;
 

    }

    return 0;
}
