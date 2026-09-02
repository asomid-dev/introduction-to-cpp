# Matrices

## 1. ¿Qué es una Matriz en programación y su Sintaxis?

Al igual que en la geometría o el álgebra lineal, una matriz en programación es un conjunto ordenado de vectores (filas), que se pueden imaginar como una tabla de valores. En C++, podemos definir una matriz de enteros como `std::vector<std::vector<int>> Matriz;`. Esta estructura es lo que se llama un “vector de vectores” (Matriz), que permite gestionar una colección de filas y columnas dinámicamente.

Podemos recorrer o iterar una matriz de la misma manera que hacemos con los bucles en el tema de **Vectores**.

**Ejemplo**: 
Supongamos que tenemos la siguiente matriz de enteros (2 filas x 3 columnas):
[ 1  2  3 ]
[ 4  5  6 ]

 **¿Cómo acceder a un elemento concreto?**

```cpp
// Para acceder al elemento de la fila 1 y la columna 2 (recuerda: ¡empezamos a contar por 0!), hacemos:
int valor = matriz[1][2]; // valor = 6

// En general, para acceder al elemento de la fila i, columna j:
int valor = matriz[i][j];

// También puedes modificar este valor igual que con los vectores:
matriz[0][1] = 99; // Ahora la matriz es: [ 1 99 3 ] / [ 4 5 6 ]
```

---

## 2. Inicializar una matriz

Tal y como hemos visto con los vectores, una matriz puede ser de cualquier tipo de dato. Desde un `int`, hasta un `Struct`. Para trabajar con matrices, es importante no olvidarnos de añadir la librería vector utilizando `#include <vector>`.

Vamos a crear algunas matrices básicas:

??? example "InicializarMatrices.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        // Matriz 3x4 de enteros, inicializada a 0
        vector<vector<int>> matriz_enteros(3, vector<int>(4, 0));
        // [ 0  0  0  0 ]
        // [ 0  0  0  0 ]
        // [ 0  0  0  0 ]

        // Matriz 2x2 de doubles, cada elemento inicializado a 3.14
        vector<vector<double>> matriz_dobles(2, vector<double>(2, 3.14));
        // [ 3.14  3.14 ]
        // [ 3.14  3.14 ]

        // Matriz "vacía" (sin tamaño fijo inicial)
        vector<vector<string>> matriz_strings;
        // [ ]
        
        // Asignación manual de una matriz de caracteres
        vector<vector<char>> matriz_caracteres = {
            {'A', 'B', 'C'},
            {'D', 'E', 'F'}
        };
    }
    ```

---

## 3. Iterar sobre una matriz

Una matriz se puede ver como un "vector de vectores". Por lo tanto, para iterar sobre cada uno de sus elementos, necesitamos dos bucles: uno para recorrer las filas y otro para recorrer las columnas de cada fila. Esto se llama hacer una **iteración doble** (bucle anidado o *nested loop*).

La sintaxis básica sería esta:

```cpp
// Supongamos que tenemos una matriz de dimensiones nfilas x ncolumnas:
vector<vector<int>> matriz(nfilas, vector<int>(ncolumnas, 0));

// Para recorrer todos los elementos y hacer alguna acción (como imprimirlos):
for (int i = 0; i < nfilas; i++) { // Iteramos sobre las filas
    for (int j = 0; j < ncolumnas; j++) { // Por cada fila, iteramos sobre cada columna
        cout << matriz[i][j] << " "; // Accedemos al ítem de la fila i, columna j
    }
    cout << endl; // Salto de línea al terminar cada fila
}
```

> **NOTA:** Recuerda que el índice `i` recorre las filas y el índice `j` recorre las columnas dentro de cada fila.

---

## 4. Ejemplos

### Ejemplo 1: Imprimir una matriz de enteros

??? example "1. ImprimirMatriz.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<int>> matriz = {
            {1, 2, 3},
            {4, 5, 6}
        };

        int filas = matriz.size();
        int columnas = matriz[0].size();

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
        // Salida:
        // 1 2 3
        // 4 5 6
    }
    ```

### Ejemplo 2: Sumar todos los elementos de una matriz de doubles

