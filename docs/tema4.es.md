# Structs (Registros)

## 1. ¿Qué es un Struct?

Hasta ahora, si queríamos guardar la información de un estudiante (por ejemplo, su nombre, su edad y su nota), necesitábamos tres variables separadas:
```cpp
string name = "Frieren";
int age = 1250;
double grade = 10.0;
```
Esto funciona para una sola persona, pero es un caos si tenemos que gestionar muchos estudiantes y mover estos datos entre funciones.

Un **struct** (o registro) nos permite crear nuestro propio "tipo de dato" agrupando diferentes variables en su interior, **incluso si son de tipos distintos**. 

**La analogía de la Ficha o el DNI:**
Imagina un `struct` como una ficha médica, un DNI o un contacto del móvil. Es una sola entidad (el contacto) que dentro contiene diferentes apartados o campos (nombre, número de teléfono, correo).

---

## 2. Cómo definir un Struct

La definición de un `struct` se tiene que poner **siempre arriba del todo del archivo**, antes de las funciones y del `main()`, para que todo el programa lo conozca.

```cpp
#include <iostream>
using namespace std;

// Definimos nuestro nuevo tipo de dato
struct Student {
    string name;
    int age;
    double grade;
}; // IMPORTANTE: ¡NO te dejes ESTE punto y coma! Es obligatorio.

int main() {
    // ...
}
```

---

## 3. Cómo declarar y acceder a un Struct

Una vez hemos creado el "molde" (el `struct`), ya podemos crear variables de este nuevo tipo dentro del `main()` o de las funciones. 

Para acceder a los diferentes campos que hay en el interior del `struct`, utilizamos un **punto (`.`)**.

```cpp
int main() {
    // Creamos una variable de tipo 'Student' llamada 'student1'
    Student student1;

    // Rellenamos los datos accediendo a los campos con un punto
    student1.name = "Megumin";
    student1.age = 14;
    student1.grade = 9.2;

    // Podemos leer los datos de la misma manera
    cout << "El alumno " << student1.name << " tiene un " << student1.grade << endl;
}
```

---

## 4. Leer Structs desde la terminal

También podemos utilizar `cin` para rellenar directamente los campos de un `struct`. Solo tenemos que recordar hacerlo campo por campo:

```cpp
int main() {
    Student student2;
    
    cout << "Enter the student's name, age and grade:" << endl;
    cin >> student2.name >> student2.age >> student2.grade;
    
    cout << "¡Datos guardados correctamente!" << endl;
}
```

---

## 5. Structs y Funciones (Muy Importante)

Los `structs` pueden llegar a contener mucha información (imagina un `struct` que guarda todos los datos de un videojuego o el expediente entero de un alumno). 

Si pasamos un `struct` a una función por **valor**, C++ hará una copia exacta de todas sus variables cada vez que llamemos a la función, gastando memoria innecesariamente y haciendo que el programa vaya lentísimo. Por lo tanto, aplicamos una regla de oro: **siempre los pasamos por referencia**.

### 1. Paso por referencia normal (Para modificar)
Si queremos que la función modifique algún dato del `struct`, utilizamos el `&`.

```cpp
// Esta función suma un punto a la nota del estudiante
void applyBonus(Student& s) {
    s.grade = s.grade + 1.0;
    if (s.grade > 10.0) {
        s.grade = 10.0;
    }
}
```

### 2. Paso por referencia constante (Solo lectura)
Si solo queremos leer los datos para imprimirlos o hacer cálculos, pero no queremos modificarlos, utilizamos `const` y `&`. Es la manera más eficiente y segura, ya que evitamos hacer copias pero prohibimos que la función modifique los datos originales por error.

```cpp
// Esta función solo lee los datos y los imprime
void printStudent(const Student& s) {
    cout << "--- STUDENT INFO ---" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Grade: " << s.grade << endl;
}
```

---

## 6. Ejercicio Final
A continuación puedes ver un ejemplo completo de cómo utilizar los structs junto con las funciones aplicando el paso por referencia y el control de límites.

??? example "final.cpp"

    ```cpp
    /*
     * Ejercicio Final
     * Ejemplo: Ficha de Aventurero Con Structs y Funciones (Con Límites).
     * Hecho por: aso
     */

    #include <iostream>
    using namespace std;

    // Definimos el struct arriba del todo para que las funciones lo puedan conocer
    struct Adventurer {
        string name;
        int level;
        double health;
    };

    // pre: cierto
    // post: lee los datos desde la terminal y los guarda en el struct,
    // asegurándose de que los valores tengan sentido.
    void readAdventurer(Adventurer& a) {
        cout << "Enter the adventurer's name, level (1-100) and health (max 9999):" << endl;
        cout << "Example: Frieren 99 1500.5" << endl;

        cin >> a.name >> a.level >> a.health;

        // Control de errores: repetimos la lectura hasta que los datos sean válidos
        while (a.level < 1 || a.level > 100 || a.health <= 0 || a.health > 9999.0) {
            cout << "Error: Invalid stats for " << a.name << ". Level must be 1-100 and Health 1-9999." << endl;
            cout << "Please enter the data again:" << endl;
            cin >> a.name >> a.level >> a.health;
        }
    }

    // pre: cierto
    // post: imprime el estado actual del aventurero
    void printAdventurer(const Adventurer& a) {
        cout << "--- ADVENTURER STATUS ---" << endl;
        cout << "Name:    " << a.name << endl;
        cout << "Level:   " << a.level << endl;
        cout << "Health: " << a.health << " HP" << endl;
    }

    // pre: cierto
    // post: sube el nivel del aventurero en 1 y le aumenta la salud, respetando los límites
    void levelUp(Adventurer& a) {
        if (a.level >= 100) {
            cout << ">> " << a.name << " is already at maximum level! <<" << endl;
        } else {
            a.level++; // Subimos 1 nivel
            a.health = a.health + 50.0; // Damos 50 puntos de vida extra

            // Nos aseguramos de no sobrepasar la vida máxima por la bonificación
            if (a.health > 9999.0) {
                a.health = 9999.0;
            }

            cout << ">> " << a.name << " leveled up to level " << a.level << "! <<" << endl;
        }
    }

    int main() {
        Adventurer hero; // Declaramos nuestra variable del nuevo tipo struct

        // 1. Rellenamos los datos (Modificación) con el filtro de límites activado
        readAdventurer(hero);
        cout << endl;

        // 2. Imprimimos la ficha (Lectura)
        printAdventurer(hero);
        cout << endl;

        // 3. Subimos de nivel el personaje (Modificación)
        levelUp(hero);
        cout << endl;

        // 4. Volvemos a imprimir para comprobar los cambios (Lectura)
        printAdventurer(hero);
    }
    ```
