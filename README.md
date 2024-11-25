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
Toda la información está contenida en el main, tan solo se utilizan el "#include <iostream>", "#include <vector>" y "#include <string>", excepto las estadísticas de los equipos, que se encuentran en el archivo .csv de este repositorio. Además, permite al usuario modificar datos de equipos.

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
Se utilizan los arrays como estructura de datos, además de vectores para el merge sort. La implementación del merge sort vista en clase usaba vectores para poder ordenar los diferentes números, aquí se usó para ordenar las diferentes estadísticas. Similar al array, el vector tiene una complejidad de O(1) en el acceso, hecho que se utilizó para ir cambiando las diferentes variables hasta que estuvieran ordenadas. Para almacenar la lista de los objetos que representaban a los equipos (almacenados así ya que cada uno tenía varias características que se repetían en todos los equipos, hecho que hizo que fuera óptimo representar a cada equipo como un objeto de clase Team) se utilizó un array de objetos tipos Team. Para acceder a cada uno, hay una complejidad de O(1), ya que si se quiere cambiar un dato de un equipo basta con acceder a él y modificar el dato que se busca.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El merge sort ha sido escogido al ser el algoritmo de ordenación de los aprendidos en clase más estable, al tener una complejidad de O(n*log(n)) en todos los casos, así no se altera la capacidad de procesar y ordenar los datos del sistema en ningún caso, siendo este algoritmo la mejor opción para hacer aquí el ordenamiento.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Para esto se ha usado la estructura de array para contener 20 objetos de la clase Team que representan a cada equipo. Se ha elegido fundamentalmente hacer uso de arrays al tener una complejidad de acceso O(1) en el mejor, promedio y peor de los casos. Al ser una plantilla fija, no es necesario añadir ni remover equipos. Cada equipo es un objeto con sus diferentes propiedades, como la posición, el nombre, los puntos, los goles a favor y en contra y la diferencia de goles. Otras estructuras no tiene esa facilidad de acceso, por lo tanto, no son tan aptas para este problema en específico.
