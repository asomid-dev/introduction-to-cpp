# Vectors

## 1. What is a vector?

In the previous topic, we saw how `structs` allow us to group different data of a single entity (such as a single student's name and grade). But what if we want to store the data of 50 students at once without having to create 50 different variables? That's what **vectors** are for.

A vector is a data structure that allows us to store a list or collection of elements of the **same type** (all integers, all strings, or all structs) in an ordered manner.

Imagine a vector as a cabinet with many drawers. Each drawer has a label with a number (the position or index), and inside each drawer, we store a value. 

> **⚠️ IMPORTANT NOTE:** In C++ (and in most programming languages), **we start counting from zero**. The first element of a vector is always at position 0, the second at position 1, and so on. If a vector has 5 elements, its last position is 4.

---

## 2. How to declare a vector

To use vectors in our code, first of all, we must include the `#include <vector>` library at the very top of the file.

The basic syntax to create one is as follows:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Syntax: vector<data_type> vector_name(size, initial_value);
    
    // Example 1: Vector of 5 integers, all initialized to 0 by default.
    vector<int> grades(5, 0); 
    
    // Example 2: Vector of 10 strings, initialized as empty.
    vector<string> words(10); 
    
    // Example 3: Empty vector (size 0), which we can grow later.
    vector<double> prices; 
    
    // Example 4: Vector predefined by the user.
    vector<char> letters = {'H', 'e', 'l', 'l', 'o'};
}
```

---

## 3. How to access a vector's position

After declaring a vector, we must know how to modify and/or access the stored information. 
To do this, we use square brackets `[]` and put the index (the position) we want to go to inside them.

```cpp
vector<int> grades(3, 0); // Vector of 3 integers: [0, 0, 0]

// Modifying values:
grades[0] = 8; // We change the first drawer to an 8. Now we have: [8, 0, 0]
grades[1] = 5; // We change the second drawer to a 5. Now we have: [8, 5, 0]

// Accessing to read:
cout << "The first grade is an: " << grades[0] << endl;
```

**Iterating through a vector with a `for` loop:** This is the mathematical/logical operation you will do most often in PRO1. We use a loop that will start at position `0` to open the drawers one by one, either to fill them with data (`cin`) or to display them (`cout`).

```cpp
// We read 5 grades from the terminal and store them in the vector
vector<int> grades(5);

for (int i = 0; i < 5; i++) {
    cin >> grades[i];
}
```

---

## 4. Vector methods

Vectors in C++ come with built-in tools (called methods) that make working with them much easier. To call a method, we simply write the vector's name followed by a dot `.` and the tool's name.

The two star methods you will use daily are:

### 1. `.size()`
It returns the current size of the vector (how many elements it has). It is **fundamental** to use it as the limit in `for` loops. This way, if you change the vector's size tomorrow, the loop adapts automatically, saving you from errors and out-of-bounds access.

```cpp
vector<int> grades(5);

// The loop will run as many times as the vector's size (5 in this case)
for (int i = 0; i < grades.size(); i++) { 
    cout << grades[i] << endl;
}
```

### 2. `.push_back(value)`
It adds a new element right at the end of the vector. This method is great because it makes the vector "grow" in size automatically. It is very useful when reading a sequence of data but you don't know how many there are in total (for example, an EOF loop), since you can start with an empty vector and fill it up.

```cpp
vector<int> evens; // We create an empty vector (size 0)

evens.push_back(2); // The vector grows. It's now size 1 and contains: [2]
evens.push_back(4); // Now it's size 2 and contains: [2, 4]
evens.push_back(6); // Now it's size 3 and contains: [2, 4, 6]
```

---

## 5. Examples

??? example "1. WordsWithVectors.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        // We create a predefined character vector
        vector<char> letters = {'H', 'e', 'l', 'l', 'o'};

        cout << "Printing the vector letter by letter: ";

        // We iterate through it exactly like any other vector
        for (int i = 0; i < letters.size(); i++) {
            cout << letters[i];
        }

        cout << endl; // The output will be "Hello"
    }
    ```

In this example, we observe that a vector of `char`s and a `string` have similar things; this is because a `string` is actually a vector of `char`s, and we can access a specific position of a `string`:

