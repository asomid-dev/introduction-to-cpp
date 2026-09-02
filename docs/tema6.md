# Recursivitat

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

---

## 2. Les dues regles d'or (Parts de la recursivitat)
TOTA funció recursiva que facis a PRO1 HA DE TENIR dues parts imprescindibles. Si te'n deixes una, la funció no pararà mai.

*   **El Cas Base:** És la condició de sortida. És el problema tan senzill que el pel podem resoldre directament sense cridar res més. Actua com el sentinella o l'EOF dels bucles.
*   **El Cas Recursiu:** És on tornem a cridar la funció a si mateixa, però passant-li un paràmetre que l'apropi al Cas Base (fent el problema més petit).

---

## 3. El perill de la Recursivitat: l'Stack Overflow
Què passa si t'oblides el Cas Base o si el Cas Recursiu no fa el problema més petit? L'error fatal anomenat **Stack Overflow** (desbordament de pila).

A C++, cada vegada que crides una funció, l'ordinador posa una "caixa" temporal amb les variables d'aquella crida en una zona de la memòria anomenada **Pila** (*Stack*). Quan la funció acaba, la caixa es treu. En la recursivitat, l'ordinador va apilant caixes una sobre l'altra abans de tancar les anteriors. 

Si la recursivitat és infinita (per exemple, cridar `compteEnrere(segons)` en lloc de `compteEnrere(segons - 1)`), l'ordinador apilarà caixes fins a tocar el límit de la memòria. Quan ja no hi caben més, la memòria es desborda i el programa mor instantàniament. Revisa sempre que les teves crides recursives s'apropin al Cas Base!

---

## 4. Exemples

??? example "1. CompteEnrere.cpp"

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

??? example "2. MCD.cpp"

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

??? example "3. Factorial.cpp"

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

??? example "4. Potencia.cpp"

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

---

## 5. Exercici Final

Aquest exercici combina la recursivitat amb elements que ja hem vist anteriorment, introduint un concepte nou i molt útil: l'`std::pair`, que ens permet retornar dues dades diferents alhora des d'una mateixa funció.

??? example "final.cpp"

    ```cpp
    /*
     * Exercici Final
     * Exemple: Registre Amb Sentinella i Cerca Recursiva Retornant un Pair.
     * Fet per: aso
     *
     * ----------------------------------------------------------------------
     * 💡 QUÈ ÉS UN PAIR?
     * Un std::pair és una eina de C++ que ens permet agrupar dos valors
     * (poden ser de tipus iguals o diferents) en una sola variable.
     * Imagina't que és un "mini-struct" prefabricat que sempre té
     * exactament dos camps: el primer es diu '.first' i el segon '.second'.
     *
     * És súper útil quan una funció necessita RETORNAR DUES COSES alhora.
     * En aquest cas, la nostra funció de cerca ha de respondre dues preguntes:
     * 1. L'has trobat? -> Un booleà (true/false) que guardarem a .first
     * 2. A quina posició? -> Un enter (l'índex) que guardarem a .second
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
    // post: retorna {true, índex} si el troba, o {false, -1} si no hi és.
    pair<bool, int> recursiveSearch(const vector<Adventurer>& v, string target, int index) {
        // 1. CAS BASE 1: Hem arribat al final del vector (fora de límits) i no l'hem trobat
        if (index == v.size()) {
            return {false, -1};
        }
        // 2. CAS BASE 2: L'hem trobat a la posició actual!
        else if (v[index].name == target) {
            return {true, index};
        }
        // 3. CAS RECURSIU: No és aquí, així que busquem a la següent posició (index + 1)
        else {
            return recursiveSearch(v, target, index + 1);
        }
    }

    int main() {
        vector<Adventurer> party;
        string newName;
        int newLevel;

        // --- FASE 1: REGISTRE (Bucle amb Sentinella) ---
        cout << "--- ADVENTURER GUILD REGISTRATION ---" << endl;
        cout << "Enter the adventurer's name and level (Type 'END' as name to finish):" << endl;

        // Llegim el nom. Si no és "END", llegim també el nivell i l'afegim al vector
        cin >> newName;
        while (newName != "END") {
            cin >> newLevel;
            party.push_back({newName, newLevel});

            cout << "> " << newName << " registered successfully!" << endl;
            cin >> newName; // Llegim el següent nom per veure si és el sentinella
        }

        cout << endl << ">> Registration closed! Total members: " << party.size() << " <<" << endl << endl;

        // --- FASE 2: CERCA (Bucle fins EOF) ---
        cout << "--- GUILD DATABASE SEARCH ---" << endl;
        cout << "Who are you looking for? (Press Ctrl+D to exit)" << endl;

        string targetName;
        while (cin >> targetName) {

            // Cridem la funció recursiva començant des de la posició 0
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
