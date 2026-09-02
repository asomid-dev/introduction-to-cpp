# Iteracions (Bucles)

## 1. Sintaxi d'un bucle
Fins ara hem vist com fer un codi que funciona només un cop l'executem, però i si volem que el mateix fragment es repeteixi tota l'estona fins que es trobi una condició per parar d'executar-se?
Això es diu bucle, i serveix per iterar un codi múltiples cops. 
Per fer un bucle a C++ tenim dues formes:

```cpp
while (condition){
    // ...
}
```

```cpp
for (content) // a content podeu posar:

for (int i = 0; i < 10; i++){ 
    // ...
}
/* Aquest bucle fa que una variable "i" temporal inicialitzada a 0 iteri tants cops mentre sigui menor a 10. 
Funcionament: i = 0, comparació, executa codi, fa la suma.
*/

for (int i = 10; i > 0; i--){ // El mateix que l'anterior però al revés.
    // ...
}

// si 'i' ja ha estat declarada anteriorment, podeu ometre la declaració de la variable:

// Exemple 1:
for (i = 0; ...){

}

// Exemple 2:
int i = 5;
for (; i < 10; ...){

}
```

---

## 2. Tipus de While
Tenim 3 tipus de while CIRCUMSTANCIALS per PRO1.

*   **While amb sentinella (o de cerca):** Farà iteracions fins que trobi un caràcter o element per parar.
*   **While fins EOF (End Of File):** Farà iteracions mentre rep informació per la consola o un arxiu; quan a la consola s'executa CTRL + D o l'arxiu es queda sense dades, el bucle s'aturarà.
*   **While amb nombre d'elements:** El while funcionarà sempre que la condició del nombre d'elements (comptador) sigui correcta. 

Exemples:

??? example "1. WhileSentinella.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main(){
        char ch;
        string result = "";

        cin >> ch;
        while (ch != '0'){ // Volem inserir chars a un string fins que un char sigui '0'.
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

        while (cin >> n){ // Fins que no fem CTRL+D a consola, el codi no pararà.
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

## 3. Exercici Final
Per consolidar l'ús dels bucles (tant `while` com `for`), aquí tens un programa complet que genera muntanyes d'asteriscs a la consola segons l'alçada indicada. L'execució es manté fins que forcem el final d'arxiu (EOF).

??? example "final.cpp"

    ```cpp
    /*
     * Exercici Final
     * Exemple: Construir Muntanyes on el Pic és de N Altitud.
     * Fet per: aso
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
                // Pujada de la muntanya
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j <= i; j++) {
                        cout << '*';
                    }
                    cout << endl;
                }

                // Quan i = n, la muntanya ha de tornar a baixar. Per tant comencem a n - 1.
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
