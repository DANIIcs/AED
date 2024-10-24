class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // Variables para llevar un seguimiento de los tres números en aumento
        int first = INT_MAX;  // Almacenará el número más pequeño encontrado hasta ahora
        int second = INT_MAX; // Almacenará el segundo número más pequeño
        
        // Recorremos el array de números usando un bucle for tradicional
        for (int i = 0; i < nums.size(); i++) {
            // Si encontramos un número más pequeño que el primer número, lo actualizamos
            if (nums[i] <= first) {
                first = nums[i];
            }
            // Si encontramos un número más grande que el primero pero más pequeño que el segundo, actualizamos el segundo
            else if (nums[i] <= second) {
                second = nums[i];
            }
            // Si encontramos un número más grande que el segundo, ya tenemos la tripleta creciente
            else {
                return true;
            }
        }
        
        // Si no encontramos ninguna tripleta creciente, devolvemos false
        return false;
    }
};
