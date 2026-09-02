# Algoritmos Fundamentales (Búsqueda y Ordenación)

## 1. ¿Qué son los Algoritmos Fundamentales?

Hasta ahora hemos aprendido las piezas básicas de C++ (bucles, funciones, vectores, structs...). Ahora que ya sabemos construir herramientas, toca aprender **cómo utilizarlas para resolver los problemas más clásicos de la informática**: buscar información y ordenarla.

Para entender la importancia de esto, imagínate que tienes un diccionario con 10.000 páginas completamente desordenadas y tienes que buscar la palabra "Recursividad". Si vas mirando página por página (búsqueda lineal), puedes tardar horas. En cambio, si el diccionario está ordenado alfabéticamente, puedes abrirlo por la mitad e ir descartando mitades rápidamente hasta encontrarla en segundos.

**¿Por qué estudiamos estos algoritmos en PRO1?**
1. **Eficiencia:** Un mal algoritmo puede hacer que tu programa tarde horas en resolver un problema que un buen algoritmo resuelve en milisegundos (y el Jutge de la FIB te dará un *Time Limit Exceeded*).
2. **Fundamentos:** Entender cómo ordenar (Sort) y cómo buscar (Search) es la base para comprender estructuras de datos mucho más complejas en el futuro (PRO2 y EDA).

---

## 2. La magia de C++: `std::sort`

Antes de empezar a escribir código para ordenar vectores manualmente, debes saber un secreto: C++ ya tiene una función increíblemente rápida y optimizada que lo hace por ti. Se llama `std::sort` y forma parte de la librería `<algorithm>`.

En la vida real (y en problemas donde no te obliguen a hacerlo a mano), siempre utilizarás esta función para ordenar vectores, ya que está programada con un algoritmo híbrido muy avanzado (Introsort) que es mucho más rápido que los que veremos aquí.

### ¿Cómo se utiliza con tipos básicos?
Si tienes un vector de enteros o de strings, C++ ya sabe cómo compararlos (sabe que 2 es menor que 5, o que la 'A' va antes que la 'B'):
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // OBLIGATORIO para usar el sort()
using namespace std;

int main() {
    vector<int> v = {5, 2, 9, 1, 5, 6};

    // Ordenamos el vector de menor a mayor (por defecto)
    // v.begin() indica el inicio, y v.end() el final del vector.
    sort(v.begin(), v.end()); 

    // Ahora 'v' es: {1, 2, 5, 5, 6, 9}
}
```

### ¿Cómo ordenar un `Struct` personalizado? (La función `cond`)
¿Qué pasa si tenemos un vector de aventureros (un `struct`) y queremos ordenarlos? C++ no sabe si quieres ordenarlos por nivel, por nombre o por edad. 
Le tenemos que dar nosotros las instrucciones creando una función booleana (normalmente llamada `cond` o `cmp`) que le diga **quién debe ir antes**. Esta función recibe dos elementos por referencia constante y devuelve `true` si el primer elemento debe ir antes que el segundo.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Adventurer {
    string name;
    int level;
};

// pre: cierto
// post: devuelve true si el aventurero 'a' debe ir ANTES que 'b' en el vector ordenado
bool cond(const Adventurer& a, const Adventurer& b) {
    // 1r Criterio: Queremos ordenar por nivel de MAYOR a MENOR
    if (a.level != b.level) {
        return a.level > b.level;
    }
    // 2n Criterio (Caso de empate): Si tienen el mismo nivel, ordenamos por nombre alfabéticamente
    return a.name < b.name;
}

int main() {
    vector<Adventurer> party = {
        {"Megumin", 45},
        {"Frieren", 100},
        {"Retzel", 50},
        {"Sigrid", 45} // Empata en nivel con Megumin
    };

    // ¡Le pasamos nuestra función 'cond' como tercer parámetro!
    sort(party.begin(), party.end(), cond);

    /* El orden final será:
       1. Frieren (100)
       2. Retzel (50)
       3. Megumin (45) -> Va antes que Sigrid porque la 'M' va antes que la 'S'
       4. Sigrid (45)
    */
}
```

*Y entonces... ¿por qué debemos aprender a hacer los algoritmos a mano?* Porque en PRO1 te evaluarán para ver si **entiendes la lógica interna**. Así que ¡nos arremangamos y vamos a ver cómo funcionan por dentro!

