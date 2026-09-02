# Vectors

## 1. Què és un vector?

Al tema anterior vam veure com els `structs` ens permeten agrupar diferents dades d'una sola entitat (com el nom i la nota d'un sol estudiant). Però, i si volem guardar les dades de 50 estudiants de cop sense haver de crear 50 variables diferents? Per això existeixen els **vectors**.

Un vector és una estructura de dades que ens permet emmagatzemar una llista o col·lecció d'elements del **mateix tipus** (tots enters, tots strings, o tots structs) de forma ordenada.

Imagina un vector com un moble amb molts calaixos. Cada calaix té una etiqueta amb un número (la posició o índex), i dins de cada calaix hi guardem un valor. 

> **⚠️ NOTA IMPORTANT:** A C++ (i a la majoria de llenguatges de programació), **es comença a comptar des del zero**. El primer element d'un vector està sempre a la posició 0, el segon a la posició 1, etc. Si un vector té 5 elements, la seva última posició és la 4.

---

## 2. Com declarar un vector

Per poder utilitzar vectors al nostre codi, primer de tot hem d'afegir la llibreria `#include <vector>` a dalt de tot de l'arxiu.

La sintaxi bàsica per crear-ne un és la següent:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Sintaxi: vector<tipus_de_dada> nom_del_vector(mida, valor_inicial);
    
    // Exemple 1: Vector de 5 enters, tots inicialitzats a 0 per defecte.
    vector<int> notes(5, 0); 
    
    // Exemple 2: Vector de 10 strings, inicialitzats buits.
    vector<string> paraules(10); 
    
    // Exemple 3: Vector buit (mida 0), que podrem fer créixer més endavant.
    vector<double> preus; 
    
    // Exemple 4: Vector predefinit per l'usuari.
    vector<char> lletres = {'H', 'o', 'l', 'a'};
}
```

---

## 3. Com accedir a una posició d'un vector

Després de declarar un vector, hem de saber com modificar i/o accedir a la informació continguda. 
Per fer-ho, utilitzem els claudàtors `[]` i hi posem a dins l'índex (la posició) on volem anar.

```cpp
vector<int> notes(3, 0); // Vector de 3 enters: [0, 0, 0]

// Modificar valors:
notes[0] = 8; // Canviem el primer calaix per un 8. Ara tenim: [8, 0, 0]
notes[1] = 5; // Canviem el segon calaix per un 5. Ara tenim: [8, 5, 0]

// Accedir per llegir:
cout << "La primera nota és un: " << notes[0] << endl;
```

**Recórrer un vector amb un bucle `for`:** Aquesta és l'operació matemàtica/lògica que faràs més sovint a PRO1. Utilitzem un bucle que començarà a la posició `0` per anar obrint els calaixos un per un, ja sigui per omplir-los de dades (`cin`) o per mostrar-les (`cout`).

```cpp
// Llegim 5 notes de la terminal i les guardem al vector
vector<int> notes(5);

for (int i = 0; i < 5; i++) {
    cin >> notes[i];
}
```

---

## 4. Mètodes dels vectors

Els vectors a C++ venen amb eines incorporades (anomenades mètodes) que ens faciliten moltíssim treballar-hi. Per cridar un mètode, simplement escrivim el nom del vector seguit d'un punt `.` i el nom de l'eina.

Els dos mètodes estrelles que utilitzaràs diàriament són:

### 1. `.size()`
Ens retorna la mida actual del vector (quants elements té). És **fonamental** posar-ho com a límit als bucles `for`. Així, si demà canvies la mida del vector, el bucle s'adapta automàticament i t'estalvies errors i sortides fora de límit.

```cpp
vector<int> notes(5);

// El bucle farà tantes voltes com gran sigui el vector (5 en aquest cas)
for (int i = 0; i < notes.size(); i++) { 
    cout << notes[i] << endl;
}
```

### 2. `.push_back(valor)`
Afegeix un nou element just al final del vector. Aquest mètode és genial perquè fa que el vector "creixi" automàticament de mida. És molt útil quan llegeixes una seqüència de dades però no saps quantes n'hi ha en total (per exemple, un bucle EOF), ja que pots començar amb un vector buit i anar-lo omplint.

```cpp
vector<int> parells; // Creem un vector buit (mida 0)

parells.push_back(2); // El vector creix. Ara és de mida 1 i conté: [2]
parells.push_back(4); // Ara és de mida 2 i conté: [2, 4]
parells.push_back(6); // Ara és de mida 3 i conté: [2, 4, 6]
```

---

## 5. Exemples

??? example "1. ParaulesAmbVectors.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        // Creem un vector de caràcters predefinit
        vector<char> letters = {'H', 'o', 'l', 'a'};

        cout << "Printing the vector letter by letter: ";

        // El recorrem exactament igual que qualsevol altre vector
        for (int i = 0; i < letters.size(); i++) {
            cout << letters[i];
        }

        cout << endl; // La sortida serà "Hola"
    }
    ```

En aquest exemple observem que un vector de `char`s i un `string` tenen coses similars; això és perquè un `string` és realment un vector de `char`s i podem accedir a una posició específica d'un `string`:

