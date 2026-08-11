#include <iostream>
using namespace std;

//pre: a >= 0, b >= 0
//post: retorna el mcd mitjançant l'algorisme d' Euclides
int mcd(int a, int b){
    while (b!=0){
        int aux = b;
        b = a % b;
        a = aux;
    }
    return a;
}

int main(){
    int n1 = 4;
    int n2 = 2;
    cout << mcd(n1,n2) << endl;
}
