# Recursividad

## 1. ¿Qué es la Recursividad y su Sintaxis?
Hasta ahora hemos visto cómo repetir código utilizando bucles (`while` y `for`), pero ¿y si queremos que una función se repita llamándose a sí misma?
Esto se llama recursividad, y sirve para resolver problemas dividiéndolos en subproblemas más pequeños.

**La analogía de las Muñecas Rusas (Matrioskas):**
Imagina que tienes una muñeca de madera que dentro tiene una más pequeña, y esta otra, y otra. La acción es siempre la misma: "abrir la muñeca". Solo paras de hacerlo cuando llegas a la muñeca más pequeñita de todas, que ya no se puede abrir. Esto es exactamente la recursividad: una función que hace una parte del trabajo y se vuelve a llamar a sí misma con un problema más pequeño, hasta llegar a un punto donde ya no se puede dividir más.

Para hacer una función recursiva en C++ la estructura básica es la siguiente:

```cpp
void funcionRecursiva(int n){
    if (condicion_de_parada){
        // Caso base: el problema es tan pequeño que se resuelve directamente (la muñeca más pequeña).
        // Aquí se detiene la recursividad.
    } else {
        // Caso recursivo: hacemos una parte del trabajo y volvemos a llamar 
        // a la función con un valor modificado (abrimos la muñeca y pasamos a la siguiente).
        funcionRecursiva(n - 1);
    }
}
/* Este esquema hace que la función se llame a sí misma disminuyendo 'n' en cada paso.
Cuando 'n' cumple la condición de parada, la función deja de llamarse.
*/
```

---

## 2. Las dos reglas de oro (Partes de la recursividad)
TODA función recursiva que hagas en PRO1 DEBE TENER dos partes imprescindibles. Si te dejas una, la función no parará nunca.

*   **El Caso Base:** Es la condición de salida. Es el problema tan sencillo que lo podemos resolver directamente sin llamar a nada más. Actúa como el centinela o el EOF de los bucles.
*   **El Caso Recursivo:** Es donde volvemos a llamar a la función a sí misma, pero pasándole un parámetro que la acerque al Caso Base (haciendo el problema más pequeño).

---

## 3. El peligro de la Recursividad: el Stack Overflow
¿Qué pasa si te olvidas el Caso Base o si el Caso Recursivo no hace el problema más pequeño? El error fatal llamado **Stack Overflow** (desbordamiento de pila).

En C++, cada vez que llamas a una función, el ordenador pone una "caja" temporal con las variables de esa llamada en una zona de la memoria llamada **Pila** (*Stack*). Cuando la función termina, la caja se quita. En la recursividad, el ordenador va apilando cajas una sobre otra antes de cerrar las anteriores. 

Si la recursividad es infinita (por ejemplo, llamar a `cuentaAtras(segundos)` en lugar de `cuentaAtras(segundos - 1)`), el ordenador apilará cajas hasta tocar el límite de la memoria. Cuando ya no caben más, la memoria se desborda y el programa muere instantáneamente. ¡Revisa siempre que tus llamadas recursivas se acerquen al Caso Base!

---

## 4. Ejemplos

??? example "1. CuentaAtras.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    // pre: segundos >= 0
    // post: imprime una cuenta atrás desde 'segundos' hasta 0, acabando con una explosión
    void cuentaAtras(int segundos){
        if (segundos == 0){ // CASO BASE: Cuando llega a 0, paramos e imprimimos el mensaje final.
            cout << "EXPLOSION! 💥" << endl;
        } else { // CASO RECURSIVO: Imprimimos el número y llamamos a la función con 1 segundo menos.
            cout << segundos << "..." << endl;
            cuentaAtras(segundos - 1); 
        }
    }

    int main(){
        cout << "Megumin is preparing the spell:" << endl;
        cuentaAtras(3);
    }

    /* Funcionamiento para cuentaAtras(3): 
    1. Imprime 3 y llama a cuentaAtras(2)
    2. Imprime 2 y llama a cuentaAtras(1)
    3. Imprime 1 y llama a cuentaAtras(0)
    4. Entra en el CASO BASE: imprime "EXPLOSION!" y no llama a nadie más.
    */
    ```

??? example "2. MCD.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    // pre: a >= 0, b >= 0
    // post: devuelve el Máximo Común Divisor (MCD) de a y b utilizando el algoritmo de Euclides
    int mcd(int a, int b){
        if (b == 0){ // CASO BASE: Si el resto llega a 0, el MCD es el otro número.
            return a;
        } else { // CASO RECURSIVO: Intercambiamos los valores y pasamos el resto (a % b).
            return mcd(b, a % b);
        }
    }

    int main(){
        int a, b;
        cout << "Matikanetannhauser asks for two numbers to find their GCD: ";
        cin >> a >> b;
        
        cout << "The GCD of " << a << " and " << b << " is " << mcd(a, b) << endl;
    }
    ```

