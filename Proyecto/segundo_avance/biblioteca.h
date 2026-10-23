/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 23/10/2026
 * Version : 2
 * Esta clase almacena videojuegos de distintos tipos en un vector de punteros a videojuegos,
 * esto es para poder usar el polimorfismo en tiempo de ejecucion y guardar objetos de las
 * clases hijas (JuegoAccion, JuegoRPG y JuegoAventuraGrafica) en un vector de la clase padre
 * (Videojuego). Tambien carga juegos desde un archivo de texto, guarda los nuevos en ese
 * archivo y los muestra ordenados por calificacion con merge sort.
 *
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Videojuego.h"
#include "JuegoRPG.h"
#include "JuegoAccion.h"
#include "JuegoAventuraGrafica.h"
#include "Ordenar.h"

using namespace std;

class Biblioteca {

//Declarar las variables privadas de instancia
private:

    vector<Videojuego*> juegos;

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
 * agregarJuego agrega un videojuego a la biblioteca.
 *
 * @param juego apuntador al videojuego
 *
 * La complejidad temporal es O(1) amortizado, porque push_back agrega al final
 * del vector sin recorrerlo (solo a veces el vector crece y se copia).
 * La complejidad espacial es O(1) porque solo se guarda un puntero.
 */
void Biblioteca::agregarJuego(
    Videojuego* juego) {

    juegos.push_back(juego);                          // O(1), agrega el puntero al final
}

/**
 * mostrarJuegos muestra todos los videojuegos ordenados de menor a mayor calificacion.
 *
 * Primero ordena el vector con merge sort y despues lo recorre
 * mostrando cada juego con mostrarInfo().
 *
 * La complejidad temporal es O(n log n) por el ordenamiento, mas O(n) del recorrido,
 * y O(n log n) + O(n) sigue siendo O(n log n).
 * La complejidad espacial es O(n) por el vector temporal del merge sort.
 */
void Biblioteca::mostrarJuegos() {

    OrdenadorJuegos ordenador;                        // O(1), crea el objeto ordenador

    ordenador.ordenarPorCalificacion(juegos);         // O(n log n), ordena el vector

    cout << "\n VIDEOJUEGOS "
         << endl;

    if (juegos.size() == 0) {                         // O(1), size solo consulta un contador

        cout << "No hay juegos registrados."          // O(1), solo imprime el mensaje
             << endl;

        return;
    }

    for (int i = 0;                                   // O(n), recorre todos los juegos
         i < juegos.size();
         i++) {

        juegos[i]->mostrarInfo();                     // O(1), muestra un solo juego
    }
}

/**
 * buscarJuego busca un videojuego por nombre
 *
 * @param nombreBuscado nombre a buscar
 *
 * La complejidad temporal es O(n) porque revisa todos los juegos en todos los casos
 * (no se detiene al encontrarlo, por si hay nombres repetidos).
 * La complejidad espacial es O(1).
 */
void Biblioteca::buscarJuego(
    string nombreBuscado) {

    bool encontrado = false;                          // O(1), bandera para saber si se encontro

    for (int i = 0;
         i < juegos.size();
         i++) {                                       // O(n), recorre todos los juegos

        if (juegos[i]->getNombre()
            == nombreBuscado) {                       // O(1), compara dos nombres

            juegos[i]->mostrarInfo();                 // O(1), muestra el juego encontrado

            encontrado = true;                        // O(1), asigna variable
        }
    }

    if (!encontrado) {                                // O(1), revisa si se encontro el juego

        cout << "\nJuego no encontrado."              // O(1), imprime mensaje
             << endl;
    }
}

/**
 * cargarDesdeArchivo lee un archivo de texto y agrega cada juego al vector.
 *
 * @param juegos.txt 
 *
 * Formato de cada linea: tipo,nombre,plataforma,calificacion,dato_especial
 *
 * La complejidad temporal es O(n) donde n es el numero de lineas del archivo,
 * porque cada linea se lee una vez y agregar al vector es O(1) amortizado.
 * La complejidad espacial es O(n) porque se crean n objetos de videojuego.
 */
void Biblioteca::cargarDesdeArchivo(
    string nombreArchivo) {

    ifstream archivo(nombreArchivo);                  // O(1), abre el archivo

    if (!archivo.is_open()) {                         // O(1), revisa si se pudo abrir

        cout << "\nNo se encontro el archivo "        // O(1), imprime mensaje
             << nombreArchivo
             << endl;

        return;                                       // O(1), termina la funcion
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
                    calificacion, extra));            // O(1), crea y agrega el juego
            }
            else if (tipo == "ACCION") {

                agregarJuego(new JuegoAccion(
                    nombre, plataforma,
                    calificacion, extra));            // O(1), crea y agrega el juego
            }
            else if (tipo == "AVENTURA") {

                agregarJuego(new JuegoAventuraGrafica(
                    nombre, plataforma,
                    calificacion, extra));            // O(1), crea y agrega el juego
            }
            else {                                     

                cout << "Tipo invalido en linea: "    // O(1), imprime mensaje
                     << linea
                     << endl;
            }
        }
        catch (...) {                                 // O(1), captura cualquier error de conversion

            cout << "Linea invalida: "                // O(1), imprime mensaje
                 << linea
                 << endl;
        }
    }

    archivo.close();                                  // O(1), cierra el archivo
}

/**
 * guardarEnArchivo agrega una linea nueva al final del archivo de texto.
 *
 * @param juegos.txt
 * @param linea texto con el formato tipo,nombre,plataforma,calificacion,dato_especial
 *
 * La complejidad temporal es O(1) porque solo escribe una linea al final,
 * sin recorrer ni leer el resto del archivo
 * La complejidad espacial es O(1) porque no se crean estructuras nuevas.
 */
void Biblioteca::guardarEnArchivo(
    string nombreArchivo,
    string linea) {

    ofstream archivo(nombreArchivo, ios::app);        // O(1), abre el archivo para agregar al final

    if (!archivo.is_open()) {                         // O(1), revisa si se pudo abrir

        cout << "\nNo se pudo guardar en el archivo." // O(1), imprime mensaje
             << endl;

        return;
    }

    archivo << "\n" << linea;                         // O(1), escribe un salto de linea y el juego

    archivo.close();                                  // O(1), cierra el archivo
}

#endif