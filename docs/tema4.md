# Structs (Registres)

## 1. Què és un Struct?

Fins ara, si volíem guardar la informació d'un estudiant (per exemple, el seu nom, la seva edat i la seva nota), necessitàvem tres variables separades:
```cpp
string name = "Frieren";
int age = 1250;
double grade = 10.0;
```
Això funciona per a una sola persona, però és un caos si hem de gestionar molts estudiants i moure aquestes dades entre funcions.

Un **struct** (o registre) ens permet crear el nostre propi "tipus de dada" agrupant diferents variables al seu interior, **encara que siguin de tipus diferents**. 

**L'analogia de la Fitxa o el DNI:**
Imagina un `struct` com una fitxa mèdica, un DNI o un contacte del mòbil. És una sola entitat (el contacte) que a dins conté diferents apartats o camps (nom, número de telèfon, correu).

---

## 2. Com definir un Struct

La definició d'un `struct` s'ha de posar **sempre a dalt de tot de l'arxiu**, abans de les funcions i del `main()`, perquè tot el programa el conegui.

```cpp
#include <iostream>
using namespace std;

// Definim el nostre nou tipus de dada
struct Student {
    string name;
    int age;
    double grade;
}; // IMPORTANT: NO et deixis AQUEST punt i coma! És obligatori.

int main() {
    // ...
}
```

---

## 3. Com declarar i accedir a un Struct

Un cop hem hem creat el "motlle" (el `struct`), ja podem crear variables d'aquest nou tipus dins del `main()` o de les funcions. 

Per accedir als diferents camps que hi ha a l'interior del `struct`, utilitzem un **punt (`.`)**.

```cpp
int main() {
    // Creem una variable de tipus 'Student' anomenada 'student1'
    Student student1;

    // Omplim les dades accedint als camps amb un punt
    student1.name = "Megumin";
    student1.age = 14;
    student1.grade = 9.2;

    // Podem llegir les dades de la mateixa manera
    cout << "L'alumne " << student1.name << " té un " << student1.grade << endl;
}
```

---

## 4. Llegir Structs de la terminal

També podem utilitzar `cin` per omplir directament els camps d'un `struct`. Només hem de recordar fer-ho camp per camp:

```cpp
int main() {
    Student student2;
    
    cout << "Enter the student's name, age and grade:" << endl;
    cin >> student2.name >> student2.age >> student2.grade;
    
    cout << "Dades guardades correctament!" << endl;
}
```

---

## 5. Structs i Funcions (Molt Important)

Els `structs` poden arribar a contenir molta informació (imagina un `struct` que guarda totes les dades d'un videojoc o l'expedient sencer d'un alumne). 

Si passem un `struct` a una funció per **valor**, C++ farà una còpia exacta de totes les seves variables cada cop que cridem la funció, gastant memòria innecessàriament i fent que el programa vagi lentíssim. Per tant, apliquem una regla d'or: **sempre els passem per referència**.

### 1. Pas per referència normal (Per modificar)
Si volem que la funció modifiqui alguna dada del `struct`, utilitzem l'`&`.

```cpp
// Aquesta funció suma un punt a la nota de l'estudiant
void applyBonus(Student& s) {
    s.grade = s.grade + 1.0;
    if (s.grade > 10.0) {
        s.grade = 10.0;
    }
}
```

### 2. Pas per referència constant (Només lectura)
Si només volem llegir les dades per imprimir-les o fer càlculs, però no volem modificar-les, utilitzem `const` i `&`. És la manera més eficient i segura, ja que evitem fer còpies però prohibim que la funció modifiqui les dades originals per error.

```cpp
// Aquesta funció només llegeix les dades i les imprimeix
void printStudent(const Student& s) {
    cout << "--- STUDENT INFO ---" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Grade: " << s.grade << endl;
}
```

---

## 6. Exercici Final
A continuació pots veure un exemple complet de com utilitzar els structs juntament amb les funcions aplicant el pas per referència i el control de límits.

??? example "final.cpp"

    ```cpp
    /*
     * Exercici Final
     * Exemple: Fitxa D'Aventurer Amb Structs i Funcions (Amb Límits).
     * Fet per: aso
     */

    #include <iostream>
    using namespace std;

    // Definim l'struct a dalt de tot perquè les funcions el puguin conèixer
    struct Adventurer {
        string name;
        int level;
        double health;
    };

    // pre: cert
    // post: llegeix les dades des de la terminal i les guarda a l'struct,
    // assegurant-se que els valors tinguin sentit.
    void readAdventurer(Adventurer& a) {
        cout << "Enter the adventurer's name, level (1-100) and health (max 9999):" << endl;
        cout << "Example: Frieren 99 1500.5" << endl;

        cin >> a.name >> a.level >> a.health;

        // Control d'errors: repetim la lectura fins que les dades siguin vàlides
        while (a.level < 1 || a.level > 100 || a.health <= 0 || a.health > 9999.0) {
            cout << "Error: Invalid stats for " << a.name << ". Level must be 1-100 and Health 1-9999." << endl;
            cout << "Please enter the data again:" << endl;
            cin >> a.name >> a.level >> a.health;
        }
    }

    // pre: cert
    // post: imprimeix l'estat actual de l'aventurer
    void printAdventurer(const Adventurer& a) {
        cout << "--- ADVENTURER STATUS ---" << endl;
        cout << "Name:    " << a.name << endl;
        cout << "Level:   " << a.level << endl;
        cout << "Health: " << a.health << " HP" << endl;
    }

    // pre: cert
    // post: apuja el nivell de l'aventurer en 1 i li augmenta la salut, respectant els límits
    void levelUp(Adventurer& a) {
        if (a.level >= 100) {
            cout << ">> " << a.name << " is already at maximum level! <<" << endl;
        } else {
            a.level++; // Pugem 1 nivell
            a.health = a.health + 50.0; // Donem 50 punts de vida extra

            // Ens assegurem de no sobrepassar la vida màxima per la bonificació
            if (a.health > 9999.0) {
                a.health = 9999.0;
            }

            cout << ">> " << a.name << " leveled up to level " << a.level << "! <<" << endl;
        }
    }

    int main() {
        Adventurer hero; // Declarem la nostra variable del nou tipus struct

        // 1. Emplenem les dades (Modificació) amb el filtre de límits activat
        readAdventurer(hero);
        cout << endl;

        // 2. Imprimim la fitxa (Lectura)
        printAdventurer(hero);
        cout << endl;

        // 3. Pugem de nivell el personatge (Modificació)
        levelUp(hero);
        cout << endl;

        // 4. Tornem a imprimir per comprovar els canvis (Lectura)
        printAdventurer(hero);
    }
    ```
