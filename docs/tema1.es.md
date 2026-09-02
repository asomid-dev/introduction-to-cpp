# Funcionamiento C++ y Compilación

## 1. Sintaxis
La sintaxis de C++ es sencilla. En PRO1 trabajaréis en la mayoría de ejercicios con la librería `<iostream>` para hacer el input y output del código.
Para añadir una librería solo tenemos que escribir al inicio de un archivo `.cpp` o `.cc` (formatos C++) `#include <libreria>`.

Además de la librería, también usamos un "namespace". El namespace es como un prefijo de la función; por ejemplo, si en la librería estándar (`std`) tenemos una función `cout` y en la librería personalizada *paco* tenemos una función con la misma definición `paco`, evitaremos el problema con el prefijo. Para no tener que escribir todo el rato el prefijo (ej: `std::cout`), al inicio añadiremos después de las librerías (por estructura de la asignatura): `using namespace std;`.

Todo código de C++ tiene una función principal (`main`) que es la que busca el compilador para poder ejecutar un código. (En el ejemplo está la declaración del main).

Ejemplo:
```cpp
#include <iostream>
using namespace std;

int main() {
    
}
```

Para añadir comentarios a un código (texto que no afecta a nuestro código) solo tenemos que escribir un `//` (comentario por línea) o `/* */` (comentario por bloque).

```cpp
#include <iostream>
using namespace std;

// Este es un comentario solo para esta línea.

/* 
Este es un comentario
hasta que 
se cierra el bloque 
*/

int main() {
    // ...
}
```

---

## 2. Tipos de variables
Tenemos diferentes variables:
*   `int` (enteros) -> (p. ej. `124`)
*   `string` (palabras) -> (p. ej. `"Hola"`)
*   `char` (caracteres) -> (p. ej. `'a'`) **Nota:** un carácter se almacena con su valor ASCII, por ejemplo el `'0'` es el `48`.
*   `double` (decimales) -> (p. ej. `67.67`)
*   `bool` (verdadero o falso) -> (p. ej. `true`) **Nota:** también se puede declarar con `1` (true) y `0` (false).

Para declarar variables, usamos una palabra clave que servirá para asignar un valor a esa palabra. 
Además, podemos hacer que una variable sea **constante**, es decir, que no cambiará nunca. Solo tenemos que poner `const` delante de una declaración de variable.

Ejemplo de cómo se declara una variable:
```cpp
#include <iostream>
using namespace std;

int main() {
    // Estructura: tipo nombre_variable = valor;
    int nombre = 124; // Cada vez que definimos un valor, debemos poner el ; 
    string palabra = "Frieren";
    char ch = 'a';
    double sixseven = 67.67;
    
    // Al igual que podemos asignar nombre = 124, podemos hacer lo siguiente:
    int aux = nombre; // Como nombre es igual a 124, 
                      // podemos asignar este valor a otra variable.
    
    // Declaración de una constante:
    const int restricted_age = 18;
}
```

---

## 3. Input y Output
Ahora que sabemos cómo funcionan las variables, aprenderemos a compilar un archivo `.cpp`, introducir datos por la terminal y cómo imprimir datos por la terminal.

Primero haremos el ejercicio típico de cualquier lenguaje de programación:

??? example "1. HelloWorld.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        cout << "Hello World!" << endl; 
        
        // cout: Console OUTput
        // << operador de inserción del cout (significa: muestra en la consola lo que viene después)
        // endl: palabra reservada de la librería std, es un carácter que significa fin de línea (end line)
    }
    ```

Para poder ver "Hello World!" por la terminal tenemos que compilar. ¿Cómo lo hacemos? Fácil.
En la terminal Linux vamos a la carpeta del archivo:
```bash
cd /home/aso/CODE/cpp
g++ archivo.cpp -o ejecutable
./ejecutable
```
Al ejecutable podéis ponerle el nombre que queráis, yo por costumbre pongo siempre `x.x`, otras personas hacen un ejecutable por programa.

Ejemplo de compilación y ejecución con HelloWorld:
```bash
g++ HelloWorld.cpp -o x.x
./x.x 
```
Después de hacer `./x.x` veréis por la terminal: `Hello World!`

> **NOTA:** Recordad guardar (`CTRL + S` o `CTRL + G`) siempre antes de compilar, para evitar errores tontos de compilación.

??? example "2. HelloName.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        string name; // Declaración sin asignación de valor
                     // En C++, por defecto el string recibe el valor vacío "".
                     
        cout << "What is your name?" << endl; 
        cin >> name; // Escribimos en la terminal el nombre con UNA sola palabra. 
        cout << "Hello " << name << '!' << endl;
        
        // cin: Console INput
        // >> operador de extracción del cin (significa: introduce el valor recibido en la variable)
    }
    ```

Cuando es un `cin`, ponemos los valores que nos piden y pulsamos la tecla Enter para avisar al código de que ya hemos puesto la información. 

> **DIFERENCIAS IMPORTANTES ENTRE `cin` Y `cout` CON LOS STRINGS**
> Con un `cin` solo podemos introducir **una palabra** por variable `string`. El `cin` detecta el espacio como final de string.
> En cambio, con el `cout`, cuando ponemos `cout << "frase con espacios" << endl;` imprime en la consola toda la frase entera sin cortarla.

