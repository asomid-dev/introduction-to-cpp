# Vectores

## 1. ¿Qué es un vector?

En el tema anterior vimos cómo los `structs` nos permiten agrupar diferentes datos de una sola entidad (como el nombre y la nota de un solo estudiante). Pero, ¿y si queremos guardar los datos de 50 estudiantes de golpe sin tener que crear 50 variables diferentes? Para eso existen los **vectores**.

Un vector es una estructura de datos que nos permite almacenar una lista o colección de elementos del **mismo tipo** (todos enteros, todos strings, o todos structs) de forma ordenada.

Imagina un vector como un mueble con muchos cajones. Cada cajón tiene una etiqueta con un número (la posición o índice), y dentro de cada cajón guardamos un valor. 

> **⚠️ NOTA IMPORTANTE:** En C++ (y en la mayoría de lenguajes de programación), **se empieza a contar desde el cero**. El primer elemento de un vector está siempre en la posición 0, el segundo en la posición 1, etc. Si un vector tiene 5 elementos, su última posición es la 4.

---

## 2. Cómo declarar un vector

Para poder utilizar vectores en nuestro código, primero de todo debemos añadir la librería `#include <vector>` arriba del todo del archivo.

La sintaxis básica para crear uno es la siguiente:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Sintaxis: vector<tipo_de_dato> nombre_del_vector(tamaño, valor_inicial);
    
    // Ejemplo 1: Vector de 5 enteros, todos inicializados a 0 por defecto.
    vector<int> notas(5, 0); 
    
    // Ejemplo 2: Vector de 10 strings, inicializados vacíos.
    vector<string> palabras(10); 
    
    // Ejemplo 3: Vector vacío (tamaño 0), que podremos hacer crecer más adelante.
    vector<double> precios; 
    
    // Ejemplo 4: Vector predefinido por el usuario.
    vector<char> letras = {'H', 'o', 'l', 'a'};
}
```

---

## 3. Cómo acceder a una posición de un vector

Después de declarar un vector, debemos saber cómo modificar y/o acceder a la información contenida. 
Para hacerlo, utilizamos los corchetes `[]` y ponemos dentro el índice (la posición) a la que queremos ir.

```cpp
vector<int> notas(3, 0); // Vector de 3 enteros: [0, 0, 0]

// Modificar valores:
notas[0] = 8; // Cambiamos el primer cajón por un 8. Ahora tenemos: [8, 0, 0]
notas[1] = 5; // Cambiamos el segundo cajón por un 5. Ahora tenemos: [8, 5, 0]

// Acceder para leer:
cout << "La primera nota es un: " << notas[0] << endl;
```

**Recorrer un vector con un bucle `for`:** Esta es la operación matemática/lógica que harás más a menudo en PRO1. Utilizamos un bucle que empezará en la posición `0` para ir abriendo los cajones uno por uno, ya sea para llenarlos de datos (`cin`) o para mostrarlos (`cout`).

```cpp
// Leemos 5 notas de la terminal y las guardamos en el vector
vector<int> notas(5);

for (int i = 0; i < 5; i++) {
    cin >> notas[i];
}
```

---

## 4. Métodos de los vectores

Los vectores en C++ vienen con herramientas incorporadas (llamadas métodos) que nos facilitan muchísimo trabajar con ellos. Para llamar a un método, simplemente escribimos el nombre del vector seguido de un punto `.` y el nombre de la herramienta.

Los dos métodos estrella que utilizarás a diario son:

### 1. `.size()`
Nos devuelve el tamaño actual del vector (cuántos elementos tiene). Es **fundamental** ponerlo como límite en los bucles `for`. Así, si mañana cambias el tamaño del vector, el bucle se adapta automáticamente y te ahorras errores y salidas fuera de límite.

```cpp
vector<int> notas(5);

