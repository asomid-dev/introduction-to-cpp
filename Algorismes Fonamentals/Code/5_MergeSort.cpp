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
        if (i1 == v1.size()) {
            res[k] = v2[i2];
            i2++;
        } else if (i2 == v2.size()) {
            res[k] = v1[i1];
            i1++;
        } else if (v1[i1] <= v2[i2]) {
            res[k] = v1[i1];
            i1++;
        } else {
            res[k] = v2[i2];
            i2++;
        }
        k++;
    }
    return res;
}

// pre: cert
// post: retorna el vector 'v' ordenat de forma creixent
vector<int> mergeSort(const vector<int>& v) {
    // CAS BASE: Un vector buit o d'1 element ja està ordenat
    if (v.size() <= 1) {
        return v;
    }

    // DIVISIÓ: Calculem la meitat
    int mid = v.size() / 2;

    // Creem els dos sub-vectors (esquerra i dreta)
    vector<int> left;
    vector<int> right;

    for (int i = 0; i < mid; i++) left.push_back(v[i]);
    for (int i = mid; i < v.size(); i++) right.push_back(v[i]);

    // RECURSIVITAT: Ordenem cadascuna de les meitats
    vector<int> sorted_left = mergeSort(left);
    vector<int> sorted_right = mergeSort(right);

    // FUSIÓ: Tornem a ajuntar les parts ja ordenades
    return fusionSort(sorted_left, sorted_right);
}

int main() {
    vector<int> v = {38, 27, 43, 3, 9, 82, 10};

    cout << "Vector original: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // Cridem al mergeSort complet
    vector<int> resultat = mergeSort(v);

    cout << "Vector ordenat:  ";
    for (int i = 0; i < resultat.size(); i++) {
        cout << resultat[i] << " ";
    }
    cout << endl;
}
