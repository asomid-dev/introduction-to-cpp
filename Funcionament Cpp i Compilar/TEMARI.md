# 1. Com funciona C++ i com compilar

## 1. Sintaxi
La sintaxi de C++ és senzilla. A PRO1 treballareu a la majoria d'exercicis amb la llibreria `<iostream>` per fer l'input i output del codi.
Per afegir una llibreria només hem d'escriure a l'inici d'un arxiu `.cpp` o `.cc` (formats C++) `#include <llibreria>`.

A més de la llibreria, també fem servir un "namespace". El namespace és com un prefix de la funció; per exemple, si a la llibreria estàndard (`std`) tenim una funció `cout` i a la llibreria personalitzada *paco* tenim una funció amb la mateixa definició `paco`, evitarem el problema amb el prefix. Per no haver d'escriure tota l'estona el prefix (ex: `std::cout`), a l'inici afegirem després de les llibreries (per estructura de l'assignatura): `using namespace std;`.

Tot codi de C++ té una funció principal (`main`) que és la que busca el compilador per poder executar un codi. (A l'exemple hi ha la declaració del main).

Exemple:
```cpp
#include <iostream>
using namespace std;

int main() {
    
}
```

Per afegir comentaris a un codi (text que no afecta el nostre codi) només hem d'escriure un `//` (comentari per línia) o `/* */` (comentari per bloc).

```cpp
#include <iostream>
using namespace std;

// Aquest és un comentari només per aquesta línia.

/* 
Aquest és un comentari
fins que 
es tanca el bloc 
*/

int main() {
    // ...
}
```

---

## 2. Tipus de variables
Tenim diferents variables:
*   `int` (enters) -> (p. ex. `124`)
*   `string` (paraules) -> (p. ex. `"Hola"`)
*   `char` (caràcters) -> (p. ex. `'a'`) **Nota:** un caràcter s'emmagatzema amb el seu valor ASCII, per exemple el `'0'` és el `48`.
*   `double` (decimals) -> (p. ex. `67.67`)
*   `bool` (veritat o fals) -> (p. ex. `true`) **Nota:** també es pot declarar amb `1` (true) i `0` (false).

Per declarar variables, fem servir una paraula clau que servirà per assignar un valor a aquella paraula. 
A més, podem fer que una variable sigui **constant**, és a dir, que no canviarà mai. Només hem de posar `const` al davant d'una declaració de variable.

Exemple de com es declara una variable:
```cpp
#include <iostream>
using namespace std;

int main() {
    // Estructura: tipus nom_variable = valor;
    int nombre = 124; // Cada cop que definim un valor, hem de posar el ; 
    string paraula = "Frieren";
    char ch = 'a';
    double sixseven = 67.67;
    
    // Igual que podem assignar nombre = 124, podem fer el següent:
    int aux = nombre; // Com que nombre és igual a 124, podem assignar aquest valor a una altra variable.
    
    // Declaració d'una constant:
    const int restricted_age = 18;
}
```

---

## 3. Input i Output
Ara que sabem com funcionen les variables, aprendrem a compilar un arxiu `.cpp`, introduir dades per la terminal i com imprimir dades per la terminal.

Primer farem l'exercici típic de qualsevol llenguatge de programació:

### 1. HelloWorld.cpp
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World!" << endl; 
    
    // cout: Console OUTput
    // << operador d'inserció del cout (significa: mostra a la consola el que ve després)
    // endl: paraula reservada de la llibreria std, és un caràcter que significa fi de línia (end line)
}
```

Per poder veure "Hello World!" per la terminal hem de compilar. Com ho fem? Fàcil.
A la terminal Linux anem a la carpeta de l'arxiu:
```bash
cd /home/aso/CODE/cpp
g++ arxiu.cpp -o executable
./executable
```
A l'executable podeu posar el que vulgueu, jo per costum poso sempre `x.x`, altres persones fan un executable per programa.

Exemple de compilació i execució amb HelloWorld:
```bash
g++ HelloWorld.cpp -o x.x
./x.x 
```
Després de fer `./x.x` veureu per la terminal: `Hello World!`

> **NOTA:** Recordeu guardar (`CTRL + S` o `CTRL + G`) sempre abans de compilar, per evitar errors ximples de compilació.

### 2. HelloName.cpp
```cpp
#include <iostream>
using namespace std;

