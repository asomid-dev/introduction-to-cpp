# Functions

## 1. What is a function?

So far, all the code we have written has been placed inside `int main() { ... }`. This works for small programs, but as the code grows, keeping everything in a single block becomes chaotic. 

A **function** is like a "mini-program" within your code that handles a specific task.

To understand how a function works, imagine a coffee machine. We have a coffee machine, and we need to provide it with water and coffee powder for it to give us a ready-to-drink coffee. A function works exactly the same way. It receives parameters (water and coffee powder) and returns a result.

**Why do we use functions?**
1. **Reusability:** If we need to calculate the least common multiple 10 times, we don't want to write the same code 10 times. We write it once and call the function.
2. **Order and readability:** It allows us to break down a large, complex problem into smaller, easily solvable problems.

---

## 2. Function Syntax

The function must be defined and declared before `main()`. It has the following structure:

```cpp
//pre: 
//post: 
return_type functionName(type parameter1, type parameter2){
    // code
    return result;
}
```

- **Pre:** In the precondition (`pre`), we state what the code or parameters must satisfy for the function to execute correctly. If the function always works regardless of the input, we write `true`.
- **Post:** Explains what the function does, what it returns as a result, or which variables it modifies.
- **Return type:** What will the function return? An `int`, `double`, `string`, `bool`, or `char`?
- **Function name:** A descriptive name (e.g., `calculateArea`, `isEven`).
- **Parameters:** The data the function needs to work, placed inside parentheses. If the function doesn't need any data, the parentheses are left empty `()`.
- **return:** The keyword that sends the result out of the function. Once `return` is executed, the function stops immediately.

## Parameters

Parameters can be passed by:
- **Value:** A temporary copy is made, and it does not modify anything in `main`.
```cpp
//pre: ...
//post: ...
int imAFunc(int a, int b){ 
    // ...
}
```

- **Reference:** No copy is made, meaning we modify the actual parameter received from `main`.
```cpp
void imAFunc(int &a){ 
    // if we modify 'a', it also changes in main.
}
```

---

## 3. Procedures (void)

Sometimes we want a function to perform a specific action (like printing a message to the console, drawing something, or modifying an external variable) but **we don't need it to return any value**.

In these cases, instead of using `int` or `string` as the return type, we use `void` ("empty").

`void` functions do not include the `return result;` statement. (At most, they can include an empty `return;` to stop the function early).

---

## 4. Examples

??? example "1. SumaVariables.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: true
    //post: returns the sum of two integer elements.
    int sum(int a, int b){
        return a + b;
    }

    int main(){
        int n1 = 5;
        int n2 = 10;
        cout << sum(n1,n2) << endl;
    }
    ```

??? example "2. MCD.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: a >= 0, b >= 0
    //post: returns the GCD using the Euclidean algorithm.
    int mcd(int a, int b){
        while (b != 0){
            int aux = b;
            b = a % b;
            a = aux;
        }
        return a;
    }

    int main(){
        int n1 = 4;
        int n2 = 2;
        cout << mcd(n1,n2) << endl;
    }
    ```

*IMPORTANT NOTE: THIS CODE IS NOT OPTIMIZED, IT IS JUST TO SHOW AN EXAMPLE.*

??? example "3. IsPrime.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: a >= 2
    //post: returns true if the number is prime; if not, returns false.
    bool isPrime(int a){
        if (a < 2){ // BASE CASE: if 'a' is less than 2, then it is not prime.
            return false;
        }
        int counter = 0;
        for (int i = 1; i <= a; i++){ // We check how many divisors does 'a' have.
            if (a % i == 0){
                counter++;
            }
        }
        if (counter > 2){ // If 'a' has more than 2 divisors, then it is not prime.
            return false;
        } else{
            return true;
        }
    }

    int main(){
        int n1;

        cout << "Enter an integer number: ";
        while (cin >> n1){
            cout << endl;

            if (isPrime(n1)){
                cout << n1 << " is prime." << endl;
            } else{
                cout << n1 << " is NOT prime." << endl;
            }

            cout << "Enter an integer number: ";
        }
    }
    ```

??? example "4. HiName.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: true
    //post: prints a greeting to the person in the console.
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
    ```

??? example "5. Swap.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    //pre: true
    //post: swaps the numbers.
    void swapNumbers(int &a, int &b){
        int aux = b;
        b = a;
        a = aux;
    }

    int main(){
        int a = 5;
        int b = 2;

        cout << "a: " << a << " b: " << b << endl;

        swapNumbers(a, b);
        cout << "a: " << a << " b: " << b << endl;
    }
    ```

**There is no final.cpp for this topic since it is purely theoretical.**