??? example "2. SumarMatriz.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<double>> matriz = {
            {1.1, 2.2},
            {3.3, 4.4}
        };

        double suma = 0;
        for (int i = 0; i < matriz.size(); i++) {
            for (int j = 0; j < matriz[i].size(); j++) {
                suma += matriz[i][j];
            }
        }
        cout << "La suma total es: " << suma << endl;
        // Salida: La suma total es: 11
    }
    ```

### Ejemplo 3: Cambiar un elemento de una matriz de caracteres

??? example "3. CambiarElemento.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<char>> letras = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'}
        };

        letras[0][1] = 'z'; // Cambiamos la 'b' por una 'z'

        for (int i = 0; i < letras.size(); i++) {
            for (int j = 0; j < letras[i].size(); j++) {
                cout << letras[i][j] << " ";
            }
            cout << endl;
        }
        // Salida:
        // a z c
        // d e f
    }
    ```

### Ejemplo 4: Leer una matriz de enteros por teclado

??? example "4. LeerMatriz.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        int filas, columnas;
        cin >> filas >> columnas;
        vector<vector<int>> matriz(filas, vector<int>(columnas));

        // Leemos los valores por filas y columnas
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cin >> matriz[i][j];
            }
        }

        // Mostramos la matriz
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << matriz[i][j] << " ";
            }
            cout << endl;
        }
    }
    ```

---

## 5. A destacar
### 1. Valores por referencia
Al igual que en el tema de vectores, es importante recordar que si queremos pasar una matriz como parámetro de una función, usamos el operador de referencia `&`. Para más información, repasa el tema de vectores.

### 2. Typedef Matriz
A veces, los profesores de PRO1 definen un tipo de datos llamado 'Matriu' (o 'Matriz') con la siguiente definición:
```cpp
typedef vector< vector<int> > Matriz;
```
Esto solamente indica que la palabra 'Matriz' es equivalente a escribir `vector<vector<int>>`, por lo tanto, `vector<vector<int>> nums;` y `Matriz nums;` es equivalente.

---

## 6. Ejercicio Final

Aquí tienes un ejercicio de nivel avanzado que te pedirá combinar todo lo que sabes sobre matrices, bucles anidados y búsqueda de máximos para encontrar la mejor submatriz.

??? example "final.cpp"

    ```cpp
    /*
    * Ejercicio Final
    * Ejemplo: Encuentra la Submatriz Cuadrada de Suma Máxima
    * Hecho por: Uri
    */

    /*
    Este programa lee una matriz de enteros positivos de f filas y c columnas (primero el usuario introduce f y c,
    después los valores de la matriz), y luego lee un entero positivo k (1 <= k <= min(f,c)).
    El programa busca dentro de la matriz la submatriz cuadrada de tamaño k x k cuya suma de elementos
    sea máxima. Imprime:
    - El valor de esta suma máxima.
    - La submatriz k x k correspondiente (en la misma disposición que la original), correspondiente a la primera (de arriba a abajo, de izquierda a derecha) con suma máxima que encuentre, en caso de empate.

    Ejemplo:
    Input:
    4 5
    1 2 0 3 4
    0 6 3 4 1
    2 4 5 2 3
    1 0 1 1 1
    3

    Output:
    Suma maxima: 29
    Submatriz:
    6 3 4
    4 5 2
    0 1 1
    */

    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        int f, c;
        cin >> f >> c; // Leemos filas y columnas
        // Leemos la matriz de enteros
        vector<vector<int>> matriz(f, vector<int>(c));
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matriz[i][j];
        
        int k;
        cin >> k; // Leemos el tamaño de la submatriz cuadrada

        // Variables para guardar la suma máxima y la posición de la mejor submatriz
        int suma_max = 0; // La suma máxima encontrada hasta ahora (mínimo 0)
        int mejor_i = 0, mejor_j = 0; // Coordenadas del inicio de la mejor submatriz

        // Recorremos todas las submatrices posibles de tamaño k x k
        for (int i = 0; i <= f - k; ++i) {
            for (int j = 0; j <= c - k; ++j) {
                int suma = 0; // Suma de los elementos de la submatriz actual
                // Calculamos la suma de esta submatriz
                for (int a = 0; a < k; ++a)
                    for (int b = 0; b < k; ++b)
                        suma += matriz[i + a][j + b];
                // Si la suma de esta submatriz es mejor, la guardamos
                if (suma > suma_max) {
                    suma_max = suma;
                    mejor_i = i;
                    mejor_j = j;
                }
            }
        }

        // Imprimimos el resultado
        cout << "Suma maxima: " << suma_max << endl;
        cout << "Submatriz:" << endl;
        // Mostramos la submatriz de suma máxima
        for (int a = 0; a < k; ++a) {
            for (int b = 0; b < k; ++b)
                cout << matriz[mejor_i + a][mejor_j + b] << " ";
            cout << endl;
        }
    }
    ```
