/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 11/11/2026
 * Version : 3
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
 * La complejidad temporal y espacial es O(1).
 */
JuegoRPG::JuegoRPG(string nom,
                   string plat,
                   float cal,
                   int horas)
    : Videojuego(nom, plat, cal) {         // O(1), llama al constructor del padre

    horasHistoria = horas;                 // O(1), asigna el dato propio
}

/**
 * mostrarInfo muestra toda la información
 * del videojuego.
 * La complejidad temporal es O(1) porque son impresiones de texto y números.
 * La complejidad espacial es O(1).
 */
void JuegoRPG::mostrarInfo() {

    cout << "\nJUEGO RPG "
         << endl;                          // O(1), imprime un dato

    mostrarDatosBasicos();                 // O(1), llama al metodo del padre

    cout << "Horas de historia: "
         << horasHistoria
         << endl;                          // O(1), imprime un dato
}

#endif