# University Coursework Repository

This repository contains solutions and projects developed for various Computer Engineering and Informatics Department (CEID) laboratory exercises and courses.

---

## 💻 1. C Programming Lab (1st Semester)

A collection of foundational programming exercises focusing on core C language concepts, control flow, functions, and string handling.

| File | Description | Concepts Covered |
| :--- | :--- | :--- |
| `MostFrequentNumber.c` | Finds the longest sequence of the same consecutive integer in a stream of input numbers. | Loops, input handling. |
| `FourDigitNumbers.c` | Finds and prints all **4-digit Armstrong Numbers** (where the number equals the sum of its digits raised to the 4th power). | Loops, arithmetic manipulation, array pre-calculation. |
| `Divisors.c` | Determines if an integer is a **Prime Number** and, if not, lists all its proper divisors. | Prime number check, functions, pointers. |
| `HailstoneSequenceV*.c` | Implements the **Hailstone (Collatz) Sequence** calculator, printing the sequence until it reaches 1. | Loops, conditional logic. |
| `Menu.c` | A menu-driven calculator program supporting basic arithmetic, logarithms (`log10`), and powers (`pow`). | `switch` statements, mathematical functions. |
| `StringHandling.c` | Basic C program demonstrating string input (`getStringV2`) and output operations. | String handling, `getchar()`. |
| `WordsHandlingV1.c` | Command-line application for managing a list of words (add, display, sort, search, statistical analysis). | Arrays of strings, `strcmp()`, nested loops for sorting. |
| `FibonacciV*.c` | Calculates and prints terms of the **Fibonacci Sequence** using both recursive (`V1`) and iterative array (`V2`) methods. | Recursion, arrays, iterative calculation. |
| `Orders.c` | Calculates the total cost of a bottle order, applying tiered discounts based on total cost or quantity. | `if/else if` logic, floating-point arithmetic. |
| `OrdersHandlingApp.c` | A robust CLI application for managing **Factory Orders** (Pending, Ready, Closed) with functionality to execute, close, and **save/load data to files**. | `struct`, file I/O (`fopen`, `fscanf`), complex menu management. |
| `ClassroomApp.c` | A management system for seating students in a lab, including registration, searching by name/ID/position, and **data persistence** using binary files. | `struct`, File I/O (binary), 2D arrays, string comparison. |

---

## 🛠️ 2. C++ Lab (2nd Semester)

Exercises demonstrating object-oriented programming (OOP) principles in C++, focusing on classes, inheritance, operator overloading, and STL containers.

| File | Description | Concepts Covered |
| :--- | :--- | :--- |
| `askisi1/kouti.cpp` | Defines the `Kouti` (Box) class and demonstrates **Operator Overloading** by defining `operator+` to add the dimensions of two boxes. | Classes, constructors, operator overloading. |
| `askisi1/q1.cpp` | Reads two $N \times N$ matrices from user input and calculates their element-wise sum. | Dynamic memory allocation (`new int*[N]`), nested loops, console I/O. |
| `askisi2/q1*.cpp` | Demonstrates usage of the C++ **`std::vector`** container, including dynamic size changes (`push_back`), access, iteration, and resizing. | STL `vector`, iterators. |
| `askisi2/q2.cpp` | Implements a simple `Kouti` class to calculate the **Ogkos** (Volume) using `get` and `set` accessor methods. | Class methods, encapsulation. |
| `askisi2/q3.cpp` | Demonstrates **Polymorphism** and **Multiple Inheritance** using `Polygon` (virtual function), `Rectangle`, and `PaintCost` classes. | `virtual` functions, Multiple Inheritance, object pointers. |
| `rock_paper_scissors.cpp` | A simple console-based **Rock-Paper-Scissors game** implemented using a C++ class with helper methods. | Classes, `enum` types, random number generation. |

---

## ☕ 2. Java Lab (2nd Semester)

Exercises exploring core Java OOP concepts, inheritance, method overriding, and container classes.

| File | Description | Concepts Covered |
| :--- | :--- | :--- |
| `Askisi1/Age.java` | Handles **command-line arguments (`args[]`)** to process and print a person's name and age. | Command line arguments, `if/else if` control flow. |
| `Askisi2/Window.java` | Simple class demonstrating basic constructors and accessor methods (`getSize`). | Class structure, encapsulation. |
| `Askisi3/MWindow.java` | Demonstrates **Inheritance** and **Method Overriding** where `MWindow` extends `Window`, showing access to superclass methods (`super.SetSize`). | `extends`, `super`, method overriding. |
| `Askisi4/Tester.java` | Demonstrates **Polymorphism** and **Collection Handling**. It tests an `ArrayList` and native arrays containing mixed `Robot` and `RobVehicle` objects. | Inheritance hierarchy (`Robot` $\rightarrow$ `RobVehicle`), Polymorphism, `ArrayList`, `Iterator`. |

---

## 📐 3. Algorithms Lab (3rd Semester)

Projects focused on implementing and analyzing classical graph and sorting algorithms.

| File | Description | Algorithm / Concept |
| :--- | :--- | :--- |
| `ex1.cpp` | Finds the maximum even and minimum odd values in a list of numbers loaded from a file and performs in-place swaps. | Array traversal, basic min/max search. |
| `ex2.cpp` | Implements a **Max-Heap** data structure with core operations (`insert`, `extractMax`, `replaceMax`) including detailed tracing of the `heapifyUp` and `heapifyDown` processes. | Max-Heap, Priority Queue, Heapify. |
| `ex3.cpp` | Implements the **Merge Sort** algorithm to sort a list of numbers in **descending order**, combined with a **Binary Search** implementation for lookup. | Divide and Conquer, Merge Sort (descending), Binary Search. |
| `ex4.cpp` | Implements **Depth First Search (DFS)** on a graph to systematically traverse and **classify every edge** as either Tree, Forward, Back, or Cross. | DFS, Edge Classification. |
| `ex5.cpp` | Implements **Breadth First Search (BFS)** to find the shortest path/level from a starting node to a target node in an unweighted graph. | BFS, Shortest Path in unweighted graphs, queue usage. |
