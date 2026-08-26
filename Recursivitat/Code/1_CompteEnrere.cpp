#include <iostream>
using namespace std;

// pre: segons >= 0
// post: imprimeix un compte enrere des de 'segons' fins a 0, acabant amb una explosió
void compteEnrere(int segons){
    if (segons == 0){ // CAS BASE: Quan arriba a 0, parem i imprimim el missatge final.
        cout << "EXPLOSION! 💥" << endl;
    } else { // CAS RECURSIU: Imprimim el número i cridem la funció amb 1 segon menys.
        cout << segons << "..." << endl;
        compteEnrere(segons - 1);
    }
}

int main(){
    cout << "Megumin is preparing the spell:" << endl;
    compteEnrere(3);
}

/* Funcionament per compteEnrere(3):
1. Imprimeix 3 i crida compteEnrere(2)
2. Imprimeix 2 i crida compteEnrere(1)
3. Imprimeix 1 i crida compteEnrere(0)
4. Entra al CAS BASE: imprimeix "EXPLOSION!" i no crida a ningú més.
*/
