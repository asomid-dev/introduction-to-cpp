#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<double>> matriu = {
        {1.1, 2.2},
        {3.3, 4.4}
    };

    double suma = 0;
    for (int i = 0; i < matriu.size(); i++) {
        for (int j = 0; j < matriu[i].size(); j++) {
            suma += matriu[i][j];
        }
    }
    cout << "La suma total és: " << suma << endl;
    // Sortida: La suma total és: 11
}