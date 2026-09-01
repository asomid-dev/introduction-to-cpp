#include <iostream>
#include <vector>
using namespace std;

//pre: v.size() > 0.
//post: retorna el vector 'v' ordenat de forma creixent.
void selectionSort(vector<int>& v){
    if (v.empty()) return; // AQUEST ÉS UN IF DE PROTECCIÓ PER SI ES SALTEN LA PRECONDICIÓ DE LA FUNCIÓ.

    for (int i = 0; i < v.size(); i++){
        int lowest = i;
        for (int j = i+1; j < v.size(); j++){
            if (v[j] < v[lowest]){
                lowest = j;
            }
        }

        if (lowest != i){ // Hi ha un nombre més petit, fem el swap
            int aux = v[i];
            v[i] = v[lowest];
            v[lowest] = aux;
        }
    }
}

int main() {
    vector<int> v = {64, 25, 12, 22, 11};

    cout << "Vector original: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    selectionSort(v);

    cout << "Vector ordenat:  ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
