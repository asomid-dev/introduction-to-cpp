#include <iostream>
using namespace std;

//pre: true
//post: intercanvia els nombres
void swapNumbers(int &a, int &b){
    int aux = b;
    b = a;
    a = aux;
}

int main(){
    int a = 5;
    int b = 2;

    cout << "a: " << a << " b: " << b << endl;

    swapNumbers(a, b);
    cout << "a: " << a << " b: " << b << endl;
}
