# Iteraciones (Bucles)

## 1. Sintaxis de un bucle
Hasta ahora hemos visto cómo hacer que un código funcione solo una vez al ejecutarlo, pero ¿y si queremos que un mismo fragmento se repita continuamente hasta que se cumpla una condición para detenerse?
Esto se llama bucle, y sirve para iterar un código múltiples veces. 
Para hacer un bucle en C++ tenemos dos formas principales:

```cpp
while (condition){
    // ...
}
```

```cpp
for (content) // en content podéis poner:

for (int i = 0; i < 10; i++){ 
    // ...
}
/* Este bucle hace que una variable "i" temporal inicializada a 0 itere tantas veces mientras sea menor a 10. 
Funcionamiento: i = 0, comparación, ejecuta código, hace el incremento.
*/

for (int i = 10; i > 0; i--){ // Lo mismo que el anterior pero al revés.
    // ...
}

// si 'i' ya ha sido declarada anteriormente, podéis omitir la declaración de la variable:

// Ejemplo 1:
for (i = 0; ...){

}

// Ejemplo 2:
int i = 5;
for (; i < 10; ...){

}
```

---

## 2. Tipos de While
Tenemos 3 tipos de while CIRCUNSTANCIALES para PRO1.

*   **While con centinela (o de búsqueda):** Hará iteraciones hasta que encuentre un carácter o elemento específico para parar.
*   **While hasta EOF (End Of File):** Hará iteraciones mientras reciba información por la consola o un archivo; cuando en la consola se ejecute CTRL + D o el archivo se quede sin datos, el bucle se detendrá.
*   **While con número de elementos:** El while funcionará siempre que la condición del número de elementos (contador) se cumpla. 

Ejemplos:

??? example "1. WhileCentinela.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main(){
        char ch;
        string result = "";

        cin >> ch;
        while (ch != '0'){ // Queremos insertar chars en un string hasta que un char sea '0'.
            result += ch;
            cin >> ch;
        }

        cout << result << endl;
    }
    ```

??? example "2. WhileEOF.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main(){
        int n;
        int total = 0;

        while (cin >> n){ // Hasta que no hagamos CTRL+D en la consola, el código no parará.
            total += n;
            cout << total << endl;
        }
    }
    ```

??? example "3. WhileNElements.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main(){
        int n = 0;
        cout << "How many times do you want to subtract 1 until it's 0? Input (Must be an integer greater than 1): ";
        cin >> n;
        cout << endl;

        if (n <= 0){
            cout << "Invalid Input" << endl;
        } else{
            while (n > 0){ 
                cout << n-- << endl;
            }
        }
    }
    ```

---

## 3. Ejercicio Final
Para consolidar el uso de los bucles (tanto `while` como `for`), aquí tienes un programa completo que genera montañas de asteriscos en la consola según la altura indicada. La ejecución continúa hasta que forzamos el fin de archivo (EOF).

??? example "final.cpp"

    ```cpp
    /*
     * Ejercicio Final
     * Ejemplo: Construir Montañas donde el Pico es de N Altitud.
     * Hecho por: aso
     */

    #include <iostream>
    using namespace std;

    int main(){
        int n;

        cout << "How many '*' should have the peak of this mountain? (The answer must be an Integer greater or equal than 1): ";

        while (cin >> n) {
            cout << endl;

            if (n < 1) {
                cout << "Invalid Input" << endl;
            } else {
                // Subida de la montaña
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j <= i; j++) {
                        cout << '*';
                    }
                    cout << endl;
                }

                // Cuando i = n, la montaña debe volver a bajar. Por lo tanto empezamos en n - 1.
                for (int i = n - 1; i > 0; i--) {
                    for (int j = i; j > 0; j--) {
                        cout << '*';
                    }
                    cout << endl;
                }
            }

            cout << "And the next mountain? Answer: ";
        }
    }
    ```
