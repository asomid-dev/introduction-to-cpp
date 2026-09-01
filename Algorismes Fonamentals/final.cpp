/*
 * Exercici Final
 * Exemple: Fitxa D'Aventurer Amb Structs i Funcions (Amb Límits).
 * Fet per: aso
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Player {
    int id;
    string name;
    int score;
};

// pre: cert
// post: retorna true si el jugador 'a' té un ID estrictament menor que el jugador 'b'
bool cond(const Player& a, const Player& b) {
    return a.id < b.id;
}

// pre: el vector 'v' està ordenat per ID de forma creixent, 0 <= left, right < v.size()
// post: retorna la posició del jugador amb l'id_buscat, o -1 si no existeix
int binarySearch(const vector<Player>& v, int x, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (v[mid].id < x) return binarySearch(v, x, mid + 1, right);
    if (v[mid].id > x) return binarySearch(v, x, left, mid - 1);
    return mid;
}

int main() {
    vector<Player> tournament;
    Player p;

    cout << "Registration phase, enter a player (format: ID PlayerName Score), for closing this phase, enter -1:" << endl;

        cin >> p.id;
        while (p.id != -1) {
            cin >> p.name >> p.score;
            tournament.push_back(p);

            cout << "\nEnter another player:" << endl;
            cin >> p.id;
        }

    sort(tournament.begin(), tournament.end(), cond);

    if (tournament.empty()){
        cout << "\nNo player was registered. Ending program." << endl;
    } else{
        cout << "- - - - - - - - - - - - - - - -\n";
        cout << "Query phase. Enter ID to search (Ctrl + D to exit):\n";

        int id;

        while (cin >> id) {

            int pos = binarySearch(tournament, id, 0, tournament.size() - 1);

            if (pos == -1){
                cout << "Error: Player not registered" << endl;
            } else{
                cout << "The player " << tournament[pos].name << " has " << tournament[pos].score << " points." << endl;
            }
            cout << "\nEnter ID to search (Ctrl + D to exit):\n";
        }
    }
}
