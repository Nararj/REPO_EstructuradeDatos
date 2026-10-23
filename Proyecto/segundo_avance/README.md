# Proyecto: Biblioteca Videojuegos
- La idea de este proyecto es permitir al usuario registrar, organizar y visualizar videojuegos según su género donde el sistema incluye juegos de acción, RPG y aventura gráfica, cada uno con características específicas.

## Descripción del avance 1
- Este es un proyecto anterior hecho en la clase de "Programación orientada a objetos" en segundo semestre, por lo que las clases bilbioteca, juegoAccion, juegoAventuraGrafica, juegoRPG, usuario, videojuego y el main ya estaban hechas.
- En este avance se agrego una clase llamada "ordenar" que accede a el vector de juegos para ordenar estos dependiendo de su calificación de manera ascendente y al momento de que el usuario pida mostrar los juegos estos aparezcan ya ordenados, esto mandando a llamar a esta funcion en biblioteca la momento de mostrar los juegos.
- Se agregó tambien la clase "sistema" que paso el funcionamiento del main a esta clase para que el main quedara más limpio.

## Descripción del avance 2
- Se agrego un archivo .txt que guardara el vector de videojuegos cada vez que se agregue un juego nuevo, ya que el proyecto ya contaba con un vetor que guardara los videojuegos agregados, pero los borraba al temrinar la eecucion del programa.

### Cambios sobre el primer avance
1. Se cambio el metodo de ordenamiento a un merge sort, ya que un bubble sort es ineficiente al momento de guardar muchos datos. Mientras el bubble sort tiene una complejidad temporal de O(n^2) en el peor de los casos y O(n) en los mejores, el merge sort en cualquier caso es O(n log n) sienda mas eficiente.
2. Se agrego un archivo .txt para guardar el vector de videojuegos que se vayan agregando, tambien se actualizo bioblioteca.h y sistema.h para que leyeran directamente de este archivo asi como al momento de agregar un juegp se guarde directamente en este (todavia no sirve para favoritos), esto porque el programa no hacia realmente algo ya que despues de terminarlo se borraban todos los juegos.
3. Se agregó un metodo para que al momento de buscar juegos se convierta en minusculas y asi evitar que no se encuentren juegos por errores de ortografía, antes tenias que escribir el nombre exactamente como lo guardaste o no lo encontraba.

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
- Se recibe un archivo llamado juegos.txt que ya tiene guardados juegos en forma de vector donde cada línea representa un videojuego, con los campos separados por comas: tipo, nombre, plataforma, calkificacion, caracteristica
	- Tipo:   (RPG, ACCION, AVENTURA)
    - Nombre:   (string)
    - Plataforma:   (string)
    - Calificación:   (float)
    - Caracteristica que un tipo de juego (ej. decisiones totales):  (int)

- Para guardar un juego nuevo el programa pide los atributos de la siguiente forma para despues guardarlos en el txt
    - Nombre: Life is Strange
    - Plataforma: Xbox
    - Calificación: 10
    - Cantidad de decisiones: 230

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
- El desarollo se encuentra en el archivo "biblioteca" donde se hizo el analisis de complejidad de la estructura que son vectores al igual que en usuario para acceder a los favoritos, este se demuestra al hacer el analisis dentro del archivo aunque sigo considerando que se me dificulta hacerlo algunas veces.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
- En el archivo "ordenar" se usa un merge sort para acomodar los videojuegos agregados, este metodo es el adecuado ya que se puede llegar a manejar una gran cantidad de datos y es temrinos de ocmplejidad de tiempo su mejor, promedio y peor caso es un O(n log (n)), siendo este el más eficiente.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
- En el archivo "biblioteca" en los atributos privados esta la estructura principal y en videojeugo las clases hijas hacen que el vector sea de punteros a la clase padre. Este metodo se uso porque el programa necesita acceso directo por posición, y el merge sort lo usa constantemente para comparar e intercambiar elementos, además, agregar un juego al final con push_back es O(1).
- Tambien se utiliza otro vector en "usuario" para los favoritos aunque estos todavia no se guarden en el archivo o uno aparte.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
- En los archivos "biblioteca" y "usuario" se puede ver que el programa tiene mecanismos para consultar la información guardada en el vector donde mostrarJuegos recorre el vector ya ordenado de menor a mayor calificación por el ordenamiento y buscarJuego hace una búsqueda secuencial por nombre y avisa si no encontró el juego

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
- El método cargarDesdeArchivo de Biblioteca.h lee juegos.txt línea por línea y crea los objetos en el vector al iniciar el programa, este revisa que el archivo exista con is_open(), separa cada línea por comas con stringstream, convierte los números con stof y stoi, ignora líneas vacías, y usa try/catch para que una línea mal escrita no cierre el programa.
