/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 23/10/2026
 * Version : 2
 * Esta clase define objeto de tipo Videojuego que contiene las clases heredadas
 * Nombre, plataforma, calificacion.
 */

#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <iostream>
using namespace std;

using namespace std;

//Declaracion de clase videojuego que es abstracta
class Videojuego {
  
//Declarar variables de instancia
protected:

    string nombre;
    string plataforma;
    float calificacion;

//Declaro los métodos que va a tener el objeto
public:

    Videojuego();
    Videojuego(string nom,
               string plat,
               float cal);

    string getNombre();

    float getCalificacion();

    void mostrarDatosBasicos();

    virtual void mostrarInfo() = 0; //método abstracto será sobreescrito

};

/**
 * Constructor por defecto.
 */
Videojuego::Videojuego() {

    nombre = "";
    plataforma = "";
    calificacion = 0;
}

/**
 * Constructor con parámetros.
 *
 * @param nom nombre del videojuego
 * @param plat plataforma
 * @param cal calificación
 */
Videojuego::Videojuego(string nom,
                       string plat,
                       float cal) {

    nombre = nom;
    plataforma = plat;
    calificacion = cal;
}

/**
 * getNombre regresa el nombre del videojuego.
 *
 * @return nombre
 */
string Videojuego::getNombre() {

    return nombre;
}

/**
 * getCalificacion regresa la calificación.
 *
 * @return calificación
 */
float Videojuego::getCalificacion() {

    return calificacion;
}

/**
 * mostrarDatosBasicos muestra la información básica
 * de cualquier videojuego.
 */
void Videojuego::mostrarDatosBasicos() {

    cout << "Nombre: "
         << nombre
         << endl;

    cout << "Plataforma: "
         << plataforma
         << endl;

    cout << "Calificacion: "
         << calificacion
         << endl;
}

#endif