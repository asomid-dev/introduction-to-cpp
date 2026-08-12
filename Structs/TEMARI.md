# 4. Structs (Registres)

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

## 3. Com declarar i accedir a un Struct

Un cop hem creat el "motlle" (el `struct`), ja podem crear variables d'aquest nou tipus dins del `main()` o de les funcions. 

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

> 📁 **Nota sobre els exemples pràctics:** 
> A diferència de la resta de temes d'aquest repositori, en aquest apartat **no hi ha una carpeta `Code`** amb múltiples miniexemples. Com que l'ús dels *structs* és un concepte que s'entén millor quan s'aplica sencer, tota la pràctica d'aquest tema la trobaràs integrada directament a l'arxiu **`final.cpp`**. Obre'l per veure un exercici complet que demostra exactament com llegir, modificar i imprimir *structs* utilitzant funcions!