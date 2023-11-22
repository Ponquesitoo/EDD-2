/**
Tarea 3
Problema 2: Comandos - Funciones
**/

#include "metodosHeap.cpp"
using namespace std;

/*****
 * string pushCommand
 ******
 * Crea un nuevo comando a ser enviado a los dispositivos
 * Recibe las tres componentes del comando y las posiciona en un struct, y
 *posteriormente invoca a la función método insertColaP para insertarlo En caso
 *de no poseer espacio suficiente, solicita un resize para la cola de prioridad
 ******
 * Input:
 *   string id: identificador del comando
 *   int prty: prioridad del comando
 *   string ins: instrucción del comando
 *
 *   heap *comandosHeap: puntero a la cola de prioridad que almacena los
 *comandos que no han sido consumidos
 * .......
 ******
 * Returns:
 *   string, retorna una linea con la cantidad de comandos pendientes por enviar
 *seguido de PENDING
 *****/

string pushCommand(string id, int prty, string ins, heap *comandosHeap) {
  if (comandosHeap->maxSizeColaP() == comandosHeap->sizeColaP())
    comandosHeap->resizeColaP(15); // para no andar mandando tdo el rato

  // crear comando
  comando x;
  x.ID = id;
  x.priority = prty;
  x.instruction = ins;

  // inserta el comando en la cola de prioridad
  comandosHeap->insertColaP(x);

  // output
  string push = to_string(comandosHeap->sizeColaP()) + " PENDING \n";
  return push;
}

/*****
 * string get
 ******
 * Entrega N comandos al dispositivo para que sean ejecutados
 * Hasta enviar los N comandos, obtiene la información del máximo elemento de la
 *cola de prioridad, y lo almacena correspondientemente en un string En caso de
 *que no hayan comandos por enviar, retorna 0
 ******
 * Input:
 *   int N: cantidad de comandos que deben ser entregados
 *   heap *comandosHeap: puntero a la cola de prioridad que almacena los
 *comandos que no han sido consumidos
 * .......
 ******
 * Returns:
 *   string, retorna N + 1 lineas de texto, tal que:
 *       Linea 1: corresponde al entero N seguido de los identificadores de los
 *comandos a enviar Lineas 2-(N+1): entrega la instrucción correspondiente a
 *cada comando enviado
 *****/

string get(int N, heap *comandosHeap) {

  if (comandosHeap->sizeColaP() == 0) {
    string GET = "0 \n";
    return GET;
  }

  string linea01, id, linea0N, instruccion;
  linea01 = to_string(N);
  linea0N = "";

  for (int n = 0; n < N; n++) {
    if (comandosHeap->sizeColaP() == 0) {
      linea01 = linea01 + " ";
      linea0N = linea0N + "\n";
    }

    else {
      // recuperar comando de mayor prioridad
      comando x = comandosHeap->findMax();

      id = x.ID;
      linea01 = linea01 + " " + id;

      instruccion = x.instruction;
      linea0N = linea0N + instruccion + "\n";

      // eliminar max
      comandosHeap->removeMax();
    }
  }

  string GET = linea01 + "\n" + linea0N;
  return GET;
}

/*****
 * void terminate
 ******
 * Limpia los recursos utilizados por la cola de prioridad.
 * Invoca al destructor de clase para eliminar el objeto y devolver su memoria
 *dinámica
 ******
 * Input:
 *   heap *comandosHeap: puntero a la cola de prioridad que almacena los
 *comandos que no han sido consumidos
 * .......
 ******
 * Returns:
 *   void, solo modifica la estructura
 *****/

void terminate(heap *comandosHeap) {
  comandosHeap->~heap();
  return;
}