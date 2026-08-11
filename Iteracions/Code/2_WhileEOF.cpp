#include <iostream>
using namespace std;

int main(){
    int n;
    int total = 0;

    while (cin >> n){ // fins que no fem CTRL+D a consola, el codi no pararà.
        total += n;
        cout << total << endl;
    }
}
