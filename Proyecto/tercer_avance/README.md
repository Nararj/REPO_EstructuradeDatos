# Proyecto: Biblioteca Videojuegos
- La idea de este proyecto es permitir al usuario registrar, organizar y visualizar videojuegos según su género donde el sistema incluye juegos de acción, RPG y aventura gráfica, cada uno con características específicas.

## Descripción del avance 1
- Este es un proyecto anterior hecho en la clase de "Programación orientada a objetos" en segundo semestre, por lo que las clases bilbioteca, juegoAccion, juegoAventuraGrafica, juegoRPG, usuario, videojuego y el main ya estaban hechas.
- En este avance se agrego una clase llamada "ordenar" que accede a el vector de juegos para ordenar estos dependiendo de su calificación de manera ascendente y al momento de que el usuario pida mostrar los juegos estos aparezcan ya ordenados, esto mandando a llamar a esta funcion en biblioteca la momento de mostrar los juegos.
- Se agregó tambien la clase "sistema" que paso el funcionamiento del main a esta clase para que el main quedara más limpio.

## Descripción del avance 2
- Se agrego un archivo .txt que guardara el vector de videojuegos cada vez que se agregue un juego nuevo, ya que el proyecto ya contaba con un vector que guardara los videojuegos agregados, pero los borraba al temrinar la eecucion del programa.

### Cambios sobre el primer avance
1. Se cambio el metodo de ordenamiento a un merge sort, ya que un bubble sort es ineficiente al momento de guardar muchos datos. Mientras el bubble sort tiene una complejidad temporal de O(n^2) en el peor de los casos y O(n) en los mejores, el merge sort en cualquier caso es O(n log n) sienda mas eficiente.
2. Se agrego un archivo .txt para guardar el vector de videojuegos que se vayan agregando, tambien se actualizo bioblioteca.h y sistema.h para que leyeran directamente de este archivo asi como al momento de agregar un juegp se guarde directamente en este (todavia no sirve para favoritos), esto porque el programa no hacia realmente algo ya que despues de terminarlo se borraban todos los juegos.
3. Se agregó un metodo para que al momento de buscar juegos se convierta en minusculas y asi evitar que no se encuentren juegos por errores de ortografía, antes tenias que escribir el nombre exactamente como lo guardaste o no lo encontraba.

## Descripción del avance 3
- En este avance se corrigió la estructura de datos de los juegos, pasando de un vector a un árbol binario de búsqueda ordenado por calificación. Además, los favoritos ahora tienen su propio archivo de texto y se muestran ordenados alfabéticamente con un quick sort, que sustituye al merge sort.

### Cambios sobre el segundo avance
1. Los juegos pasaron de un vector a un árbol binario de búsqueda, ordenado por calificación.
2 .Se eliminó la clase OrdenadorJuegos (merge sort) para los juegos, porque el árbol ya los entrega ordenados.
3. Los favoritos se quedaron como un vector de nombres y se muestran ordenados alfabéticamente con quick sort en OrdenadorFavoritos.h. Los favoritos son una lista corta de textos que solo se agrega y se muestra, así que un vector es suficiente.
4. Los favoritos ahora se guardan en un archivo "favoritos.txt", antes se perdían al cerrar el programa y ahora se cargan al iniciar y cada favorito nuevo se escribe al final del archivo.
5. Al capturar nombre y plataforma, las comas se reemplazan por espacios para evitar que el juego se pierda al reiniciar el programa.
6. La búsqueda ignora mayúsculas y minúsculas y ahora vive en el árbol, que es quien recorre los juegos.
7. Se agregó el análisis de complejidad en los comentarios de todos los archivos.

## Instrucciones para compilar el avance de proyecto
- Abrir todos los archivos .cpp en un proyecto de C++ (..., main.cpp)
- Abrir una terminal o consola y navegar a la carpeta donde están los archivos
- Compilar todos los archivos juntos usando un compilador de C++ (en Windows y Linux)
	- g++ main.cpp  -o main.exe
- Compilar todos los archivos juntos usando un compilador de C++ (en IOs)
	- g++ main.cpp  -o main.o

## Instrucciones para ejecutar el avance de proyecto
- Ejecutar el programa resultante (en Windows y Linux)
	- /.main.exe
- Ejecutar el programa resultante (en IOs)
	- ./main.o