??? example "2. StringVector.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        string word = "Hola";

        // 1. Podem fer servir .size() per saber quantes lletres té
        cout << "The word has " << word.size() << " letters." << endl;

        cout << "Accessing specific positions:" << endl;

        // 2. Podem fer servir els claudàtors [] per llegir lletres soltes
        cout << "First letter (position 0): " << word[0] << endl;
        cout << "Last letter (position 3): " << word[3] << endl;

        cout << "Spelling with a for loop:" << endl;

        // 3. Podem recórrer l'string amb un bucle for tal com fem amb els vectors
        for (int i = 0; i < word.size(); i++) {
            cout << "- " << word[i] << endl;
        }
    }
    ```

??? example "3. PushBack.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        // 1. Creem un vector totalment buit (mida 0)
        vector<int> numbers;
        int n;

        cout << "Enter several numbers (press Ctrl+D to finish): " << endl;

        // 2. Anem llegint dades fins que no n'hi hagi més (EOF)
        while (cin >> n) {
            // A cada volta, afegim el nombre llegit al final del vector.
            numbers.push_back(n);
        }

        cout << endl;
        cout << "Reading finished!" << endl;

        // 3. Gràcies a .size(), sabem exactament quants elements hem guardat
        cout << "You have entered " << numbers.size() << " numbers in total." << endl;

        cout << "The stored numbers are: ";

        // 4. Recorrem el vector per demostrar que tot s'ha guardat en ordre
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
    ```

---

## 6. Vectors i Funcions (Molt Important)

Quan passem un vector a una funció, hem de tenir molta cura amb la memòria. Per defecte, C++ passa els paràmetres per **valor** (fa una còpia). Si el nostre vector té 1.000.000 d'elements, fer-ne una còpia cada vegada que cridem una funció farà que el programa vagi lentíssim o es bloquegi.

Per això, a C++ **ELS VECTORS SEMPRE ES PASSEN PER REFERÈNCIA**.

Tenim dues maneres de fer-ho segons què vulguem fer amb el vector dins la funció:

### 1. Volem modificar el vector (Referència normal)
Si la funció ha d'alterar les dades del vector original (per exemple, per ordenar-lo o afegir-hi coses), el passem per referència afegint un `&`.

```cpp
// Aquesta funció posa tots els elements del vector a 0
void resetejarVector(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = 0;
    }
}
```

### 2. Només volem llegir el vector (Referència constant)
Si només volem llegir la informació (per exemple, per sumar les notes, o per buscar un número), no volem fer còpies, però tampoc volem que la funció modifiqui el vector per error. En aquest cas, utilitzem `const` abans del tipus i l'`&` al final. Això es diu **pas per referència constant**.

```cpp
// Aquesta funció només llegeix el vector, està prohibida la modificació
int sumarElements(const vector<int>& v) {
    int suma = 0;
    for (int i = 0; i < v.size(); i++) {
        suma = suma + v[i];
    }
    return suma;
}
```

---

## 7. Exercici Final

Aquest exercici combina tot el que hem vist: crearem un sistema per guardar múltiples estudiants (`structs`) dins d'un `vector`, llegirem dades fins que l'usuari decideixi parar (amb un bucle EOF i `.push_back()`), i passarem aquest vector per referència a diverses funcions per llegir-ne i modificar-ne les dades.

??? example "final.cpp"

    ```cpp
    /*
     * Exercici Final
     * Exemple: Gestor de Notes Amb Structs, Vectors i Funcions.
     * Fet per: aso
     */

    #include <iostream>
    #include <vector>
    using namespace std;

    struct Student {
        string name;
        double grade;
    };

    // pre: cert
    // post: imprimeix els noms i les notes de tots els estudiants
    void printGrades(const vector<Student>& v) {
        for (int i = 0; i < v.size(); i++) {
            cout << "- " << v[i].name << ": " << v[i].grade << endl;
        }
    }

    // pre: el vector 'v' no està buit (v.size() > 0)
    // post: retorna la nota mitjana de la classe
    double calculateAverage(const vector<Student>& v) {
        double sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum = sum + v[i].grade;
        }
        return sum / v.size();
    }

    // pre: cert
    // post: suma 1 punt a totes les notes del vector, amb un màxim de 10
    void applyBonus(vector<Student>& v) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].grade < 10.0) {
                v[i].grade++;

                if (v[i].grade > 10.0) {
                    v[i].grade = 10.0;
                }
            }
        }
    }

    int main() {
        vector<Student> classList;
        Student current;

        // Ara l'explicació de la terminal deixa clar que és per a MÚLTIPLES estudiants
        cout << "--- STUDENT RECORD SYSTEM ---" << endl;
        cout << "Enter the students' names and grades." << endl;
        cout << "You can add as many as you want! (Press Ctrl+D to finish)" << endl;
        cout << "Example:" << endl;
        cout << "Frieren 10.0" << endl;
        cout << "Megumin 8.5" << endl;
        cout << "Mugi 9.2" << endl;
        cout << "-----------------------------------" << endl;

        // Llegim dades contínuament fins que l'usuari tanqui (Ctrl+D)
        while (cin >> current.name >> current.grade) {

            if (current.grade > 10.0 || current.grade < 0.0) {
                cout << "Error: Invalid grade for " << current.name << ". It must be between 0 and 10." << endl;
            } else {
                classList.push_back(current);
            }
        }

        cout << endl;

        if (classList.size() == 0) {
            cout << "No grades were entered." << endl;
            return 0;
        }

        // Confirmació visual de que s'han afegit diferents alumnes al vector
        cout << ">> Successfully loaded " << classList.size() << " students into the system. <<" << endl << endl;

        // 2. Pas per referència constant
        cout << "--- BEFORE THE BONUS ---" << endl;
        printGrades(classList);
        cout << "Class average: " << calculateAverage(classList) << endl;

        cout << endl;

        // 3. Pas per referència normal
        cout << "Applying +1 bonus to everyone..." << endl;
        applyBonus(classList);

        cout << endl;

        // 4. Comprovem els canvis
        cout << "--- AFTER THE BONUS ---" << endl;
        printGrades(classList);
        cout << "New class average: " << calculateAverage(classList) << endl;
    }
    ```
