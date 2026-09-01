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