??? example "2. StringVector.cpp"

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        string word = "Hello";

        // 1. We can use .size() to know how many letters it has
        cout << "The word has " << word.size() << " letters." << endl;

        cout << "Accessing specific positions:" << endl;

        // 2. We can use square brackets [] to read single letters
        cout << "First letter (position 0): " << word[0] << endl;
        cout << "Last letter (position 4): " << word[4] << endl;

        cout << "Spelling with a for loop:" << endl;

        // 3. We can iterate through the string with a for loop just like we do with vectors
        for (int i = 0; i < word.size(); i++) {
            cout << "- " << word[i] << endl;
        }
    }
    ```

??? example "3. PushBack.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        // 1. We create a completely empty vector (size 0)
        vector<int> numbers;
        int n;

        cout << "Enter several numbers (press Ctrl+D to finish): " << endl;

        // 2. We keep reading data until there is no more (EOF)
        while (cin >> n) {
            // In each iteration, we add the read number to the end of the vector.
            numbers.push_back(n);
        }

        cout << endl;
        cout << "Reading finished!" << endl;

        // 3. Thanks to .size(), we know exactly how many elements we saved
        cout << "You have entered " << numbers.size() << " numbers in total." << endl;

        cout << "The stored numbers are: ";

        // 4. We iterate through the vector to show that everything was saved in order
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
    ```

---

## 6. Vectors and Functions (Very Important)

When we pass a vector to a function, we must be very careful with memory. By default, C++ passes parameters by **value** (it makes a copy). If our vector has 1,000,000 elements, making a copy every time we call a function will cause the program to run extremely slowly or crash.

For this reason, in C++, **VECTORS ARE ALWAYS PASSED BY REFERENCE**.

There are two ways to do this depending on what we want to do with the vector inside the function:

### 1. We want to modify the vector (Normal pass by reference)
If the function needs to alter the original vector's data (for example, to sort it or add things), we pass it by reference by adding an `&`.

```cpp
// This function sets all elements of the vector to 0
void resetVector(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = 0;
    }
}
```

### 2. We only want to read the vector (Constant pass by reference)
If we only want to read the information (for example, to sum the grades, or to search for a number), we don't want to make copies, but we also don't want the function to mistakenly modify the vector. In this case, we use `const` before the type and the `&` at the end. This is called **constant pass by reference (read-only)**.

```cpp
// This function only reads the vector, modification is forbidden
int sumElements(const vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum = sum + v[i];
    }
    return sum;
}
```

---

## 7. Final Exercise

This exercise combines everything we've seen: we will create a system to store multiple students (`structs`) inside a `vector`, read data until the user decides to stop (using an EOF loop and `.push_back()`), and pass this vector by reference to various functions to read and modify its data.

??? example "final.cpp"

    ```cpp
    /*
     * Final Exercise
     * Example: Grade Manager With Structs, Vectors and Functions.
     * Made by: aso
     */

    #include <iostream>
    #include <vector>
    using namespace std;

    struct Student {
        string name;
        double grade;
    };

    // pre: true
    // post: prints the names and grades of all students
    void printGrades(const vector<Student>& v) {
        for (int i = 0; i < v.size(); i++) {
            cout << "- " << v[i].name << ": " << v[i].grade << endl;
        }
    }

    // pre: the vector 'v' is not empty (v.size() > 0)
    // post: returns the class average grade
    double calculateAverage(const vector<Student>& v) {
        double sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum = sum + v[i].grade;
        }
        return sum / v.size();
    }

    // pre: true
    // post: adds 1 point to all vector grades, with a maximum of 10
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

        // Now the terminal explanation makes it clear it's for MULTIPLE students
        cout << "--- STUDENT RECORD SYSTEM ---" << endl;
        cout << "Enter the students' names and grades." << endl;
        cout << "You can add as many as you want! (Press Ctrl+D to finish)" << endl;
        cout << "Example:" << endl;
        cout << "Frieren 10.0" << endl;
        cout << "Megumin 8.5" << endl;
        cout << "Mugi 9.2" << endl;
        cout << "-----------------------------------" << endl;

        // We continuously read data until the user closes (Ctrl+D)
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

        // Visual confirmation that different students have been added to the vector
        cout << ">> Successfully loaded " << classList.size() << " students into the system. <<" << endl << endl;

        // 2. Constant pass by reference
        cout << "--- BEFORE THE BONUS ---" << endl;
        printGrades(classList);
        cout << "Class average: " << calculateAverage(classList) << endl;

        cout << endl;

        // 3. Normal pass by reference
        cout << "Applying +1 bonus to everyone..." << endl;
        applyBonus(classList);

        cout << endl;

        // 4. We check the changes
        cout << "--- AFTER THE BONUS ---" << endl;
        printGrades(classList);
        cout << "New class average: " << calculateAverage(classList) << endl;
    }
    ```
