#include <iostream>
using namespace std;

int main(){
    char ch;
    string result = "";

    cin >> ch;
    while (ch != '0'){ // volem insertar chars a un string fins que un char sigui '0'.
        result += ch;
        cin >> ch;
    }

    cout << result << endl;
}
