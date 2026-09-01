/*
 * Exercici Final
 * Exemple: Construir Muntanyes on el Pic és de N Altitud.
 * Fet per: aso
 */

#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "How many '*' should have the peak of this mountain? (The answer must be an Integer greater or equal than 1): ";

    while (cin >> n) {
        cout << endl;

        if (n < 1) {
            cout << "Invalid Input" << endl;
        } else {
            // Pujada de la muntanya
            for (int i = 0; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                    cout << '*';
                }
                cout << endl;
            }

            // Quan i = n, la muntanya ha de tornar a baixar. Per tant comencem a n - 1.
            for (int i = n - 1; i > 0; i--) {
                for (int j = i; j > 0; j--) {
                    cout << '*';
                }
                cout << endl;
            }
        }

        cout << "And the next mountain? Answer: ";
    }
}
