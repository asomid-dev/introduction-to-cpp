# Funciones

## 1. ¿Qué es una función?

Hasta ahora, todo el código que hemos escrito lo hemos puesto dentro del `int main() { ... }`. Esto funciona para programas pequeños, pero a medida que el código crece, tenerlo todo en un solo bloque se vuelve un caos. 

Una **función** es como un "miniprograma" dentro de tu código que se encarga de realizar una tarea específica.

Para entender cómo funciona una función, debemos imaginarnos una máquina de café. Nosotros tenemos una máquina de café y tenemos que ponerle agua y café en polvo para que nos devuelva un café preparado para beber; una función es exactamente lo mismo. Recibe parámetros (el agua y el café en polvo) y devuelve el resultado.

**¿Por qué usamos funciones?**
1. **Reutilización:** Si tenemos que calcular el mínimo común múltiplo 10 veces, no queremos escribir el mismo código 10 veces. Lo escribimos 1 sola vez y llamamos a la función.
2. **Orden y legibilidad:** Permite dividir un problema grande y complejo en problemas pequeños y fáciles de resolver.

---

## 2. Sintaxis de una función

La función se define y se declara antes del `main()`. Tiene la siguiente estructura:

```cpp
//pre: 
//post: 
tipo_de_retorno nombreFuncion(tipo parametro1, tipo parametro2){
    // código
    return resultado;
}
```

- **Pre:** En la precondición (pre) ponemos qué debe cumplir el código o los parámetros para que la función se ejecute correctamente. En caso de que funcione siempre correctamente sin importar la entrada, escribimos `true` o `cierto`.
- **Post:** Explica qué hace la función, qué devuelve como resultado o qué variables modifica.
- **Tipo de retorno:** ¿Qué nos devolverá la función? ¿Un `int`, `double`, `string`, `bool` o `char`?
- **Nombre de la función:** Un nombre descriptivo (p. ej. `calculaArea`, `esPar`).
- **Parámetros:** Los datos que necesita la función para trabajar, se ponen entre los paréntesis. Si la función no necesita datos, se dejan los paréntesis vacíos `()`.
- **return:** La palabra clave que devuelve el resultado hacia fuera de la función. Una vez se ejecuta el `return`, la función se detiene inmediatamente.

## Parámetros

Los parámetros se pueden pasar por:
- **Valor:** se hace una copia temporal y no modifica nada del `main`.
```cpp
//pre: ...
//post: ...
int soyUnaFunc(int a, int b){ 
    // ...
}
```

- **Referencia:** no se hace ninguna copia, es decir, modificamos el parámetro real que hemos recibido del `main`.
```cpp
void soyUnaFunc(int &a){ 
    // si modificamos 'a', también se modifica en el main.
}
```

---

## 3. Procedimientos (void)

A veces queremos que una función realice una acción concreta (como imprimir un mensaje en la consola, dibujar algo o modificar una variable externa) pero **no necesitamos que nos devuelva ningún valor**.

En estos casos, en lugar de poner `int` o `string` en el tipo de retorno, ponemos `void` ("vacío").

Las funciones `void` no llevan la instrucción `return resultado;`. (Como mucho, pueden llevar un `return;` vacío para detener la función antes de tiempo).

---

## 4. Ejemplos

??? example "1. SumaVariables.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: true
    //post: devuelve la suma de dos elementos enteros.
    int sum(int a, int b){
        return a + b;
    }

    int main(){
        int n1 = 5;
        int n2 = 10;
        cout << sum(n1,n2) << endl;
    }
    ```

??? example "2. MCD.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: a >= 0, b >= 0
    //post: devuelve el mcd mediante el algoritmo de Euclides.
    int mcd(int a, int b){
        while (b != 0){
            int aux = b;
            b = a % b;
            a = aux;
        }
        return a;
    }

    int main(){
        int n1 = 4;
        int n2 = 2;
        cout << mcd(n1,n2) << endl;
    }
    ```

*NOTA IMPORTANTE: ESTE CÓDIGO NO ESTÁ OPTIMIZADO, ES SOLO PARA QUE VEÁIS UN EJEMPLO.*

??? example "3. EsPrimer.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: a >= 2
    //post: devuelve true si el número es primo; si no lo es, devuelve false.
    bool isPrime(int a){
        if (a < 2){ // BASE CASE: if 'a' is less than 2, then it is not prime.
            return false;
        }
        int counter = 0;
        for (int i = 1; i <= a; i++){ // We check how many divisors does 'a' have.
            if (a % i == 0){
                counter++;
            }
        }
        if (counter > 2){ // If 'a' has more than 2 divisors, then it is not prime.
            return false;
        } else{
            return true;
        }
    }

    int main(){
        int n1;

        cout << "Enter an integer number: ";
        while (cin >> n1){
            cout << endl;

            if (isPrime(n1)){
                cout << n1 << " is prime." << endl;
            } else{
                cout << n1 << " is NOT prime." << endl;
            }

            cout << "Enter an integer number: ";
        }
    }
    ```

??? example "4. HiName.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: true
    //post: imprime en la consola un saludo a la persona.
    void sayHi(string name){
        cout << "Hi " << name << '!' << endl;
    }

    int main(){
        string name;

        cout << "What is your name? ";
        cin >> name;
        cout << endl;

        sayHi(name);
    }
    ```

??? example "5. Swap.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: true
    //post: intercambia los números.
    void swapNumbers(int &a, int &b){
        int aux = b;
        b = a;
        a = aux;
    }

    int main(){
        int a = 5;
        int b = 2;

        cout << "a: " << a << " b: " << b << endl;

        swapNumbers(a, b);
        cout << "a: " << a << " b: " << b << endl;
    }
    ```

**En este tema no habrá final.cpp ya que es puramente teórico.**
