#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        // Vector para almacenar los vecinos de cada nodo
        vector<vector<int>> neighbors(n);

        // Llenar la lista de vecinos con las aristas dadas
        for (const auto& edge : edges) {
            int a = edge[0];
            int b = edge[1];
            neighbors[a].push_back(vals[b]);
            neighbors[b].push_back(vals[a]);
        }

        int maxSum = INT_MIN; // Para almacenar el máximo star sum

        // Iterar sobre cada nodo para calcular su star sum
        for (int i = 0; i < n; ++i) {
            int currentSum = vals[i]; // Empezar con el valor del nodo central

            // Ordenar los vecinos de mayor a menor
            sort(neighbors[i].rbegin(), neighbors[i].rend());

            // Sumar los valores de hasta k vecinos más grandes
            for (int j = 0; j < min(k, (int)neighbors[i].size()); ++j) {
                if (neighbors[i][j] > 0) {
                    currentSum += neighbors[i][j];
                }
            }

            // Actualizar el máximo star sum
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
