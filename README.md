# Readme for Binary Search Tree Inventory System

## Overview

This project implements a Binary Search Tree (BST) data structure for managing an online bookstore inventory system. It uses templates to support a wide range of data types and includes additional features for searching, adding, deleting, and updating books in the inventory.

The main files include:

- `binarySearchTree.h`: Defines the binary search tree class and its methods.
- `binaryTree.h`: Provides the base class for a binary tree.
- `Book`: A class representing book details, including ISBN, title, author, genre, and quantity.
- `main.cpp`: Implements the inventory management system and user menu.

---

## Features

### Binary Search Tree Operations

1. **Search:** Check if an item exists in the tree.
2. **Insert:** Add a new item to the tree.
3. **Delete:** Remove an item from the tree.
4. **Traversal:** Perform inorder, preorder, and postorder traversals.
5. **Search with Options:** Search books by title, author, ISBN, or genre.
6. **Find Popular Genre:** Determine the genre with the highest quantity in stock.

### Bookstore Inventory Operations

1. **Display Inventory:** List all books in the inventory using inorder traversal.
2. **Add a New Book:** Add a new book to the inventory.
3. **Remove a Book:** Remove a book by its ISBN.
4. **Search for a Book:** Search books based on various criteria.
5. **Update Quantity:** Update the stock of a specific book.
6. **Buy a Book:** Process book purchases and update inventory.
7. **Track Popular Genre:** Identify the most popular genre based on available quantity.
8. **Total Sales:** Track the total number of books sold.
9. **Load Inventory from File:** Import inventory data from a file.

---

## Class Descriptions

### 1. **`binaryTreeType`**

#### Methods:

- `isEmpty`: Checks if the tree is empty.
- `inorderTraversal`, `preorderTraversal`, `postorderTraversal`: Perform tree traversals.
- `treeHeight`, `treeNodeCount`, `treeLeavesCount`: Calculate tree properties.
- `search`: Abstract function to be implemented by derived classes.
- `insert`: Abstract function to be implemented by derived classes.
- `deleteNode`: Abstract function to be implemented by derived classes.

### 2. **`bSearchTreeType`** (Derived from `binaryTreeType`)

#### Methods:

- `search`: Check if an item exists in the tree.
- `insert`: Add a new node to the tree.
- `deleteNode`: Remove a node from the tree.
- `searchWithOptions`: Search for a book by title, author, ISBN, or genre.
- `findPopularGenre`: Identify the most popular genre in the inventory.
- `searchRetrieval`: Retrieve details of a specific book.

### 3. **`Book`**

#### Attributes:

- `title`, `author`, `genre`, `isbn`, `quantity`

#### Methods:

- Getters and setters for all attributes.
- Overloaded operators for comparisons (`==`, `>`, `<`) and I/O (`<<`, `>>`).

---

## Input/Output File Format

The inventory file should have the following format (comma-separated):

```
ISBN,Title,Author,Genre,Quantity
123,Book A,Author A,Genre A,10
124,Book B,Author B,Genre B,8
...
```

---

## Usage

### Running the Program

1. Compile the program using a C++ compiler.
2. Run the executable.
3. Use the menu to interact with the inventory system:
   - Display books.
   - Add, search, update, or remove books.
   - Load inventory from a file.

### Example Menu Interaction

```
Welcome to Online Bookstore Inventory System
Please choose from the following options:
1. Display All Books (Inorder Traversal)
2. Add a New Book
3. Remove a Book by ISBN
4. Search for a Book
5. Update Book Quantity
6. Find Popular Genre
7. Buy a Book
8. Total Books Sold
9. Load from a file
10. Exit
```

---

## Dependencies

- Standard Template Library (STL) headers: `<iostream>`, `<vector>`, `<string>`, `<fstream>`, `<sstream>`.

---

## Compilation

Use the following command to compile:

```bash
g++ main.cpp -o bookstore_inventory
```

---

## Future Enhancements

1. Implement additional search and sorting algorithms.
2. Add support for exporting inventory to a file.
3. Include a graphical user interface (GUI).
4. Extend `Book` to include more attributes like publisher or publication year.
5. Add error handling for invalid user input.

---

## Author

Divas Online Bookstore Inventory System

