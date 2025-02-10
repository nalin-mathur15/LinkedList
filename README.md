# C++ Linked List Implementation

This project implements a basic singly linked list data structure in C++. It demonstrates essential linked list operations and serves both as an educational tool and as a reusable component for larger coding structures that require a linked list.

---

## Purpose

* **Learn about memory management:**  
  * Dynamic memory allocation using `malloc` and `free`.  
  * Understanding memory leaks and how to prevent them.  
* **Gain familiarity with data structures:**  
  * Implement core linked list operations:  
    * **Insertion (append)**  
    * **Concatenation:** Append one linked list to another (`appendList`)  
    * **Display:** Output the linked list to the console  
    * **Deletion:** Delete the entire linked list  
    * **Sorting:** Sort the linked list using merge sort (`sort`)  
    * **Remove Duplicates:** Remove duplicate elements from a sorted linked list  
* **Improve C++ programming skills:**  
  * Practice object-oriented programming concepts (classes, objects, methods).  
  * Work with pointers, references, and manual memory management.  

---

## Project Structure

* **index.cpp:**  
  Contains the implementation of the `LinkedList` class and an interactive `main()` function. The `main()` function demonstrates the use of various operations, allowing the user to create, modify, and display linked lists.  

---

## Features

* **Interactive Menu:**  
  The interactive `main()` function allows the user to:  
  * Create an initial linked list.  
  * Display the current linked list.  
  * Append new elements to the list.  
  * Append another linked list to the current one.  
  * Sort the list.  
  * Remove duplicate elements.  
  * Clear the current list and create a new one.  

* **Modular Design:**  
  Although user interaction is implemented for demonstration purposes, the `LinkedList` class is designed to be integrated into larger projects where a linked list data structure is required.  

---

## To Build and Run

1. **Ensure you have a C++ compiler installed** (e.g., GCC, Clang).  
2. **Open a terminal or command prompt.**  
3. **Navigate to the project directory.**  
4. **Compile the code:**  
   ```bash
   g++ index.cpp -o linked_list

## Future Improvements
- Add more linked list functions
- Improve memory management for deletion of lists or nodes.
- Implement garbage collector.

## License
This project is licensed under the MIT License.