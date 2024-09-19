#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Función para encontrar todas las secuencias de 10 letras que se repiten en la cadena dada
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result; // Vector para almacenar las secuencias repetidas

        // Si la longitud de la cadena es menor que 10, no puede haber secuencias de 10 letras repetidas
        if (s.size() < 10) {
            return result;
        }

        unordered_map<string, int> sequenceCount; // Mapa para contar las ocurrencias de cada secuencia de 10 letras

        // Itera sobre la cadena para extraer todas las secuencias de 10 letras
        for (int i = 0; i <= s.size() - 10; i++) {
            string sequence = s.substr(i, 10); // Extrae la secuencia de 10 letras a partir del índice i
            sequenceCount[sequence]++; // Incrementa el contador para esta secuencia en el mapa
        }

        // Recorre el mapa para encontrar las secuencias que se repiten más de una vez
        for (auto it : sequenceCount) {
            if (it.second > 1) { // Si la secuencia aparece más de una vez
                result.push_back(it.first); // Añade la secuencia repetida al resultado
            }
        }
        
        return result; // Devuelve el vector de secuencias repetidas
    }
};

int main() {
    // Crea una instancia de la clase Solution
    Solution solution;

    // Define una cadena de ejemplo
    string example = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

    // Llama a la función y almacena el resultado
    vector<string> repeatedSequences = solution.findRepeatedDnaSequences(example);

    // Imprime las secuencias repetidas
    cout << "Repeated DNA sequences are: ";
    for (const string& seq : repeatedSequences) {
        cout << seq << " ";
    }
    cout << endl;

    return 0; // Fin del programa
}
