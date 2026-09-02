# Algorismes Fonamentals (Cerca i Ordenació)

## 1. Què són els Algorismes Fonamentals?

Fins ara hem après les peces bàsiques de C++ (bucles, funcions, vectors, structs...). Ara que ja sabem construir eines, toca aprendre **com utilitzar-les per a resoldre els problemes més clàssics de la informàtica**: buscar informació i ordenar-la.

Per entendre la importància d'això, imagina't que tens un diccionari amb 10.000 pàgines completament desordenades i has de buscar la paraula "Recursivitat". Si vas mirant pàgina per pàgina (cerca lineal), pots trigar hores. En canvi, si el diccionari està ordenat alfabèticament, pots obrir-lo per la meitat i anar descartant meitats ràpidament fins a trobar-la en segons.

**Per què estudiem aquests algorismes a PRO1?**
1. **Eficiència:** Un mal algorisme pot fer que el teu programa trigui hores a resoldre un problema que un bon algorisme resol en mil·lisegons (i el Jutge de la FIB et donarà un *Time Limit Exceeded*).
2. **Fonaments:** Entendre com ordenar (Sort) i com buscar (Search) és la base per a entendre estructures de dades molt més complexes en el futur (PRO2 i EDA).

---

## 2. La màgia de C++: `std::sort`

Abans de començar a picar codi per ordenar vectors manualment, has de saber un secret: C++ ja té una funció increïblement ràpida i optimitzada que ho fa per tu. Es diu `std::sort` i forma part de la llibreria `<algorithm>`.

