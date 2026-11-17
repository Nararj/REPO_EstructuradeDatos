/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 11/11/2026
 * Version : 3
 * Esta clase controla la interfaz del sistema y la 
 * nteracción con el usuario.
 * Contiene el menú principal y coordina las operaciones
 * de registro, búsqueda y consulta de videojuegos.
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>
#include <algorithm>

#include "JuegoAccion.h"
#include "JuegoRPG.h"
#include "JuegoAventuraGrafica.h"
#include "Usuario.h"

using namespace std;

class Sistema {

//Declarar las variables privadas de instancia
private:

    Usuario usuario;

//Declarar constructor por default y metodos públicos.
public:

    Sistema();

    int leerEntero();

    float leerCalificacion();

    void pedirDatosBasicos(
        string &nombre,
        string &plataforma,
        float &calificacion
    );

    void ejecutar();
};

/**
 * Constructor
 * 
 * La complejidad temporal es O(n log n + f) en promedio y O(n^2 + f) en el peor caso
 * (archivo de juegos ya ordenado por calificacion).
 * La complejidad espacial es O(n + f) por los nodos del arbol y el vector.
 */
Sistema::Sistema()
    : usuario("Carlos") {                             // O(1), crea el usuario

    usuario.getBiblioteca()
           .cargarDesdeArchivo("juegos.txt");         // O(n log n) prom., O(n^2) peor

    usuario.cargarFavoritosDesdeArchivo(
        "favoritos.txt");                             // O(f), una vuelta por linea
}

/**
 * leerEntero lee un entero positivo o cero y maneja errores de entrada.
 * 
 * No acepta letras ni valores negativos.
 *
 * @return entero válido
 * 
 * La complejidad temporal es O(k), donde k es el numero de intentos invalidos del
 * usuario; no depende de n ni de f. En el mejor caso (dato valido) es O(1).
 * La complejidad espacial es O(1).
 */
int Sistema::leerEntero() {

    int valor;                                        // O(1), variable

    while (true) {                                    // O(k), se repite por cada dato invalido

        if (!(cin >> valor)) {                        // O(1), intenta leer un numero

            cout << "Error, ingresa un numero: ";     // O(1), mensaje

            cin.clear();                              // O(1), limpia el error de cin
            cin.ignore(1000, '\n');                   // O(1), descarta maximo 1000 caracteres (limite fijo)
        }
        else if (valor < 0) {                         // O(1), compara con 0

            cout << "Error, ingresa un numero mayor o igual a 0: ";  // O(1)
        }
        else {

            return valor;                             // O(1), dato valido
        }
    }
}

/**
 * leerCalificacion lee una calificacion entre 0 y 10 y maneja errores de entrada.
 * 
 * No permite valores negativos ni mayores a 10
 *
 * @return calificacion válida
 * 
 * La complejidad temporal es O(k), donde k es el numero de intentos invalidos del
 * usuario; no depende de n ni de f. En el mejor caso (dato valido) es O(1).
 * La complejidad espacial es O(1).
 */
float Sistema::leerCalificacion() {

    float valor;                                                          // O(1), variable

    while (true) {                                                        // O(k), se repite por cada dato invalido

        if (!(cin >> valor)) {                                            // O(1), intenta leer un numero

            cout << "Error, ingresa un numero: ";                         // O(1), mensaje
 
            cin.clear();                                                  // O(1), limpia el error de cin
            cin.ignore(1000, '\n');                                       // O(1), descarta maximo 1000 caracteres (limite fijo)
        }
        else if (valor < 0 || valor > 10) {                               // O(1), compara con 0 y 10

            cout << "Error, la calificacion debe estar entre 0 y 10: ";   // O(1), mensaje
        }
        else {

            return valor;                                                 // O(1), dato valido
        }
    }
}

/**
 * pedirDatosBasicos solicita los datos comunes de un videojuego.
 *
 * Reemplaza las comas del nombre y la plataforma por espacios, porque la coma
 * separa los campos en juegos.txt y rompería el formato al guardar y recargar.
 *
 * @param nombre nombre del juego
 * @param plataforma plataforma del juego
 * @param calificacion calificacion del juego
 *
 * La complejidad temporal es O(m), donde m es la longitud de los textos, por leerlos
 * y recorrerlos para reemplazar las comas; como son cortos, se toma casi O(1).
 * La complejidad espacial es O(1) porque usa referencias y no crea estructuras.
 */
void Sistema::pedirDatosBasicos(
    string &nombre,
    string &plataforma,
    float &calificacion) {

    cin.ignore();                                     // O(1), descarta el salto de linea pendiente

    cout << "\nNombre: ";
    getline(cin, nombre);                             // O(m), lee el nombre completo

    cout << "Plataforma: ";
    getline(cin, plataforma);                         // O(m), lee la plataforma

    replace(nombre.begin(), nombre.end(), ',', ' ');          // O(m), cambia cada coma por espacio
    replace(plataforma.begin(), plataforma.end(), ',', ' ');  // O(m), cambia cada coma por espacio

    cout << "Calificacion: ";

    calificacion = leerCalificacion();                // O(1), lee y valida
}

/**
 * ejecutar muestra el menú principal
 * y controla la ejecución del programa.
 * 
 * El ciclo do-while se repite k veces (una por cada opcion elegida) y cada vuelta cuesta
 * lo que cueste su opcion. Las opciones mas caras son recorrer el arbol, O(n), y ordenar
 * los favoritos, O(f log f) en promedio, por lo que el ciclo completo es
 * O(k * (n + f log f)). En el peor caso (quick sort con muchos favoritos repetidos)
 * ordenar favoritos llega a O(f^2).
 * La complejidad espacial es O(h) por la recursividad del arbol, mas O(n + f) de las estructuras.
 */
