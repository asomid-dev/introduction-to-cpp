# 6. Recursivitat

## 1. Què és la Recursivitat i la seva Sintaxi
Fins ara hem vist com repetir codi utilitzant bucles (`while` i `for`), però i si volem que una funció es repeteixi cridant-se a si mateixa?
Això es diu recursivitat, i serveix per resoldre problemes dividint-los en subproblemes més petits.

**L'analogia de les Nines Russes (Matrioixques):**
Imagina que tens una nina de fusta que a dins en té una de més petita, i aquesta una altra, i una altra. L'acció és sempre la mateixa: "obrir la nina". Només pares de fer-ho quan arribes a la nina més petitona de totes, que ja no es pot obrir. Això és exactament la recursivitat: una funció que fa una part del treball i es torna a cridar a si mateixa amb un problema més petit, fins a arribar a un punt on ja no es pot dividir més.

Per fer una funció recursiva a C++ l'estructura bàsica és la següent:

```cpp
void funcioRecursiva(int n){
    if (condicio_de_parada){
        // Cas base: el problema és tan petit que es resol directament (la nina més petita).
        // Aquí s'atura la recursivitat.
    } else {
        // Cas recursiu: fem una part de la feina i tornem a cridar 
        // la funció amb un valor modificat (obrim la nina i passem a la següent).
        funcioRecursiva(n - 1);
    }
}
/* Aquest esquema fa que la funció es cridi a si mateixa disminuint 'n' a cada pas.
Quan 'n' compleix la condició de parada, la funció para de cridar-se.
*/
```

## 2. Les dues regles d'or (Parts de la recursivitat)
TOTA funció recursiva que facis a PRO1 HA DE TENIR dues parts imprescindibles. Si te'n deixes una, la funció no pararà mai.

*   **El Cas Base:** És la condició de sortida. És el problema tan senzill que el podem resoldre directament sense cridar res més. Actua com el sentinella o l'EOF dels bucles.
*   **El Cas Recursiu:** És on tornem a cridar la funció a si mateixa, però passant-li un paràmetre que l'apropi al Cas Base (fent el problema més petit).

## 3. El perill de la Recursivitat: l'Stack Overflow
Què passa si t'oblides el Cas Base o si el Cas Recursiu no fa el problema més petit? L'error fatal anomenat **Stack Overflow** (desbordament de pila).

A C++, cada vegada que crides una funció, l'ordinador posa una "caixa" temporal amb les variables d'aquella crida en una zona de la memòria anomenada **Pila** (*Stack*). Quan la funció acaba, la caixa es treu. En la recursivitat, l'ordinador va apilant caixes una sobre l'altra abans de tancar les anteriors. 

Si la recursivitat és infinita (per exemple, cridar `compteEnrere(segons)` en lloc de `compteEnrere(segons - 1)`), l'ordinador apilarà caixes fins a tocar el límit de la memòria. Quan ja no hi caben més, la memòria es desborda i el programa mor instantàniament. Revisa sempre que les teves crides recursives s'apropin al Cas Base!

## 4. Exemples

### 1. CompteEnrere.cpp
```cpp
#include <iostream>
using namespace std;

// pre: segons >= 0
// post: imprimeix un compte enrere des de 'segons' fins a 0, acabant amb una explosió
void compteEnrere(int segons){
    if (segons == 0){ // CAS BASE: Quan arriba a 0, parem i imprimim el missatge final.
        cout << "EXPLOSION! 💥" << endl;
    } else { // CAS RECURSIU: Imprimim el número i cridem la funció amb 1 segon menys.
        cout << segons << "..." << endl;
        compteEnrere(segons - 1); 
    }
}

int main(){
    cout << "Megumin is preparing the spell:" << endl;
    compteEnrere(3);
}

/* Funcionament per compteEnrere(3): 
1. Imprimeix 3 i crida compteEnrere(2)
2. Imprimeix 2 i crida compteEnrere(1)
3. Imprimeix 1 i crida compteEnrere(0)
4. Entra al CAS BASE: imprimeix "EXPLOSION!" i no crida a ningú més.
*/
```

### 2. MCD.cpp
```cpp
#include <iostream>
using namespace std;

// pre: a >= 0, b >= 0
// post: retorna el Màxim Comú Divisor (MCD) d'a i b utilitzant l'algorisme d'Euclides
int mcd(int a, int b){
    if (b == 0){ // CAS BASE: Si el residu arriba a 0, el MCD és l'altre número.
        return a;
    } else { // CAS RECURSIU: Intercanviem els valors i passem el residu (a % b).
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

### 3. Factorial.cpp
```cpp
#include <iostream>
using namespace std;

// pre: n >= 0
// post: retorna el factorial de n (n!)
int factorial(int n){
    if (n == 0){ // CAS BASE: El factorial de 0 sempre és 1.
        return 1;
    } else { // CAS RECURSIU: Multipliquem 'n' pel factorial del número anterior.
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

### 4. Potencia.cpp
```cpp
#include <iostream>
using namespace std;

// pre: exp >= 0
// post: retorna la 'base' elevada a 'exp'
int power(int base, int exp){
    if (exp == 0){ // CAS BASE: Qualsevol número elevat a 0 sempre és 1.
        return 1;
    } else { // CAS RECURSIU: Multipliquem la base per la potència amb l'exponent restat en 1.
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
