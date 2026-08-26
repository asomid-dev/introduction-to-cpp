#include <iostream>
using namespace std;

// pre: exp >= 0
// post: retorna la 'base' elevada a 'exp'
int power(int base, int exp){
    if (exp == 0){ // CAS BASE: Qualsevol número elevat a 0 sempre és 1.
        return 1;
    } else { // CAS RECURSIU: Multipliquem la base per la potència amb l'exponent restat en 1.
        return base * power(base, exp - 1);
    }
}

int main(){
    int base, exp;
    cout << "Enter the base and the exponent for Scarlet's attack: ";
    cin >> base >> exp;

    if (exp < 0){
        cout << "Error: This function only supports positive exponents." << endl;
    } else {
        cout << "Total damage: " << power(base, exp) << " HP!" << endl;
    }
}
