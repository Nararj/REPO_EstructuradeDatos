/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 11/11/2026
 * Version : 3
 * Esta clase almacena videojuegos de distintos tipos en un vector de punteros a videojuegos,
 * esto es para poder usar el polimorfismo en tiempo de ejecucion y guardar objetos de las
 * clases hijas (JuegoAccion, JuegoRPG y JuegoAventuraGrafica) en un vector de la clase padre
 * (Videojuego). Tambien carga juegos desde un archivo de texto, guarda los nuevos en ese
 * archivo y los muestra ordenados por calificacion con merge sort.
 *
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <fstream>
#include <sstream>

#include "Videojuego.h"
#include "JuegoRPG.h"
#include "JuegoAccion.h"
#include "JuegoAventuraGrafica.h"
#include "ArbolJuegos.h"

using namespace std;

class Biblioteca {

//Declarar las variables privadas de instancia
private:

    ArbolJuegos arbol;

//Declarar constructor por default y metodos públicos.
public:

    Biblioteca();

    void agregarJuego(
        Videojuego* juego
    );

    void mostrarJuegos();

    void buscarJuego(
        string nombreBuscado
    );

    void cargarDesdeArchivo(
        string nombreArchivo
    );

    void guardarEnArchivo(
        string nombreArchivo,
        string linea
    );

};

/**
 * Constructor.
 */
Biblioteca::Biblioteca() {

}

/**
 * agregarJuego agrega un videojuego al arbol segun su calificacion.
 *
 * @param juego apuntador al videojuego
 *
 * La complejidad temporal es O(h), donde h es la altura del arbol: O(log n) en
 * promedio y O(n) en el peor caso (si los juegos entran ya ordenados).
 * La complejidad espacial es O(h) por la recursividad de la insercion.
 */
void Biblioteca::agregarJuego(
    Videojuego* juego) {

    arbol.insertar(juego);                            // O(h), lo coloca en su lugar
}

/**
 * mostrarJuegos muestra todos los videojuegos de menor a mayor calificacion.
 *
 * No necesita ordenar porque el arbol ya esta ordenado: basta un recorrido inorden.
 *
 * La complejidad temporal es O(n) porque visita cada juego una sola vez.
 * La complejidad espacial es O(h) por la recursividad.
 */
void Biblioteca::mostrarJuegos() {

    cout << "\n VIDEOJUEGOS "
         << endl;

    if (arbol.estaVacio()) {                          // O(1), revisa si no hay juegos

        cout << "No hay juegos registrados."
             << endl;

        return;
    }

    arbol.mostrarInorden();                           // O(n), recorrido inorden
}

/**
 * buscarJuego busca un videojuego por nombre sin importar mayusculas o minusculas.
 *
 * @param nombreBuscado nombre a buscar
 *
 * La complejidad temporal es O(n) porque el arbol esta ordenado por calificacion
 * y no por nombre, asi que se revisan todos los nodos.
 * La complejidad espacial es O(h) por la pila de recursividad.
 */
void Biblioteca::buscarJuego(
    string nombreBuscado) {

    bool encontrado =
        arbol.buscarPorNombre(nombreBuscado);         // O(n), recorre el arbol

    if (!encontrado) {                                // O(1), revisa la bandera

        cout << "\nJuego no encontrado."
             << endl;
    }
}

/**
 * cargarDesdeArchivo lee un archivo de texto y agrega cada juego al arbol.
 *
 * @param nombreArchivo nombre del archivo, por ejemplo "juegos.txt"
 *
 * Formato de cada linea: tipo,nombre,plataforma,calificacion,dato_especial
 *
 * El archivo puede estar en cualquier orden: el arbol coloca cada juego
 * en su lugar al insertarlo.
 *
 * La complejidad temporal es O(n log n) en promedio, porque se leen n lineas y cada
 * insercion cuesta O(log n); en el peor caso es O(n^2) (archivo ya ordenado).
 * La complejidad espacial es O(n) porque se crean n nodos y videojuegos.
 */
void Biblioteca::cargarDesdeArchivo(
    string nombreArchivo) {

    ifstream archivo(nombreArchivo);                  // O(1), abre el archivo

    if (!archivo.is_open()) {                         // O(1), revisa si se pudo abrir

        cout << "\nNo se encontro el archivo "
             << nombreArchivo
             << endl;

        return;
    }

    string linea;                                     // O(1), guarda cada linea leida

    while (getline(archivo, linea)) {                 // O(n), lee una linea por vuelta

        if (linea == "") {                            // O(1), ignora lineas vacias
            continue;
        }

        stringstream ss(linea);                       // O(1), permite separar la linea por comas

        string tipo;
        string nombre;
        string plataforma;
        string calTexto;
        string extraTexto;

        getline(ss, tipo, ',');                       // O(1), lee hasta la primera coma
        getline(ss, nombre, ',');                     // O(1), lee el nombre
        getline(ss, plataforma, ',');                 // O(1), lee la plataforma
        getline(ss, calTexto, ',');                   // O(1), lee la calificacion como texto
        getline(ss, extraTexto, ',');                 // O(1), lee el dato especial como texto

        try {

            float calificacion = stof(calTexto);      // O(1), convierte texto a decimal
            int extra = stoi(extraTexto);             // O(1), convierte texto a entero

            if (tipo == "RPG") {                      // O(1), revisa el tipo de juego

                agregarJuego(new JuegoRPG(
                    nombre, plataforma,
                    calificacion, extra));            // O(h), crea e inserta en el arbol
            }
            else if (tipo == "ACCION") {

                agregarJuego(new JuegoAccion(
                    nombre, plataforma,
                    calificacion, extra));            // O(h), crea e inserta en el arbol
            }
            else if (tipo == "AVENTURA") {

                agregarJuego(new JuegoAventuraGrafica(
                    nombre, plataforma,
                    calificacion, extra));            // O(h), crea e inserta en el arbol
            }
            else {

                cout << "Tipo invalido en linea: "
                     << linea
                     << endl;
            }
        }
        catch (...) {                                 // atrapa errores si el numero esta mal escrito

            cout << "Linea invalida: "
                 << linea
                 << endl;
        }
    }

    archivo.close();                                  // O(1), cierra el archivo
}

/**
 * guardarEnArchivo agrega una linea nueva al final del archivo de texto.
 *
 * @param nombreArchivo nombre del archivo, por ejemplo "juegos.txt"
 * @param linea texto con el formato tipo,nombre,plataforma,calificacion,dato_especial
 *
 * La complejidad temporal es O(1) porque solo escribe una linea al final,
 * sin recorrer ni leer el resto del archivo.
 * La complejidad espacial es O(1) porque no se crean estructuras nuevas.
 */
void Biblioteca::guardarEnArchivo(
    string nombreArchivo,
    string linea) {

    ofstream archivo(nombreArchivo, ios::app);        // O(1), abre el archivo para agregar al final

    if (!archivo.is_open()) {                         // O(1), revisa si se pudo abrir

        cout << "\nNo se pudo guardar en el archivo."
             << endl;

        return;
    }

    archivo << "\n" << linea;                         // O(1), escribe un salto de linea y el juego

    archivo.close();                                  // O(1), cierra el archivo
}

#endif