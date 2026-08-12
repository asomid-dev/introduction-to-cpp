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
