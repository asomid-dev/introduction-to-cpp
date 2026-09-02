# Funcions

## 1. Què és una funció?

Fins ara, tot el codi que hem escrit l'hem posat dins del `int main() { ... }`. Això funciona per a programes petits, però a mesura que el codi creix, tenir-ho tot en un sol bloc es torna un caos. 

Una **funció** és com un "miniprograma" dins del teu codi que s'encarrega de fer una tasca específica.

Per entendre com funciona una funció, ens hem d'imaginar una màquina de cafè. Nosaltres tenim una màquina de cafè i hem de posar-li aigua i el cafè en pols perquè ens retorni el cafè preparat per beure'l, una funció és exactament el mateix. Rep paràmetres (l'aigua i el cafè en pols) i retorna el resultat.

**Per què fem servir funcions?**
1. **Reutilització:** Si hem de calcular el mínim comú múltiple 10 vegades, no volem escriure el mateix codi 10 cops, l'escrivim 1 sol cop i cridem la funció.
2. **Ordre i llegibilitat:** Permet dividir un problema gran i complex en problemes petits i fàcils de resoldre.

---

## 2. Sintaxi d'una funció

La funció es defineix i es declara abans del `main()`. Té la següent estructura:

```cpp
//pre: 
//post: 
tipus_de_retorn nomFunció(tipus parametre1, tipus parametre2){
    // codi
    return resultat;
}
```

- **Pre:** Al pre posem què ha de complir el codi o els paràmetres perquè la funció s'executi correctament. En cas que funcioni sempre correctament, escrivim `true` o `cert`.
- **Post:** Explica què fa la funció, què retorna com a resultat o quines variables modifica.
- **Tipus de retorn:** Què ens retornarà la funció? Un `int`, `double`, `string`, `bool` o `char`?
- **Nom de la funció:** Un nom descriptiu (p.e. `calculArea`, `esParell`)
- **Paràmetres:** Les dades que necessita la funció per treballar, es posen entre els parèntesis. Si la funció no necessita dades, es deixen els parèntesis buits `()`.
- **return:** La paraula clau que retorna el resultat cap a fora de la funció. Un cop s'executa el `return`, la funció s'atura immediatament.

## Paràmetres

Els paràmetres es poden passar per:
- **Valor:** es fa una còpia temporal i no modifica res del `main`.
```cpp
//pre: ...
//post: ...
int socUnaFunc(int a, int b){ 
    // ...
}
```

- **Referència:** no fa cap còpia, és a dir, modifiquem el paràmetre rebut del `main`.
```cpp
void socUnaFunc(int &a){ 
    // si modifiquem 'a', també es modifica al main.
}
```

---

## 3. Procediments (void)

A vegades volem que una funció faci una acció concreta (com imprimir un missatge a la consola, dibuixar alguna cosa o modificar una variable externa) però **no necessitem que ens retorni cap valor**.

En aquests casos, en lloc de posar `int` o `string` al tipus de retorn, posem `void` ("buit").

Les funcions `void` no porten la instrucció `return resultat;`. (Com a molt, poden portar un `return;` buit per aturar la funció abans d'hora).

---

## 4. Exemples

??? example "1. SumaVariables.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: true
    //post: retorna la suma de dos elements enters.
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
    //post: retorna el mcd mitjançant l'algorisme d'Euclides
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

*NOTA IMPORTANT: AQUEST CODI NO ESTÀ OPTIMITZAT, ÉS NOMÉS PERQUÈ VEIEU UN EXEMPLE*

??? example "3. EsPrimer.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: a >= 2
    //post: retorna true si el nombre és primer, si no és primer, retorna false.
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
    //post: imprimeix a la consola una salutació a la persona.
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
    //post: intercanvia els nombres
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

**En aquest tema no hi haurà final.cpp ja que és només teòric.**
