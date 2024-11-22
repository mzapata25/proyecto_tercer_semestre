# Proyecto: Clasificador de torneos de fútbol
Este proyecto busca ordenar y desplegar la clasificación de un torneo de fútbol por diferentes factores

## Descripción del avance 1
Despliega la tabla conteniendo la información sobre los 20 equipos de la liga española de fútbol (válido hasta el 19-09-24), con puntos (Pts), goles a favor (GF), goles en contra (GC) y diferencia de goles (DG). De momento solo ordena (ascendente y descendente) por puntuación, pero esto se arreglará en futuros avances.
## Descripción del avance 3
Despliega la tabla conteniendo la información sobre los 20 equipos de la liga española de fútbol (válido hasta el 11-11-24), con puntos (Pts), goles a favor (GF), goles en contra (GC) y diferencia de goles (DG). Se ha conseguido ordenar todos los parámetros (ascendente y descendente), reparando lo que falló el primer avance. En lugar del primer avance, donde se utilizó un bubble sort, se ha cambiado por el más eficiente merge sort, siendo este más estable, ya que tiene el mismo nivel de complejidad en todos los casos, sean el mejor, promedio o peor.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:
`g++ -std=c++11 main.cpp -o tercer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./tercer_avance` 

## Descripción de las entradas del avance de proyecto
Toda la información está contenida en el main, tan solo se utilizan el "#include <iostream>", "#include <vector>" y "#include <string>" que no requiere de ningún archivo adicional.

## Descripción de las salidas del avance de proyecto
Despliega los resultados de la liga española de fútbol según orden descendente de puntos (orden "por defecto") y demás órdenes (ascendentes y descendentes), o sea, por goles a favor, goles en contra y diferencia de goles.
## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se utiliza un merge sort para ordenar la tabla , tiene un O(n*log(n)) para todos los casos.
El mejor de todos los casos sería, por ejemplo, ordenar la tabla por orden descendente de puntuación, que es el orden por defecto de una liga de fútbol, ya que no se alteraría nada el primer orden dado.
El peor de todos los casos sería, por ejemplo, ordenar la tabla por orden ascendente de puntuación, siendo este exactamente el opuesto del orden por defecto.
Un caso promedio sería, pues, cualquiera que no sea estos dos, ya que el orden no se tiene que modificar en su totalidad, pero tampoco sería idéntico al original.
### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El merge sort ha sido escogido al ser el algoritmo de ordenación de los aprendidos en clase más estable, al tener una complejidad de O(n*log(n)) en todos los casos, así no se altera la capacidad de procesar y ordenar los datos del sistema en ningún caso, siendo este algoritmo la mejor opción para hacer aquí el ordenamiento.
