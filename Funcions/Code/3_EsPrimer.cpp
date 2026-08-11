#include <iostream>
using namespace std;

//pre: a >= 2
//post: retorna true si el nombre es primer, si no es primer, retorna false.
bool isPrime(int a){

/*
 * NOTA IMPORTANT:
 * AQUEST CODI NO ESTÀ OPTIMITZAT, ES NOMÉS PERQUE VEIEU UN EXEMPLE
 */

    if (a < 2){ // BASE CASE: if 'a' is less than 2, then it is not prime.
        return false;
    }
    int counter = 0;
    for (int i = 1; i <= a; i++){ // We check how many divisors does 'a' have.
        if (a % i == 0){
            counter++;
        }
    }
    if (counter > 2){ // If 'a' has more than 2 divisors, then it is not prime.
        return false;
    } else{
        return true;
    }
}

int main(){
    int n1;

    cout << "Enter an integer number: ";
    while (cin >> n1){
        cout << endl;

        if (isPrime(n1)){
            cout << n1 << " is prime." << endl;
        } else{
            cout << n1 << " is NOT prime." << endl;
        }

        cout << "Enter an integer number: ";
    }

}
