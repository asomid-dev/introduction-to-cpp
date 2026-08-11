#include <iostream>
using namespace std;

// Executeu el codi a la terminal

int main(){
    // Exemple Post-Decrement
    int i = 5;
    int a = i--; // 'a' es queda amb el 5. Un cop assignat, 'i' baixa a 4.
    cout << "POST-DECREMENT -> a: " << a << ", i: " << i << endl;

    // Exemple Pre-Decrement
    int j = 5;
    int b = --j; // 'j' baixa a 4 directament. Llavors s'assigna, i 'b' també val 4.
    cout << "PRE-DECREMENT -> b: " << b << ", j: " << j << endl;

    // amb post increment i pre increment es igual:
    i = 5;
    a = i++; // 'a' es queda amb el 5. Un cop assignat, 'i' augmenta a 6.
    cout << "POST-INCREMENT -> a: " << a << ", i: " << i << endl;

    j = 5;
    b = ++j; // 'j' augmenta a 6 directament. Llavors s'assigna, i 'b' també val 6
    cout << "PRE-INCREMENT -> b: " << b << ", j: " << j << endl;
}
