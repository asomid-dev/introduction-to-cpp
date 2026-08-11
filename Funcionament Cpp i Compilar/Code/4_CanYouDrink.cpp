#include <iostream>
using namespace std;

int main(){
	int age = 0; // everyone has at least 0 years old

	cout << "How old are you? (type your age with a number (i.e. 24))" << endl;
	cin >> age;
	if (age >= 18){
		cout << "You can drink alcohol" << endl;
	} else {
		cout << "You can't drink alcohol" << endl;
	}
}
