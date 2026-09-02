# Matrius

## 1. Què és una Matriu en programació i la seva Sintaxi

Igual que a la geometria o l’àlgebra lineal, una matriu en programació és un conjunt ordenat de vectors (files), que es poden imaginar com una taula de valors. En C++, podem definir una matriu d’enters com `std::vector<std::vector<int>> Matriu;`. Aquesta estructura és el que s’anomena un “vector de vectors” (Matriu), que permet gestionar una col·lecció de files i columnes dinàmicament.

Podem recórrer o iterar una matriu de la mateixa manera que fem amb els bucles al tema de **Vectors**.

**Exemple**: 
Suposem que tenim la següent matriu d'enters (2 files x 3 columnes):
[ 1  2  3 ]
[ 4  5  6 ]

 **Com accedir a un element concret?**

```cpp
// Per accedir a l'element de la fila 1 i la columna 2 (recorda: comencem a comptar per 0!), fem:
int valor = matriu[1][2]; // valor = 6

// En general, per accedir a l'element de la fila i, columna j:
int valor = matriu[i][j];

// També pots modificar aquest valor igual que amb els vectors:
matriu[0][1] = 99; // Ara la matriu és: [ 1 99 3 ] / [ 4 5 6 ]
```

---

## 2. Inicialitzar una matriu

Tal com hem vist amb els vectors, una matriu pot ser de qualsevol tipus de dada. Des d'un int, fins a un Struct. Per treballar amb matrius, és important no oblidar-nos d'afegir la llibreria vector utilitzant `#include <vector>`.

Anem a crear algunes matrius bàsiques:

??? example "InicialitzarMatrius.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        // Matriu 3x4 d'enters, inicialitzada a 0
        vector<vector<int>> matriu_enters(3, vector<int>(4, 0));
        // [ 0  0  0  0 ]
        // [ 0  0  0  0 ]
        // [ 0  0  0  0 ]

        // Matriu 2x2 de doubles, cada element inicialitzat a 3.14
        vector<vector<double>> matriu_dobles(2, vector<double>(2, 3.14));
        // [ 3.14  3.14 ]
        // [ 3.14  3.14 ]

        // Matriu "buida" (sense mida fixa inicial)
        vector<vector<string>> matriu_strings;
        // [ ]
        
        // Assignació manual d'una matriu de caràcters
        vector<vector<char>> matriu_caracters = {
            {'A', 'B', 'C'},
            {'D', 'E', 'F'}
        };
    }
    ```

---

## 3. Iterar sobre una matriu

Una matriu es pot veure com un "vector de vectors". Per tant, per iterar sobre cadascun dels seus elements, necessitem dos bucles: un per recórrer les files i un altre per recórrer les columnes de cada fila. Això es diu fer una **iteració doble** (nested loop).

La sintaxi bàsica seria aquesta:

```cpp
// Suposem que tenim una matriu de dimensions nfiles x ncolumnes:
vector<vector<int>> matriu(nfiles, vector<int>(ncolumnes, 0));

// Per recórrer tots els elements i fer alguna acció (com imprimir-los):
for (int i = 0; i < nfiles; i++) { // Iterem sobre les files
    for (int j = 0; j < ncolumnes; j++) { // Per cada fila, iterem sobre cada columna
        cout << matriu[i][j] << " "; // Accedim al item de la fila i, columna j
    }
    cout << endl; // Salt de línia en acabar cada fila
}
```

> **NOTA:** Recorda que l’índex `i` recorre les files i l’índex `j` recorre les columnes dins de cada fila.

---

## 4. Exemples

### Exemple 1: Imprimir una matriu d'enters

??? example "1. ImprimirMatriu.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<int>> matriu = {
            {1, 2, 3},
            {4, 5, 6}
        };

        int files = matriu.size();
        int columnes = matriu[0].size();

        for (int i = 0; i < files; i++) {
            for (int j = 0; j < columnes; j++) {
                cout << matriu[i][j] << " ";
            }
            cout << endl;
        }
        // Sortida:
        // 1 2 3
        // 4 5 6
    }
    ```

### Exemple 2: Sumar tots els elements d'una matriu de doubles

