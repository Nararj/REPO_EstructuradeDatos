/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 23/10/2026
 * Version : 2
 * Esta clase define objeto de tipo juegoAventuraGrafica que agrega el atributo
 * de decisiones.
 * Sobreescribe el metodo mostrarInfo() para mostrar la informacion especifica
 * de los juegos de aventura grafica.
 * Nombre, plataforma, calificacion, decisiones
 */

#ifndef JUEGOAVENTURAGRAFICA_H
#define JUEGOAVENTURAGRAFICA_H

#include "Videojuego.h"

//Declarar objeto JuegoAventuraGrafica que hereda de Videojuego
class JuegoAventuraGrafica : public Videojuego {

//Declarar las variables de instancia privadas
private:

    int decisiones;

//Declarar metodos públicos
public:

    JuegoAventuraGrafica();

    JuegoAventuraGrafica(string nom, string plat,
                         float cal, int dec);

    void mostrarInfo() override;
};

/**
 * Constructor por defecto.
 */
JuegoAventuraGrafica::JuegoAventuraGrafica()
    : Videojuego() {

    decisiones = 0;
}

/**
 * Constructor con parámetros.
 *
 * @param nom nombre del juego
 * @param plat plataforma
 * @param cal calificación
 * @param dec cantidad de decisiones
 */
JuegoAventuraGrafica::JuegoAventuraGrafica(
    string nom,
    string plat,
    float cal,
    int dec)
    : Videojuego(nom, plat, cal) {

    decisiones = dec;
}

/**
 * mostrarInfo muestra toda la información
 * del videojuego.
 */
void JuegoAventuraGrafica::mostrarInfo() {

    cout << "\nJUEGO DE AVENTURA GRAFICA "
         << endl;

    mostrarDatosBasicos();

    cout << "Cantidad de decisiones: "
         << decisiones
         << endl;
}

#endif