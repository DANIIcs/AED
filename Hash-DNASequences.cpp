#include <iostream> 
#include <vector> 
#include <string> 
#include <unordered_map> 

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // Creamos un vector para almacenar las secuencias repetidas encontradas
        vector<string> ans;

        // Si la longitud de la cadena es menor que 10, no podemos encontrar secuencias de 10 caracteres, así que retornamos el vector vacío
        if(s.size() < 10) {
            return ans;
        }

        // Creamos un mapa para contar cuántas veces aparece cada secuencia de 10 caracteres
        unordered_map<string, int> mp;

        // Recorremos la cadena buscando todas las secuencias de 10 caracteres
        for(int i = 0; i <= s.size() - 10; i++) {
            // Extraemos la secuencia de 10 caracteres a partir de la posición i
            string str = s.substr(i, 10);
            // Aumentamos el contador de la secuencia en el mapa
            mp[str]++;
        }

        // Recorremos el mapa para encontrar las secuencias que aparecen más de una vez
        for(auto it : mp) {
            if(it.second > 1) {
                // Añadimos las secuencias repetidas al vector de resultados
                ans.push_back(it.first);
            }
        }
        
        // Retornamos el vector con las secuencias repetidas
        return ans;
    }
};

int main() {
    // Crear una instancia de la clase Solution
    Solution sol;

    // Definir una cadena de prueba
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    // Llamar al método findRepeatedDnaSequences
    vector<string> result = sol.findRepeatedDnaSequences(s);

    // Imprimir las secuencias repetidas encontradas
    for(const string& seq : result) {
        cout << seq << endl;
    }

    return 0;
}