// El bucle dará tantas vueltas como grande sea el vector (5 en este caso)
for (int i = 0; i < notas.size(); i++) { 
    cout << notas[i] << endl;
}
```

### 2. `.push_back(valor)`
Añade un nuevo elemento justo al final del vector. Este método es genial porque hace que el vector "crezca" automáticamente de tamaño. Es muy útil cuando lees una secuencia de datos pero no sabes cuántos hay en total (por ejemplo, un bucle EOF), ya que puedes empezar con un vector vacío e ir llenándolo.

```cpp
vector<int> pares; // Creamos un vector vacío (tamaño 0)

pares.push_back(2); // El vector crece. Ahora es de tamaño 1 y contiene: [2]
pares.push_back(4); // Ahora es de tamaño 2 y contiene: [2, 4]
pares.push_back(6); // Ahora es de tamaño 3 y contiene: [2, 4, 6]
```

---

## 5. Ejemplos

??? example "1. PalabrasConVectores.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        // Creamos un vector de caracteres predefinido
        vector<char> letters = {'H', 'o', 'l', 'a'};

        cout << "Printing the vector letter by letter: ";

        // Lo recorremos exactamente igual que cualquier otro vector
        for (int i = 0; i < letters.size(); i++) {
            cout << letters[i];
        }

        cout << endl; // La salida será "Hola"
    }
    ```

En este ejemplo observamos que un vector de `char`s y un `string` tienen cosas similares; esto es porque un `string` es realmente un vector de `char`s y podemos acceder a una posición específica de un `string`:

??? example "2. StringVector.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        string word = "Hola";

        // 1. Podemos usar .size() para saber cuántas letras tiene
        cout << "The word has " << word.size() << " letters." << endl;

        cout << "Accessing specific positions:" << endl;

        // 2. Podemos usar los corchetes [] para leer letras sueltas
        cout << "First letter (position 0): " << word[0] << endl;
        cout << "Last letter (position 3): " << word[3] << endl;

        cout << "Spelling with a for loop:" << endl;

        // 3. Podemos recorrer el string con un bucle for tal y como hacemos con los vectores
        for (int i = 0; i < word.size(); i++) {
            cout << "- " << word[i] << endl;
        }
    }
    ```

??? example "3. PushBack.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        // 1. Creamos un vector totalmente vacío (tamaño 0)
        vector<int> numbers;
        int n;

        cout << "Enter several numbers (press Ctrl+D to finish): " << endl;

        // 2. Vamos leyendo datos hasta que no haya más (EOF)
        while (cin >> n) {
            // En cada vuelta, añadimos el número leído al final del vector.
            numbers.push_back(n);
        }

        cout << endl;
        cout << "Reading finished!" << endl;

        // 3. Gracias a .size(), sabemos exactamente cuántos elementos hemos guardado
        cout << "You have entered " << numbers.size() << " numbers in total." << endl;

        cout << "The stored numbers are: ";

        // 4. Recorremos el vector para demostrar que todo se ha guardado en orden
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
    ```

---

## 6. Vectores y Funciones (Muy Importante)

Cuando pasamos un vector a una función, debemos tener mucho cuidado con la memoria. Por defecto, C++ pasa los parámetros por **valor** (hace una copia). Si nuestro vector tiene 1.000.000 de elementos, hacer una copia cada vez que llamamos a una función hará que el programa vaya lentísimo o se bloquee.

Por eso, en C++ **LOS VECTORES SIEMPRE SE PASAN POR REFERENCIA**.

Tenemos dos formas de hacerlo según qué queramos hacer con el vector dentro de la función:

### 1. Queremos modificar el vector (Referencia normal)
Si la función debe alterar los datos del vector original (por ejemplo, para ordenarlo o añadir cosas), lo pasamos por referencia añadiendo un `&`.

```cpp
// Esta función pone todos los elementos del vector a 0
void resetearVector(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = 0;
    }
}
```

