/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 23/10/2026
 * Version : 2
 * Esta clase define objeto de tipo juegoAccion que agrega el atributo
 * de violencia.
 * Sobreescribe el metodo mostrarInfo() para mostrar la informacion 
 * especifica de los juegos de accion.
 * Nombre, plataforma, calificacion, violencia.
 */

#ifndef JUEGOACCION_H
#define JUEGOACCION_H

#include "Videojuego.h"

//Declarar objeto JuegoAccion que hereda de Videojuego
class JuegoAccion : public Videojuego {

//Declarar las variables de instancia privadas
private:

    int violencia;
  
//Declarar metodos públicos
public:

    JuegoAccion();

    JuegoAccion(string nom, string plat,
                float cal, int viol);

    void mostrarInfo() override;
};

/**
 * Constructor por defecto.
 */
JuegoAccion::JuegoAccion() : Videojuego() {

    violencia = 0;
}

/**
 * Constructor con parámetros.
 *
 * @param nom nombre del juego
 * @param plat plataforma
 * @param cal calificación
 * @param viol nivel de violencia
 */
JuegoAccion::JuegoAccion(string nom,
                         string plat,
                         float cal,
                         int viol)
    : Videojuego(nom, plat, cal) {

    violencia = viol;
}

/**
 * mostrarInfo muestra toda la información
 * del videojuego.
 */
void JuegoAccion::mostrarInfo() {

    cout << "\n JUEGO DE ACCION "
         << endl;

    mostrarDatosBasicos();

    cout << "Nivel de violencia: "
         << violencia
         << endl;
}

#endif