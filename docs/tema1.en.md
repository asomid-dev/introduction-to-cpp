# C++ Basics and Compiling

## 1. Syntax
The syntax of C++ is simple. In PRO1, you will use the `<iostream>` library for most exercises to handle code input and output.
To include a library, we simply write `#include <library>` at the beginning of a `.cpp` or `.cc` file (C++ formats).

Besides the library, we also use a "namespace". A namespace acts like a function prefix; for example, if the standard library (`std`) has a `cout` function and a custom library *paco* has a function with the same definition `paco`, the prefix prevents conflicts. To avoid writing the prefix repeatedly (e.g., `std::cout`), we add the following line after the libraries (as per the course's standard structure): `using namespace std;`.

Every C++ program has a main function (`main`), which the compiler looks for to execute the code. (The example shows the declaration of the main function).

Example:
```cpp
#include <iostream>
using namespace std;

int main() {
    
}
```

To add comments to a code (text that does not affect our code), we just need to write `//` (single-line comment) or `/* */` (block comment).

```cpp
#include <iostream>
using namespace std;

// This is a comment only for this line.

/* 
This is a comment
until the block 
is closed 
*/

int main() {
    // ...
}
```

---

## 2. Variable Types
We have different variable types:
*   `int` (integers) -> (e.g., `124`)
*   `string` (words) -> (e.g., `"Hello"`)
*   `char` (characters) -> (e.g., `'a'`) **Note:** a character is stored using its ASCII value; for instance, `'0'` is `48`.
*   `double` (decimals) -> (e.g., `67.67`)
*   `bool` (true or false) -> (e.g., `true`) **Note:** it can also be declared with `1` (true) and `0` (false).

To declare variables, we use a keyword that assigns a value to that name. 
Additionally, we can make a variable a **constant**, meaning its value will never change. We simply put `const` in front of the variable declaration.

Example of how to declare a variable:
```cpp
#include <iostream>
using namespace std;

int main() {
    // Structure: type variable_name = value;
    int number = 124; // Every time we define a value, we must include the ; 
    string word = "Frieren";
    char ch = 'a';
    double sixseven = 67.67;
    
    // Just as we can assign number = 124, we can do the following:
    int aux = number; // Since number equals 124, 
                      // we can assign this value to another variable.
    
    // Declaration of a constant:
    const int restricted_age = 18;
}
```

---

## 3. Input and Output
Now that we know how variables work, we will learn how to compile a `.cpp` file, input data through the terminal, and print data to the terminal.

First, we will do the classic exercise for any programming language:

??? example "1. HelloWorld.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        cout << "Hello World!" << endl; 
        
        // cout: Console OUTput
        // << insertion operator for cout (means: show whatever comes next on the console)
        // endl: reserved word in the std library, a character that means end of line (end line)
    }
    ```

To see "Hello World!" in the terminal, we need to compile. How do we do it? Easy.
In the Linux terminal, navigate to the file's directory:
```bash
cd /home/aso/CODE/cpp
g++ file.cpp -o executable
./executable
```
You can name the executable whatever you want; out of habit, I always use `x.x`, while others create one executable per program.

Example of compilation and execution with HelloWorld:
```bash
g++ HelloWorld.cpp -o x.x
./x.x 
```
After running `./x.x`, you will see in the terminal: `Hello World!`

> **NOTE:** Remember to always save (`CTRL + S` or `CTRL + G`) before compiling to avoid silly compilation errors.

??? example "2. HelloName.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        string name; // Declaration without assigning a value
                     // In C++, a string receives the empty value "" by default.
                     
        cout << "What is your name?" << endl; 
        cin >> name; // We type the name in the terminal with ONLY ONE word. 
        cout << "Hello " << name << '!' << endl;
        
        // cin: Console INput
        // >> extraction operator for cin (means: input the received value into the variable)
    }
    ```

When using a `cin`, we input the requested values and press the Enter key to notify the code that we have provided the information. 

> **IMPORTANT DIFFERENCES BETWEEN `cin` AND `cout` WITH STRINGS**
> With a `cin`, we can only input **one word** per `string` variable. The `cin` command treats a space as the end of the string.
> On the other hand, with `cout`, when we write `cout << "phrase with spaces" << endl;`, it prints the entire phrase to the console without cutting it off.

---

## 4. Logic Operators and Comparators

