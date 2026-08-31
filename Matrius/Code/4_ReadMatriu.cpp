#include <iostream>
#include <vector>
using namespace std;

int main() {
    int files, columnes;
    cin >> files >> columnes;
    vector<vector<int>> matriu(files, vector<int>(columnes));

    // Llegim els valors per files i columnes
    for (int i = 0; i < files; i++) {
        for (int j = 0; j < columnes; j++) {
            cin >> matriu[i][j];
        }
    }

    // Mostrem la matriu
    for (int i = 0; i < files; i++) {
        for (int j = 0; j < columnes; j++) {
            cout << matriu[i][j] << " ";
        }
        cout << endl;
    }
}