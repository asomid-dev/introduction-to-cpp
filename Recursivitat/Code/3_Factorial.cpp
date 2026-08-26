#include <iostream>
using namespace std;

// pre: n >= 0
// post: retorna el factorial de n (n!)
int factorial(int n){
    if (n == 0){ // CAS BASE: El factorial de 0 sempre és 1.
        return 1;
    } else { // CAS RECURSIU: Multipliquem 'n' pel factorial del número anterior.
        return n * factorial(n - 1);
    }
}

int main(){
    int n;
    cout << "Mugi asks for a number to calculate its factorial: ";
    cin >> n;

    if (n < 0){
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "The factorial of " << n << " is " << factorial(n) << endl;
    }
}
