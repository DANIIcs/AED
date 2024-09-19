#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Función que determina si dos cadenas son isomorfas
    bool isIsomorphic(string s, string t) {
        // Si las longitudes de las cadenas no son iguales, no pueden ser isomorfas
        if (s.length() != t.length()) {
            return false;
        }

        // Crea un hashmap (unordered_map) para almacenar las asociaciones entre caracteres de 's' y 't'
        unordered_map<char, char> charMappingMap;

        // Itera sobre los caracteres de ambas cadenas
        for (int i = 0; i < s.length(); i++) {
            // Obtiene el carácter actual de 's' y 't'
            char original = s[i];
            char replacement = t[i];

            // Si el carácter de 's' no está aún mapeado en el hashmap
            if (charMappingMap.find(original) == charMappingMap.end()) {
                // Verifica si el carácter de 't' ya ha sido mapeado a algún otro carácter de 's'
                if (find_if(charMappingMap.begin(), charMappingMap.end(),
                            [&replacement](const pair<char, char>& pair) { return pair.second == replacement; }) == charMappingMap.end()) {
                    // Si no ha sido mapeado, asigna el carácter de 's' al carácter de 't'
                    charMappingMap[original] = replacement;
                } else {
                    // Si el carácter de 't' ya está mapeado a otro carácter, las cadenas no son isomorfas
                    return false;
                }
            } else {
                // Si el carácter de 's' ya fue mapeado, revisa si el mapeo coincide con el carácter de 't'
                char mappedCharacter = charMappingMap[original];
                if (mappedCharacter != replacement) {
                    // Si el mapeo no coincide, las cadenas no son isomorfas
                    return false;
                }
            }
        }

        // Si todas las condiciones se cumplen, las cadenas son isomorfas
        return true;
    }
};

int main() {
    Solution solution;

    // Ejemplo de prueba
    string s1 = "egg";
    string t1 = "add";

    if (solution.isIsomorphic(s1, t1)) {
        cout << "Las cadenas \"" << s1 << "\" y \"" << t1 << "\" son isomorfas." << endl;
    } else {
        cout << "Las cadenas \"" << s1 << "\" y \"" << t1 << "\" no son isomorfas." << endl;
    }

    // Otro ejemplo de prueba
    string s2 = "foo";
    string t2 = "bar";

    if (solution.isIsomorphic(s2, t2)) {
        cout << "Las cadenas \"" << s2 << "\" y \"" << t2 << "\" son isomorfas." << endl;
    } else {
        cout << "Las cadenas \"" << s2 << "\" y \"" << t2 << "\" no son isomorfas." << endl;
    }

    return 0;
}
