#include <iostream>
#include <string>
#include <fstream>
#include "DeBlock.cpp"
#include "lista.cpp"
#include "ListaDeListas.cpp"

using namespace std;

int main() {

    string linea1, linea2, linea3, linea;
    int arreglo1[2];  // Arreglo linea1

    fstream archivito;
    archivito.open("pruebas.txt", ios::in);
    if (!archivito.is_open()) {
        cout << "El archivo no se abrio. leer README.txt" << endl;
        return -1;
    }
    getline(archivito, linea1);
    getline(archivito, linea2);
    getline(archivito, linea3);

    // Linea1
    size_t espacio = linea1.find(' ');
    if (espacio != string::npos) {
        arreglo1[0] = stoi(linea1.substr(0, espacio));
        arreglo1[1] = stoi(linea1.substr(espacio + 1));
    }
    // Linea2
    int tamanio = arreglo1[0];
    int tamanio_bloq = arreglo1[1];
    int arreglo2[tamanio];
    string num = "";
    int x = 0;
    for (int i = 0; i < (int)linea2.length(); i++) {
        char caracter = linea2[i];
        if (caracter == ' ') {
            int numero = stoi(num);
            arreglo2[x] = numero;
            x++;
            num = "";
        } else {
            num += caracter;
        }
    }
    if (!num.empty()) {
        int numero = stoi(num);
        arreglo2[x] = numero;
    }
    
    //linea3
    long int cant_operaciones = stoi(linea3);
    //inicializacion de TDA's
    tLista lista;
    tListadeListas listaremix;
    DeBlock blockie(arreglo2, tamanio, tamanio_bloq);
    //desarrollo con operaciones
    int contadorcito = 1;
    while (contadorcito <= cant_operaciones) {
        getline(archivito, linea);
        char letra = linea[0];
        //letra I
        if (letra == 'I') {
            int numero1 = 0, numero2 = 0, restriccion = 0; 
            string numerito = "";
            
            for (int a = 2; a < (int)linea.length(); a++) {
                char caracter = linea[a];
                if (caracter == ' ') {
                    if (!numerito.empty()) {
                        if (restriccion == 0) {
                            numero1 = stoi(numerito);
                        } else if (restriccion == 1) {
                            numero2 = stoi(numerito);
                        }
                        numerito = "";
                    }
                    restriccion++;
                    continue;
                }
                numerito += caracter;
            }
            if (!numerito.empty()) {
                if (restriccion == 0) {
                    numero1 = stoi(numerito);
                } else if (restriccion == 1) {
                    numero2 = stoi(numerito);
                }
            }
            cout << blockie.insert(numero2, numero1) << endl;
        }
        //letra G
        else if (letra == 'G') {
            int numero3 = 0;
            string numerote;
            for (int b = 2; b < (int)linea.length(); b++) {

                char caracter = linea[b];
                numerote += caracter;
            }
            numero3 = stoi(numerote);
    
            cout << blockie.get_value(numero3) << endl;
        } 
        //letra L
        else if (letra == 'L') {
           cout << blockie.length() << endl;
        }
    contadorcito++;
    }
    blockie.clear();
    archivito.close();
    return 0;
}