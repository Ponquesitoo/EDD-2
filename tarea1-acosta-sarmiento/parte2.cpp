#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <random> 
#define min 0
#define max 53

using namespace std;

struct Naipe{

    int numero;
    char palo;
    char color;

};
int n;
int rojas = 0;
int negras = 0;
Naipe* arr_n;


/*****
* void leerBinario
******
* Lee y almacena los datos el archivo binario creado en la parte 1.
******
* Input:
* No recibe parametros
* .......
******
* Returns:
* No retorna
*****/
void leerBinario(){

  fstream file;
  file.open("baraja.dat", ios::binary | ios::in);
  file.read((char*)&n, sizeof(int));
  arr_n = new Naipe[n];
  file.read((char*)arr_n, sizeof(Naipe)*n);
  file.close();
}

/*****
* int Barajar
******
* Revuelve las cartas
******
* Input:
* No requiere parametro
* .......
******
* Returns:
* int, numero aleatorio que indica una carta al azar
*****/
int Barajar(){
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<int> dist(min, max); 
  return dist(gen); 
}

/*****
* void TipoJugada
******
* Crea un archivo de texto con una línea para cada jugador y su respectivo mazo
******
* Input:
* string juego : el juego a eleccion
* int jugadores : la cantidad de jugadores
******
* Returns:
* No tiene retorno
*****/

void TipoJugada(string juego, int jugadores){
    fstream file;
    int* pos = new int[n];
    int* ocupadas = new int[n];
    string nombre = juego + to_string(jugadores) + ".txt";
    file.open(nombre, ios::app);


    for (int i = 0; i < n; i++){
        pos[i] = 0;
        ocupadas[i] = 0;
    }

    if (juego == "P"){
        int cont = jugadores;
        for (int a = 0; a < cont; a++){
            for (int i = 0; i < 5 ; i++){
                int carta;
                do {
                    carta = Barajar();
                } while (pos[carta] != 0);

                pos[carta] = 1;
                if (arr_n[carta].color == 'R'){
                    rojas++;
                } else {
                    negras++;
                }
                file << carta << " ";
            }
            file << "\n";
        }
    } else if (juego == "B"){
        int cont = jugadores;
        for (int a = 0; a < cont; a++){
            for (int i = 0; i < 4 ; i++){
                int carta;
                do {
                    carta = Barajar();
                } while (pos[carta] != 0);

                pos[carta] = 1;
                if (arr_n[carta].color == 'R'){
                    rojas++;
                } else {
                    negras++;
                }
                file << carta << " ";
            }
            file << "\n";
        }
    } else if (juego == "C"){
        int cont = jugadores;
        for (int a = 0; a < cont; a++){
            for (int i = 0; i < 15 ; i++){
                int carta;
                do {
                    carta = Barajar();
                } while (ocupadas[carta] >= 2);
                ocupadas[carta]++; // 
                if (arr_n[carta].color == 'R'){
                    rojas++;
                } else {
                    negras++;
                }
                file << carta << " ";
            }
            file << "\n";
        }
    }
    file.close();
    delete[] pos;
    delete[] ocupadas;
}


/*****
* int main
******
* Algoritmo principa que llama a las demas funciones del programa. Muestra por pantalla la cantidad de cartas rojas y negras en el juego.
******
* Input:
* No recibe parametros
* .......
******
* Returns:
* int, 0, pues es la funcion main
*****/
int main(){
    leerBinario();
    string juego;
    int jugadores;

    cout << "Ingrese Juego (P, C o B): "<<endl;
    cin >> juego;
    cout << "Ingrese cantidad de jugadores: "<<endl;
    cin >> jugadores;
    TipoJugada(juego, jugadores);

    cout << "Cantidad de cartas Rojas: " << rojas << endl;
    cout << "Cantidad de cartas Negras: " << negras << endl;
    delete [] arr_n;
    return 0;
}
