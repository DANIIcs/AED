#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // Función para contar el número de "boomerangs" en el conjunto de puntos
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(); // Obtiene el número total de puntos
        int total = 0; // Inicializa el contador de boomerangs

        // Itera sobre cada punto en el conjunto de puntos
        for (int i = 0; i < n; i++) {
            map<int, int> mp; // Crea un mapa para almacenar la frecuencia de distancias desde el punto i

            // Calcula la distancia desde el punto i a todos los demás puntos
            for (int j = 0; j < n; j++) {
                // Calcula el cuadrado de la distancia euclidiana entre el punto i y el punto j
                int dist = ((points[i][0] - points[j][0]) * (points[i][0] - points[j][0])) +
                           ((points[i][1] - points[j][1]) * (points[i][1] - points[j][1]));

                // Incrementa el conteo de la distancia en el mapa
                mp[dist]++;
            }

            // Calcula el número de boomerangs usando el mapa de distancias
            for (auto i : mp) {
                // Si hay más de un punto a la misma distancia, se pueden formar boomerangs
                if (i.second) {
                    // Calcula el número de boomerangs para las distancias encontradas
                    total += (i.second * (i.second - 1));
                }
            }
        }
        return total; // Devuelve el número total de boomerangs
    }
};

int main() {
    // Crea una instancia de la clase Solution
    Solution solution;

    // Define algunos ejemplos de entrada
    vector<vector<int>> points1 = {{0,0}, {1,0}, {2,0}};
    vector<vector<int>> points2 = {{1,1}, {2,2}, {3,3}};
    vector<vector<int>> points3 = {{1,1}};

    // Llama a la función y muestra los resultados
    cout << "Number of boomerangs (example 1): " << solution.numberOfBoomerangs(points1) << endl; // Salida esperada: 2
    cout << "Number of boomerangs (example 2): " << solution.numberOfBoomerangs(points2) << endl; // Salida esperada: 2
    cout << "Number of boomerangs (example 3): " << solution.numberOfBoomerangs(points3) << endl; // Salida esperada: 0

    return 0; // Fin del programa
}
