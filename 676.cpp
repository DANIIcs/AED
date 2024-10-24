class MagicDictionary {
private:
    vector<string> dict; // Aquí guardamos el diccionario de palabras
    
public:
    // Constructor
    MagicDictionary() {
    }

    // Método para construir el diccionario
    void buildDict(vector<string> dictionary) {
        dict = dictionary; // Guardamos las palabras del diccionario
    }

    // Método para buscar si podemos cambiar exactamente un carácter
    bool search(string searchWord) {
        // Recorremos todas las palabras en el diccionario usando un bucle tradicional
        for (int j = 0; j < dict.size(); j++) {
            string word = dict[j]; // Obtenemos la palabra actual del diccionario
            
            // Si la palabra tiene diferente longitud, pasamos a la siguiente
            if (word.length() != searchWord.length()) continue;
            
            int diffCount = 0; // Contador para las diferencias de caracteres
            
            // Comparamos cada letra de la palabra del diccionario con la de searchWord
            for (int i = 0; i < word.length(); i++) {
                if (word[i] != searchWord[i]) {
                    diffCount++;
                    // Si hay más de una diferencia, ya no es válida esta palabra
                    if (diffCount > 1) break;
                }
            }
            
            // Si encontramos exactamente una diferencia, retornamos true
            if (diffCount == 1) return true;
        }
        
        // Si no encontramos ninguna coincidencia con una diferencia de 1 carácter
        return false;
    }
};
