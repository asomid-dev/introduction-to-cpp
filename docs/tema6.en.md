# Recursion

## 1. What is Recursion and its Syntax?
So far, we have seen how to repeat code using loops (`while` and `for`), but what if we want a function to repeat by calling itself?
This is called recursion, and it is used to solve problems by dividing them into smaller subproblems.

**The Russian Dolls (Matryoshkas) Analogy:**
Imagine you have a wooden doll that has a smaller one inside it, and that one has another, and another. The action is always the same: "open the doll". You only stop doing it when you reach the tiniest doll of all, which can no longer be opened. This is exactly what recursion is: a function that does a part of the work and calls itself again with a smaller problem, until it reaches a point where it can no longer be divided.

To create a recursive function in C++, the basic structure is as follows:

```cpp
void recursiveFunction(int n){
    if (stopping_condition){
        // Base case: the problem is so small that it is solved directly (the smallest doll).
        // Recursion stops here.
    } else {
        // Recursive case: we do part of the work and call the function again 
        // with a modified value (we open the doll and move to the next one).
        recursiveFunction(n - 1);
    }
}
/* This structure makes the function call itself, decreasing 'n' at each step.
When 'n' meets the stopping condition, the function stops calling itself.
*/
```

---

## 2. The two golden rules (Parts of recursion)
EVERY recursive function you write in PRO1 MUST HAVE two essential parts. If you miss one, the function will never stop.

*   **The Base Case:** This is the exit condition. It is a problem so simple that we can solve it directly without calling anything else. It acts like the sentinel or EOF in loops.
*   **The Recursive Case:** This is where we call the function itself again, but passing a parameter that brings it closer to the Base Case (making the problem smaller).

---

## 3. The danger of Recursion: Stack Overflow
What happens if you forget the Base Case or if the Recursive Case doesn't make the problem smaller? The fatal error known as **Stack Overflow** occurs.

In C++, every time you call a function, the computer places a temporary "box" with the variables of that call in an area of memory called the **Stack**. When the function finishes, the box is removed. In recursion, the computer stacks boxes on top of each other before closing the previous ones. 

If the recursion is infinite (for example, calling `countdown(seconds)` instead of `countdown(seconds - 1)`), the computer will stack boxes until it hits the memory limit. When no more boxes fit, the memory overflows and the program dies instantly. Always double-check that your recursive calls get closer to the Base Case!

---

## 4. Examples

??? example "1. Countdown.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    // pre: seconds >= 0
    // post: prints a countdown from 'seconds' to 0, ending with an explosion
    void countdown(int seconds){
        if (seconds == 0){ // BASE CASE: When it reaches 0, we stop and print the final message.
            cout << "EXPLOSION! 💥" << endl;
        } else { // RECURSIVE CASE: We print the number and call the function with 1 second less.
            cout << seconds << "..." << endl;
            countdown(seconds - 1); 
        }
    }

    int main(){
        cout << "Megumin is preparing the spell:" << endl;
        countdown(3);
    }

    /* How countdown(3) works: 
    1. Prints 3 and calls countdown(2)
    2. Prints 2 and calls countdown(1)
    3. Prints 1 and calls countdown(0)
    4. Enters the BASE CASE: prints "EXPLOSION!" and calls nothing else.
    */
    ```

??? example "2. GCD.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    // pre: a >= 0, b >= 0
    // post: returns the Greatest Common Divisor (GCD) of a and b using the Euclidean algorithm
    int gcd(int a, int b){
        if (b == 0){ // BASE CASE: If the remainder reaches 0, the GCD is the other number.
            return a;
        } else { // RECURSIVE CASE: We swap the values and pass the remainder (a % b).
            return gcd(b, a % b);
        }
    }

    int main(){
        int a, b;
        cout << "Matikanetannhauser asks for two numbers to find their GCD: ";
        cin >> a >> b;
        
        cout << "The GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    }
    ```

