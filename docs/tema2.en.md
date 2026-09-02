# Iterations (Loops)

## 1. Loop Syntax
So far, we have seen how to write code that runs only once when executed. But what if we want the same fragment of code to repeat repeatedly until a specific condition is met to stop its execution?
This is called a loop, and it is used to iterate over code multiple times. 
In C++, there are two main ways to create a loop:

```cpp
while (condition){
    // ...
}
```

```cpp
for (content) // in content you can put:

for (int i = 0; i < 10; i++){ 
    // ...
}
/* This loop creates a temporary variable "i" initialized to 0 and iterates as long as it is less than 10. 
How it works: i = 0, comparison, code execution, increment.
*/

for (int i = 10; i > 0; i--){ // The same as above but in reverse.
    // ...
}

// if 'i' has already been declared previously, you can omit the variable declaration:

// Example 1:
for (i = 0; ...){

}

// Example 2:
int i = 5;
for (; i < 10; ...){

}
```

---

## 2. Types of While Loops
We have 3 CIRCUMSTANTIAL types of `while` loops for PRO1.

*   **While with a sentinel (or search loop):** It will iterate until it finds a specific character or element to stop.
*   **While until EOF (End Of File):** It will iterate as long as it receives information through the console or a file; when `CTRL + D` is executed in the console or the file runs out of data, the loop will stop.
*   **While with a number of elements:** The loop will run as long as the condition for the number of elements (counter) is met. 

Examples:

??? example "1. SentinelWhile.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main(){
        char ch;
        string result = "";

        cin >> ch;
        while (ch != '0'){ // We want to insert chars into a string until a char is '0'.
            result += ch;
            cin >> ch;
        }

        cout << result << endl;
    }
    ```

??? example "2. WhileEOF.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main(){
        int n;
        int total = 0;

        while (cin >> n){ // The code won't stop until we press CTRL+D in the console.
            total += n;
            cout << total << endl;
        }
    }
    ```

??? example "3. WhileNElements.cpp"

    ```cpp
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
    ```

---

## 3. Final Exercise
To consolidate the use of loops (both `while` and `for`), here is a complete program that generates mountains of asterisks in the console based on the specified height. Execution continues until we force an end-of-file (EOF).

??? example "final.cpp"

    ```cpp
    /*
     * Final Exercise
     * Example: Building Mountains with a Peak of N Altitude.
     * Made by: aso
     */

    #include <iostream>
    using namespace std;

    int main(){
        int n;

        cout << "How many '*' should have the peak of this mountain? (The answer must be an Integer greater or equal than 1): ";

        while (cin >> n) {
            cout << endl;

            if (n < 1) {
                cout << "Invalid Input" << endl;
            } else {
                // Going up the mountain
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j <= i; j++) {
                        cout << '*';
                    }
                    cout << endl;
                }

                // When i = n, the mountain must go back down. Therefore, we start at n - 1.
                for (int i = n - 1; i > 0; i--) {
                    for (int j = i; j > 0; j--) {
                        cout << '*';
                    }
                    cout << endl;
                }
            }

            cout << "And the next mountain? Answer: ";
        }
    }
    ```
