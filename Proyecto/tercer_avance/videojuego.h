/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 11/11/2026
 * Version : 3
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
    
    virtual ~Videojuego() {}
};

/**
 * Constructor por defecto.
 * 
 * La complejidad temporal es O(1) y la espacial es O(1), solo asigna valores iniciales.
 */
Videojuego::Videojuego() {

    nombre = "";                    // O(1), asigna texto vacio
    plataforma = "";                // O(1), asigna texto vacio
    calificacion = 0;               // O(1), asigna un numero
}

/**
 * Constructor con parámetros.
 *
 * @param nom nombre del videojuego
 * @param plat plataforma
 * @param cal calificación
 * 
 * La complejidad temporal es O(1) (O(m) por copiar los textos, que son cortos).
 * La complejidad espacial es O(1).
 */
Videojuego::Videojuego(string nom, string plat, float cal) {

    nombre = nom;                      // O(1), copia el nombre
    plataforma = plat;                 // O(1), copia la plataforma
    calificacion = cal;                // O(1), asigna un numero
}

/**
 * getNombre regresa el nombre del videojuego.
 *
 * @return nombre
 * 
 * Complejidad temporal y espacial O(1).
 */
string Videojuego::getNombre() {

    return nombre;                      // O(1), regresa el atributo
}


/**
 * getCalificacion regresa la calificación.
 *
 * @return calificación
 * 
 * Complejidad temporal y espacial O(1).
 */
float Videojuego::getCalificacion() {

    return calificacion;                // O(1), regresa el atributo
}

/**
 * mostrarDatosBasicos muestra la información básica
 * de cualquier videojuego.
 * 
 * La complejidad temporal es O(1) porque son solo impresiones de texto y números.
 * La complejidad espacial es O(1).
 */
void Videojuego::mostrarDatosBasicos() {

    // O(1), imprime un dato
    cout << "Nombre: "
         << nombre
         << endl;

    // O(1), imprime un dato
    cout << "Plataforma: "
         << plataforma
         << endl;

    // O(1), imprime un dato
    cout << "Calificacion: "
         << calificacion
         << endl;
}

#endif