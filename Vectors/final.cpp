/*
 * Exercici Final
 * Exemple: Gestor de Notes Amb Structs, Vectors i Funcions.
 * Fet per: aso
 */

#include <iostream>
#include <vector>
using namespace std;

struct Student {
    string name;
    double grade;
};

// pre: cert
// post: imprimeix els noms i les notes de tots els estudiants
void printGrades(const vector<Student>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << "- " << v[i].name << ": " << v[i].grade << endl;
    }
}

// pre: el vector 'v' no està buit (v.size() > 0)
// post: retorna la nota mitjana de la classe
double calculateAverage(const vector<Student>& v) {
    double sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum = sum + v[i].grade;
    }
    return sum / v.size();
}

// pre: cert
// post: suma 1 punt a totes les notes del vector, amb un màxim de 10
void applyBonus(vector<Student>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].grade < 10.0) {
            v[i].grade++;

            if (v[i].grade > 10.0) {
                v[i].grade = 10.0;
            }
        }
    }
}

int main() {
    vector<Student> classList;
    Student current;

    // Ara l'explicació de la terminal deixa clar que és per a MÚLTIPLES estudiants
    cout << "--- STUDENT RECORD SYSTEM ---" << endl;
    cout << "Enter the students' names and grades." << endl;
    cout << "You can add as many as you want! (Press Ctrl+D to finish)" << endl;
    cout << "Example:" << endl;
    cout << "Frieren 10.0" << endl;
    cout << "Megumin 8.5" << endl;
    cout << "Mugi 9.2" << endl;
    cout << "-----------------------------------" << endl;

    // Llegim dades contínuament fins que l'usuari tanqui (Ctrl+D)
    while (cin >> current.name >> current.grade) {

        if (current.grade > 10.0 || current.grade < 0.0) {
            cout << "Error: Invalid grade for " << current.name << ". It must be between 0 and 10." << endl;
        } else {
            classList.push_back(current);
        }
    }

    cout << endl;

    if (classList.size() == 0) {
        cout << "No grades were entered." << endl;
        return 0;
    }

    // Confirmació visual de que s'han afegit diferents alumnes al vector
    cout << ">> Successfully loaded " << classList.size() << " students into the system. <<" << endl << endl;

    // 2. Pas per referència constant
    cout << "--- BEFORE THE BONUS ---" << endl;
    printGrades(classList);
    cout << "Class average: " << calculateAverage(classList) << endl;

    cout << endl;

    // 3. Pas per referència normal
    cout << "Applying +1 bonus to everyone..." << endl;
    applyBonus(classList);

    cout << endl;

    // 4. Comprovem els canvis
    cout << "--- AFTER THE BONUS ---" << endl;
    printGrades(classList);
    cout << "New class average: " << calculateAverage(classList) << endl;
}
