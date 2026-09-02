# Matrices

## 1. What is a Matrix in programming and its Syntax

Just like in geometry or linear algebra, a matrix in programming is an ordered set of vectors (rows) that can be visualized as a table of values. In C++, we can define an integer matrix as `std::vector<std::vector<int>> Matrix;`. This structure is what we call a "vector of vectors" (Matrix), which allows us to manage a collection of rows and columns dynamically.

We can traverse or iterate through a matrix in the exact same way we use loops in the **Vectors** topic.

**Example**: 
Suppose we have the following integer matrix (2 rows x 3 columns):
[ 1  2  3 ]
[ 4  5  6 ]

 **How to access a specific element?**

```cpp
// To access the element in row 1 and column 2 (remember: we start counting from 0!), we do:
int value = matrix[1][2]; // value = 6

// In general, to access the element in row i, column j:
int value = matrix[i][j];

// You can also modify this value just like with vectors:
matrix[0][1] = 99; // Now the matrix is: [ 1 99 3 ] / [ 4 5 6 ]
```

---

## 2. Initializing a matrix

As we saw with vectors, a matrix can store any data type, ranging from an `int` to a `Struct`. To work with matrices, it is important not to forget to include the vector library using `#include <vector>`.

Let's create some basic matrices:

??? example "InitializeMatrices.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        // 3x4 integer matrix, initialized to 0
        vector<vector<int>> int_matrix(3, vector<int>(4, 0));
        // [ 0  0  0  0 ]
        // [ 0  0  0  0 ]
        // [ 0  0  0  0 ]

        // 2x2 double matrix, each element initialized to 3.14
        vector<vector<double>> double_matrix(2, vector<double>(2, 3.14));
        // [ 3.14  3.14 ]
        // [ 3.14  3.14 ]

        // "Empty" matrix (no initial fixed size)
        vector<vector<string>> string_matrix;
        // [ ]
        
        // Manual assignment of a character matrix
        vector<vector<char>> char_matrix = {
            {'A', 'B', 'C'},
            {'D', 'E', 'F'}
        };
    }
    ```

---

## 3. Iterating over a matrix

A matrix can be seen as a "vector of vectors". Therefore, to iterate over each of its elements, we need two loops: one to traverse the rows and another to traverse the columns of each row. This is called a **nested loop** (double iteration).

The basic syntax would look like this:

```cpp
// Suppose we have a matrix of dimensions nrows x ncolumns:
vector<vector<int>> matrix(nrows, vector<int>(ncolumns, 0));

// To traverse all elements and perform an action (like printing them):
for (int i = 0; i < nrows; i++) { // We iterate over the rows
    for (int j = 0; j < ncolumns; j++) { // For each row, we iterate over each column
        cout << matrix[i][j] << " "; // We access the item at row i, column j
    }
    cout << endl; // Line break when finishing each row
}
```

> **NOTE:** Remember that the index `i` traverses the rows and the index `j` traverses the columns within each row.

---

## 4. Examples

### Example 1: Print an integer matrix

??? example "1. PrintMatrix.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<int>> matrix = {
            {1, 2, 3},
            {4, 5, 6}
        };

        int rows = matrix.size();
        int columns = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        // Output:
        // 1 2 3
        // 4 5 6
    }
    ```

### Example 2: Sum all elements of a double matrix

??? example "2. SumMatrix.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<double>> matrix = {
            {1.1, 2.2},
            {3.3, 4.4}
        };

        double sum = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                sum += matrix[i][j];
            }
        }
        cout << "The total sum is: " << sum << endl;
        // Output: The total sum is: 11
    }
    ```

### Example 3: Change an element in a character matrix

??? example "3. ChangeElement.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        vector<vector<char>> letters = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'}
        };

        letters[0][1] = 'z'; // We change the 'b' to a 'z'

        for (int i = 0; i < letters.size(); i++) {
            for (int j = 0; j < letters[i].size(); j++) {
                cout << letters[i][j] << " ";
            }
            cout << endl;
        }
        // Output:
        // a z c
        // d e f
    }
    ```

### Example 4: Read an integer matrix from the keyboard

??? example "4. ReadMatrix.cpp"

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        int rows, columns;
        cin >> rows >> columns;
        vector<vector<int>> matrix(rows, vector<int>(columns));

        // We read the values row by row, column by column
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cin >> matrix[i][j];
            }
        }

        // We display the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    ```

---

## 5. Important Notes
### 1. Pass by reference
Just like in the vectors topic, it is important to remember that if we want to pass a matrix as a function parameter, we use the reference operator `&`. For more information, review the vectors topic.

### 2. Typedef Matrix
Sometimes, PRO1 professors define a data type called 'Matrix' (or 'Matriu' in Catalan) using the following definition:
```cpp
typedef vector< vector<int> > Matrix;
```
This simply indicates that the word 'Matrix' is equivalent to writing `vector<vector<int>>`, therefore, `vector<vector<int>> nums;` and `Matrix nums;` are completely equivalent.

---

## 6. Final Exercise

Here is an advanced-level exercise that will require you to combine everything you know about matrices, nested loops, and finding maximums to locate the best submatrix.

??? example "final.cpp"

    ```cpp
    /*
    * Final Exercise
    * Example: Find the Square Submatrix with the Maximum Sum
    * Made by: Uri
    */

    /*
    This program reads a matrix of positive integers with f rows and c columns (the user first inputs f and c,
    then the matrix values), and then reads a positive integer k (1 <= k <= min(f,c)).
    The program searches within the matrix for the square submatrix of size k x k whose sum of elements
    is the maximum. It prints:
    - The value of this maximum sum.
    - The corresponding k x k submatrix (in the same layout as the original), corresponding to the first one (top to bottom, left to right) with the maximum sum found, in case of a tie.

    Example:
    Input:
    4 5
    1 2 0 3 4
    0 6 3 4 1
    2 4 5 2 3
    1 0 1 1 1
    3

    Output:
    Maximum sum: 29
    Submatrix:
    6 3 4
    4 5 2
    0 1 1
    */

    #include <iostream>
    #include <vector>
    using namespace std;

    int main() {
        int f, c;
        cin >> f >> c; // We read rows and columns
        // We read the integer matrix
        vector<vector<int>> matrix(f, vector<int>(c));
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        
        int k;
        cin >> k; // We read the size of the square submatrix

        // Variables to store the maximum sum and the position of the best submatrix
        int max_sum = 0; // The maximum sum found so far (minimum 0)
        int best_i = 0, best_j = 0; // Coordinates of the start of the best submatrix

        // We iterate through all possible submatrices of size k x k
        for (int i = 0; i <= f - k; ++i) {
            for (int j = 0; j <= c - k; ++j) {
                int current_sum = 0; // Sum of the elements of the current submatrix
                // We calculate the sum of this submatrix
                for (int a = 0; a < k; ++a)
                    for (int b = 0; b < k; ++b)
                        current_sum += matrix[i + a][j + b];
                // If the sum of this submatrix is better, we store it
                if (current_sum > max_sum) {
                    max_sum = current_sum;
                    best_i = i;
                    best_j = j;
                }
            }
        }

        // We print the result
        cout << "Maximum sum: " << max_sum << endl;
        cout << "Submatrix:" << endl;
        // We display the submatrix with the maximum sum
        for (int a = 0; a < k; ++a) {
            for (int b = 0; b < k; ++b)
                cout << matrix[best_i + a][best_j + b] << " ";
            cout << endl;
        }
    }
    ```
