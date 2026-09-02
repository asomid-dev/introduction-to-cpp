# Structs (Records)

## 1. What is a Struct?

So far, if we wanted to store a student's information (for example, their name, their age, and their grade), we needed three separate variables:
```cpp
string name = "Frieren";
int age = 1250;
double grade = 10.0;
```
This works for a single person, but it becomes chaotic if we have to manage many students and pass this data between functions.

A **struct** (or record) allows us to create our own "data type" by grouping different variables inside it, **even if they are of different types**. 

**The ID Card or Medical Record Analogy:**
Imagine a `struct` as a medical record, an ID card, or a phone contact. It is a single entity (the contact) that contains different sections or fields inside (name, phone number, email).

---

## 2. How to define a Struct

The definition of a `struct` must **always be placed at the very top of the file**, before the functions and `main()`, so that the entire program knows about it.

```cpp
#include <iostream>
using namespace std;

// We define our new data type
struct Student {
    string name;
    int age;
    double grade;
}; // IMPORTANT: DO NOT forget THIS semicolon! It is mandatory.

int main() {
    // ...
}
```

---

## 3. How to declare and access a Struct

Once we have created the "blueprint" (the `struct`), we can create variables of this new type inside `main()` or in functions. 

To access the different fields inside the `struct`, we use a **dot (`.`)**.

```cpp
int main() {
    // We create a variable of type 'Student' named 'student1'
    Student student1;

    // We fill in the data by accessing the fields with a dot
    student1.name = "Megumin";
    student1.age = 14;
    student1.grade = 9.2;

    // We can read the data the exact same way
    cout << "The student " << student1.name << " has a " << student1.grade << endl;
}
```

---

## 4. Reading Structs from the terminal

We can also use `cin` to directly fill in the fields of a `struct`. We just have to remember to do it field by field:

```cpp
int main() {
    Student student2;
    
    cout << "Enter the student's name, age and grade:" << endl;
    cin >> student2.name >> student2.age >> student2.grade;
    
    cout << "Data saved successfully!" << endl;
}
```

---

## 5. Structs and Functions (Very Important)

`structs` can contain a lot of information (imagine a `struct` that stores all the data of a video game or a student's entire academic record). 

If we pass a `struct` to a function by **value**, C++ will make an exact copy of all its variables every time we call the function, wasting memory unnecessarily and making the program run extremely slowly. Therefore, we apply a golden rule: **we always pass them by reference**.

### 1. Normal pass by reference (To modify)
If we want the function to modify any data within the `struct`, we use the `&`.

```cpp
// This function adds one point to the student's grade
void applyBonus(Student& s) {
    s.grade = s.grade + 1.0;
    if (s.grade > 10.0) {
        s.grade = 10.0;
    }
}
```

### 2. Constant pass by reference (Read-only)
If we only want to read the data to print it or do calculations, but we do not want to modify it, we use `const` and `&`. This is the most efficient and secure way, as we avoid making copies while preventing the function from mistakenly modifying the original data.

```cpp
// This function only reads the data and prints it
void printStudent(const Student& s) {
    cout << "--- STUDENT INFO ---" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Age: " << s.age << endl;
    cout << "Grade: " << s.grade << endl;
}
```

---

## 6. Final Exercise
Below you can see a complete example of how to use structs alongside functions by applying pass by reference and limit control.

??? example "final.cpp"

    ```cpp
    /*
     * Final Exercise
     * Example: Adventurer's Status Screen With Structs and Functions (With Limits).
     * Made by: aso
     */

    #include <iostream>
    using namespace std;

    // We define the struct at the very top so the functions can recognize it
    struct Adventurer {
        string name;
        int level;
        double health;
    };

    // pre: true
    // post: reads the data from the terminal and stores it in the struct,
    // ensuring the values make sense.
    void readAdventurer(Adventurer& a) {
        cout << "Enter the adventurer's name, level (1-100) and health (max 9999):" << endl;
        cout << "Example: Frieren 99 1500.5" << endl;

        cin >> a.name >> a.level >> a.health;

        // Error handling: we repeat the read process until the data is valid
        while (a.level < 1 || a.level > 100 || a.health <= 0 || a.health > 9999.0) {
            cout << "Error: Invalid stats for " << a.name << ". Level must be 1-100 and Health 1-9999." << endl;
            cout << "Please enter the data again:" << endl;
            cin >> a.name >> a.level >> a.health;
        }
    }

    // pre: true
    // post: prints the adventurer's current status
    void printAdventurer(const Adventurer& a) {
        cout << "--- ADVENTURER STATUS ---" << endl;
        cout << "Name:    " << a.name << endl;
        cout << "Level:   " << a.level << endl;
        cout << "Health: " << a.health << " HP" << endl;
    }

    // pre: true
    // post: increases the adventurer's level by 1 and boosts their health, respecting the limits
    void levelUp(Adventurer& a) {
        if (a.level >= 100) {
            cout << ">> " << a.name << " is already at maximum level! <<" << endl;
        } else {
            a.level++; // Level up by 1
            a.health = a.health + 50.0; // Give 50 extra health points

            // We make sure not to exceed the maximum health due to the bonus
            if (a.health > 9999.0) {
                a.health = 9999.0;
            }

            cout << ">> " << a.name << " leveled up to level " << a.level << "! <<" << endl;
        }
    }

    int main() {
        Adventurer hero; // We declare our variable of the new struct type

        // 1. Fill in the data (Modification) with the limit filter active
        readAdventurer(hero);
        cout << endl;

        // 2. Print the status screen (Read-only)
        printAdventurer(hero);
        cout << endl;

        // 3. Level up the character (Modification)
        levelUp(hero);
        cout << endl;

        // 4. Print again to check the changes (Read-only)
        printAdventurer(hero);
    }
    ```
