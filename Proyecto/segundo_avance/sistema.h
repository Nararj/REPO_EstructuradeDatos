/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 23/10/2026
 * Version : 2
 * Esta clase controla la interfaz del sistema y la 
 * nteracción con el usuario.
 * Contiene el menú principal y coordina las operaciones
 * de registro, búsqueda y consulta de videojuegos.
 */

#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <string>

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
 * Constructor.
 */
Sistema::Sistema()
    : usuario("Nara") {

    usuario.getBiblioteca()
           .cargarDesdeArchivo("juegos.txt");
}

/**
 * leerEntero lee un entero positivo o cero y maneja errores de entrada.
 * 
 * No acepta letras ni valores negativos.
 *
 * @return entero válido
 */
int Sistema::leerEntero() {

    int valor;

    while (true) {

        if (!(cin >> valor)) {

            cout << "Error, ingresa un numero: ";

            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (valor < 0) {

            cout << "Error, ingresa un numero mayor o igual a 0: ";
        }
        else {

            return valor;
        }
    }
}

/**
 * leerCalificacion lee una calificacion entre 0 y 10 y maneja errores de entrada.
 * 
 * No permite valores negativos ni mayores a 10
 *
 * @return calificacion válida
 */
float Sistema::leerCalificacion() {

    float valor;

    while (true) {

        if (!(cin >> valor)) {

            cout << "Error, ingresa un numero: ";

            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (valor < 0 || valor > 10) {

            cout << "Error, la calificacion debe estar entre 0 y 10: ";
        }
        else {

            return valor;
        }
    }
}

/**
 * pedirDatosBasicos solicita los datos comunes de un videojuego.
 *
 * @param nombre nombre del juego
 * @param plataforma plataforma del juego
 * @param calificacion calificacion del juego
 */
void Sistema::pedirDatosBasicos(
    string &nombre,
    string &plataforma,
    float &calificacion) {

    cin.ignore();

    cout << "\nNombre: ";
    getline(cin, nombre);

    cout << "Plataforma: ";
    getline(cin, plataforma);

    cout << "Calificacion: ";

    calificacion = leerCalificacion();
}

/**
 * ejecutar muestra el menú principal
 * y controla la ejecución del programa.
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
    
        opcion = leerEntero();

        switch(opcion) {

        case 1: {

            string nombre;
            string plataforma;
            float calificacion;
            int horasHistoria;

            pedirDatosBasicos(
                nombre,
                plataforma,
                calificacion
            );

            cout << "Horas de historia: ";

            horasHistoria = leerEntero();

            Videojuego* juego =
                new JuegoRPG(
                    nombre,
                    plataforma,
                    calificacion,
                    horasHistoria
                );

            usuario.getBiblioteca()
                   .agregarJuego(juego);

            usuario.getBiblioteca()
                   .guardarEnArchivo(
                       "juegos.txt",
                       "RPG," + nombre + "," + plataforma + ","
                       + to_string(calificacion) + ","
                       + to_string(horasHistoria)
                   );

            cout << "\nJuego agregado."
                 << endl;
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
            );

            cout << "Nivel de violencia: ";

            violencia = leerEntero();

            Videojuego* juego =
                new JuegoAccion(
                    nombre,
                    plataforma,
                    calificacion,
                    violencia
                );

            usuario.getBiblioteca()
                   .guardarEnArchivo(
                       "juegos.txt",
                       "ACCION," + nombre + "," + plataforma + ","
                       + to_string(calificacion) + ","
                       + to_string(violencia)
                   );

            cout << "\nJuego agregado."
                 << endl;

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
            );

            cout << "Cantidad de decisiones: ";

            decisiones = leerEntero();

            Videojuego* juego =
                new JuegoAventuraGrafica(
                    nombre,
                    plataforma,
                    calificacion,
                    decisiones
                );

            usuario.getBiblioteca()
                   .guardarEnArchivo(
                       "juegos.txt",
                       "AVENTURA," + nombre + "," + plataforma + ","
                       + to_string(calificacion) + ","
                       + to_string(decisiones)
                   );

            cout << "\nJuego agregado."
                 << endl;

            break;
        }

        case 4: {

            usuario.getBiblioteca()
                   .mostrarJuegos();

            break;
        }

        case 5: {

            string nombreBuscado;

            cin.ignore();

            cout << "\nNombre del juego: ";

            getline(cin, nombreBuscado);

            usuario.getBiblioteca()
                   .buscarJuego(
                       nombreBuscado
                   );

            break;
        }

        case 6: {

            string favorito;

            cin.ignore();

            cout << "\nNombre del favorito: ";

            getline(cin, favorito);

            usuario.agregarFavorito(
                favorito
            );

            cout << "\nFavorito agregado."
                 << endl;

            break;
        }

        case 7: {

            usuario.mostrarFavoritos();

            break;
        }

        case 8: {

            cout << "\nGracias :D"
                 << endl;

            break;
        }
    }

    } while(opcion != 8);
}

#endif