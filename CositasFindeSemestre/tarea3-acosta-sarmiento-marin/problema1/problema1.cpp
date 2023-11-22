#include <iostream>
#include <string>
#include "TDA.hpp"
#include "hash.hpp"
using namespace std;

int main(){

    Hashing hash; 
    Login log; 
    int operacion;

    string completo, operacionSTR, usuarioSTR, contrasenaSTR, nueva_contrasena;

    do {
        cout << "";
        getline(cin, completo);
        size_t espacio1 = completo.find(' ');
        size_t espacio2 = completo.find(' ', espacio1 + 1);

        if (espacio1 != string::npos && espacio2 != string::npos) {

            operacionSTR = completo.substr(0, espacio1);
            usuarioSTR = completo.substr(espacio1 + 1, espacio2 - espacio1 - 1);
            contrasenaSTR = completo.substr(espacio2 + 1);

            if (operacionSTR == "INICIAR_SESION") {
                
                operacion = 1;
            }
            else if (operacionSTR == "REGISTRAR") {

                operacion = 2;
            }
            else if (operacionSTR == "ACTUALIZAR") {
                
                operacion = 3;
            }
        }
        else if (completo == "FINALIZAR") {
            operacion = 4;
        }

        switch(operacion){

            case 1:
                
                log.iniciar_sesion(usuarioSTR, contrasenaSTR);

                break;

            case 2:

                log.crear_nuevo_usuario(usuarioSTR, contrasenaSTR);

                break;

            case 3:
                
                nueva_contrasena = contrasenaSTR;
                log.cambiar_clave(usuarioSTR, nueva_contrasena);

                break;
        }

    }while(operacion != 4); 

    return 0;
}