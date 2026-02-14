Student Database Management System (C++)
📌 Project Description

This is a simple student database management system written in C++.
The project uses a text file (student_data.txt) to store student records.

This project was built to understand:

File handling in C++

Fixed-length record storage

Random file access using seekg() and seekp()

Basic database operations without external libraries

The system currently stores student name and age only.

🛠 Technologies Used

C++

Standard Library (fstream, iostream, iomanip, cstring)

Text File Storage

📂 Project Structure
Student_Database/
│
├── main.cpp              → Main source file
├── student_data.txt      → Database file (auto-created if not present)
└── README.md

⚙️ Requirements

C++ Compiler (g++)

Windows / Linux / macOS

Recommended terminal (Windows):

▶️ How to Compile

Run the following command inside the project directory:

g++ Student_manager.cpp -o student_db.exe

▶️ How to Run

After successful compilation:

./student_db.exe


The program will display a menu with options to:

1. Add a student

2. View all students

3. Search a student

4. Update a student

5. Delete a student

6. Clear the database

🗂 Data Storage Format

Each record is stored using a fixed-length format:

Field	Size
Name	10 bytes
Space	1 byte
Age	2 bytes
Newline: 2 bytes for windows(/r/n), 1 bytes for linux & mac os(/n)

Total size per record/Line: 15 bytes or 14 bytes

This structure allows direct modification of specific records using file pointer repositioning.

⚠️ Important Notes

Maximum name length is 10 characters.

Age is limited to 2 digits.

Data is stored in plain text format.

Improper input may cause formatting issues.

The file must not be manually edited to maintain structure consistency.

🎯 Project Level

This project is suitable for:

Beginner to Intermediate C++ learners

Students learning file handling

Anyone practicing low-level file database logic

🚀 Future Improvements

Add unique student ID

Input validation improvements

Dynamic record length

Sorting functionality

Binary file implementation

Simple GUI version

👨‍💻 Author

Created as a learning project to practice file handling and database logic in C++.