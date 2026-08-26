#include <iostream>
using namespace std;

// pre: a >= 0, b >= 0
// post: retorna el Màxim Comú Divisor (MCD) d'a i b utilitzant l'algorisme d'Euclides
int mcd(int a, int b){
    if (b == 0){ // CAS BASE: Si el residu arriba a 0, el MCD és l'altre número.
        return a;
    } else { // CAS RECURSIU: Intercanviem els valors i passem el residu (a % b).
        return mcd(b, a % b);
    }
}

int main(){
    int a, b;
    cout << "Matikanetannhauser asks for two numbers to find their GCD: ";
    cin >> a >> b;

    cout << "The GCD of " << a << " and " << b << " is " << mcd(a, b) << endl;
}
