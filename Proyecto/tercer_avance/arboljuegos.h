/*
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 11/11/2026
 * Version : 3
 * Arbol binario de busqueda que guarda punteros a Videojuego ordenados por calificacion. Menores a la izquierda,
 * mayores o iguales a la derecha.
 */

#ifndef ARBOLJUEGOS_H
#define ARBOLJUEGOS_H

#include <iostream>
#include <string>
#include <cctype>

#include "Videojuego.h"

using namespace std;

//Nodo del arbol: guarda un juego y sus dos hijos
struct NodoJuego {

    Videojuego* juego;
    NodoJuego* izq;
    NodoJuego* der;

    NodoJuego(Videojuego* j) {

        juego = j;
        izq = nullptr;
        der = nullptr;
    }
};

class ArbolJuegos {

private:

    NodoJuego* raiz;

    NodoJuego* insertarNodo(NodoJuego* nodo, Videojuego* juego);

    void mostrarNodo(NodoJuego* nodo);

    bool buscarNodo(NodoJuego* nodo, string buscadoMin);

    void liberarNodo(NodoJuego* nodo);

    string aMinusculas(string texto);

public:

    ArbolJuegos();

    ~ArbolJuegos();

    void insertar(Videojuego* juego);

    bool estaVacio();

    void mostrarInorden();

    bool buscarPorNombre(string nombreBuscado);
};

/**
 * Constructor. Crea un arbol vacio.
 */
ArbolJuegos::ArbolJuegos() {

    raiz = nullptr;            // O(1), inicializa el arbol vacio
}

/**
 * Destructor. Libera todos los nodos y los juegos.
 *
 * La complejidad temporal es O(n) porque visita cada nodo una vez.
 * La complejidad espacial es O(h) por la pila de recursividad, donde h es la altura.
 */
ArbolJuegos::~ArbolJuegos() {

    liberarNodo(raiz);                        // O(n), libera todo el arbol
}

/**
 * liberarNodo borra los hijos primero y luego el nodo (recorrido postorden).
 *
 * @param nodo nodo actual
 */
void ArbolJuegos::liberarNodo(NodoJuego* nodo) {

    if (nodo == nullptr) {                    // O(1), caso base: no hay nodo
        return;
    }

    liberarNodo(nodo->izq);                   // T(subarbol izquierdo)
    liberarNodo(nodo->der);                   // T(subarbol derecho)

    delete nodo->juego;                       // O(1), libera el videojuego
    delete nodo;                              // O(1), libera el nodo
}

/**
 * insertarNodo baja por el arbol comparando calificaciones hasta encontrar
 * un lugar vacio y ahi coloca el juego nuevo.
 *
 * @param nodo nodo actual
 * @param juego juego a insertar
 * @return el nodo actual (para reconectar los hijos)
 *
 * Si la calificacion es menor se va a la izquierda, si es mayor o igual a la derecha.
 */
NodoJuego* ArbolJuegos::insertarNodo(NodoJuego* nodo,
                                     Videojuego* juego) {

    if (nodo == nullptr) {                    // O(1), caso base: lugar vacio

        return new NodoJuego(juego);          // O(1), crea el nodo nuevo
    }

    if (juego->getCalificacion() <
        nodo->juego->getCalificacion()) {     // O(1), compara calificaciones

        nodo->izq = insertarNodo(nodo->izq, juego);   // baja un nivel a la izquierda
    }
    else {

        nodo->der = insertarNodo(nodo->der, juego);   // baja un nivel a la derecha
    }

    return nodo;                              // O(1)
}

/**
 * insertar agrega un juego al arbol segun su calificacion.
 *
 * @param juego apuntador al videojuego
 *
 * La complejidad temporal es O(h), donde h es la altura del arbol: en promedio
 * h = log n, por lo que es O(log n); en el peor caso (datos ya ordenados) el arbol
 * es una "lista" y h = n, por lo que es O(n).
 * La complejidad espacial es O(h) por la pila de recursividad.
 */
