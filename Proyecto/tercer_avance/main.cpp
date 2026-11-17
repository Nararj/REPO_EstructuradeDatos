/*
 *
 * Proyecto Biblioteca Videojuegos
 * Narayana Rajaram López
 * A01714315
 * 11/11/2026
 * Version : 3
 * Proyecto para la clase Programación Orientado a Objetos. Es un programa 
 * que captura diferentes tipos de juegos con sus propios atributos y los
 * almacena en una biblioteca para poder ver su calificación, plataforma y
 * otros datos, permitiendo también agregar juegos a favoritos. 
 * La complejidad total de main es la de Sistema: O(constructor) + O(ejecutar).
 * main por si solo es O(1): crea un objeto y llama a dos metodos.
 */
int main() {

    Sistema sistema;                                  // O(n log n + f) prom., carga los archivos

    sistema.ejecutar();                               // O(k * (n + f log f)), menu

    return 0;                                         // O(1), al cerrar se destruyen las estructuras: O(n + f)
}