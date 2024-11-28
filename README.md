# Proyecto: Clasificador de torneos de fútbol
Este proyecto busca ordenar y desplegar la clasificación de un torneo de fútbol por diferentes factores

## Descripción del avance 1
Despliega la tabla conteniendo la información sobre los 20 equipos de la liga española de fútbol (válido hasta el 19-09-24), con puntos (Pts), goles a favor (GF), goles en contra (GC) y diferencia de goles (DG). De momento solo ordena (ascendente y descendente) por puntuación, pero esto se arreglará en futuros avances.
## Descripción del avance 3
Despliega la tabla conteniendo la información sobre los 20 equipos de la liga española de fútbol (válido hasta el 11-11-24), con puntos (Pts), goles a favor (GF), goles en contra (GC) y diferencia de goles (DG). Se ha conseguido ordenar todos los parámetros (ascendente y descendente), reparando lo que falló el primer avance. En lugar del primer avance, donde se utilizó un bubble sort, se ha cambiado por el más eficiente merge sort, siendo este más estable, ya que tiene el mismo nivel de complejidad en todos los casos, sean el mejor, promedio o peor.

## Descripción del avance final
Despliega la tabla conteniendo la información sobre los 20 equipos de la liga española de fútbol (válido hasta el 25-11-24), con posición (Pos.), nombre de equipo (Equipo), puntos (Pts), goles a favor (GF), goles en contra (GC) y diferencia de goles (DG). Además de ya tener el orden del primer avance, aquí ya se ha implementado el manejo de archivos, ya que los datos están almacenados en un archivo tipo .csv que está en este mismo repositorio. El archivo, de nombre "equipos.csv", contiene nombre, puntos, goles a favor y goles en contra de cada equipo, ya que la posición es calculada tras ordenar los puntos y la diferencia de goles es una simple resta entre los goles a favor menos los goles en contra. El programa lee el archivo y presenta los resultados al usuario, que puede ordenarlos tal y como ya estaba en el anterior avance, pero con la diferencia de que los datos los ha obtenido del .csv y no directamente del código, como en entregas pasadas. Además, presenta la opción al usuario de modificar los registros, pudiendo cambiar los nombres, puntos, goles a favor y goles en contra. Todos estos cambios quedando reflejados en el archivo .csv.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:
`g++ -std=c++11 main.cpp -o tercer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./tercer_avance` 

## Descripción de las entradas del avance de proyecto
Toda la información está contenida en el main, tan solo se utilizan el #include <iostream>, #include <iomanip>, #include <sstream>, #include <fstream>, #include <vector>, #include <string>, excepto las estadísticas de los equipos, que se encuentran en el archivo .csv de este repositorio. Además, permite al usuario modificar datos de equipos.

## Descripción de las salidas del avance de proyecto
Despliega los resultados de la liga española de fútbol según orden descendente de puntos (orden "por defecto") y demás órdenes (ascendentes y descendentes), o sea, por goles a favor, goles en contra y diferencia de goles. Además, guarda los datos modificados por el usuario en el .csv para uso futuro.
## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se utiliza un merge sort para ordenar la tabla , tiene un O(n*log(n)) para todos los casos.
El mejor de todos los casos sería, por ejemplo, ordenar la tabla por orden descendente de puntuación, que es el orden por defecto de una liga de fútbol, ya que no se alteraría nada el primer orden dado.
El peor de todos los casos sería, por ejemplo, ordenar la tabla por orden ascendente de puntuación, siendo este exactamente el opuesto del orden por defecto.
Un caso promedio sería, pues, cualquiera que no sea estos dos, ya que el orden no se tiene que modificar en su totalidad, pero tampoco sería idéntico al original.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
Se utiliza como estructura de datos el BST, que tiene como complejidad O(log(n)) para todos sus usos en el mejor de los casos y O(n) para todos sus usos en el peor de los casos. Los datos están originalmente en el archivo .csv, de allí se asignan a los objetos de clase Team, y después se insertan esos datos en un BST, para poder ordenar y manejarlos mejor. Además, se usó el tipo inOrder, para poder determinar el orden de los equipos en todas sus estadísticas. Además, si se modifica los puntos de un equipo, las posiciones se modificarán acorde a eso.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
El programa en su conjunto tiene O((n)), ya que se crea un archivo temporal para modificar los datos y  se tienen que copiar todos (y luego restaurar esos datos en el original .csv) aunque sea para modificar un solo dato.
Para el resto, la complejidad máxima es de O(log(n)) en el mejor de los casos, ya que después de la función de modificar datos, el BST tiene esa complejidad para eso. 
El programa NO pasará de O(n), ya que eso da como resultado el BST asumiendo el peor de los casos para ese tipo de estructura.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El merge sort ha sido escogido al ser el algoritmo de ordenación de los aprendidos en clase más estable, al tener una complejidad de O(n*log(n)) en todos los casos, así no se altera la capacidad de procesar y ordenar los datos del sistema en ningún caso, siendo este algoritmo la mejor opción para hacer aquí el ordenamiento.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Para esto se ha usado la estructura de array para contener 20 objetos de la clase Team que representan a cada equipo. Se ha elegido fundamentalmente hacer uso de arrays al tener una complejidad de acceso O(1) en el mejor, promedio y peor de los casos. Al ser una plantilla fija, no es necesario añadir ni remover equipos. Cada equipo es un objeto con sus diferentes propiedades, como la posición, el nombre, los puntos, los goles a favor y en contra y la diferencia de goles. Otras estructuras no tiene esa facilidad de acceso, por lo tanto, no son tan aptas para este problema en específico.


### SICT0303B: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
El programa despliega la tabla de posiciones con el orden predeterminado, o sea, después de su ordenamiento a través del inOrder del BST, se verán en orden descendente (de mayor a menor) de puntos, según la información en el archivo .csv. Además, permite ordenar según diferentes criterios, no solo la puntuación.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
El programa viene dotado de un archivo .csv anexo. Este archivo ya contiene los datos de los equipos, y con la función de asignaDatos, se cargan estos datos (primeramente) a los objetos de clase Team que forman parte del array arregloEquipos. Luego, para poder desplegarlos, también se cargan en un BST, que, a su vez, mediante inOrder, se encarga de ordenarlos.

#### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta.
El programa permite al usuario modificar los datos de los equipos (tanto el nombre como las diferentes estadísticas), cambios que se quedan guardados en el archivo .csv, además se reflejarán cada vez que se utilice el BST para volver a desplegar los datos al usuario. Estos cambios perduran entre diferentes usos del programa, permitiendo que se use para modificarlo a lo largo del tiempo, sin tener que volver a comenzar desde cero.
