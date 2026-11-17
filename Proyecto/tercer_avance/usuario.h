/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 11/11/2026
 * Version : 3
 * Esta clase define objeto de tipo Usuario que contiene el nombre del 
 * usuario, una lista de juegos favoritos y una biblioteca de juegos
 * Vector videojuegos
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <string>
#include <fstream>

#include "Biblioteca.h"
#include "OrdenarFavoritos.h"

using namespace std;

class Usuario {

//Declarar las variables privadas de instancia
private:

    string nombre;

    vector<string> favoritos;

    bool favoritosOrdenados;

    Biblioteca biblioteca;

    void ordenarSiHaceFalta();

//Declarar constructor por default y metodos públicos.
public:

    Usuario();

    Usuario(string nom);

    void agregarFavorito(
        string juego
    );

    void mostrarFavoritos();

    void cargarFavoritosDesdeArchivo(
        string nombreArchivo
    );

    void guardarFavoritoEnArchivo(
        string nombreArchivo,
        string juego
    );

    Biblioteca& getBiblioteca();
};

/**
 * Constructor por defecto.
 */
Usuario::Usuario() {

    nombre = "";
    favoritosOrdenados = true;
}

/**
 * Constructor con parámetro.
 *
 * @param nom nombre del usuario
 */
Usuario::Usuario(string nom) {

    nombre = nom;
    favoritosOrdenados = true;
}

/**
 * ordenarSiHaceFalta ordena el vector de favoritos con quick sort,
 * pero solo si se agrego algo desde la ultima vez que se ordeno.
 *
 * La complejidad temporal es O(1) si ya estaba ordenado; si no, es O(n log n)
 * en promedio y O(n^2) en el peor caso por el quick sort.
 * La complejidad espacial es O(log n) en promedio por la recursividad.
 */
void Usuario::ordenarSiHaceFalta() {

    if (!favoritosOrdenados) {                        // O(1), revisa la bandera

        OrdenadorFavoritos ordenador;                 // O(1), crea el ordenador

        ordenador.ordenar(favoritos);                 // O(n log n), quick sort

        favoritosOrdenados = true;                    // O(1), ya esta ordenado
    }
}

/**
 * agregarFavorito agrega un videojuego a favoritos.
 *
 * @param juego nombre del videojuego
 *
 * La complejidad temporal es O(1) porque push_back agrega al final.
 * La complejidad espacial es O(1) porque solo se guarda un string.
 */
void Usuario::agregarFavorito(
    string juego) {

    favoritos.push_back(juego);                       // O(1), agrega al final del vector

    favoritosOrdenados = false;                       // O(1), ahora hay que reordenar
}

/**
 * mostrarFavoritos muestra los favoritos en orden alfabetico.
 *
 * La complejidad temporal es O(n log n) en promedio si hubo cambios (por el quick sort)
 * y O(n) si ya estaba ordenado, por el recorrido.
 * La complejidad espacial es O(log n) en promedio por el quick sort.
 */
void Usuario::mostrarFavoritos() {

    cout << "\n FAVORITOS "
         << endl;

    if (favoritos.size() == 0) {                      // O(1), size solo consulta un contador

        cout << "No hay favoritos."
             << endl;

        return;
    }

    ordenarSiHaceFalta();                             // O(n log n) o O(1), ordena si hace falta

    for (int i = 0;
         i < favoritos.size();
         i++) {                                       // O(n), recorre todos los favoritos

        cout << favoritos[i]                          // O(1), acceso por indice
             << endl;
    }
}

/**
 * cargarFavoritosDesdeArchivo lee un archivo de texto con un favorito por linea
 * y los agrega al vector de favoritos.
 *
 * @param nombreArchivo nombre del archivo, por ejemplo "favoritos.txt"
 *
 * Si el archivo no existe no hace nada, porque se crea al guardar el primer favorito.
 * La complejidad temporal es O(n), donde n es el numero de lineas del archivo,
 * porque cada linea se lee una vez y push_back es O(1) amortizado.
 * La complejidad espacial es O(n) porque se guardan n nombres en el vector.
 */
void Usuario::cargarFavoritosDesdeArchivo(
    string nombreArchivo) {

    ifstream archivo(nombreArchivo);                  // O(1), abre el archivo

    if (!archivo.is_open()) {                         // O(1), si no existe, no hay favoritos guardados
        return;
    }

    string linea;                                     // O(1), guarda cada linea leida

    while (getline(archivo, linea)) {                 // O(n), lee una linea por vuelta

        if (linea != "") {                            // O(1), ignora lineas vacias

            agregarFavorito(linea);                   // O(1), agrega al vector
        }
    }

    archivo.close();                                  // O(1), cierra el archivo
}

/**
 * guardarFavoritoEnArchivo agrega un favorito al final del archivo de texto.
 *
 * @param nombreArchivo nombre del archivo, por ejemplo "favoritos.txt"
 * @param juego nombre del favorito a guardar
 *
 * La complejidad temporal es O(1) porque solo escribe una linea al final,
 * sin leer el resto del archivo.
 * La complejidad espacial es O(1) porque no se crean estructuras nuevas.
 */
void Usuario::guardarFavoritoEnArchivo(
    string nombreArchivo,
    string juego) {

    ofstream archivo(nombreArchivo, ios::app);        // O(1), abre el archivo para agregar al final

    if (!archivo.is_open()) {                         // O(1), revisa si se pudo abrir

        cout << "\nNo se pudo guardar el favorito."
             << endl;

        return;
    }

    archivo << "\n" << juego;                         // O(1), escribe un salto de linea y el nombre

    archivo.close();                                  // O(1), cierra el archivo
}

/**
 * getBiblioteca regresa una referencia a la biblioteca del usuario.
 *
 * @return referencia a biblioteca
 */
Biblioteca& Usuario::getBiblioteca() {

    return biblioteca;
}

#endif