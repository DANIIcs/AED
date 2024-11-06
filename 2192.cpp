class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Paso 1: Crear la estructura del grafo como una lista de adyacencia
        // `graph` es un vector de vectores, donde cada índice representa un nodo
        // y su vector interno contiene los nodos a los que tiene conexiones directas.
        vector<vector<int>> graph(n);
        for (vector<int>& edge : edges) {
            int from = edge[0], to = edge[1];
            graph[from].push_back(to); // Agrega `to` a la lista de `from`
        }

        // Paso 2: Crear una estructura para almacenar los ancestros de cada nodo
        // `ancestros` es un vector de conjuntos (`set<int>`), donde cada `set`
        // almacenará los ancestros únicos de cada nodo. Usamos `set` para evitar duplicados
        // y mantener los elementos en orden ascendente automáticamente.
        vector<set<int>> ancestros(n);

        // Paso 3: Realizar BFS desde cada nodo para encontrar sus ancestros
        // Iteramos sobre cada nodo del grafo
        for (int node = 0; node < n; ++node) {
            queue<int> q;
            q.push(node); // Comienza la búsqueda desde el nodo actual

            // Mientras haya nodos en la cola
            while (!q.empty()) {
                int curr = q.front(); q.pop(); // Extrae el nodo actual de la cola
                
                // Itera sobre todos los vecinos del nodo `curr` en el grafo
                for (int neighbor : graph[curr]) {
                    // Inserta `node` como ancestro de `neighbor` si aún no está en su conjunto
                    if (ancestros[neighbor].insert(node).second) {
                        q.push(neighbor); // Agrega `neighbor` a la cola para continuar la búsqueda
                    }
                    
                    // Inserta todos los ancestros de `curr` en el conjunto de `neighbor`
                    // Esto asegura que `neighbor` herede todos los ancestros de `curr`
                    ancestros[neighbor].insert(ancestros[curr].begin(), ancestros[curr].end());
                }
            }
        }
        
        // Paso 4: Convertir el conjunto de ancestros en un vector de vectores
        // Creamos `result`, un vector de vectores para almacenar los ancestros finales en el formato requerido
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            // Convertimos el `set` de ancestros en un `vector` y lo asignamos a `result[i]`
            result[i].assign(ancestros[i].begin(), ancestros[i].end());
        }
        
        // Paso 5: Retornar el resultado final
        return result;
    }
};
