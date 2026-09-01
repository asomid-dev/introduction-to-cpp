#include <iostream>
#include <vector>
using namespace std;

// pre: v1 i v2 estan ordenats de forma creixent
// post: retorna un vector amb la fusió de v1 i v2 ordenat
vector<int> fusionSort(const vector<int>& v1, const vector<int>& v2) {
    int n = v1.size() + v2.size();
    vector<int> res(n);
    int i1 = 0, i2 = 0, k = 0;

    while (k < n) {
        // 1. Si v1 s'ha esgotat, agafem obligatòriament de v2
        if (i1 == v1.size()) {
            res[k] = v2[i2];
            i2++;
        }
        // 2. Si v2 s'ha esgotat, agafem obligatòriament de v1
        else if (i2 == v2.size()) {
            res[k] = v1[i1];
            i1++;
        }
        // 3. Si cap s'ha esgotat, comparem (amb el <= per evitar bucles infinits amb empats)
        else if (v1[i1] <= v2[i2]) {
            res[k] = v1[i1];
            i1++;
        }
        // 4. Si el de v2 és més petit
        else {
            res[k] = v2[i2];
            i2++;
        }

        k++; // k sempre avança passi el que passi
    }

    return res;
}

int main() {
    // Vectors de mides diferents per posar-ho a prova de veritat
    vector<int> v1 = {1, 3, 5, 7, 9};
    vector<int> v2 = {2, 4, 6, 8, 10, 12, 14};

    cout << "Vector 1: ";
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    cout << "Vector 2: ";
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;

    vector<int> resultat = fusionSort(v1, v2);

    cout << "Vector fusionat: ";
    for (int i = 0; i < resultat.size(); i++) {
        cout << resultat[i] << " ";
    }
    cout << endl;
}