int main() {
    string name; // Declaració sense assignació de valor
                 // A C++, per defecte l'string rep el valor buit "".
                 
    cout << "What is your name?" << endl; 
    cin >> name; // Escrivim a la terminal el nom amb UNA sola paraula. 
    cout << "Hello " << name << '!' << endl;
    
    // cin: Console INput
    // >> operador d'extracció del cin (significa: introdueix el valor rebut a la variable)
}
```
Quan és un `cin`, posem els valors que ens demanen i premem la tecla Enter per avisar el codi que ja hem posat la informació. 

> **DIFERÈNCIES IMPORTANTS ENTRE `cin` I `cout` AMB L'STRING**
> Amb un `cin` només podem introduir **una paraula** per variable `string`. El `cin` detecta l'espai com a final d'string.
> En canvi, amb el `cout`, quan posem `cout << "frase amb espais" << endl;` imprimeix a la consola tota la frase sencera sense tallar-la.

---

## 4. Operadors i Comparadors Lògics

### Operadors Aritmètics
| Tipus | Declaració |
| :--- | :--- |
| Suma | `+` |
| Resta | `-` |
| Multiplicació | `*` |
| Divisió | `/` |
| Residu d'una divisió | `%` |
| Assignació | `=` |

> **NOTA:** La divisió `/`, si dividim enters, retornarà la part entera. En canvi, si dividim doubles, retornarà la divisió normal. Per tant, no podrem fer mai `double % double`, ja que la pròpia divisió de decimals ja afegeix el residu.

### Operadors Compostos i d'Increment
```cpp
// suposem que i és un enter

i++; // suma post-increment -> després de treballar amb la i, incrementem 1, és a dir: i = i + 1.

++i; // suma pre-increment -> abans de treballar amb la i, incrementem 1.

// també es pot fer resta post-decrement i pre-decrement

i += 20; // traducció: i = i + 20
 
i /= 2; // traducció: i = i / 2;
```

Exemple:
### 3. PostAndPreExample.cpp
```cpp
#include <iostream>
using namespace std;

int main(){
    // Exemple Post-Decrement
    int i = 5;
    int a = i--; // 'a' es queda amb el 5. Un cop assignat, 'i' baixa a 4.
    cout << "POST-DECREMENT -> a: " << a << ", i: " << i << endl;

    // Exemple Pre-Decrement
    int j = 5;
    int b = --j; // 'j' baixa a 4 directament. Llavors s'assigna, i 'b' també val 4.
    cout << "PRE-DECREMENT -> b: " << b << ", j: " << j << endl;

    // amb post-increment i pre-increment és igual:
    i = 5;
    a = i++; // 'a' es queda amb el 5. Un cop assignat, 'i' augmenta a 6.
    cout << "POST-INCREMENT -> a: " << a << ", i: " << i << endl;

    j = 5;
    b = ++j; // 'j' augmenta a 6 directament. Llavors s'assigna, i 'b' també val 6
    cout << "PRE-INCREMENT -> b: " << b << ", j: " << j << endl;
}
```
### Operadors Lògics
| Tipus | Declaració |
| :---- | :--------- |
| AND   | `&&`       |
| OR    | \|\|       |
| NOT   | `!`        |


### Comparadors Lògics

*Un comparador sempre dona un resultat booleà (`true` o `false`)*

| Tipus | Declaració |
| :--- | :--- |
| Major | `a > b` |
| Menor | `a < b` |
| Major o igual | `a >= b` |
| Menor o igual | `a <= b` |
| Estrictament igual | `a == b` |
| Diferent | `a != b` |

---

## 5. Condicionals
A la programació tenim condicionals: `if`, `else if`, `else`.

Sempre declarem primer `if`. Si hi ha una segona condició que volem cobrir després que la primera falli, posem `else if`. Per a la resta de casos (les excepcions), posem `else`.
Per estructura i elegància, sempre obrirem un bloc `{}` després del condicional.

### 4. CanYouDrink.cpp
```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 0; // tothom té com a mínim 0 anys
    
    cout << "How old are you? (type your age with a number (i.e. 24))" << endl;
    cin >> age;
    
    if (age >= 18) { // Mirem si l'edat és major o igual a 18.
        cout << "You can drink alcohol" << endl;
    } else {
        cout << "You can't drink alcohol" << endl;
    } 
}
```
