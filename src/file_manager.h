#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

#include "graphs.h"
#include <fstream>
#include <sstream>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

namespace fmanagement {

    // Guarda la información del grafo en un archivo "flights.txt"
    bool guardarGrafo(const Graph grafo, const string filename = "flights.txt") {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            cerr << "No se pudo abrir el archivo para escribir: " << filename << endl;
            return false;
        }
    
        auto ciudades = grafo.obtenerCiudades();
        for (auto temp : ciudades) {
            auto ciudad = temp.second;
            // Escribe el nombre de la ciudad
            outFile << ciudad.nombre << " " 
                    << ciudad.x << " " << ciudad.y;
            // Escribe cada conexión (destino y peso)
            for (auto vuelo : ciudad.conexiones) {
                outFile << " " << vuelo.destino
                        << " " << vuelo.peso;
            }
            outFile << endl;
        }
        outFile.close();
        return true;
    }
}

#endif