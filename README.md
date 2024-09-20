# Proyecto: Clasificador de torneos de fútbol
Este proyecto busca ordenar y desplegar la clasificación de un torneo de fútbol por diferentes factores

## Descripción del avance 1
Despliega la tabla conteniendo la información sobre los 20 equipos de la liga española de fútbol (válido hasta el 19-09-24), con puntos (Pts), goles a favor (GF), goles en contra (GC) y diferencia de goles (DG). De momento solo ordena (ascendente y descendente) por puntuación, pero esto se arreglará en futuros avances.

## Instrucciones para compilar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp -o primer_avance` 

## Instrucciones para ejecutar el avance de proyecto
Ejecuta el siguiente comando en la terminal:

`./primer_avance` 

## Descripción de las entradas del avance de proyecto
Toda la información está contenida en el main, tan solo se utiliza el "#include <iostream>" que no requiere de ningún archivo adicional.

## Descripción de las salidas del avance de proyecto
Despliega los resultados de la liga española de fútbol según orden descendente de puntos (orden "por defecto") y orden ascendente de puntos.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
Se utiliza un bubble sort para ordenar la tabla por orden ascendente de puntos, como el orden por defecto es completamente inverso, tiene un O(n^2), siendo el peor caso posible.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Como he decidido trabajar con arreglos (y arreglos de arreglos) la implementación en código del merge sort es más compleja, además de que el bubble sort es menos complejo para corroborar que la tabla está ya ordenada, algo útil para evitar errores, por lo tanto, he considerado que, para esto en particular, el bubble sort me convenía más que el merge sort.