---

## 4. Operadores y Comparadores Lógicos

### Operadores Aritméticos
| Tipo | Declaración |
| :--- | :--- |
| Suma | `+` |
| Resta | `-` |
| Multiplicación | `*` |
| División | `/` |
| Resto de una división | `%` |
| Asignación | `=` |

> **NOTA:** La división `/`, si dividimos enteros, devolverá la parte entera. En cambio, si dividimos doubles, devolverá la división normal. Por lo tanto, no podremos hacer nunca `double % double`, ya que la propia división de decimales ya añade el resto.

### Operadores Compuestos y de Incremento
```cpp
// suponemos que i es un entero

i++; // suma post-incremento -> después de trabajar con la i, 
     // incrementamos 1, es decir: i = i + 1.

++i; // suma pre-incremento -> antes de trabajar con la i, 
     // incrementamos 1.

// también se puede hacer resta post-decremento y pre-decremento

i += 20; // traducción: i = i + 20
 
i /= 2; // traducción: i = i / 2;
```

Ejemplo:

??? example "3. PostAndPreExample.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main(){
        // Ejemplo Post-Decremento
        int i = 5;
        int a = i--; // 'a' se queda con el 5. Una vez asignado, 'i' baja a 4.
        cout << "POST-DECREMENT -> a: " << a << ", i: " << i << endl;

        // Ejemplo Pre-Decremento
        int j = 5;
        int b = --j; // 'j' baja a 4 directamente. Entonces se asigna, y 'b' también vale 4.
        cout << "PRE-DECREMENT -> b: " << b << ", j: " << j << endl;

        // con post-incremento y pre-incremento es igual:
        i = 5;
        a = i++; // 'a' se queda con el 5. Una vez asignado, 'i' aumenta a 6.
        cout << "POST-INCREMENT -> a: " << a << ", i: " << i << endl;

        j = 5;
        b = ++j; // 'j' aumenta a 6 directamente. Entonces se asigna, y 'b' también vale 6.
        cout << "PRE-INCREMENT -> b: " << b << ", j: " << j << endl;
    }
    ```

### Operadores Lógicos
| Tipo | Declaración |
| :---- | :--------- |
| AND   | `&&`       |
| OR    | \|\|       |
| NOT   | `!`        |


### Comparadores Lógicos

*Un comparador siempre da un resultado booleano (`true` o `false`)*

| Tipo | Declaración |
| :--- | :--- |
| Mayor | `a > b` |
| Menor | `a < b` |
| Mayor o igual | `a >= b` |
| Menor o igual | `a <= b` |
| Estrictamente igual | `a == b` |
| Diferente | `a != b` |

---

## 5. Condicionales
En la programación tenemos condicionales: `if`, `else if`, `else`.

Siempre declaramos primero `if`. Si hay una segunda condición que queremos cubrir después de que la primera falle, ponemos `else if`. Para el resto de casos (las excepciones), ponemos `else`.
Por estructura y elegancia, siempre abriremos un bloque `{}` después del condicional.

??? example "4. CanYouDrink.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        int age = 0; // todo el mundo tiene como mínimo 0 años
        
        cout << "How old are you? (type your age with a number (i.e. 24))" << endl;
        cin >> age;
        
        if (age >= 18) { // Miramos si la edad es mayor o igual a 18.
            cout << "You can drink alcohol" << endl;
        } else {
            cout << "You can't drink alcohol" << endl;
        } 
    }
    ```

---

## 6. Ejercicio Final
Para consolidar todo lo que hemos visto en este primer tema (variables, `cin`/`cout`, operadores y condiciones), aquí tienes un programa completo que implementa una calculadora básica de un solo uso. 

??? example "final.cpp"

    ```cpp
    /*
     * Ejercicio Final
     * Ejemplo: Calculadora Básica de un Solo Uso.
     * Hecho por: aso
     */

    #include <iostream>
    using namespace std;

    int main(){
        int a, b;
        char op;
        bool correct = true;

        cout << "Type an integer operation with only one operator (i.e. 24 - 12), valid operators: +, -, *, /, %." << endl;
        cin >> a >> op >> b; // leemos número a, operador, número b

        int result = 0; // Siempre que un número vaya a salir por pantalla, por seguridad, lo inicializamos a 0.
        if (op == '+'){
            result = a + b;
        } else if (op == '-'){
            result = a - b;
        } else if (op == '*'){
            result = a * b;
        } else if (op == '/'){
            if (b != 0){ // En PRO1 siempre buscan los puntos débiles del ejercicio.
                result = a / b;
            } else{ // b == 0
                correct = false;
            }
        } else if (op == '%'){
            if (b != 0){
                result = a % b;
            } else{ // b == 0
                correct = false;
            }
        } else{ // operador inválido
            correct = false;
        }
        
        if (correct){
            cout << "The operation is equal to " << result << '.' << endl;
        } else{
            cout << "Error: Invalid operator or division by zero" << endl;
        }
    }
    ```
