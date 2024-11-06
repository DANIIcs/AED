class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        // Inicializamos la suma de nodos con abuelo de valor par
        return dfs(root, nullptr, nullptr);
    }

private:
    // Función recursiva DFS para recorrer el árbol
    int dfs(TreeNode* node, TreeNode* parent, TreeNode* grandparent) {
        if (!node) return 0; // Caso base: si el nodo es nulo, retornamos 0
        
        int sum = 0;
        
        // Verificamos si el abuelo es par
        if (grandparent && grandparent->val % 2 == 0) {
            sum += node->val; // Sumamos el valor del nodo si el abuelo es par
        }
        
        // Llamada recursiva para el hijo izquierdo y derecho
        sum += dfs(node->left, node, parent);  // nodo actual pasa a ser el padre y el padre el abuelo
        sum += dfs(node->right, node, parent); // nodo actual pasa a ser el padre y el padre el abuelo
        
        return sum; // Retornamos la suma acumulada
    }
};
