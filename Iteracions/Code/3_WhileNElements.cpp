#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cout << "How many times do you want to subtract 1 until it's 0? Input (Must be an integer greater than 1): ";
    cin >> n;
    cout << endl;

    if (n <= 0){
        cout << "Invalid Input" << endl;
    } else{
        while (n > 0){
            cout << n-- << endl;
        }
    }
}
