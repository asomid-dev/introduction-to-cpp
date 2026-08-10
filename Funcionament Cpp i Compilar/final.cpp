/*
 * EXERCICI FINAL PER ENSENYAR COM FUNCIONA TOT PLEGAT
 * EXEMPLE: CALCULADORA BÀSICA D'UN SOL ÚS.
 * FET PER: ASO
 */

#include <iostream>
using namespace std;

int main(){
    int a, b;
    char op;
    bool correct = true;

    cout << "Type an integer operation with only one operator (i.e. 24 - 12), valid operators: +, -, *, /, %." << endl;
    cin >> a >> op >> b; // legim nombre a, operador, nombre b

    int result = 0; // Sempre que un nombre sortirà per la pantalla, per seguretat, l'inicialitzem a 0.
    if (op == '+'){
        result = a + b;
    } else if (op == '-'){
        result = a - b;
    } else if (op == '*'){
        result = a * b;
    } else if (op == '/'){
        if (b != 0){ // A PRO1 sempre busquen els punts fluixos del exercici.
            result = a / b;
        } else{ // b == 0
            correct = false;
        }
    } else if (op == '%'){
        if (b != 0){
            result = a % b;
        } else{ // b == 0
            correct = false;
        }

    } else{ // operador invalid
        correct = false;
    }
    if (correct){
        cout << "The operation is equal to " << result << '.' << endl;
    } else{
        cout << "Error: Invalid operator or division by zero" << endl;
    }

}