### Arithmetic Operators
| Type | Declaration |
| :--- | :--- |
| Addition | `+` |
| Subtraction | `-` |
| Multiplication | `*` |
| Division | `/` |
| Modulo (Remainder) | `%` |
| Assignment | `=` |

> **NOTE:** The division `/`, when dividing integers, will return the integer part. Conversely, if we divide doubles, it will return the exact decimal division. Therefore, we can never do `double % double`, since decimal division itself inherently accounts for the remainder.

### Compound and Increment Operators
```cpp
// assume i is an integer

i++; // post-increment -> after working with i, 
     // we increment by 1, meaning: i = i + 1.

++i; // pre-increment -> before working with i, 
     // we increment by 1.

// post-decrement and pre-decrement can also be done

i += 20; // translation: i = i + 20
 
i /= 2; // translation: i = i / 2;
```

Example:

??? example "3. PostAndPreExample.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main(){
        // Post-Decrement Example
        int i = 5;
        int a = i--; // 'a' keeps the 5. Once assigned, 'i' drops to 4.
        cout << "POST-DECREMENT -> a: " << a << ", i: " << i << endl;

        // Pre-Decrement Example
        int j = 5;
        int b = --j; // 'j' drops to 4 immediately. Then it is assigned, so 'b' is also 4.
        cout << "PRE-DECREMENT -> b: " << b << ", j: " << j << endl;

        // post-increment and pre-increment work the same way:
        i = 5;
        a = i++; // 'a' keeps the 5. Once assigned, 'i' increases to 6.
        cout << "POST-INCREMENT -> a: " << a << ", i: " << i << endl;

        j = 5;
        b = ++j; // 'j' increases to 6 immediately. Then it is assigned, so 'b' is also 6.
        cout << "PRE-INCREMENT -> b: " << b << ", j: " << j << endl;
    }
    ```

### Logic Operators
| Type | Declaration |
| :---- | :--------- |
| AND   | `&&`       |
| OR    | \|\|       |
| NOT   | `!`        |


### Logical Comparators

*A comparator always yields a boolean result (`true` or `false`)*

| Type | Declaration |
| :--- | :--- |
| Greater than | `a > b` |
| Less than | `a < b` |
| Greater than or equal to | `a >= b` |
| Less than or equal to | `a <= b` |
| Strictly equal | `a == b` |
| Not equal | `a != b` |

---

## 5. Conditionals
In programming, we use conditionals: `if`, `else if`, `else`.

We always declare the `if` first. If there is a second condition we want to handle after the first one fails, we use `else if`. For all other cases (the exceptions), we use `else`.
For structural clarity and elegance, we will always open a `{}` block after the conditional statement.

??? example "4. CanYouDrink.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        int age = 0; // everyone is at least 0 years old
        
        cout << "How old are you? (type your age with a number (i.e. 24))" << endl;
        cin >> age;
        
        if (age >= 18) { // We check if the age is greater than or equal to 18.
            cout << "You can drink alcohol" << endl;
        } else {
            cout << "You can't drink alcohol" << endl;
        } 
    }
    ```

---

## 6. Final Exercise
To consolidate everything we have seen in this first topic (variables, `cin`/`cout`, operators, and conditionals), here is a complete program that implements a basic single-use calculator. 

??? example "final.cpp"

    ```cpp
    /*
     * Final Exercise
     * Example: Basic Single-Use Calculator.
     * Made by: aso
     */

    #include <iostream>
    using namespace std;

    int main(){
        int a, b;
        char op;
        bool correct = true;

        cout << "Type an integer operation with only one operator (i.e. 24 - 12), valid operators: +, -, *, /, %." << endl;
        cin >> a >> op >> b; // read number a, operator, number b

        int result = 0; // Whenever a number is printed to the screen, we initialize it to 0 for safety.
        if (op == '+'){
            result = a + b;
        } else if (op == '-'){
            result = a - b;
        } else if (op == '*'){
            result = a * b;
        } else if (op == '/'){
            if (b != 0){ // In PRO1 they always test for the weak points of the exercise.
                result = a / b;
            } else{ // b == 0
                correct = false;
            }
        } else if (op == '%'){
            if (b != 0){
                result = a % b;
            } else{ // b == 0
                correct = false;
            }
        } else{ // invalid operator
            correct = false;
        }
        
        if (correct){
            cout << "The operation is equal to " << result << '.' << endl;
        } else{
            cout << "Error: Invalid operator or division by zero" << endl;
        }
    }
    ```