### 2. Solo queremos leer el vector (Referencia constante)
Si solo queremos leer la información (por ejemplo, para sumar las notas, o para buscar un número), no queremos hacer copias, pero tampoco queremos que la función modifique el vector por error. En este caso, utilizamos `const` antes del tipo y el `&` al final. Esto se llama **paso por referencia constante**.

```cpp
// Esta función solo lee el vector, está prohibida la modificación
int sumarElementos(const vector<int>& v) {
    int suma = 0;
    for (int i = 0; i < v.size(); i++) {
        suma = suma + v[i];
    }
    return suma;
}
```

---

## 7. Ejercicio Final

Este ejercicio combina todo lo que hemos visto: crearemos un sistema para guardar múltiples estudiantes (`structs`) dentro de un `vector`, leeremos datos hasta que el usuario decida parar (con un bucle EOF y `.push_back()`), y pasaremos este vector por referencia a varias funciones para leer y modificar sus datos.

??? example "final.cpp"

    ```cpp
    /*
     * Ejercicio Final
     * Ejemplo: Gestor de Notas Con Structs, Vectores y Funciones.
     * Hecho por: aso
     */

    #include <iostream>
    #include <vector>
    using namespace std;

    struct Student {
        string name;
        double grade;
    };

    // pre: cierto
    // post: imprime los nombres y las notas de todos los estudiantes
    void printGrades(const vector<Student>& v) {
        for (int i = 0; i < v.size(); i++) {
            cout << "- " << v[i].name << ": " << v[i].grade << endl;
        }
    }

    // pre: el vector 'v' no está vacío (v.size() > 0)
    // post: devuelve la nota media de la clase
    double calculateAverage(const vector<Student>& v) {
        double sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum = sum + v[i].grade;
        }
        return sum / v.size();
    }

    // pre: cierto
    // post: suma 1 punto a todas las notas del vector, con un máximo de 10
    void applyBonus(vector<Student>& v) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].grade < 10.0) {
                v[i].grade++;

                if (v[i].grade > 10.0) {
                    v[i].grade = 10.0;
                }
            }
        }
    }

    int main() {
        vector<Student> classList;
        Student current;

        // Ahora la explicación de la terminal deja claro que es para MÚLTIPLES estudiantes
        cout << "--- STUDENT RECORD SYSTEM ---" << endl;
        cout << "Enter the students' names and grades." << endl;
        cout << "You can add as many as you want! (Press Ctrl+D to finish)" << endl;
        cout << "Example:" << endl;
        cout << "Frieren 10.0" << endl;
        cout << "Megumin 8.5" << endl;
        cout << "Mugi 9.2" << endl;
        cout << "-----------------------------------" << endl;

        // Leemos datos continuamente hasta que el usuario cierre (Ctrl+D)
        while (cin >> current.name >> current.grade) {

            if (current.grade > 10.0 || current.grade < 0.0) {
                cout << "Error: Invalid grade for " << current.name << ". It must be between 0 and 10." << endl;
            } else {
                classList.push_back(current);
            }
        }

        cout << endl;

        if (classList.size() == 0) {
            cout << "No grades were entered." << endl;
            return 0;
        }

        // Confirmación visual de que se han añadido diferentes alumnos al vector
        cout << ">> Successfully loaded " << classList.size() << " students into the system. <<" << endl << endl;

        // 2. Paso por referencia constante
        cout << "--- BEFORE THE BONUS ---" << endl;
        printGrades(classList);
        cout << "Class average: " << calculateAverage(classList) << endl;

        cout << endl;

        // 3. Paso por referencia normal
        cout << "Applying +1 bonus to everyone..." << endl;
        applyBonus(classList);

        cout << endl;

        // 4. Comprobamos los cambios
        cout << "--- AFTER THE BONUS ---" << endl;
        printGrades(classList);
        cout << "New class average: " << calculateAverage(classList) << endl;
    }
    ```
