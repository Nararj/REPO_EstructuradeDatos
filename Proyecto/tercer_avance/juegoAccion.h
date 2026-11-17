/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 11/11/2026
 * Version : 3
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

    void mostrarInfo() override;      // O(1), muestra toda la informacion del juego de accion
};

/**
 * Constructor por defecto.
 */
JuegoAccion::JuegoAccion() : Videojuego() {

    violencia = 0;                    // O(1), inicializa violencia
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
    : Videojuego(nom, plat, cal) {  // O(1), llama al constructor de la clase padre

    violencia = viol;                 
}

/**
 * mostrarInfo muestra toda la información
 * del videojuego.
 */
void JuegoAccion::mostrarInfo() {

    cout << "\nJUEGO DE ACCION "
         << endl;                  // O(1), mensaje

    mostrarDatosBasicos();         // O(1), llama al metodo del padre

    cout << "Nivel de violencia: "
         << violencia
         << endl;                  // O(1), imprime un dato
}

#endif