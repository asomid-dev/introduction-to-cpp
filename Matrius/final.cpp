/*
* Exercici Final
* Exemple: Troba la Submatriu Quadrada de Suma Màxima
* Fet per: Uri
*/

/*
Aquest programa llegeix una matriu d'enters positius de f files i c columnes (primer l'usuari entra f i c,
després els valors de la matriu), i després llegeix un enter positiu k (1 <= k <= min(f,c)).
El programa cerca dins la matriu la submatriu quadrada de mida k x k la suma dels elements
de la qual sigui màxima. Imprimeix:
- El valor d'aquesta suma màxima.
- La submatriu k x k corresponent (en la mateixa disposició que l'original), corresponent a la primera (de dalt a baix, esquerra a dreta) amb suma màxima que trobi, en cas d'empat.

Exemple:
Input:
4 5
1 2 0 3 4
0 6 3 4 1
2 4 5 2 3
1 0 1 1 1
3

Output:
Suma màxima: 29
Submatriu:
6 3 4
4 5 2
0 1 1
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int f, c;
    cin >> f >> c; // Llegim files i columnes
    // Llegim la matriu d'enters
    vector<vector<int>> matriu(f, vector<int>(c));
    for (int i = 0; i < f; ++i)
        for (int j = 0; j < c; ++j)
            cin >> matriu[i][j];
    
    int k;
    cin >> k; // Llegim la mida de la submatriu quadrada

    // Variables per guardar la suma màxima i la posició de la millor submatriu
    int suma_max = 0; // La suma màxima trobada fins ara (mínim 0)
    int millor_i = 0, millor_j = 0; // Coordenades de l'inici de la millor submatriu

    // Recorrem totes les submatrius possibles de mida k x k
    for (int i = 0; i <= f - k; ++i) {
        for (int j = 0; j <= c - k; ++j) {
            int suma = 0; // Suma dels elements de la submatriu actual
            // Calculem la suma d'aquesta submatriu
            for (int a = 0; a < k; ++a)
                for (int b = 0; b < k; ++b)
                    suma += matriu[i + a][j + b];
            // Si la suma d'aquesta submatriu és millor, la guardem
            if (suma > suma_max) {
                suma_max = suma;
                millor_i = i;
                millor_j = j;
            }
        }
    }

    // Imprimim el resultat
    cout << "Suma màxima: " << suma_max << endl;
    cout << "Submatriu:" << endl;
    // Mostrem la submatriu de suma màxima
    for (int a = 0; a < k; ++a) {
        for (int b = 0; b < k; ++b)
            cout << matriu[millor_i + a][millor_j + b] << " ";
        cout << endl;
    }
}