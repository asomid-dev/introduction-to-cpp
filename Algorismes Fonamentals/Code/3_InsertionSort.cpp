#include <iostream>
#include <vector>
using namespace std;

//pre: v.size() > 1;
//post: retorna el vector 'v' ordenat de forma creixent.
void insertionSort(vector<int>& v){
    if (v.size() < 2) return; // if de protecció

    for (int i = 1; i < v.size(); i++){
        int j = i;
        int x = v[i];

        // Mentre no arribem a l'inici i l'element anterior sigui més gran que 'x'
        while (j > 0 && x < v[j-1]){
            v[j] = v[j-1]; // Desplacem cap a la dreta
            j--;
        }
        v[j] = x; // Inserim la carta al seu forat correcte
    }
}

int main() {
    vector<int> v = {64, 25, 12, 22, 11};

    cout << "Vector original: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    insertionSort(v);

    cout << "Vector ordenat:  ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