void ArbolJuegos::insertar(Videojuego* juego) {

    raiz = insertarNodo(raiz, juego);            // O(h), baja hasta su lugar
}

/**
 * estaVacio revisa si el arbol no tiene juegos.
 *
 * La complejidad temporal y espacial es O(1).
 */
bool ArbolJuegos::estaVacio() {

    return raiz == nullptr;                       // O(1), compara un apuntador
}

/**
 * mostrarNodo recorre el arbol en inorden: primero lo menor (izquierda),
 * luego el nodo, luego lo mayor (derecha). Asi salen de menor a mayor calificacion.
 *
 * @param nodo nodo actual
 */
void ArbolJuegos::mostrarNodo(NodoJuego* nodo) {

    if (nodo == nullptr) {                            // O(1), caso base: no hay nodo
        return;
    }

    mostrarNodo(nodo->izq);                           // T(subarbol izquierdo), los menores

    nodo->juego->mostrarInfo();                       // O(1), muestra un juego

    mostrarNodo(nodo->der);                           // T(subarbol derecho), los mayores
}

/**
 * mostrarInorden muestra todos los juegos de menor a mayor calificacion.
 *
 * La complejidad temporal es O(n) porque visita cada nodo exactamente una vez.
 * No necesita ordenar porque el arbol ya esta ordenado.
 * La complejidad espacial es O(h) por la pila de recursividad.
 */
void ArbolJuegos::mostrarInorden() {

    mostrarNodo(raiz);                                // O(n), recorre todo el arbol
}

/**
 * aMinusculas convierte un texto a minusculas.
 *
 * @param texto texto a convertir
 * @return copia del texto en minusculas
 *
 * La complejidad temporal es O(m), donde m es la longitud del texto, porque
 * recorre cada letra una vez.
 * La complejidad espacial es O(m) porque se crea una copia del texto.
 */
string ArbolJuegos::aMinusculas(string texto) {

    for (int i = 0; i < texto.size(); i++) {          // O(m), recorre cada letra

        texto[i] = tolower(texto[i]);                 // O(1), convierte una letra
    }

    return texto;
}

/**
 * buscarNodo recorre el arbol y muestra los juegos cuyo nombre coincide,
 * sin importar mayusculas o minusculas.
 *
 * @param nodo nodo actual
 * @param buscadoMin nombre buscado ya en minusculas
 * @return true si encontro al menos uno
 */
bool ArbolJuegos::buscarNodo(NodoJuego* nodo,
                             string buscadoMin) {

    if (nodo == nullptr) {                            // O(1), caso base: no hay nodo
        return false;
    }

    bool enIzquierda = buscarNodo(nodo->izq,
                                  buscadoMin);        // T(subarbol izquierdo)

    bool actual = false;                              // O(1), bandera del nodo actual

    if (aMinusculas(nodo->juego->getNombre())
        == buscadoMin) {                              // O(1), compara nombres (m es corto)

        nodo->juego->mostrarInfo();                   // O(1), muestra el juego encontrado

        actual = true;                                // O(1), asigna variable
    }

    bool enDerecha = buscarNodo(nodo->der,
                                buscadoMin);          // T(subarbol derecho)

    return enIzquierda || actual || enDerecha;        // O(1), combina resultados
}

/**
 * buscarPorNombre busca un juego por nombre en todo el arbol.
 *
 * @param nombreBuscado nombre a buscar
 * @return true si se encontro al menos un juego
 *
 * La complejidad temporal es O(n) porque el arbol esta ordenado por calificacion,
 * no por nombre, asi que no se puede descartar ninguna rama y hay que revisar
 * todos los nodos (no se detiene al encontrarlo, por si hay nombres repetidos).
 * La complejidad espacial es O(h) por la pila de recursividad.
 */
bool ArbolJuegos::buscarPorNombre(string nombreBuscado) {

    string buscadoMin = aMinusculas(nombreBuscado);   // O(m), nombre en minusculas

    return buscarNodo(raiz, buscadoMin);              // O(n), revisa todos los nodos
}

#endif