??? example "3. Factorial.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    // pre: n >= 0
    // post: devuelve el factorial de n (n!)
    int factorial(int n){
        if (n == 0){ // CASO BASE: El factorial de 0 siempre es 1.
            return 1;
        } else { // CASO RECURSIVO: Multiplicamos 'n' por el factorial del número anterior.
            return n * factorial(n - 1);
        }
    }

    int main(){
        int n;
        cout << "Mugi asks for a number to calculate its factorial: ";
        cin >> n;
        
        if (n < 0){
            cout << "Factorial is not defined for negative numbers." << endl;
        } else {
            cout << "The factorial of " << n << " is " << factorial(n) << endl;
        }
    }
    ```

??? example "4. Potencia.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    // pre: exp >= 0
    // post: devuelve la 'base' elevada a 'exp'
    int power(int base, int exp){
        if (exp == 0){ // CASO BASE: Cualquier número elevado a 0 siempre es 1.
            return 1;
        } else { // CASO RECURSIVO: Multiplicamos la base por la potencia con el exponente restado en 1.
            return base * power(base, exp - 1);
        }
    }

    int main(){
        int base, exp;
        cout << "Enter the base and the exponent for Scarlet's attack: ";
        cin >> base >> exp;
        
        if (exp < 0){
            cout << "Error: This function only supports positive exponents." << endl;
        } else {
            cout << "Total damage: " << power(base, exp) << " HP!" << endl;
        }
    }
    ```

---

## 5. Ejercicio Final

Este ejercicio combina la recursividad con elementos que ya hemos visto anteriormente, introduciendo un concepto nuevo y muy útil: el `std::pair`, que nos permite devolver dos datos diferentes a la vez desde una misma función.

??? example "final.cpp"

    ```cpp
    /*
     * Ejercicio Final
     * Ejemplo: Registro Con Centinela y Búsqueda Recursiva Devolviendo un Pair.
     * Hecho por: aso
     *
     * ----------------------------------------------------------------------
     * 💡 ¿QUÉ ES UN PAIR?
     * Un std::pair es una herramienta de C++ que nos permite agrupar dos valores
     * (pueden ser de tipos iguales o diferentes) en una sola variable.
     * Imagínate que es un "mini-struct" prefabricado que siempre tiene
     * exactamente dos campos: el primero se llama '.first' y el segundo '.second'.
     *
     * Es súper útil cuando una función necesita DEVOLVER DOS COSAS a la vez.
     * En este caso, nuestra función de búsqueda debe responder dos preguntas:
     * 1. ¿Lo has encontrado? -> Un booleano (true/false) que guardaremos en .first
     * 2. ¿En qué posición? -> Un entero (el índice) que guardaremos en .second
     * ----------------------------------------------------------------------
     */

    #include <iostream>
    #include <vector>
    using namespace std;

    struct Adventurer {
        string name;
        int level;
    };

    // pre: 0 <= index <= v.size()
    // post: devuelve {true, índice} si lo encuentra, o {false, -1} si no está.
    pair<bool, int> recursiveSearch(const vector<Adventurer>& v, string target, int index) {
        // 1. CASO BASE 1: Hemos llegado al final del vector (fuera de límites) y no lo hemos encontrado
        if (index == v.size()) {
            return {false, -1};
        }
        // 2. CASO BASE 2: ¡Lo hemos encontrado en la posición actual!
        else if (v[index].name == target) {
            return {true, index};
        }
        // 3. CASO RECURSIVO: No está aquí, así que buscamos en la siguiente posición (index + 1)
        else {
            return recursiveSearch(v, target, index + 1);
        }
    }

    int main() {
        vector<Adventurer> party;
        string newName;
        int newLevel;

        // --- FASE 1: REGISTRO (Bucle con Centinela) ---
        cout << "--- ADVENTURER GUILD REGISTRATION ---" << endl;
        cout << "Enter the adventurer's name and level (Type 'END' as name to finish):" << endl;

        // Leemos el nombre. Si no es "END", leemos también el nivel y lo añadimos al vector
        cin >> newName;
        while (newName != "END") {
            cin >> newLevel;
            party.push_back({newName, newLevel});

            cout << "> " << newName << " registered successfully!" << endl;
            cin >> newName; // Leemos el siguiente nombre para ver si es el centinela
        }

        cout << endl << ">> Registration closed! Total members: " << party.size() << " <<" << endl << endl;

        // --- FASE 2: BÚSQUEDA (Bucle hasta EOF) ---
        cout << "--- GUILD DATABASE SEARCH ---" << endl;
        cout << "Who are you looking for? (Press Ctrl+D to exit)" << endl;

        string targetName;
        while (cin >> targetName) {

            // Llamamos a la función recursiva empezando desde la posición 0
            pair<bool, int> result = recursiveSearch(party, targetName, 0);

            if (result.first == true) {
                int pos = result.second;
                cout << ">> Found! " << targetName << " is at position " << pos
                     << " with level " << party[pos].level << ". <<" << endl;
            } else {
                cout << ">> " << targetName << " is not registered in the guild. <<" << endl;
            }

            cout << endl << "Who else are you looking for? ";
        }

        cout << endl << "Terminal closed. Goodbye!" << endl;
    }
    ```
