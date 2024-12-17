# Repositorio del trabajo hecho en el ramo Estructuras de datos

## Requerimientos
- "MinGW" para compilar archivos C++
- "Make" para ejecutar el makefile (opcional)

## Laboratorios
Cada laboratorio está contenido por sí mismo y puede ser ejecutado por separado.

## Proyecto-1 de estructura de datos de texto predictivo
En los motores de búsqueda, como Google, la función de predicción de palabras es una herramienta clave para mejorar la experiencia del usuario, permitiendo completar automáticamente las consultas mientras se escriben. Este proceso, conocido como autocompletado o predicción de búsqueda, está diseñado para ahorrar tiempo, reducir errores de escritura y ofrecer sugerencias relevantes basadas en el contexto, preferencias del usuario e información histórica.

Puede revisar el documento donde se explica en detalle el funcionamiento del algoritmo en los [docs](proyecto-1/docs/) del proyecto 1.

### Ejemplo de ejecución
```console
<nombrearchivo> dic.txt quer.txt resp.txt 10
```

`dic.txt`: el nombre del archivo que se usará como diccionario base para buscar palabras.
`quer.txt`: Aquí se ingresan las palabras que se estarían "escribiendo en el buscador".
`resp.txt`: Archivo generado por el ejecutable (puede tener el nombre que quieran, pero debe ser un .txt), el cual contendrá
las palabras que se predecirían en base a las palabras ingresadas en el `quer.txt`.
`<numero>`: Un número entero que indica la cantidad de palabras parecidas que se quieren encontrar.

## Proyecto-2 de estructura de datos de compresión de largas cadenas de caracteres haciendo uso del algoritmo Re-Pair

El algoritmo de compresión Re-Pair (abreviatura de Recursive Pairing) es un método de compresión de datos sin pérdida diseñado para trabajar con secuencias de símbolos, como texto o datos binarios. Su objetivo principal es lograr una buena tasa de compresión utilizando un enfoque basado en la detección y sustitución de patrones repetidos en los datos.

Puede revisar el documento donde se explica en detalle el funcionamiento del algoritmo en los [docs](proyecto-2/docs/) del proyecto 2.

Para correr el ejecutable, indicar el nombre del ejecutable seguido del largo de la cadena de caracteres a comprimir.
### Ejemplo de ejecución
```console
<nombrearchivo> 1000000
```