---

## 3. Tipos de Algoritmos (Lo que veremos)

La **Búsqueda Dicotómica (Binary Search)** sirve para buscar si hay un elemento dentro de un vector **previamente ordenado**. Este algoritmo es muy importante, ya que su coste es exponencialmente menor en comparación con buscar un elemento desde el inicio del vector hasta el final (búsqueda lineal).

**¿Por qué es tan eficiente?**
Porque a cada paso dividimos el problema por la mitad. Iremos a la posición central y miraremos hacia qué mitad debería estar el elemento que estamos buscando (descartando automáticamente todo el resto). Haremos esta división las veces que sean necesarias hasta encontrar el elemento. Si los límites se cruzan significa que no está, y devolveremos `-1`.

??? example "1. BinarySearch.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    //pre: v está ordenado de forma creciente, 0 <= left, right < v.size().
    //post: devuelve la posición de 'x' dentro de 'v'. Devuelve -1 si 'x' no está.
    int binarySearch(const vector<int>& v, int x, int left, int right){
        // CASO BASE 1: Los límites se han cruzado (el elemento no está).
        if (left > right) return -1;

        int mid = (left + right) / 2;
        // CASO RECURSIVO: 'x' está hacia la derecha.
        if (v[mid] < x) { return binarySearch(v, x, mid + 1, right); }
        // CASO RECURSIVO: 'x' está hacia la izquierda.
        if (v[mid] > x) { return binarySearch(v, x, left, mid - 1); }

        // CASO BASE 2: Lo hemos encontrado en el medio (v[mid] == x).
        return mid;
    }

    int main(){
        vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        int x = 0;
        cout << "Which number's position do you want to find? ";
        cin >> x;

        int pos = binarySearch(v, x, 0, v.size() - 1);

        if (pos != -1){
            cout << "\nYour number is located at index " << pos << '.' << endl;
        } else{
            cout << "\nYour number is NOT in the vector." << endl;
        }
    }
    ```

Para entender qué hace el Selection Sort, debemos imaginarnos que tenemos unas cartas y las queremos ordenar sobre la mesa. 

De todas las cartas, buscamos cuál es la más pequeña y la intercambiamos con la que está en la primera posición. Una vez tenemos la primera asegurada, buscamos cuál es la más pequeña del resto y la intercambiamos con la que está en la segunda posición. Hacemos esto continuamente hasta que todo el vector queda ordenado.

??? example "2. SelectionSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    //pre: v.size() > 0.
    //post: devuelve el vector 'v' ordenado de forma creciente.
    void selectionSort(vector<int>& v){
        if (v.empty()) return; // ESTE ES UN IF DE PROTECCIÓN POR SI SE SALTAN LA PRECONDICIÓN DE LA FUNCIÓN.

        for (int i = 0; i < v.size(); i++){
            int lowest = i;
            for (int j = i+1; j < v.size(); j++){
                if (v[j] < v[lowest]){
                    lowest = j;
                }
            }

            if (lowest != i){ // Hay un número más pequeño, hacemos el swap
                int aux = v[i];
                v[i] = v[lowest];
                v[lowest] = aux;
            }
        }
    }

    int main() {
        vector<int> v = {64, 25, 12, 22, 11};

        cout << "Vector original: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        selectionSort(v);

        cout << "Vector ordenat:  ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    ```

Este algoritmo funciona exactamente igual que cuando ordenamos las cartas de póquer en nuestra mano.

Supongamos que la primera carta ya está ordenada. Cogemos la segunda carta (la guardamos en la variable `x`) y la comparamos con la de su izquierda. Si es más pequeña, desplazamos la carta grande hacia la derecha y continuamos mirando hacia atrás hasta encontrar su sitio exacto para "insertarla". Repetimos esto con todas las cartas de izquierda a derecha.

Esta versión de aquí es la **versión optimizada**, ya que en lugar de hacer *swaps* enteros continuamente, guardamos el valor a buscar (`x`), vamos desplazando hacia la derecha los valores grandes (`v[j] = v[j-1]`), y al final del todo dejamos la `x` en el hueco libre que ha quedado.

