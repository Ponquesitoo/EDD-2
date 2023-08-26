#include <iostream>
#include <fstream>
#include <string>
#define numeroNaipes 52
using namespace std;

struct Naipe {
    int numero; // va del 0 al 13
    char palo;  // pica, corazón, diamante, trebol
    char color; // rojo o negro
};

void ingresoNaipes(Naipe array[numeroNaipes]) {

    //declaracion de variables;
    char colorcito = ' ', tipo = ' ';
    //contadores
    int uno = 1, dos = 1, tres = 1, cuatro = 1;

    for(int i = 0; i < 52; i++) {

        if(i < 13) { //corazones {m, C, R}
            colorcito = 'R';
            tipo = 'C';
            array[i].numero = uno;
            array[i].palo = tipo;
            array[i].color = colorcito;

            uno++;
        }
        else if(13 <= i && i < 26) { //diamantes {m, D, R}

            colorcito = 'R';
            tipo = 'D';
            array[i].numero = dos;
            array[i].palo = tipo;
            array[i].color = colorcito;

            dos++;
        }
        else if(26 <= i && i < 39) { //picas {m, P, N}

            colorcito = 'N';
            tipo = 'P';
            array[i].numero = tres;
            array[i].palo = tipo;
            array[i].color = colorcito;

            tres++;
        }
        else if(39 <= i && i < 52) { //treboles {m, T, N}

            colorcito = 'N';
            tipo = 'T';
            array[i].numero = cuatro;
            array[i].palo = tipo;
            array[i].color = colorcito;

            cuatro++;
        }
    }
}


int main() {
    Naipe baraja[numeroNaipes];
    ingresoNaipes(baraja);

    // Abre el archivo binario en modo lectura
    ifstream archivo("baraja.dat", ios::binary);

    // Verifica si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return -1;
    }

    // Lee los datos del archivo
    for (int i = 0; i < numeroNaipes; i++) {
        archivo.read(reinterpret_cast<char*>(&baraja[i]), sizeof(Naipe));
    }

    // Cierra el archivo
    archivo.close();

    // Imprime los datos leídos
    for (int i = 0; i < numeroNaipes; i++) {
        cout << "Naipe " << i + 1 << ": " << baraja[i].numero << " " << baraja[i].palo << " " << baraja[i].color << endl;
    }

    return 0;
}
