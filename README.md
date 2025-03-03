# ProyectoEDAI_ReservaDeVuelos
- Fabián Muñoz C15386
- Bryan Mora C15141
- Leonardo Serrano C17484
- Danna

Este programa busca modelar un sistema de reserva de vuelos.

## Estructura
- `src/`: Archivos fuente del proyecto.
- `build/`: Aquí se almacenarán los archivos de ejecución una vez ejecutado el make.

## Uso del Makefile para compilar y ejecutar
Este programa puede ser compilado y ejecutado a través del uso del Makefile. Es necesario posicionarse en el directorio principal.

Para compilar y ejecutar se debe utilizar el comando **"make all"**. Para limpiar su contenido se puede ejecutar "make clean".

# Algoritmo de Dijkstra (Bryan Mora C15141)

El archivo `algorithm.cpp` implementa el algoritmo de Dijkstra para encontrar el camino más corto en un grafo ponderado dirigido.

## Funcionamiento

### 1. Inicialización
- Se crean `dist` (distancias mínimas) y `prev` (nodos anteriores en el camino óptimo).
- Se inicializan distancias a infinito y la de inicio a 0.
- Se usa una cola de prioridad (`pq`) para seleccionar el nodo con menor distancia.

### 2. Exploración de Nodos
- Se extrae el nodo con menor distancia.
- Si es el destino, el algoritmo finaliza.
- Se actualizan distancias y nodos previos si se encuentra un camino más corto.
- Se insertan nodos vecinos en la cola de prioridad.

### 3. Construcción del Camino
- Se reconstruye el camino desde el destino al inicio usando `prev`.
- Se invierte para obtener el orden correcto.
- Si el camino es inválido, se devuelve un vector vacío.

### Ejemplo de Uso

```cpp
#include "graphs.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    Graph graph;
    // ... (agregar nodos y conexiones al grafo)
    std::string start = "NewYork", finish = "SanJose";
    std::vector<std::string> path = dijkstra(graph, start, finish);
    
    if (!path.empty()) {
        std::cout << "El recorrido más rápido es: ";
        for (const auto& node : path) std::cout << node << " ";
        std::cout << std::endl;
    } else {
        std::cout << "No se encontró vuelos disponibles." << std::endl;
    }
    return 0;
}
```

### Consideraciones
- El grafo debe ser ponderado y dirigido.


## Manejo de archivos. (Fabián M C15386)
    Este header pretende trabajar con un archivo de texto "flights.txt" para utilizarlo a modo de base de datos.
Esta funcionalidad permitiria al usuario guardar una sesión, imprimir el grafo dentro del archivo para su
próxima recuperación, y cargar una sesión, procesar este grafo guardado previamente para almacenar los valores
impresos dentro del grafo en el que se esta trabajando actualmente. 

    Los dos metodos existentes son guardarGrafo que requiere dos parámetros, un grafo y el nombre del archivo que
se utilizará como base de datos. A partir de esto imprime los valores deseados de cada ciudad a partir del método
getter del grafo. Este se imprime en el formato:
- Nombre X Y Conexion(x) Peso(X) (Asi sucesivamente para cada conexión)

    El siguiente método recibe un grafo y el nombre del archivo nuevamente. Este método se encarga de leer todas 
las líneas del archivo hasta que una de estas este vacia. A partir de esto, guarda en un vector temporal todos 
los datos necesarios para la reconstrucción del grafo y los guarda en un vector de 'tuples' (un formato de datos 
que guarda una colección de datos en un solo lugar). Al obtener todos los datos del archivo, comienza a desempaque-
tar los datos que existen dentro del tuple para utilizar los métodos existentes del grafo para reconstruir el archi-
vo. 

    Dentro de los recursos utilizados son los siguientes:
- [Tuples_Yt](https://www.youtube.com/watch?v=T9-agjKW4PQ&ab_channel=TechWithTim)
- [Files_YT](https://www.youtube.com/watch?=Cz4fl-TUjVkt=225sab_channel=CalebCurry)
- [StackOverflow](https:stackoverflowcomquestions66552813how-to-read-file-into-vector-of-tuple)
- [ChatGPT](https://chatgpt.com/share/67c27693-a118-800d-b830-fb1e3dd6ca29)
