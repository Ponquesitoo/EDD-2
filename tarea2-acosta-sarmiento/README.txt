Instrucciones de Compilacion

El codigo consiste de un "main" y los TDA del mismo.

Para compilar el programa se debe navegar hasta la carpeta "/tarea2-acosta-sarmiento" e ingresar los siguentes comandos:

g++ DeBlock.cpp ListaDeListas.cpp lista.cpp main.cpp -Wall -o <nombre>

Y posteriormente se debe usar el siguiente comando: ./ <nombre>

siendo <nombre>, un nombre arbitrario.

En caso de producirse que no se abra el archivo "pruebas.txt" deberá colocarse la direccion del archivo directamente en el 

segmento de codigo que se encarga de abrir el archivo, especificamente en la linea 16 del archivo "main.cpp".

ejemplo:

15	. . .
16	archivito.open("direccion/pruebas.txt", ios::in);
17	. . .

Es importante notar que se deben cambiar los "\" de la direccion del archivo por "/" para evitar errores.

