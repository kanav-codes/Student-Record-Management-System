# Student Record Management System

A menu-driven console application built in **C** to efficiently handle, store, and manage student records. This project demonstrates core programming concepts like file handling, structures, and data manipulation in C.

## 🚀 Features
- **Add New Records:** Insert details like Name, Roll Number, Course, and Marks/GPA.
- **View All Records:** Display a well-formatted list of all registered students.
- **Search Student:** Search for a specific student's details instantly using their Roll Number.
- **Modify/Update:** Edit existing student information without altering other data.
- **Delete Record:** Remove a student's record from the system permanently.
- **Persistent File Storage:** Data is safely stored in a file, so records are preserved even after closing the program.

## 🛠️ Tech Stack & Concepts Used
- **Language:** C
- **Core Concepts:** 
  - Structures (for organizing student data)
  - File Handling (`fopen`, `fprintf`, `fscanf`, `fclose` or binary file methods)
  - Functions & Control Flow (for the menu-driven interface)

## 💻 How to Run the Project

### Prerequisites
You need a C compiler (like GCC) installed on your system.

### Steps to Execute
1. Clone this repository or download the source code files.
2. Open your terminal/command prompt in the project folder.
3. Compile the C file using the following command:
   ```bash
   gcc main.c -o student_system
4.Run the compiled executable:

On Windows:

DOS
student_system.exe
On Linux/Mac:

Bash
./student_system


## 📋 Future Enhancements
- Adding a login system for admin security.
- Improving the console UI with tabular representations.
- Implementing search features by student name.

---
*Developed as a practical implementation of structural  programming and file handling in C.*
## 📊 Project Screenshots

Here are the sample runtime screenshots of the application:

### 1. Main Menu
![Main Menu](image/menu.png)

### 2. View/Add Records Output
![Student Records Output](image/output.png)