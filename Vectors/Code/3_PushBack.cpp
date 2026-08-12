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
        // El vector anirà creixent automàticament: mida 1, mida 2, mida 3...
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
