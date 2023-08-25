//codigo binario
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Naipe{

    int numero; //va del 0 al 13
    char palo; //pica, corazon, diamante, trebol
    char color; //rojo o negro

};

//funcion para general naipes
void generarN(Naipe N[]) {

    int contador = 0;

    for(int numero = 1; numero <= 13; numero++) {

        Naipe Naipes;
        Naipes.numero;
        Naipes.palo;
        Naipes.color;


    }


}

int main(){
    //arreglo de naipes


    //abrimos el archivo
    ofstream archivo;//ofstream sirve solo para escribir
    archivo.open("baraja.dat", ios::binary);
    //hay que asegurarnos que el archivo se haya abierto correctamente
    if(!archivo.is_open()) {

        cout << "No se pudo abrir el archivo\n\n";
        return -1; //no se pudo abrir el archivo
    }
    else {//se pudo abrir el archivo
    //declaracion de variables
    int Cant_Naipes = 52;




    }
    archivo.close();

    return 0;
}
