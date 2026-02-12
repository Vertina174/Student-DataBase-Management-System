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

MSYS2 MinGW64 (Recommended for Windows)

Recommended terminal (Windows):

MSYS2 MinGW64

▶️ How to Compile

Run the following command inside the project directory:

g++ main.cpp -o student_db.exe

▶️ How to Run

After successful compilation:

./student_db.exe


The program will display a menu with options to:

Add a student

View all students

Search a student

Update a student

Delete a student

Clear the database

🗂 Data Storage Format

Each record is stored using a fixed-length format:

Field	Size
Name	10 bytes
Space	1 byte
Age	2 bytes
Newline	1 byte

Total size per record: 15 bytes

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