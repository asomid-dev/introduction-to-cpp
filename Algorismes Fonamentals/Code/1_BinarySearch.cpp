#include <iostream>
#include <vector>
using namespace std;

//pre: v està ordenat de forma creixent, 0 <= left, right < v.size().
//post: retorna la posició de 'x' dins de 'v'. Retorna -1 si 'x' no hi és.
int binarySearch(const vector<int>& v, int x, int left, int right){
    // CAS BASE 1: Els límits s'han creuat (l'element no hi és).
    if (left > right) return -1;

    int mid = (left + right) / 2;
    // CAS RECURSIU: 'x' està cap a la dreta.
    if (v[mid] < x) { return binarySearch(v, x, mid + 1, right); }
    // CAS RECURSIU: 'x' està cap a l'esquerra.
    if (v[mid] > x) { return binarySearch(v, x, left, mid - 1); }

    // CAS BASE 2: L'hem trobat al mig (v[mid] == x).
    return mid;
}

int main(){
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int x = 0;
    cout << "Which number's position do you want to find? ";
    cin >> x;

    int pos = binarySearch(v, x, 0, v.size() - 1);

    if (pos != -1){
        cout << "\nYour number is located at index " << pos << '.' << endl;
    } else{
        cout << "\nYour number is NOT in the vector." << endl;
    }
}
