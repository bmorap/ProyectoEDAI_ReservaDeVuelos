#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(const unordered_map<int, vector<pii>>& graph, int start, int end) {
    unordered_map<int, int> dist; // Almacena la distancia más corta desde el inicio a cada nodo
    unordered_map<int, int> prev; // Almacena el nodo anterior en el camino óptimo desde el inicio
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Cola de prioridad de min-heap para seleccionar el nodo con la distancia más pequeña

    // Inicializar distancias a todos los nodos como infinito
    for (const auto& node : graph) {
        dist[node.first] = INT_MAX;
    }
    dist[start] = 0; // La distancia al nodo de inicio es 0
    pq.push({0, start}); // Empujar el nodo de inicio a la cola de prioridad

    while (!pq.empty()) {
        int currentNode = pq.top().second; // Obtener el nodo con la distancia más pequeña
        pq.pop();

        if (currentNode == end) break; // Si llegamos al nodo final, detener

        // Explorar todos los vecinos del nodo actual
        for (const auto& neighbor : graph.at(currentNode)) {
            int neighborNode = neighbor.first; // Nodo vecino
            int edgeWeight = neighbor.second; // Peso del borde al vecino

            int alternativePathDistance = dist[currentNode] + edgeWeight; // Calcular la distancia del camino alternativo
            if (alternativePathDistance < dist[neighborNode]) { // Si el camino alternativo es más corto
                dist[neighborNode] = alternativePathDistance; // Actualizar la distancia más corta al vecino
                prev[neighborNode] = currentNode; // Actualizar el nodo anterior en el camino
                pq.push({alternativePathDistance, neighborNode}); // Empujar el vecino a la cola de prioridad
            }
        }
    }

    vector<int> path; // Para almacenar el camino más corto
    // Reconstruir el camino desde el final hasta el inicio usando el mapa prev
    for (int at = end; at != start; at = prev[at]) {
        path.push_back(at);
    }
    path.push_back(start); // Agregar el nodo de inicio al camino
    reverse(path.begin(), path.end()); // Invertir el camino para obtenerlo desde el inicio hasta el final

    return path; // Devolver el camino más corto
}
