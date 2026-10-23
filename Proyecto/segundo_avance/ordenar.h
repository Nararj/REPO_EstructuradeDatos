/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 23/10/2026
 * Version : 2
 * Esta clase ordena un vector de punteros a Videojuego de forma
 * ascendente por su calificacion, usa merge sort para ordenarlos.
 */

#ifndef ORDENADORJUEGOS_H
#define ORDENADORJUEGOS_H

#include <vector>

#include "Videojuego.h"

using namespace std;

class OrdenadorJuegos {

private:

    void mezclar(vector<Videojuego*> &juegos,
                 int inicio, int medio, int fin);

    void mergeSort(vector<Videojuego*> &juegos,
                   int inicio, int fin);

public:

    void ordenarPorCalificacion(
        vector<Videojuego*> &juegos
    );
};

/**
 * mezclar une dos mitades que ya estan ordenadas en una sola.
 *
 * @param juegos vector de punteros a Videojuego
 * @param inicio posicion donde empieza la mitad izquierda
 * @param medio posicion donde termina la mitad izquierda
 * @param fin posicion donde termina la mitad derecha
 *
 * En complejidad temporal es O(n) en todos los casos, donde n es la cantidad de
 * elementos que se estan mezclando, ya que los ciclos no estan anidados, van uno
 * despues de otro (n + n + n sigue siendo O(n)).
 * En complejidad espacial es O(n) porque se crea un vector temporal.
 */
void OrdenadorJuegos::mezclar(vector<Videojuego*> &juegos,
                              int inicio, int medio, int fin) {

    vector<Videojuego*> temp;                         // O(1), crea un vector vacio

    int i = inicio;                                   // O(1), indice de la mitad izquierda
    int j = medio + 1;                                // O(1), indice de la mitad derecha

    while (i <= medio && j <= fin) {                  // O(n), recorre las dos mitades una sola vez

        if (juegos[i]->getCalificacion() <=
            juegos[j]->getCalificacion()) {           // O(1), compara calificaciones ya guardadas

            temp.push_back(juegos[i]);                // O(1), agrega el puntero al final
            i++;                                      // O(1), avanza en la mitad izquierda
        }
        else {

            temp.push_back(juegos[j]);                // O(1), agrega el puntero al final
            j++;                                      // O(1), avanza en la mitad derecha
        }
    }

    while (i <= medio) {                              // O(n), copia lo que sobro de la izquierda
        temp.push_back(juegos[i]);                    // O(1), agrega el puntero al final
        i++;                                          // O(1), avanza el indice
    }

    while (j <= fin) {                                // O(n), copia lo que sobro de la derecha
        temp.push_back(juegos[j]);                    // O(1), agrega el puntero al final
        j++;                                          // O(1), avanza el indice
    }

    for (int k = 0; k < temp.size(); k++) {           // O(n), regresa lo ordenado al vector original
        juegos[inicio + k] = temp[k];                 // O(1), solo asigna puntero
    }
}

/**
 * mergeSort divide el vector a la mitad, ordena cada mitad con
 * recursividad y despues las une con mezclar.
 *
 * @param juegos vector de punteros a Videojuego
 * @param inicio primera posicion del rango a ordenar
 * @param fin ultima posicion del rango a ordenar
 *
 * La complejidad temporal es O(n log n) en el mejor, promedio y peor caso, ya que
 * siempre divide a la mitad (log n niveles) y en cada nivel mezcla n elementos.
 */
void OrdenadorJuegos::mergeSort(vector<Videojuego*> &juegos,
                                int inicio, int fin) {

    if (inicio >= fin) {                              // O(1), caso base: 0 o 1 elemento ya esta ordenado
        return;
    }

    int medio = inicio + (fin - inicio) / 2;          // O(1), calcula la mitad

    mergeSort(juegos, inicio, medio);
    mergeSort(juegos, medio + 1, fin);

    mezclar(juegos, inicio, medio, fin);              // O(n), une las dos mitades ordenadas
}

/**
 * ordenarPorCalificacion ordena el vector de juegos
 * de menor a mayor calificacion usando merge sort.
 *
 * @param juegos vector de punteros a Videojuego que se va a ordenar
 *
 * En el caso de la complejidad temporal, el mejor, promedio y peor caso es O(n log n)
 * porque siempre divide y mezcla igual, aunque el vector ya este ordenado.
 * En complejidad espacial es O(n) porque mezclar usa un vector temporal.
 */
void OrdenadorJuegos::ordenarPorCalificacion(
    vector<Videojuego*> &juegos) {

    int n = juegos.size();                            // O(1), solo se guarda el tamaño del vector

    if (n <= 1) {                                     // O(1), con 0 o 1 juego no hay nada que ordenar
        return;
    }

    mergeSort(juegos, 0, n - 1);                      // O(n log n), ordena todo el vector
}

#endif
