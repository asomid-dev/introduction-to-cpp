#include <iostream>
using namespace std;

//pre: true
//post: retorna la suma de dos elements enters.
int sum(int a, int b){
    return a + b;
}

int main(){
    int n1 = 5;
    int n2 = 10;
    cout << sum(n1,n2) << endl;
}
