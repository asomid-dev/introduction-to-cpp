#include <iostream>
using namespace std;

int main(){
	string name; // declaració sense assignació de valor
				 // igualment, a C++ per default
				 // l'string rep el valor "".
	cout << "What is your name?" << endl;
	cin >> name; // escrivim a la terminal el nom amb UNA sola paraula.
	cout << "Hello " << name << '!' << endl;

	// cin: Console INput
	// >> operador logic del cin (significa introdueix el valor rebut a la variable)
}
