# Bookshop Inventory Management System (OOP - C++)

A **Bookshop Inventory Management System** implemented using **Object-Oriented Programming (OOP)** principles in **C++**.
This console-based application allows bookshop owners to manage book records efficiently using **classes**, **inheritance**, and **file handling**.

---

## Key Features

* Add New Books
* View All Books
* Search Books by Title or Author
* Update Book Information
* Delete Books from Inventory
* Purchase Books (Stock Management + Total Bill)

---

## Technologies Used

| Technology              | Purpose                             |
| ----------------------- | ----------------------------------- |
| **C++**                 | Programming Language                |
| **OOP Concepts**        | Classes, Inheritance, Encapsulation |
| **File Handling**       | Persistent Storage (`book.txt`)     |
| **Console Application** | User Interaction                    |

---

## Project Structure

```
Bookshop-inventory-management-system-OOP-CPP-
│
├── main.cpp           # Main source code (OOP-based implementation)
├── book.txt           # Auto-generated data file (stores book records)
├── README.md          # Project documentation (this file)
```

---

## How It Works

1. **Menu-driven Interface:**
   The user selects operations from a console-based menu.

2. **Book Management System:**

   * **Add**: Enter details like Title, Author, Publisher, Price, Quantity.
   * **Search**: Find books by Title or Author.
   * **Update**: Modify existing book details.
   * **Delete**: Remove books from the inventory.
   * **Purchase**: Calculate total cost and update stock.

3. **OOP Implementation:**

   * **Class `Book`**: Handles individual book data.
   * **Class `Shop`**: Manages inventory operations.

4. **Data Storage:**
   All operations persist using `book.txt` as storage.

---

## Usage Guide

### 1️⃣ Clone the Repository:

```bash
git clone https://github.com/m-wasiq-37/Bookshop-inventory-managment-system-OOP-CPP-.git
cd Bookshop-inventory-managment-system-OOP-CPP-
```

### 2️⃣ Compile and Run:

For Windows:

```bash
g++ main.cpp -o bookshop
bookshop.exe
```

For Linux/macOS:

```bash
g++ main.cpp -o bookshop
./bookshop
```

---

## Example Menu Output

```
=========== BOOKSHOP INVENTORY SYSTEM (OOP) ===========

1. Add New Book
2. View All Books
3. Search Book
4. Update Book
5. Delete Book
6. Purchase Book
7. Exit

Enter your choice:
```

---

## Learning Objectives

This project helps you:

* Practice **OOP in C++**
* Use **File Handling for data storage**
* Understand **CRUD operations** in C++
* Build **real-world console applications**

---

## Limitations

* No GUI (Console-based only)
* No database (Uses text file storage)
* Basic input validation only

---

## Future Improvements (Optional Ideas)

* Add **Graphical User Interface (GUI)** with Qt or SFML.
* Integrate with **Database** (e.g., SQLite/MySQL).
* Implement **User Authentication** (Admin/Employee).
* Add **Reporting Features** (Daily Sales, Stock Reports).

---

## Contribution

If you'd like to contribute:

1. Fork the repository
2. Create a feature branch
3. Submit a Pull Request

---

## License

This project is **open-source** and available under the **MIT License**.

---

## Acknowledgements

Created by **[M Wasiq](https://github.com/m-wasiq-37)**
For academic purposes and hands-on practice with **OOP in C++**.
