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
