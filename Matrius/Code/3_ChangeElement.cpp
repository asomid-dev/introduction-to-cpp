#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<char>> lletres = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'}
    };

    lletres[0][1] = 'z'; // Canviem la 'b' per una 'z'

    for (int i = 0; i < lletres.size(); i++) {
        for (int j = 0; j < lletres[i].size(); j++) {
            cout << lletres[i][j] << " ";
        }
        cout << endl;
    }
    // Sortida:
    // a z c
    // d e f
}