??? example "3. InsertionSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    //pre: v.size() > 1;
    //post: devuelve el vector 'v' ordenado de forma creciente.
    void insertionSort(vector<int>& v){
        if (v.size() < 2) return; // if de protección

        for (int i = 1; i < v.size(); i++){
            int j = i;
            int x = v[i];

            // Mientras no lleguemos al inicio y el elemento anterior sea más grande que 'x'
            while (j > 0 && x < v[j-1]){
                v[j] = v[j-1]; // Desplazamos hacia la derecha
                j--;
            }
            v[j] = x; // Insertamos la carta en su hueco correcto
        }
    }

    int main() {
        vector<int> v = {64, 25, 12, 22, 11};

        cout << "Vector original: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        insertionSort(v);

        cout << "Vector ordenat:  ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    ```

La función de fusión no es un algoritmo de ordenación completo para cualquier vector desordenado, sino una **herramienta específica** diseñada exclusivamente para fusionar dos vectores que **ya están previamente ordenados** en uno solo.

Mediante un solo bucle muy inteligente y tres índices (`i1`, `i2` y `k`), el programa va decidiendo cuál de los dos vectores tiene el número más pequeño en cada momento para irlo colocando en el vector resultante. Comprobamos primero si uno de los dos vectores ya se ha agotado para evitar leer memoria inválida (Segmentation Fault). Esta función es la pieza central y fundamental que hace posible la magia del *Merge Sort*.

??? example "4. FusionSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    // pre: v1 y v2 están ordenados de forma creciente
    // post: devuelve un vector con la fusión de v1 y v2 ordenado
    vector<int> fusionSort(const vector<int>& v1, const vector<int>& v2) {
        int n = v1.size() + v2.size();
        vector<int> res(n);
        int i1 = 0, i2 = 0, k = 0;

        while (k < n) {
            // 1. Si v1 se ha agotado, cogemos obligatoriamente de v2
            if (i1 == v1.size()) {
                res[k] = v2[i2];
                i2++;
            }
            // 2. Si v2 se ha agotado, cogemos obligatoriamente de v1
            else if (i2 == v2.size()) {
                res[k] = v1[i1];
                i1++;
            }
            // 3. Si ninguno se ha agotado, comparamos (con el <= para evitar bucles infinitos con empates)
            else if (v1[i1] <= v2[i2]) {
                res[k] = v1[i1];
                i1++;
            }
            // 4. Si el de v2 es más pequeño
            else {
                res[k] = v2[i2];
                i2++;
            }

            k++; // k siempre avanza pase lo que pase
        }

        return res;
    }

    int main() {
        // Vectores de tamaños diferentes para ponerlo a prueba de verdad
        vector<int> v1 = {1, 3, 5, 7, 9};
        vector<int> v2 = {2, 4, 6, 8, 10, 12, 14};

        cout << "Vector 1: ";
        for (int i = 0; i < v1.size(); i++) {
            cout << v1[i] << " ";
        }
        cout << endl;

        cout << "Vector 2: ";
        for (int i = 0; i < v2.size(); i++) {
            cout << v2[i] << " ";
        }
        cout << endl;

        vector<int> resultat = fusionSort(v1, v2);

        cout << "Vector fusionat: ";
        for (int i = 0; i < resultat.size(); i++) {
            cout << resultat[i] << " ";
        }
        cout << endl;
    }
    ```

¿Qué pasa si queremos ordenar usando nuestra función de fusión, pero el vector original está completamente desordenado? Si le pasamos directamente a `fusionSort` el resultado será inválido. Para resolver esto utilizamos el algoritmo de **Merge Sort** (Divide y Vencerás).

**¿Qué hace el Merge Sort?** 
Básicamente, divide el vector por la mitad generando dos vectores más pequeños (`left` y `right`). Después, divide estas mitades continuamente utilizando recursividad hasta que llegamos a vectores de tamaño 1. 
Como por definición un vector de 1 solo elemento **ya está ordenado**, nuestra función `fusionSort` puede empezar a juntarlos de dos en dos hacia arriba, reconstruyendo y ordenando todo el vector original con una velocidad espectacular.

El Merge Sort nos enseña exactamente la magia de la recursividad y lo importante que es para el día a día en la programación.

??? example "5. MergeSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    // pre: v1 y v2 están ordenados de forma creciente
    // post: devuelve un vector con la fusión de v1 y v2 ordenado
    vector<int> fusionSort(const vector<int>& v1, const vector<int>& v2) {
        int n = v1.size() + v2.size();
        vector<int> res(n);
        int i1 = 0, i2 = 0, k = 0;

        while (k < n) {
            if (i1 == v1.size()) {
                res[k] = v2[i2];
                i2++;
            } else if (i2 == v2.size()) {
                res[k] = v1[i1];
                i1++;
            } else if (v1[i1] <= v2[i2]) {
                res[k] = v1[i1];
                i1++;
            } else {
                res[k] = v2[i2];
                i2++;
            }
            k++;
        }
        return res;
    }

    // pre: cierto
    // post: devuelve el vector 'v' ordenado de forma creciente
    vector<int> mergeSort(const vector<int>& v) {
        // CASO BASE: Un vector vacío o de 1 elemento ya está ordenado
        if (v.size() <= 1) {
            return v;
        }

        // DIVISIÓN: Calculamos la mitad
        int mid = v.size() / 2;

        // Creamos los dos sub-vectores (izquierda y derecha)
        vector<int> left;
        vector<int> right;

        for (int i = 0; i < mid; i++) left.push_back(v[i]);
        for (int i = mid; i < v.size(); i++) right.push_back(v[i]);

        // RECURSIVIDAD: Ordenamos cada una de las mitades
        vector<int> sorted_left = mergeSort(left);
        vector<int> sorted_right = mergeSort(right);

        // FUSIÓN: Volvemos a juntar las partes ya ordenadas
        return fusionSort(sorted_left, sorted_right);
    }

    int main() {
        vector<int> v = {38, 27, 43, 3, 9, 82, 10};

        cout << "Vector original: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        // Llamamos al mergeSort completo
        vector<int> resultat = mergeSort(v);

        cout << "Vector ordenat:  ";
        for (int i = 0; i < resultat.size(); i++) {
            cout << resultat[i] << " ";
        }
        cout << endl;
    }
    ```

---

## 4. Ejercicio Final

A continuación verás cómo combinar la ordenación y la búsqueda para resolver un problema completo donde hay que estructurar datos y buscarlos de manera eficiente.

??? example "final.cpp"

    ```cpp
    /*
     * Ejercicio Final
     * Ejemplo: Sistema de Registro y Búsqueda de Jugadores (Binary Search).
     * Hecho por: aso
     */

    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    struct Player {
        int id;
        string name;
        int score;
    };

    // pre: cierto
    // post: devuelve true si el jugador 'a' tiene un ID estrictamente menor que el jugador 'b'
    bool cond(const Player& a, const Player& b) {
        return a.id < b.id;
    }

    // pre: el vector 'v' está ordenado por ID de forma creciente, 0 <= left, right < v.size()
    // post: devuelve la posición del jugador con el id buscado, o -1 si no existe
    int binarySearch(const vector<Player>& v, int x, int left, int right) {
        if (left > right) return -1;
        int mid = (left + right) / 2;
        if (v[mid].id < x) return binarySearch(v, x, mid + 1, right);
        if (v[mid].id > x) return binarySearch(v, x, left, mid - 1);
        return mid;
    }

    int main() {
        vector<Player> tournament;
        Player p;

        cout << "Registration phase, enter a player (format: ID PlayerName Score), for closing this phase, enter -1:" << endl;

            cin >> p.id;
            while (p.id != -1) {
                cin >> p.name >> p.score;
                tournament.push_back(p);

                cout << "\nEnter another player:" << endl;
                cin >> p.id;
            }

        sort(tournament.begin(), tournament.end(), cond);

        if (tournament.empty()){
            cout << "\nNo player was registered. Ending program." << endl;
        } else{
            cout << "- - - - - - - - - - - - - - - -\n";
            cout << "Query phase. Enter ID to search (Ctrl + D to exit):\n";

            int id;

            while (cin >> id) {

                int pos = binarySearch(tournament, id, 0, tournament.size() - 1);

                if (pos == -1){
                    cout << "Error: Player not registered" << endl;
                } else{
                    cout << "The player " << tournament[pos].name << " has " << tournament[pos].score << " points." << endl;
                }
                cout << "\nEnter ID to search (Ctrl + D to exit):\n";
            }
        }
    }
    ```