??? example "3. Factorial.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    // pre: n >= 0
    // post: returns the factorial of n (n!)
    int factorial(int n){
        if (n == 0){ // BASE CASE: The factorial of 0 is always 1.
            return 1;
        } else { // RECURSIVE CASE: We multiply 'n' by the factorial of the previous number.
            return n * factorial(n - 1);
        }
    }

    int main(){
        int n;
        cout << "Mugi asks for a number to calculate its factorial: ";
        cin >> n;
        
        if (n < 0){
            cout << "Factorial is not defined for negative numbers." << endl;
        } else {
            cout << "The factorial of " << n << " is " << factorial(n) << endl;
        }
    }
    ```

??? example "4. Power.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    // pre: exp >= 0
    // post: returns 'base' raised to 'exp'
    int power(int base, int exp){
        if (exp == 0){ // BASE CASE: Any number raised to 0 is always 1.
            return 1;
        } else { // RECURSIVE CASE: We multiply the base by the power with the exponent decreased by 1.
            return base * power(base, exp - 1);
        }
    }

    int main(){
        int base, exp;
        cout << "Enter the base and the exponent for Scarlet's attack: ";
        cin >> base >> exp;
        
        if (exp < 0){
            cout << "Error: This function only supports positive exponents." << endl;
        } else {
            cout << "Total damage: " << power(base, exp) << " HP!" << endl;
        }
    }
    ```

---

## 5. Final Exercise

This exercise combines recursion with elements we've already seen, introducing a new and very useful concept: `std::pair`, which allows us to return two different pieces of data at once from a single function.

??? example "final.cpp"

    ```cpp
    /*
     * Final Exercise
     * Example: Sentinel Registration and Recursive Search Returning a Pair.
     * Made by: aso
     *
     * ----------------------------------------------------------------------
     * 💡 WHAT IS A PAIR?
     * A std::pair is a C++ tool that allows us to group two values
     * (they can be of the same or different types) into a single variable.
     * Imagine it as a pre-built "mini-struct" that always has
     * exactly two fields: the first one is called '.first' and the second '.second'.
     *
     * It is extremely useful when a function needs to RETURN TWO THINGS at once.
     * In this case, our search function must answer two questions:
     * 1. Did you find it? -> A boolean (true/false) that we will store in .first
     * 2. At what position? -> An integer (the index) that we will store in .second
     * ----------------------------------------------------------------------
     */

    #include <iostream>
    #include <vector>
    using namespace std;

    struct Adventurer {
        string name;
        int level;
    };

    // pre: 0 <= index <= v.size()
    // post: returns {true, index} if found, or {false, -1} if it isn't there.
    pair<bool, int> recursiveSearch(const vector<Adventurer>& v, string target, int index) {
        // 1. BASE CASE 1: We have reached the end of the vector (out of bounds) and haven't found it
        if (index == v.size()) {
            return {false, -1};
        }
        // 2. BASE CASE 2: We found it at the current position!
        else if (v[index].name == target) {
            return {true, index};
        }
        // 3. RECURSIVE CASE: It's not here, so we search in the next position (index + 1)
        else {
            return recursiveSearch(v, target, index + 1);
        }
    }

    int main() {
        vector<Adventurer> party;
        string newName;
        int newLevel;

        // --- PHASE 1: REGISTRATION (Sentinel Loop) ---
        cout << "--- ADVENTURER GUILD REGISTRATION ---" << endl;
        cout << "Enter the adventurer's name and level (Type 'END' as name to finish):" << endl;

        // We read the name. If it's not "END", we also read the level and add it to the vector
        cin >> newName;
        while (newName != "END") {
            cin >> newLevel;
            party.push_back({newName, newLevel});

            cout << "> " << newName << " registered successfully!" << endl;
            cin >> newName; // We read the next name to check if it's the sentinel
        }

        cout << endl << ">> Registration closed! Total members: " << party.size() << " <<" << endl << endl;

        // --- PHASE 2: SEARCH (Loop until EOF) ---
        cout << "--- GUILD DATABASE SEARCH ---" << endl;
        cout << "Who are you looking for? (Press Ctrl+D to exit)" << endl;

        string targetName;
        while (cin >> targetName) {

            // We call the recursive function starting from position 0
            pair<bool, int> result = recursiveSearch(party, targetName, 0);

            if (result.first == true) {
                int pos = result.second;
                cout << ">> Found! " << targetName << " is at position " << pos
                     << " with level " << party[pos].level << ". <<" << endl;
            } else {
                cout << ">> " << targetName << " is not registered in the guild. <<" << endl;
            }

            cout << endl << "Who else are you looking for? ";
        }

        cout << endl << "Terminal closed. Goodbye!" << endl;
    }
    ```