A la vida real (i en problemes on no t'obliguin a fer-ho a mà), sempre utilitzaràs aquesta funció per ordenar vectors, ja que està programada amb un algorisme híbrid molt avançat (Introsort) que és molt més ràpid que els que veurem aquí.

### Com s'utilitza amb tipus bàsics?
Si tens un vector d'enters o de strings, C++ ja sap com comparar-los (sap que 2 és menor que 5, o que la 'A' va abans que la 'B'):
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // OBLIGATORI per a fer servir el sort()
using namespace std;

int main() {
    vector<int> v = {5, 2, 9, 1, 5, 6};

    // Ordenem el vector de menor a major (per defecte)
    // v.begin() indica l'inici, i v.end() el final del vector.
    sort(v.begin(), v.end()); 

    // Ara 'v' és: {1, 2, 5, 5, 6, 9}
}
```

### Com ordenar un `Struct` personalitzat? (La funció `cond`)
Què passa si tenim un vector d'aventurers (un `struct`) i volem ordenar-los? C++ no sap si vols ordenar-los per nivell, per nom o per edat. 
Li hem de donar nosaltres les instruccions creant una funció booleana (normalment anomenada `cond` o `cmp`) que li digui **qui ha d'anar abans**. Aquesta funció rep dos elements per referència constant i retorna `true` si el primer element ha d'anar abans que el segon.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Adventurer {
    string name;
    int level;
};

// pre: cert
// post: retorna true si l'aventurer 'a' ha d'anar ABANS que 'b' al vector ordenat
bool cond(const Adventurer& a, const Adventurer& b) {
    // 1r Criteri: Volem ordenar per nivell de MAJOR a MENOR
    if (a.level != b.level) {
        return a.level > b.level;
    }
    // 2n Criteri (Cas d'empat): Si tenen el mateix nivell, ordenem per nom alfabèticament
    return a.name < b.name;
}

int main() {
    vector<Adventurer> party = {
        {"Megumin", 45},
        {"Frieren", 100},
        {"Retzel", 50},
        {"Sigrid", 45} // Empata en nivell amb Megumin
    };

    // Li passem la nostra funció 'cond' com a tercer paràmetre!
    sort(party.begin(), party.end(), cond);

    /* L'ordre final serà:
       1. Frieren (100)
       2. Retzel (50)
       3. Megumin (45) -> Va abans que Sigrid perquè la 'M' va abans que la 'S'
       4. Sigrid (45)
    */
}
```

*I llavors... per què hem d'aprendre a fer els algorismes a mà?* Perquè a PRO1 t'avaluaran per veure si **entens la lògica interna**. Així que ens arremanguem i anem a veure com funcionen per dins!

---

## 3. Tipus d'Algorismes (El que veurem)

La **Cerca Dicotòmica (Binary Search)** serveix per buscar si hi ha un element dins d'un vector **prèviament ordenat**. Aquest algorisme és molt important, ja que el seu cost és exponencialment menor en comparació a buscar un element des de l'inici del vector fins al final (cerca lineal).

**Per què és tan eficient?**
Perquè a cada pas dividim el problema per la meitat. Anirem a la posició central i mirarem cap a quina meitat hauria d'estar l'element que estem buscant (descartant automàticament tota la resta). Farem aquesta divisió els cops que siguin necessaris fins a trobar l'element. Si els límits es creuen vol dir que no hi és, i retornarem `-1`.

??? example "1. BinarySearch.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    //pre: v està ordenat de forma creixent, 0 <= left, right < v.size().
    //post: retorna la posició de 'x' dins de 'v'. Retorna -1 si 'x' no hi és.
    int binarySearch(const vector<int>& v, int x, int left, int right){
        // CAS BASE 1: Els límits s'han creuat (l'element no hi és).
        if (left > right) return -1;

        int mid = (left + right) / 2;
        // CAS RECURSIU: 'x' està cap a la dreta.
        if (v[mid] < x) { return binarySearch(v, x, mid + 1, right); }
        // CAS RECURSIU: 'x' està cap a l'esquerra.
        if (v[mid] > x) { return binarySearch(v, x, left, mid - 1); }

        // CAS BASE 2: L'hem trobat al mig (v[mid] == x).
        return mid;
    }

    int main(){
        vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        int x = 0;
        cout << "Which number's position do you want to find? ";
        cin >> x;

        int pos = binarySearch(v, x, 0, v.size() - 1);

        if (pos != -1){
            cout << "\nYour number is located at index " << pos << '.' << endl;
        } else{
            cout << "\nYour number is NOT in the vector." << endl;
        }
    }
    ```

Per entendre què fa el Selection Sort, ens hem d'imaginar que tenim unes cartes i les volem ordenar sobre la taula. 

De totes les cartes, busquem quina és la més petita i la intercanviem amb la que està a la primera posició. Un cop tenim la primera assegurada, busquem quina és la més petita de la resta i la intercanviem amb la que està a la segona posició. Fem això contínuament fins que tot el vector queda ordenat.

??? example "2. SelectionSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    //pre: v.size() > 0.
    //post: retorna el vector 'v' ordenat de forma creixent.
    void selectionSort(vector<int>& v){
        if (v.empty()) return; // AQUEST ÉS UN IF DE PROTECCIÓ PER SI ES SALTEN LA PRECONDICIÓ DE LA FUNCIÓ.

        for (int i = 0; i < v.size(); i++){
            int lowest = i;
            for (int j = i+1; j < v.size(); j++){
                if (v[j] < v[lowest]){
                    lowest = j;
                }
            }

            if (lowest != i){ // Hi ha un nombre més petit, fem el swap
                int aux = v[i];
                v[i] = v[lowest];
                v[lowest] = aux;
            }
        }
    }

    int main() {
        vector<int> v = {64, 25, 12, 22, 11};

        cout << "Vector original: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        selectionSort(v);

        cout << "Vector ordenat:  ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    ```

Aquest algorisme funciona exactament igual que quan ordenem les cartes de pòquer a la nostra mà.

Suposem que la primera carta ja està ordenada. Agafem la segona carta (la guardem a la variable `x`) i la comparem amb la de la seva esquerra. Si és més petita, desplacem la carta gran cap a la dreta i continuem mirant cap enrere fins a trobar el seu lloc exacte per "inserir-la". Repetim això amb totes les cartes d'esquerra a dreta.

Aquesta versió d'aquí és la **versió optimitzada**, ja que en lloc de fer *swaps* sencers contínuament, guardem el valor a buscar (`x`), anem desplaçant cap a la dreta els valors grans (`v[j] = v[j-1]`), i al final de tot deixem la `x` al forat lliure que ha quedat.

??? example "3. InsertionSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    //pre: v.size() > 1;
    //post: retorna el vector 'v' ordenat de forma creixent.
    void insertionSort(vector<int>& v){
        if (v.size() < 2) return; // if de protecció

        for (int i = 1; i < v.size(); i++){
            int j = i;
            int x = v[i];

            // Mentre no arribem a l'inici i l'element anterior sigui més gran que 'x'
            while (j > 0 && x < v[j-1]){
                v[j] = v[j-1]; // Desplacem cap a la dreta
                j--;
            }
            v[j] = x; // Inserim la carta al seu forat correcte
        }
    }

    int main() {
        vector<int> v = {64, 25, 12, 22, 11};

        cout << "Vector original: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        insertionSort(v);

        cout << "Vector ordenat:  ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    ```

La funció de fusió no és un algorisme d'ordenació complert per a qualsevol vector desordenat, sinó una **eina específica** dissenyada exclusivament per a fusionar dos vectors que **ja estan prèviament ordenats** en un de sol.

Mitjançant un sol bucle molt intel·ligent i tres índexs (`i1`, `i2` i `k`), el programa va decidint quin dels dos vectors té el número més petit en cada moment per anar-lo col·locant al vector resultant. Comprovem primer si un dels dos vectors ja s'ha esgotat per evitar llegir memòria invàlida (Segmentation Fault). Aquesta funció és la peça central i fonamental que fa possible la màgia del *Merge Sort*.

??? example "4. FusionSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    // pre: v1 i v2 estan ordenats de forma creixent
    // post: retorna un vector amb la fusió de v1 i v2 ordenat
    vector<int> fusionSort(const vector<int>& v1, const vector<int>& v2) {
        int n = v1.size() + v2.size();
        vector<int> res(n);
        int i1 = 0, i2 = 0, k = 0;

        while (k < n) {
            // 1. Si v1 s'ha esgotat, agafem obligatòriament de v2
            if (i1 == v1.size()) {
                res[k] = v2[i2];
                i2++;
            }
            // 2. Si v2 s'ha esgotat, agafem obligatòriament de v1
            else if (i2 == v2.size()) {
                res[k] = v1[i1];
                i1++;
            }
            // 3. Si cap s'ha esgotat, comparem (amb el <= per evitar bucles infinits amb empats)
            else if (v1[i1] <= v2[i2]) {
                res[k] = v1[i1];
                i1++;
            }
            // 4. Si el de v2 és més petit
            else {
                res[k] = v2[i2];
                i2++;
            }

            k++; // k sempre avança passi el que passi
        }

        return res;
    }

    int main() {
        // Vectors de mides diferents per posar-ho a prova de veritat
        vector<int> v1 = {1, 3, 5, 7, 9};
        vector<int> v2 = {2, 4, 6, 8, 10, 12, 14};

        cout << "Vector 1: ";
        for (int i = 0; i < v1.size(); i++) {
            cout << v1[i] << " ";
        }
        cout << endl;

        cout << "Vector 2: ";
        for (int i = 0; i < v2.size(); i++) {
            cout << v2[i] << " ";
        }
        cout << endl;

        vector<int> resultat = fusionSort(v1, v2);

        cout << "Vector fusionat: ";
        for (int i = 0; i < resultat.size(); i++) {
            cout << resultat[i] << " ";
        }
        cout << endl;
    }
    ```

Què passa si volem ordenar fent servir la nostra funció de fusió, però el vector original està completament desordenat? Si li passem directament a `fusionSort` el resultat serà invàlid. Per resoldre això utilitzem l'algorisme de **Merge Sort** (Divideix i Venceràs).

**Què fa el Merge Sort?** 
Bàsicament, divideix el vector per la meitat generant dos vectors més petits (`left` i `right`). Després, divideix aquestes meitats contínuament utilitzant recursivitat fins que arribem a vectors de mida 1. 
Com que per definició un vector d'1 sol element **ja està ordenat**, la nostra funció `fusionSort` pot començar a ajuntar-los de dos en dos cap amunt, reconstruint i ordenant tot el vector original amb una velocitat espectacular.

El Merge Sort ens ensenya exactament la màgia de la recursivitat i com d'important és per al dia a dia a la programació.

??? example "5. MergeSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    // pre: v1 i v2 estan ordenats de forma creixent
    // post: retorna un vector amb la fusió de v1 i v2 ordenat
    vector<int> fusionSort(const vector<int>& v1, const vector<int>& v2) {
        int n = v1.size() + v2.size();
        vector<int> res(n);
        int i1 = 0, i2 = 0, k = 0;

        while (k < n) {
            if (i1 == v1.size()) {
                res[k] = v2[i2];
                i2++;
            } else if (i2 == v2.size()) {
                res[k] = v1[i1];
                i1++;
            } else if (v1[i1] <= v2[i2]) {
                res[k] = v1[i1];
                i1++;
            } else {
                res[k] = v2[i2];
                i2++;
            }
            k++;
        }
        return res;
    }

    // pre: cert
    // post: retorna el vector 'v' ordenat de forma creixent
    vector<int> mergeSort(const vector<int>& v) {
        // CAS BASE: Un vector buit o d'1 element ja està ordenat
        if (v.size() <= 1) {
            return v;
        }

        // DIVISIÓ: Calculem la meitat
        int mid = v.size() / 2;

        // Creem els dos sub-vectors (esquerra i dreta)
        vector<int> left;
        vector<int> right;

        for (int i = 0; i < mid; i++) left.push_back(v[i]);
        for (int i = mid; i < v.size(); i++) right.push_back(v[i]);

        // RECURSIVITAT: Ordenem cadascuna de les meitats
        vector<int> sorted_left = mergeSort(left);
        vector<int> sorted_right = mergeSort(right);

        // FUSIÓ: Tornem a ajuntar les parts ja ordenades
        return fusionSort(sorted_left, sorted_right);
    }

    int main() {
        vector<int> v = {38, 27, 43, 3, 9, 82, 10};

        cout << "Vector original: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        // Cridem al mergeSort complet
        vector<int> resultat = mergeSort(v);

        cout << "Vector ordenat:  ";
        for (int i = 0; i < resultat.size(); i++) {
            cout << resultat[i] << " ";
        }
        cout << endl;
    }
    ```

---

## 4. Exercici Final

A continuació veuràs com combinar l'ordenació i la cerca per resoldre un problema complet on cal estructurar dades i buscar-les de manera eficient.

??? example "final.cpp"

    ```cpp
    /*
     * Exercici Final
     * Exemple: Sistema de Registre i Cerca de Jugadors (Binary Search).
     * Fet per: aso
     */

    #include <iostream>
    #include <vector>
    #include <algorithm>
    using namespace std;

    struct Player {
        int id;
        string name;
        int score;
    };

    // pre: cert
    // post: retorna true si el jugador 'a' té un ID estrictament menor que el jugador 'b'
    bool cond(const Player& a, const Player& b) {
        return a.id < b.id;
    }

    // pre: el vector 'v' està ordenat per ID de forma creixent, 0 <= left, right < v.size()
    // post: retorna la posició del jugador amb l'id_buscat, o -1 si no existeix
    int binarySearch(const vector<Player>& v, int x, int left, int right) {
        if (left > right) return -1;
        int mid = (left + right) / 2;
        if (v[mid].id < x) return binarySearch(v, x, mid + 1, right);
        if (v[mid].id > x) return binarySearch(v, x, left, mid - 1);
        return mid;
    }

    int main() {
        vector<Player> tournament;
        Player p;

        cout << "Registration phase, enter a player (format: ID PlayerName Score), for closing this phase, enter -1:" << endl;

            cin >> p.id;
            while (p.id != -1) {
                cin >> p.name >> p.score;
                tournament.push_back(p);

                cout << "\nEnter another player:" << endl;
                cin >> p.id;
            }

        sort(tournament.begin(), tournament.end(), cond);

        if (tournament.empty()){
            cout << "\nNo player was registered. Ending program." << endl;
        } else{
            cout << "- - - - - - - - - - - - - - - -\n";
            cout << "Query phase. Enter ID to search (Ctrl + D to exit):\n";

            int id;

            while (cin >> id) {

                int pos = binarySearch(tournament, id, 0, tournament.size() - 1);

                if (pos == -1){
                    cout << "Error: Player not registered" << endl;
                } else{
                    cout << "The player " << tournament[pos].name << " has " << tournament[pos].score << " points." << endl;
                }
                cout << "\nEnter ID to search (Ctrl + D to exit):\n";
            }
        }
    }
    ```
