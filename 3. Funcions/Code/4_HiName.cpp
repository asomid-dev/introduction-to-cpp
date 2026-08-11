#include <iostream>
using namespace std;

//pre: true
//post: imprimeix a la consola una salutació a la persona.
void sayHi(string name){
    cout << "Hi " << name << '!' << endl;
}

int main(){
    string name;

    cout << "What is your name? ";
    cin >> name;
    cout << endl;

    sayHi(name);
}
