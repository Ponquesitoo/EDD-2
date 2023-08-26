//codigo binario
#include <iostream>
#include <fstream>
#include <string>
#define numeroNaipes 52
using namespace std;


struct Naipe{

    int numero; //va del 0 al 13
    char palo; //pica, corazon, diamante, trebol
    char color; //rojo o negro

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

int main(){
    
    Naipe baraja[numeroNaipes];
    ingresoNaipes(baraja);

    //abrimos el archivo
    ofstream archivo;//ofstream sirve solo para escribir
    archivo.open("baraja.dat", ios::binary);
    //hay que asegurarnos que el archivo se haya abierto correctamente
    if(!archivo.is_open()) {

        cout << "No se pudo abrir el archivo\n\n";
        return -1; //no se pudo abrir el archivo
    }
    else {//se pudo abrir el archivo

        archivo.write(reinterpret_cast<char*>(baraja), sizeof(baraja));

    }
    archivo.close();

    return 0;
}
