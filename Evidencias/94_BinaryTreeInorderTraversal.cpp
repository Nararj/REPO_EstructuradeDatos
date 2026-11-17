/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Inorder que es recorrer el subárbol izquierdo, visitar el nodo actual y luego recorrer el subárbol derecho, primero visitamos un nodo
    // y vamos guardando los valores en un vector de enteros
    void recorrerInorder(TreeNode* nodo, vector<int>& resultado) {
        // Si el nodo es nulo, hemos llegado a una hoja y no hay nada que recorrer
        if (nodo == nullptr) {
            return;
        }

        // La funcion se llama a si misma y recorre el subarbol izquierdo hasta que encontrar uno que no tenga hijo
        recorrerInorder(nodo->left, resultado);
        // Guardamos el valor del nodo actual al final del vector
        resultado.push_back(nodo->val);
        // La funcion se llama a si misma y recorre el subarbol derecho hasta que encontrar uno que no tenga hijo
        recorrerInorder(nodo->right, resultado);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // Creamos un vector para almacenar los valores de los nodos en orden
        vector<int> resultado;
        // Llamamos a la función auxiliar para recorrer el árbol en orden y llenar el vector
        recorrerInorder(root, resultado);
        return resultado;
    }
};
