/***
INF134 - Estructuras de Datos 2023-1
Tarea 3, Problema 2: Comandos
***/

#include "funcionesComando.cpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  int sent = 0, created = 0;
  heap comandosHeap = heap(20);

  string instruccion, push, GET, term, comando, output = "";
  comando = "";

  while (getline(cin, instruccion) && comando != "TERMINATE") {
    istringstream niau(instruccion);
    niau >> comando;

    if (comando == "PUSHCOMMAND") {
      string parametro1;
      int parametro2;
      string parametro3;

      niau >> parametro1 >> parametro2;
      getline(niau >> ws, parametro3);
      push = pushCommand(parametro1, parametro2, parametro3, &comandosHeap);
      output = output + push;
      created++;
    }

    else if (comando == "GET") {
      int parametro;
      niau >> parametro;
      GET = get(parametro, &comandosHeap);
      output = output + GET;

      if (GET == "0 \n")
        sent = sent;
      else
        sent = sent + parametro;
    }

    else if (comando == "TERMINATE") {
      terminate(&comandosHeap);
      term = to_string(sent) + " SENT " + to_string(created) + " CREATED \n";
      output = output + term;
      break;
    }

    else {
      cout << "Ingrese una instrucción válida: " << comando << endl;
    }
  }

  cout << "\n" << output << endl;
  return 0;
}