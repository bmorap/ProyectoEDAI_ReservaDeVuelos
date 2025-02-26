#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <fstream> 
#include "graphs.h" //donde se vaya a crear el grafo y guardar

using namespace std;

void readGraph (const Graph &graph) {
    ofstream file("flights.txt");
    if (!file) {
        cout << "No se encontro la base de datos." << endl;
        return;
    } else {
        for (const auto &kvPair : graph.adjList) {
            file << kvPair.first << ": [ ";
            for (size_t i = 0; i < kvPair.second.size(); ++i) {
                file << "(" << kvPair.second[i].first << ", " << kvPair.second[i].second << ") ";
            }
            file << "]" << endl;
        }
    }
    file.close();
    cout << "Grafo guardado exitosamente" << endl;
}


void loadGraph(const Graph &graph) {
    ifstream inFile("flights.txt");
    if (!inFile) {
        cerr << "Error al abrir el archivo flights.txt" << endl;
        return;
    }

     unordered_set<string> addedEdges; // Para evitar duplicar la inserción de aristas
    string line;
    while (getline(inFile, line)) {
        // Se espera que la línea tenga el formato: vertex: [ (neighbor, weight) (neighbor, weight) ... ]
        size_t colonPos = line.find(':');
        if (colonPos == string::npos)
            continue;

         // Extraer el vértice y limpiar espacios
        string vertex = line.substr(0, colonPos);
        vertex.erase(remove(vertex.begin(), vertex.end(), ' '), vertex.end());

         // Extraer la parte de aristas
        string edgesPortion = line.substr(colonPos + 1);
        // Quitar espacios iniciales
        while (!edgesPortion.empty() && isspace(edgesPortion.front()))
            edgesPortion.erase(edgesPortion.begin());
        // Se espera que empiece con '[' y termine con ']'
        if (!edgesPortion.empty() && edgesPortion.front() == '[')
            edgesPortion.erase(0, 1);
        if (!edgesPortion.empty() && edgesPortion.back() == ']')
            edgesPortion.pop_back();
        // Ahora edgesPortion es algo como: " (c, 8) (d, 3) (e, 4) "
        
        // Procesar cada arista buscando los paréntesis
        size_t pos = 0;
        while (true) {
            size_t openParen = edgesPortion.find('(', pos);
            if (openParen == string::npos)
                break;
            size_t closeParen = edgesPortion.find(')', openParen);
            if (closeParen == string::npos)
                break;
            // Extraer el contenido entre paréntesis, que debe ser "neighbor, weight"
            string edgeContent = edgesPortion.substr(openParen + 1, closeParen - openParen - 1);
            // Buscar la coma
            size_t commaPos = edgeContent.find(',');
            if (commaPos != string::npos) {
                string neighbor = edgeContent.substr(0, commaPos);
                string weightStr = edgeContent.substr(commaPos + 1);
                // Limpiar espacios
                neighbor.erase(remove(neighbor.begin(), neighbor.end(), ' '), neighbor.end());
                weightStr.erase(remove(weightStr.begin(), weightStr.end(), ' '), weightStr.end());
                int weight = stoi(weightStr);

                 // Usar una clave única (ordenada) para evitar duplicados en el grafo
                string key = (vertex < neighbor) ? vertex + "-" + neighbor : neighbor + "-" + vertex;
                if (addedEdges.find(key) == addedEdges.end()) {
                    graph.addEdge(vertex, neighbor, weight);
                    addedEdges.insert(key);
                }
            }
            pos = closeParen + 1;
        }
    }

     inFile.close();
    cout << "Grafo cargado desde flights.txt" << endl;
}