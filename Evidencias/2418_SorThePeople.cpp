class Solution {
public:

    // Intercambia dos enteros
    void intercambiarAlturas(int &a, int &b) {
        // Guardamos el valor de a en una variable temporal, luego asignamos b a a y finalmente asignamos el valor temporal a b
        int temp = a;
        a = b;
        b = temp;
    }

    // Intercambia dos strings
    void intercambiarNombres(string &a, string &b) {
        // Guardamos el valor de a en una variable temporal, luego asignamos b a a y finalmente asignamos el valor temporal a b
        string temp = a;
        a = b;
        b = temp;
    }

    // Ordenar los elementos 
    void bubbleSortDescendente(vector<string> &names, vector<int> &heights) {
        // Obtenemos el tamaño del vector de alturas
        int n = heights.size();

        // Recorremos todos los elemntos del vector
        for (int i = 0; i < n - 1; i++) {
            bool huboIntercambio = false;

            // Comparar un elemento con el siguiente
            for (int j = 0; j < n - 1 - i; j++) {
                // Si el actual es menor que el siguiente, se intercambian
                if (heights[j] < heights[j + 1]) {
                    intercambiarAlturas(heights[j], heights[j + 1]);
                    intercambiarNombres(names[j], names[j + 1]);
                    huboIntercambio = true;
                }
            }

            // Si en una pasada completa no hubo cambios, es que ya está ordenado
            if (!huboIntercambio) {
                break;
            }
        }
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        bubbleSortDescendente(names, heights);
        return names;
    }
};