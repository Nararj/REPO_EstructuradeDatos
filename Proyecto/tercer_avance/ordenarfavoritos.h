/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 11/11/2026
 * Version : 3
 * Esta clase ordena un vector de nombres (string) alfabeticamente,
 * sin importar mayusculas, usando quick sort.
 */

#ifndef ORDENADORFAVORITOS_H
#define ORDENADORFAVORITOS_H

#include <vector>
#include <string>
#include <utility>
#include <cctype>

using namespace std;

class OrdenadorFavoritos {

private:

    int particionar(vector<string> &favoritos,
                    int inicio, int fin);

    void quickSort(vector<string> &favoritos,
                   int inicio, int fin);
    
    string aMinusculas(string texto);

public:

    void ordenar(vector<string> &favoritos);
};

/**
 * aMinusculas convierte un texto a minusculas para comparar
 * los nombres sin distinguir mayusculas.
 *
 * @param texto texto a convertir
 * @return copia del texto en minusculas
 *
 * La complejidad temporal es O(m), donde m es la longitud del texto, porque
 * recorre cada letra una vez. Como los nombres son cortos, se considera casi O(1).
 * La complejidad espacial es O(m) porque se crea una copia del texto.
 */
string OrdenadorFavoritos::aMinusculas(string texto) {

    for (int i = 0; i < texto.size(); i++) {          // O(m), recorre cada letra

        texto[i] = tolower(texto[i]);                 // O(1), convierte una letra
    }

    return texto;
}

/**
 * particionar elige un pivote (el elemento del medio) y acomoda el rango:
 * lo menor o igual al pivote a la izquierda y lo mayor a la derecha.
 *
 * @param favoritos vector de nombres
 * @param inicio primera posicion del rango
 * @param fin ultima posicion del rango
 * @return la posicion final donde quedo el pivote
 *
 * La complejidad temporal es O(n), donde n es el tamaño del rango, porque
 * el ciclo recorre cada elemento una sola vez.
 * La complejidad espacial es O(1) porque acomoda sobre el mismo vector.
 */
int OrdenadorFavoritos::particionar(vector<string> &favoritos,
                                    int inicio, int fin) {

    int medio = inicio + (fin - inicio) / 2;          // O(1), posicion del medio

    swap(favoritos[medio], favoritos[fin]);           // O(1), manda el pivote al final

    string pivote = aMinusculas(favoritos[fin]);      // O(1), pivote en minusculas

    int i = inicio - 1;                               // O(1), fin de la zona de menores

    for (int j = inicio; j < fin; j++) {              // O(n), recorre el rango una vez

        if (aMinusculas(favoritos[j]) <= pivote) {    // O(1), compara con el pivote

            i++;                                      // O(1), crece la zona de menores

            swap(favoritos[i], favoritos[j]);         // O(1), manda el menor a su zona
        }
    }

    swap(favoritos[i + 1], favoritos[fin]);           // O(1), pone el pivote en su lugar

    return i + 1;                                     // O(1), posicion final del pivote
}

/**
 * quickSort particiona el rango y se llama a si mismo para cada lado del pivote.
 *
 * @param favoritos vector de nombres
 * @param inicio primera posicion del rango
 * @param fin ultima posicion del rango
 *
 * La complejidad temporal es O(n log n) en el mejor y promedio caso, porque
 * cada particion divide el rango en dos partes parecidas (log n niveles) y en cada
 * nivel se recorren n elementos. En el peor caso es O(n^2), cuando el pivote
 * queda siempre en un extremo.
 * La complejidad espacial es O(log n) en promedio por la pila de recursividad.
 */
void OrdenadorFavoritos::quickSort(vector<string> &favoritos,
                                   int inicio, int fin) {

    if (inicio >= fin) {                              // O(1), caso base: 0 o 1 elemento
        return;
    }

    int posPivote = particionar(favoritos,
                                inicio, fin);         // O(n), acomoda alrededor del pivote

    quickSort(favoritos, inicio, posPivote - 1);      // T(parte izquierda)
    quickSort(favoritos, posPivote + 1, fin);         // T(parte derecha)
}

/**
 * ordenar ordena el vector de favoritos alfabeticamente con quick sort.
 *
 * @param favoritos vector de nombres a ordenar
 *
 * La complejidad temporal es O(n log n) en promedio y O(n^2) en el peor caso.
 * La complejidad espacial es O(log n) en promedio por la recursividad.
 */
void OrdenadorFavoritos::ordenar(vector<string> &favoritos) {

    int n = favoritos.size();                         // O(1), tamaño del vector

    if (n <= 1) {                                     // O(1), nada que ordenar
        return;
    }

    quickSort(favoritos, 0, n - 1);                   // O(n log n) promedio
}

#endif