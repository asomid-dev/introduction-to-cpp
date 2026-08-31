#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> matriu = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int files = matriu.size();
    int columnes = matriu[0].size();

    for (int i = 0; i < files; i++) {
        for (int j = 0; j < columnes; j++) {
            cout << matriu[i][j] << " ";
        }
        cout << endl;
    }
    // Sortida:
    // 1 2 3
    // 4 5 6
}