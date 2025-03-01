# ProyectoEDAI_ReservaDeVuelos

## Manejo de archivos. (Fabián M C15386)
    Este header pretende trabajar con un archivo de texto "flights.txt" para utilizarlo a modo de base de datos.
Esta funcionalidad permitiria al usuario guardar una sesión, imprimir el grafo dentro del archivo para su
próxima recuperación, y cargar una sesión, procesar este grafo guardado previamente para almacenar los valores
impresos dentro del grafo en el que se esta trabajando actualmente. 

    Los dos metodos existentes son guardarGrafo que requiere dos parámetros, un grafo y el nombre del archivo que
se utilizará como base de datos. A partir de esto imprime los valores deseados de cada ciudad a partir del método
getter del grafo. Este se imprime en el formato:
- Nombre X Y Conexion(x) Peso(X) (Asi sucesivamente para cada conexión)

    El siguiente método recibe un grafo y el nombre del archivo nuevamente. Este método se encarga de leer todas 
las líneas del archivo hasta que una de estas este vacia. A partir de esto, guarda en un vector temporal todos 
los datos necesarios para la reconstrucción del grafo y los guarda en un vector de 'tuples' (un formato de datos 
que guarda una colección de datos en un solo lugar). Al obtener todos los datos del archivo, comienza a desempaque-
tar los datos que existen dentro del tuple para utilizar los métodos existentes del grafo para reconstruir el archi-
vo. 

    Dentro de los recursos utilizados son los siguientes:
- [Tuples_Yt](https://www.youtube.com/watch?v=T9-agjKW4PQ&ab_channel=TechWithTim)
- [Files_YT](https://www.youtube.com/watch?=Cz4fl-TUjVkt=225sab_channel=CalebCurry)
- [StackOverflow](https:stackoverflowcomquestions66552813how-to-read-file-into-vector-of-tuple)
- [ChatGPT](https://chatgpt.com/share/67c27693-a118-800d-b830-fb1e3dd6ca29)