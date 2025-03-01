#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "graphs.h"
#include <fstream>
#include <sstream>
#include <tuple>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


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

    // Carga la información desde "flights.txt" y reconstruye el grafo.
bool cargarGrafo(Graph& grafo, const string filename = "flights.txt") {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "No se pudo abrir el archivo para leer: " << filename << endl;
        return false;
    }
        
    // Se limpia el grafo 
    grafo.vaciarGrafo();

    // Estructura para almacenar temporalmente la información leída:
    vector<tuple<string, int, int, vector<pair<string, double>>>> datosCiudades;
    string linea;
    while (getline(inFile, linea)) {
        if (linea.empty())
            continue;
        // Termina el proceso al encontrar una linea vacia
        istringstream info(linea);
        //cout << linea << endl;
        string nombre;
        int x, y;
        if (!(info >> nombre >> x >> y)) {
            cerr << "Error al leer la ciudad de la línea: " << linea << endl;
            continue;
        }
        //cout << nombre << " " << x << " " << y << endl;
        vector<pair<string, double>> conexiones;
        string destino;
        double peso;
        // Lee las conexiones (destino y peso)
        while (info >> destino >> peso) {
            // cout << destino << " " << peso << endl;
            conexiones.push_back({destino, peso});
        }
        datosCiudades.push_back(make_tuple(nombre, x, y, conexiones));
    }
    inFile.close();
    // Primero se agregan todas las ciudades (sin conexiones)
    for (const auto& data : datosCiudades) {
        string nombre;
        int x, y;
        vector<pair<string, double>> conexiones;
        tie(nombre, x, y, conexiones) = data;
        cout << nombre << " " << x << " " << y << endl;
        grafo.agregarCiudad(nombre, x, y);
    }
    
    // Luego se agregan las conexiones para cada ciudad
    for (const auto& data : datosCiudades) {
        string nombre;
        int x, y;
        vector<pair<string, double>> conexiones;
        tie(nombre, x, y, conexiones) = data;
        for (const auto& conn : conexiones) {
            const string& destino = conn.first;
            double peso = conn.second;
            cout << nombre << " " << destino << " " << peso << endl;
            grafo.agregarConexion(nombre, destino, peso);
        }
    }
    return true;
}
#endif