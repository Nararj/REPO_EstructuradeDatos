/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 23/10/2026
 * Version : 2
 * Esta clase define objeto de tipo juegoRPG que agrega el atributo
 * de horas de historia.
 * Sobreescribe el metodo mostrarInfo() para mostrar la informacion 
 * especifica de los juegos RPG.
 * Nombre, plataforma, calificacion, horas de historia
 */

#ifndef JUEGORPG_H
#define JUEGORPG_H

#include "Videojuego.h"

//Declarar objeto JuegoRPG que hereda de Videojuego
class JuegoRPG : public Videojuego {

//Declarar las variables de instancia privadas
private:

    int horasHistoria;

//Declarar metodos públicos
public:

    JuegoRPG();

    JuegoRPG(string nom, string plat,
             float cal, int horas);

    void mostrarInfo() override;
};

/**
 * Constructor por defecto.
 */
JuegoRPG::JuegoRPG() : Videojuego() {

    horasHistoria = 0;
}

/**
 * Constructor con parámetros.
 *
 * @param nom nombre del juego
 * @param plat plataforma
 * @param cal calificación
 * @param horas duración de la historia
 */
JuegoRPG::JuegoRPG(string nom,
                   string plat,
                   float cal,
                   int horas)
    : Videojuego(nom, plat, cal) {

    horasHistoria = horas;
}

/**
 * mostrarInfo muestra toda la información
 * del videojuego.
 */
void JuegoRPG::mostrarInfo() {

    cout << "\n JUEGO RPG "
         << endl;

    mostrarDatosBasicos();

    cout << "Horas de historia: "
         << horasHistoria
         << endl;
}

#endif