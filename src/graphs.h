#ifndef GRAPHS_H
#define GRAPHS_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Estructura que representa un vuelo
struct Flight {
    string destino;  // Ciudad destino
    double peso;     // Peso
};

// Clase del grafo dirigido
class Graph {
public:
    // Estructura que representa una ciudad
    struct City {
        string nombre;
        int x, y; // Coordenadas del nodo
        vector<Flight> conexiones;  // Vuelos asociados
    };

private:
    unordered_map<string, City> ciudades;
};

#endif
