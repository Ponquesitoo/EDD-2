Instrucciónes de Compilación

El código consiste en cuatro códigos, de modo tal que:
    - tda.hpp : contiene el TDA cola de prioridad, clase heap
    - metodosHeap.cpp : implementa los métodos de la clase
    - funcionesComando.cpp : contiene las tres funciones correspondientes al problema
    - problema2.cpp : almacena el main para ejecutar el programa 

Para compilar el programa se debe navegar hasta la carpeta "/tarea3/problema2" e ingresar el siguente comando:
    g++ problema2.cpp -Wall -o <problema2-ejecutable>

Y para la posterior ejecución, se debe utilizar el siguiente comando:
    ./<problema2-ejecutable>
Para posteriormente ingresar las operaciones por medio de la entrada estándar.

El programa entregará las salidas una vez sea ingresado TERMINATE, de no recibirlo, continuará esperando entradas hasta reconocerlo en ellas. En caso de ingresar una operación no válida, se solicitará ingresar nuevamente la entrada.

A modo de comentario, si se utiliza GET con un N mayor a la cantidad de elementos existentes en la cola de prioridad, el programa entregará los comandos que le sea posible entregar, y para el resto imprimirá saltos de linea. Dichas lineas en blanco son contabilizadas en el SENT final.

Finalmente, el programa fue compilado en Ubuntu mediante WSL.