## Descripción de las entradas del avance de proyecto
- Se reciben dos archivos de texto que se cargan automáticamente al iniciar el programa:
☆ juegos.txt
- Cada línea representa un videojuego, con los campos separados por comas: tipo, nombre, plataforma, calificación, característica 	- Tipo:   (RPG, ACCION, AVENTURA)
    - Nombre:   (string)
    - Plataforma:   (string)
    - Calificación:   (float)
    - Caracteristica que un tipo de juego (ej. decisiones totales):  (int)

- Para guardar un juego nuevo el programa pide los atributos de la siguiente forma para despues guardarlos en el txt
    - Nombre: Life is Strange
    - Plataforma: Xbox
    - Calificación: 10
    - Cantidad de decisiones: 230

- El archivo puede estar en cualquier orden, porque el árbol coloca cada juego en su lugar al cargarlo, las líneas vacías se ignoran y las líneas con formato inválido se omiten con un aviso.

☆ favoritos.txt
- Cada línea es el nombre de un juego favorito:
-- The Witcher 3
-- Doom

- Si este archivo no existe, el programa inicia sin favoritos y lo crea al guardar el primero.

## Descripción de las salidas del avance de proyecto
- Al ejecutar el programa se despliega un menú principal con 8 opciones
    - Las opciones 1 a 3 permiten registrar un nuevo juego de diferente tipo
    - La opción 4 muestra los juegos registrados, ordenados de forma ascendente 
    - La opción 5 busca un juego por nombre exacto y muestra su información, si no exite manda el mensaje 'Juego no encontrado' 
    - Las opciones 6 y 7 permiten agregar y mostrar juegos favoritos (solo se guarda el nombre)
    - La opción 8 termina el programa

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
- El desarrollo se puede encontrar en el archivo "ordenar" donde se hizo el analisis de la complejidad del metodo de ordenamiento, se demuestra al hacer este analisis en el este archivo aunque considero que me falta estudiarlo más ya que hay algunas que me costo saber porque era asi e investigar ya que habia puesto la complejidad incorrecta al primer intento.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
- El proyecto usa dos estructuras, el árbol binario de búsqueda de los juegos y el vector de favoritos, cada desarrollo se puede observar en su respectivo archivo, el arbol binario en el archivo arboljuegos.h y el vector de favoritos en el archivo usuario.h

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
- Cada archivo tiene su analisis de complejidad, por lo que se puede observar en los comentarios de todos los archivos y la complejidad final del programa es O(n log n + f log f) en tiempo promedio y O(n + f) en espacio

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
- En el archivo "ordenar" se usa un quick sort para acomodar alfabéticamente los favoritos, esto porque los favoritos son un vector de textos que puede crecer, y el quick sort ordena sobre el mismo vector (espacio O(log n), contra O(n) de un merge sort), con tiempo O(n log n) en el mejor y promedio caso y O(n^2) en el peor caso poco común.
- Para los juegos ya no hace falta un algoritmo de ordenamiento aparte, porque el árbol binario de búsqueda los mantiene ordenados por calificación desde que se insertan.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
- Para los juegos elegí un árbol binario de búsqueda ordenado por calificación, porque la necesidad principal es ver los juegos de menor a mayor calificación: el árbol los deja ordenados al insertarlos (O(log n) en promedio) y mostrarlos es un recorrido inorden de O(n), sin reordenar cada vez como con el vector, esto se puede opbservar en arboljeugos.h, biblioteca.h y usuario.h
- Para los favoritos elegí un vector de textos, porque solo se guardan nombres, se agregan al final en O(1) y se muestran ordenados, aparte de que normalmente una persona no tiene muchos favoritos agregados,

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
- Se puede consultar información de ambas estructuras: mostrarJuegos recorre el arbol que esta ordenado por calificacion y buscarJuego busca el nombre en el arból, asi como mostrarFavoritos muestra los favoritos que estan dentro de un vector ordenado, esto se puede ver en arboljuegos.h, biblioteca.h y usuario.h

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
- En biblioteca.h cargarDesdeArchivo lee juegos.txt linea por linea y separa los campos por comas con stringstream, convierte la calificación y la característica con stof(String to Float) y stoi(String to Integer), y según el tipo crea el objeto de la clase hija correcta y lo inserta en el árbol
- En usuario.h cargarFavoritosDesdeArchivo lee favoritos.txt y agrega cada nombre al vector.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
- Cada dato nuevo que entra a una estructura también se escribe en su archivo, así que se conserva entre ejecuciones. guardarEnArchivo (en Biblioteca.h) agrega al final de juegos.txt la línea del juego nuevo con el formato que luego se puede cargar, y guardarFavoritoEnArchivo (en Usuario.h) hace lo mismo con favoritos.txt