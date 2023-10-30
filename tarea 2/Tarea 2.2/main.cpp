#include <iostream>
#include <string>
#include <fstream>
#include "DeBlock.cpp"
#include "lista.cpp"
#include "ListaDeListas.cpp"

using namespace std;

int main() {
//como pinga se usaban los archivos jaskdj
fstream archivito;
archivito.open("prueba.txt", ios::in); //se supone que asi
//colocar condicion chiquibeibi
if(!archivito.is_open()) return -1; //condicion para verificar que se abre el archivo correctamente.




archivito.close();

    return 0;
}