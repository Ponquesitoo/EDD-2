Instrucciónes de Compilación

El código consiste en una cabecera, «tda.hpp», y su implementación, «problema1.cpp» 
    - tda.cpp contiene el TDA de listas enlazadas, clase listaNucleotidos
    - problema.cpp implementa los métodos de la clase, y realiza la lectura y reconstrucción de secuencias en el main

Para compilar el programa se debe navegar hasta la carpeta "/tarea2/problema1" e ingresar el siguente comando:
    g++ problema1.cpp -Wall -o <problema1-ejecutable>

Y para la posterior ejecución, se debe utilizar el siguiente comando:
    ./<problema1-ejecutable>

Hay que asegurarse de que exista el archivo de nombre "secuencias-nucleotidos.txt" dentro de la carpeta, con las respectivas indicaciones. O, en su defecto, cambiar el nombre del archivo de lectura desde el main de problema1.cpp.
Las secuencias reconstruidas se encontrarán en el archivo "secuencias-reconstruidas.txt", dentro de la misma carpeta.

Finalmente, el programa fue compilado en Ubuntu mediante WSL.