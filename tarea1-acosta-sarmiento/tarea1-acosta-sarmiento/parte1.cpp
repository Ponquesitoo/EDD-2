//codigo binario
#include <iostream>
#include <fstream>
#include <string>
#define numeroNaipes 52
using namespace std;


struct Naipe{

    int numero; 
    char palo; 
    char color; 

};

/*****
* void ingresoNaipes
******
* Crea e ingresa los naipes dentro de un arreglo de structs tipo Naipe, de esa manera creandose la baraja de naipes.
******
* Input:
* Naipe array[numeroNaipes] : es un arreglo vacio, que contiene el numero de naipes de una baraja.
* .......
******
* Returns:
* No retorna
*****/

void ingresoNaipes(Naipe array[numeroNaipes]) {

    char colorcito = ' ', tipo = ' ';
    int uno = 1, dos = 1, tres = 1, cuatro = 1;

    for(int i = 0; i < 52; i++) {

        if(i < 13) {
            colorcito = 'R';
            tipo = 'C';
            array[i].numero = uno;
            array[i].palo = tipo;
            array[i].color = colorcito;

            uno++;
        }
        else if(13 <= i && i < 26) {

            colorcito = 'R';
            tipo = 'D';
            array[i].numero = dos;
            array[i].palo = tipo;
            array[i].color = colorcito;

            dos++;
        }
        else if(26 <= i && i < 39) {

            colorcito = 'N';
            tipo = 'P';
            array[i].numero = tres;
            array[i].palo = tipo;
            array[i].color = colorcito;

            tres++;
        }
        else if(39 <= i && i < 52) {

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

    
    ofstream archivo;
    archivo.open("baraja.dat", ios::binary);
    if(!archivo.is_open()) {

        cout << "No se pudo abrir el archivo\n\n";
        return -1; 
    }
    else {

        int cantidadNaipes = numeroNaipes;
        archivo.write(reinterpret_cast<char*>(&cantidadNaipes),sizeof(int));
        archivo.write(reinterpret_cast<char*>(baraja), sizeof(baraja));

    }
    archivo.close();

    return 0;
}
