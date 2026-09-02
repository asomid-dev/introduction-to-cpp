# Fundamental Algorithms (Searching and Sorting)

## 1. What are Fundamental Algorithms?

So far we have learned the basic building blocks of C++ (loops, functions, vectors, structs...). Now that we know how to build tools, it's time to learn **how to use them to solve the most classic computer science problems**: searching for information and sorting it.

To understand the importance of this, imagine you have a 10,000-page dictionary that is completely out of order, and you have to search for the word "Recursion". If you check page by page (linear search), it might take you hours. On the other hand, if the dictionary is sorted alphabetically, you can open it in the middle and quickly discard halves until you find it in seconds.

**Why do we study these algorithms in PRO1?**
1. **Efficiency:** A bad algorithm can make your program take hours to solve a problem that a good algorithm solves in milliseconds (and the FIB's Jutge will give you a *Time Limit Exceeded* error).
2. **Foundations:** Understanding how to sort (Sort) and how to search (Search) is the baseline for understanding much more complex data structures in the future (PRO2 and EDA).

---

## 2. The magic of C++: `std::sort`

Before we start writing code to sort vectors manually, you should know a secret: C++ already has an incredibly fast and optimized function that does it for you. It is called `std::sort` and it is part of the `<algorithm>` library.

In real life (and in problems where you are not forced to do it by hand), you will always use this function to sort vectors, since it is programmed with a highly advanced hybrid algorithm (Introsort) that is much faster than the ones we will see here.

### How is it used with basic types?
If you have a vector of integers or strings, C++ already knows how to compare them (it knows that 2 is less than 5, or that 'A' comes before 'B'):
```cpp
#include <iostream>
#include <vector>
#include <algorithm> // MANDATORY to use sort()
using namespace std;

int main() {
    vector<int> v = {5, 2, 9, 1, 5, 6};

    // We sort the vector from smallest to largest (by default)
    // v.begin() indicates the start, and v.end() the end of the vector.
    sort(v.begin(), v.end()); 

    // Now 'v' is: {1, 2, 5, 5, 6, 9}
}
```

### How to sort a custom `Struct`? (The `cond` function)
What happens if we have a vector of adventurers (a `struct`) and we want to sort them? C++ doesn't know if you want to sort them by level, by name, or by age. 
We have to give it the instructions ourselves by creating a boolean function (usually called `cond` or `cmp`) that tells it **who should go first**. This function receives two elements by constant reference and returns `true` if the first element should go before the second.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Adventurer {
    string name;
    int level;
};

// pre: true
// post: returns true if the adventurer 'a' should go BEFORE 'b' in the sorted vector
bool cond(const Adventurer& a, const Adventurer& b) {
    // 1st Criterion: We want to sort by level from HIGHEST to LOWEST
    if (a.level != b.level) {
        return a.level > b.level;
    }
    // 2nd Criterion (Tie-breaker): If they have the same level, sort by name alphabetically
    return a.name < b.name;
}

int main() {
    vector<Adventurer> party = {
        {"Megumin", 45},
        {"Frieren", 100},
        {"Retzel", 50},
        {"Sigrid", 45} // Ties in level with Megumin
    };

    // We pass our 'cond' function as the third parameter!
    sort(party.begin(), party.end(), cond);

    /* The final order will be:
       1. Frieren (100)
       2. Retzel (50)
       3. Megumin (45) -> Goes before Sigrid because 'M' comes before 'S'
       4. Sigrid (45)
    */
}
```

*So... why do we have to learn to build these algorithms by hand?* Because in PRO1, you will be evaluated to see if you **understand the internal logic**. So let's roll up our sleeves and see how they work on the inside!

---

## 3. Types of Algorithms (What we will cover)

**Binary Search** is used to check if an element exists inside a **previously sorted** vector. This algorithm is very important because its cost is exponentially lower compared to searching for an element from the beginning of the vector to the end (linear search).

**Why is it so efficient?**
Because at each step we divide the problem in half. We go to the center position and check which half the element we are looking for should be in (automatically discarding the entire other half). We perform this division as many times as necessary until we find the element. If the boundaries cross, it means it is not there, and we return `-1`.

??? example "1. BinarySearch.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    //pre: v is sorted in ascending order, 0 <= left, right < v.size().
    //post: returns the position of 'x' inside 'v'. Returns -1 if 'x' is not there.
    int binarySearch(const vector<int>& v, int x, int left, int right){
        // BASE CASE 1: The boundaries have crossed (the element is not there).
        if (left > right) return -1;

        int mid = (left + right) / 2;
        // RECURSIVE CASE: 'x' is towards the right.
        if (v[mid] < x) { return binarySearch(v, x, mid + 1, right); }
        // RECURSIVE CASE: 'x' is towards the left.
        if (v[mid] > x) { return binarySearch(v, x, left, mid - 1); }

        // BASE CASE 2: We found it in the middle (v[mid] == x).
        return mid;
    }

    int main(){
        vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        int x = 0;
        cout << "Which number's position do you want to find? ";
        cin >> x;

        int pos = binarySearch(v, x, 0, v.size() - 1);

        if (pos != -1){
            cout << "\nYour number is located at index " << pos << '.' << endl;
        } else{
            cout << "\nYour number is NOT in the vector." << endl;
        }
    }
    ```

To understand what Selection Sort does, we must imagine we have some playing cards and we want to arrange them on the table. 

Out of all the cards, we look for the smallest one and swap it with the one in the first position. Once we have the first one secured, we look for the smallest of the remaining cards and swap it with the one in the second position. We do this continuously until the whole vector is sorted.

??? example "2. SelectionSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    //pre: v.size() > 0.
    //post: returns the vector 'v' sorted in ascending order.
    void selectionSort(vector<int>& v){
        if (v.empty()) return; // THIS IS A SAFEGUARD IF THE FUNCTION'S PRECONDITION IS VIOLATED.

        for (int i = 0; i < v.size(); i++){
            int lowest = i;
            for (int j = i+1; j < v.size(); j++){
                if (v[j] < v[lowest]){
                    lowest = j;
                }
            }

            if (lowest != i){ // There is a smaller number, we swap
                int aux = v[i];
                v[i] = v[lowest];
                v[lowest] = aux;
            }
        }
    }

    int main() {
        vector<int> v = {64, 25, 12, 22, 11};

        cout << "Original vector: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        selectionSort(v);

        cout << "Sorted vector:   ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    ```

This algorithm works exactly the same way as when we sort poker cards in our hand.

Suppose the first card is already sorted. We take the second card (we save it in variable `x`) and compare it with the one to its left. If it is smaller, we shift the larger card to the right and keep looking backwards until we find its exact place to "insert" it. We repeat this with all the cards from left to right.

This version here is the **optimized version**, because instead of constantly doing full *swaps*, we store the value we are placing (`x`), shift the large values to the right (`v[j] = v[j-1]`), and finally we drop `x` into the empty gap that was left.

??? example "3. InsertionSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    //pre: v.size() > 1;
    //post: returns the vector 'v' sorted in ascending order.
    void insertionSort(vector<int>& v){
        if (v.size() < 2) return; // safeguard if

        for (int i = 1; i < v.size(); i++){
            int j = i;
            int x = v[i];

            // As long as we don't reach the beginning and the previous element is greater than 'x'
            while (j > 0 && x < v[j-1]){
                v[j] = v[j-1]; // We shift to the right
                j--;
            }
            v[j] = x; // We insert the card into its correct gap
        }
    }

    int main() {
        vector<int> v = {64, 25, 12, 22, 11};

        cout << "Original vector: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        insertionSort(v);

        cout << "Sorted vector:   ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    ```

The fusion function is not a complete sorting algorithm for any unsorted vector, but rather a **specific tool** designed exclusively to merge two vectors that **are already sorted** into a single one.

Through a very clever single loop and three indices (`i1`, `i2`, and `k`), the program decides which of the two vectors has the smallest number at any given moment to place it into the resulting vector. We first check if one of the two vectors has already run out of elements to avoid reading invalid memory (Segmentation Fault). This function is the central and fundamental piece that makes the magic of *Merge Sort* possible.

??? example "4. FusionSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    // pre: v1 and v2 are sorted in ascending order
    // post: returns a sorted vector resulting from merging v1 and v2
    vector<int> fusionSort(const vector<int>& v1, const vector<int>& v2) {
        int n = v1.size() + v2.size();
        vector<int> res(n);
        int i1 = 0, i2 = 0, k = 0;

        while (k < n) {
            // 1. If v1 is exhausted, we must take from v2
            if (i1 == v1.size()) {
                res[k] = v2[i2];
                i2++;
            }
            // 2. If v2 is exhausted, we must take from v1
            else if (i2 == v2.size()) {
                res[k] = v1[i1];
                i1++;
            }
            // 3. If neither is exhausted, we compare (using <= to avoid infinite loops on ties)
            else if (v1[i1] <= v2[i2]) {
                res[k] = v1[i1];
                i1++;
            }
            // 4. If the one in v2 is smaller
            else {
                res[k] = v2[i2];
                i2++;
            }

            k++; // k always advances no matter what
        }

        return res;
    }

    int main() {
        // Vectors of different sizes to really put it to the test
        vector<int> v1 = {1, 3, 5, 7, 9};
        vector<int> v2 = {2, 4, 6, 8, 10, 12, 14};

        cout << "Vector 1: ";
        for (int i = 0; i < v1.size(); i++) {
            cout << v1[i] << " ";
        }
        cout << endl;

        cout << "Vector 2: ";
        for (int i = 0; i < v2.size(); i++) {
            cout << v2[i] << " ";
        }
        cout << endl;

        vector<int> result = fusionSort(v1, v2);

        cout << "Merged vector: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    ```

What happens if we want to sort using our fusion function, but the original vector is completely unsorted? If we pass it directly to `fusionSort`, the result will be invalid. To solve this, we use the **Merge Sort** algorithm (Divide and Conquer).

**What does Merge Sort do?** 
Basically, it divides the vector in half, generating two smaller vectors (`left` and `right`). Then, it continuously divides these halves using recursion until we reach vectors of size 1. 
Since by definition a vector of just 1 element **is already sorted**, our `fusionSort` function can start putting them together two by two upwards, rebuilding and sorting the entire original vector with spectacular speed.

Merge Sort teaches us exactly the magic of recursion and how important it is for day-to-day programming.

??? example "5. MergeSort.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    // pre: v1 and v2 are sorted in ascending order
    // post: returns a sorted vector resulting from merging v1 and v2
    vector<int> fusionSort(const vector<int>& v1, const vector<int>& v2) {
        int n = v1.size() + v2.size();
        vector<int> res(n);
        int i1 = 0, i2 = 0, k = 0;

        while (k < n) {
            if (i1 == v1.size()) {
                res[k] = v2[i2];
                i2++;
            } else if (i2 == v2.size()) {
                res[k] = v1[i1];
                i1++;
            } else if (v1[i1] <= v2[i2]) {
                res[k] = v1[i1];
                i1++;
            } else {
                res[k] = v2[i2];
                i2++;
            }
            k++;
        }
        return res;
    }

    // pre: true
    // post: returns the vector 'v' sorted in ascending order
    vector<int> mergeSort(const vector<int>& v) {
        // BASE CASE: An empty vector or a vector with 1 element is already sorted
        if (v.size() <= 1) {
            return v;
        }

        // DIVISION: We calculate the middle
        int mid = v.size() / 2;

        // We create the two sub-vectors (left and right)
        vector<int> left;
        vector<int> right;

        for (int i = 0; i < mid; i++) left.push_back(v[i]);
        for (int i = mid; i < v.size(); i++) right.push_back(v[i]);

        // RECURSION: We sort each of the halves
        vector<int> sorted_left = mergeSort(left);
        vector<int> sorted_right = mergeSort(right);

        // FUSION: We merge the already sorted parts back together
        return fusionSort(sorted_left, sorted_right);
    }

    int main() {
        vector<int> v = {38, 27, 43, 3, 9, 82, 10};

        cout << "Original vector: ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        // We call the complete mergeSort
        vector<int> result = mergeSort(v);

        cout << "Sorted vector:   ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    ```

---

## 4. Final Exercise

Below you will see how to combine sorting and searching to solve a complete problem where data needs to be structured and searched efficiently.

??? example "final.cpp"

    ```cpp
    /*
     * Final Exercise
     * Example: Player Registration and Search System (Binary Search).
     * Made by: aso
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

    // pre: true
    // post: returns true if player 'a' has an ID strictly less than player 'b'
    bool cond(const Player& a, const Player& b) {
        return a.id < b.id;
    }

    // pre: vector 'v' is sorted by ID in ascending order, 0 <= left, right < v.size()
    // post: returns the position of the player with the searched id, or -1 if they don't exist
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
    ```
