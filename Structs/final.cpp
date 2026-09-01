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
    cout << "Name:   " << a.name << endl;
    cout << "Level:  " << a.level << endl;
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