void Sistema::ejecutar() {

    int opcion;

    do {

        cout << "\nBIBLIOTECA DE VIDEOJUEGOS"
             << endl;

        cout << "1. Agregar Juego RPG"
             << endl;

        cout << "2. Agregar Juego de Accion"
             << endl;

        cout << "3. Agregar Juego de Aventura Grafica"
             << endl;

        cout << "4. Mostrar Juegos"
             << endl;

        cout << "5. Buscar Juego"
             << endl;

        cout << "6. Agregar Favorito"
             << endl;

        cout << "7. Mostrar Favoritos"
             << endl;

        cout << "8. Salir"
             << endl;

        cout << "\nOpcion: ";
    
        opcion = leerEntero();             // O(1), lee y valida la opcion

        switch(opcion) {                   // O(1), elige la opcion

        case 1: {                          // O(1), agregar juego RPG

            string nombre;
            string plataforma;
            float calificacion;
            int horasHistoria;

            pedirDatosBasicos(
                nombre,
                plataforma,
                calificacion
            );                             // O(1), pide nombre, plataforma y calificacion

            cout << "Horas de historia: ";

            horasHistoria = leerEntero();

            Videojuego* juego =            // O(1), crea un juego RPG
                new JuegoRPG(
                    nombre,
                    plataforma,
                    calificacion,
                    horasHistoria
                );

            usuario.getBiblioteca()
                   .agregarJuego(juego);   // O(log n) prom., O(n) peor, lo coloca en su lugar en el arbol

            usuario.getBiblioteca()
                   .guardarEnArchivo(
                       "juegos.txt",
                       "RPG," + nombre + "," + plataforma + ","
                       + to_string(calificacion) + ","
                       + to_string(horasHistoria)
                   );                      // O(1), agrega al final del archivo

            cout << "\nJuego agregado."
                 << endl;                  // O(1), mensaje
            break;
        }
 
        case 2: {

            string nombre;
            string plataforma;
            float calificacion;
            int violencia;

            pedirDatosBasicos(
                nombre,
                plataforma,
                calificacion
            );                                   // O(1), pide nombre, plataforma y calificacion

            cout << "Nivel de violencia: ";      // O(1), mensaje

            violencia = leerEntero();            // O(1), lee y valida

            Videojuego* juego =                  // O(1), crea un juego de accion
                new JuegoAccion(
                    nombre,
                    plataforma,
                    calificacion,
                    violencia
                );                               // O(1), crea un juego de accion

            usuario.getBiblioteca()
                   .guardarEnArchivo(
                       "juegos.txt",
                       "ACCION," + nombre + "," + plataforma + ","
                       + to_string(calificacion) + ","
                       + to_string(violencia)    // O(1), agrega al final del archivo
                   );

            cout << "\nJuego agregado."
                 << endl;            // O(1), mensaje

            break;
        }

        case 3: {

            string nombre;
            string plataforma;
            float calificacion;
            int decisiones;             

            pedirDatosBasicos(
                nombre,
                plataforma,
                calificacion
            );                          // O(1), pide nombre, plataforma y calificacion

            cout << "Cantidad de decisiones: ";   // O(1), mensaje

            decisiones = leerEntero();  // O(1), lee y valida

            Videojuego* juego =
                new JuegoAventuraGrafica(
                    nombre,
                    plataforma,
                    calificacion,
                    decisiones
                );                       // O(1), crea un juego de aventura grafica

            usuario.getBiblioteca()
                   .guardarEnArchivo(
                       "juegos.txt",
                       "AVENTURA," + nombre + "," + plataforma + ","
                       + to_string(calificacion) + ","
                       + to_string(decisiones)
                   );                     // O(1), agrega al final del archivo

            cout << "\nJuego agregado."
                 << endl;                 // O(1), mensaje

            break;
        }

        case 4: {                          // O(1), mostrar juegos

            usuario.getBiblioteca()
                   .mostrarJuegos();

            break;                         // O(n), recorre el arbol y muestra los juegos
        }

        case 5: {                          // O(1), buscar juego

            string nombreBuscado;          // O(1), variable

            cin.ignore();                  // O(1), descarta el salto de linea pendiente

            cout << "\nNombre del juego: ";  // O(1), mensaje

            getline(cin, nombreBuscado);     // O(m), lee el nombre completo

            usuario.getBiblioteca()
                   .buscarJuego(
                       nombreBuscado
                   );                        // O(n), recorre el arbol y busca coincidencias

            break;
        }

        case 6: {                         // O(1), agregar favorito

            string favorito;              // O(1), variable

            cin.ignore();                 // O(1), descarta el salto de linea pendiente

            cout << "\nNombre del favorito: ";   // O(1), mensaje

            getline(cin, favorito);              // O(m), lee el nombre completo

            usuario.agregarFavorito(
                favorito
            );                                   // O(1), agrega al vector y marca que hay que ordenar

            usuario.guardarFavoritoEnArchivo(
                "favoritos.txt",
                favorito
            );                                   // O(1), agrega al final del archivo
            
            cout << "\nFavorito agregado."
                 << endl;

            break;                               // O(1), mensaje
        }

        case 7: {                          // O(1), mostrar favoritos
 
            usuario.mostrarFavoritos();    // O(f log f) prom., O(f^2) peor, ordena y muestra los favoritos

            break;                         // O(f), recorre el vector y muestra los favoritos
        }

        case 8: {                          // O(1), salir del programa

            cout << "\nGracias :D"
                 << endl;

            break;                         // O(1), mensaje
        }
    }

    } while(opcion != 8);                  // O(k * (n + f log f)) prom., O(k * (n + f^2)) peor, ciclo de menu
}

#endif