??? example "2. SumarMatriu.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<double>> matriu = {
            {1.1, 2.2},
            {3.3, 4.4}
        };

        double suma = 0;
        for (int i = 0; i < matriu.size(); i++) {
            for (int j = 0; j < matriu[i].size(); j++) {
                suma += matriu[i][j];
            }
        }
        cout << "La suma total és: " << suma << endl;
        // Sortida: La suma total és: 11
    }
    ```

### Exemple 3: Canviar un element d'una matriu de caràcters

??? example "3. CanviarElement.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<char>> lletres = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'}
        };

        lletres[0][1] = 'z'; // Canviem la 'b' per una 'z'

        for (int i = 0; i < lletres.size(); i++) {
            for (int j = 0; j < lletres[i].size(); j++) {
                cout << lletres[i][j] << " ";
            }
            cout << endl;
        }
        // Sortida:
        // a z c
        // d e f
    }
    ```

### Exemple 4: Llegir una matriu d'enters per teclat

??? example "4. LlegirMatriu.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        int files, columnes;
        cin >> files >> columnes;
        vector<vector<int>> matriu(files, vector<int>(columnes));

        // Llegim els valors per files i columnes
        for (int i = 0; i < files; i++) {
            for (int j = 0; j < columnes; j++) {
                cin >> matriu[i][j];
            }
        }

        // Mostrem la matriu
        for (int i = 0; i < files; i++) {
            for (int j = 0; j < columnes; j++) {
                cout << matriu[i][j] << " ";
            }
            cout << endl;
        }
    }
    ```

---

## 5. A destacar
### 1. Valors per referència
Igual que al tema de vectors, és important recordar que si volem passar una matriu com a paràmetre d'una funció, fem servir l'operador de referència `&`. Per més informació, llegiu el tema de vectors.

### 2. Typedef Matriu
A vegades, els professors de PRO1 defineixen un tipus de dades anomenat 'Matriu' amb la següent definició:
```cpp
typedef vector< vector<int> > Matriu;
```
Això solament indica que la paraula 'Matriu' és equivalent a escriure `vector<vector<int>>`, per tant, `vector<vector<int>> nums;` i `Matriu nums;` és equivalent.

---

## 6. Exercici Final

Aquí tens un exercici de nivell avançat que et demanarà combinar tot el que saps sobre matrius, bucles niats i cerca de màxims per trobar la millor submatriu.

??? example "final.cpp"

    ```cpp
    /*
    * Exercici Final
    * Exemple: Troba la Submatriu Quadrada de Suma Màxima
    * Fet per: Uri
    */

    /*
    Aquest programa llegeix una matriu d'enters positius de f files i c columnes (primer l'usuari entra f i c,
    després els valors de la matriu), i després llegeix un enter positiu k (1 <= k <= min(f,c)).
    El programa cerca dins la matriu la submatriu quadrada de mida k x k la suma dels elements
    de la qual sigui màxima. Imprimeix:
    - El valor d'aquesta suma màxima.
    - La submatriu k x k corresponent (en la mateixa disposició que l'original), corresponent a la primera (de dalt a baix, esquerra a dreta) amb suma màxima que trobi, en cas d'empat.

    Exemple:
    Input:
    4 5
    1 2 0 3 4
    0 6 3 4 1
    2 4 5 2 3
    1 0 1 1 1
    3

    Output:
    Suma màxima: 29
    Submatriu:
    6 3 4
    4 5 2
    0 1 1
    */

    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        int f, c;
        cin >> f >> c; // Llegim files i columnes
        // Llegim la matriu d'enters
        vector<vector<int>> matriu(f, vector<int>(c));
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matriu[i][j];
        
        int k;
        cin >> k; // Llegim la mida de la submatriu quadrada

        // Variables per guardar la suma màxima i la posició de la millor submatriu
        int suma_max = 0; // La suma màxima trobada fins ara (mínim 0)
        int millor_i = 0, millor_j = 0; // Coordenades de l'inici de la millor submatriu

        // Recorrem totes les submatrius possibles de mida k x k
        for (int i = 0; i <= f - k; ++i) {
            for (int j = 0; j <= c - k; ++j) {
                int suma = 0; // Suma dels elements de la submatriu actual
                // Calculem la suma d'aquesta submatriu
                for (int a = 0; a < k; ++a)
                    for (int b = 0; b < k; ++b)
                        suma += matriu[i + a][j + b];
                // Si la suma d'aquesta submatriu és millor, la guardem
                if (suma > suma_max) {
                    suma_max = suma;
                    millor_i = i;
                    millor_j = j;
                }
            }
        }

        // Imprimim el resultat
        cout << "Suma màxima: " << suma_max << endl;
        cout << "Submatriu:" << endl;
        // Mostrem la submatriu de suma màxima
        for (int a = 0; a < k; ++a) {
            for (int b = 0; b < k; ++b)
                cout << matriu[millor_i + a][millor_j + b] << " ";
            cout << endl;
        }
    }
    ```
