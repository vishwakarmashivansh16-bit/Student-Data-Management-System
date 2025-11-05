/*
------------------------------------------------------------
|   Project Title : Student Data Management System (C++)    |
|   Author        : SHIVANSH VISHWAKARMA                    |
|   Language      : C++                                     |
|   Date Created  : November 2025                           |
|   Version       : 1.0                                     |
|-----------------------------------------------------------|
|   Description:                                            |
|   This project is a console-based Student Data Management |
|   System built using C++ file handling. It allows users to |
|   add, display, and search student records that are saved  |
|   in a file.                                               |
|                                                           |
|   Features:                                               |
|   ➤ Add new student records and save them in a file       |
|   ➤ Display all student records in a formatted table      |
|   ➤ Search specific student details using roll number     |
|   ➤ Uses binary file I/O for fast data access             |
|   ➤ Beginner-friendly and well-commented code             |
------------------------------------------------------------
*/

#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

// ===========================================================
//                 CLASS DEFINITION : student
// ===========================================================
class student {
    // ---- Private Data Members ----
    string name;
    int rollno;
    float marks;
    string date;   // Date of Birth

public:
    // -------------------------------------------------------
    // FUNCTION: getdata()
    // PURPOSE : Input student details from the user
    // -------------------------------------------------------
    void getdata() {
        cin.ignore(); // Clears input buffer to avoid getline() issues
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Roll No: ";
        cin >> rollno;
        cout << "Enter Marks: ";
        cin >> marks;
        cin.ignore();
        cout << "Enter the Date of Birth: ";
        getline(cin, date);
    }

    // -------------------------------------------------------
    // FUNCTION: showdata()
    // PURPOSE : Display student information in formatted style
    // -------------------------------------------------------
    void showdata() {
        cout << left << setw(15) << name
             << setw(10) << rollno
             << setw(10) << marks
             << setw(15) << date << endl;
    }

    // ---- Getter Functions ----
    int getRollno() const { 
        return rollno; }
    float getmarks() const {
         return marks; }
    string getname() const {
         return name; }
    string getdate() const { 
        return date; }
};

// ===========================================================
//             FUNCTION DECLARATIONS (PROTOTYPES)
// ===========================================================
void addstudent();              // Adds a new student record
void displaystudent();          // Displays all student records
void searchstudent(int rollno); // Searches for a specific student

// ===========================================================
//                        MAIN FUNCTION
// ===========================================================
int main() {
    int choice, roll;

    // Repeat menu until user chooses to exit
    do {
        cout << "\n==============================================\n";
        cout << "     🧾 STUDENT DATA MANAGEMENT SYSTEM 🧾      \n";
        cout << "==============================================\n";
        cout << "1. ADD STUDENT\n";
        cout << "2. DISPLAY STUDENT DATA\n";
        cout << "3. SEARCH STUDENT\n";
        cout << "4. EXIT\n";
        cout << "----------------------------------------------\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        // ---- Menu Handling using switch-case ----
        switch (choice) {
            case 1: {
                addstudent();
                break;
            }
            case 2: {
                displaystudent();
                break;
            }
            case 3: {
                cout << "Enter Student Roll No: ";
                cin >> roll;
                searchstudent(roll);
                break;
            }
            case 4: {
                cout << "\nExiting Program... Thank you! 👋\n";
                break;
            }
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }

    } while (choice != 4); // Continue until exit option is chosen

    return 0;
}

// ===========================================================
//              FUNCTION: addstudent()
// PURPOSE : Add a new student and save to file
// ===========================================================
void addstudent() {
    ofstream file("student.txt", ios::app); // Open file in append mode
    student s;
    s.getdata();                            // Get student details from user
    file.write((char*)&s, sizeof(s));       // Write binary object data
    file.close();
    cout << "✅ Record added successfully!\n";
}

// ===========================================================
//             FUNCTION: displaystudent()
// PURPOSE : Display all students stored in file
// ===========================================================
void displaystudent() {
    ifstream file("student.txt", ios::in);  // Open file in read mode
    student s;

    cout << "\n=============== ALL STUDENT RECORDS ===============\n";
    cout << left << setw(15) << "NAME"
         << setw(10) << "ROLL NO"
         << setw(10) << "MARKS"
         << setw(15) << "DATE OF BIRTH" << endl;
    cout << "---------------------------------------------------\n";

    // Read and display all records
    while (file.read((char*)&s, sizeof(s))) {
        s.showdata();
    }

    file.close();
}

// ===========================================================
//             FUNCTION: searchstudent(int rollno)
// PURPOSE : Search a student record by roll number
// ===========================================================
void searchstudent(int rollno) {
    ifstream file("student.txt", ios::in);  // Open file for reading
    student s;
    bool found = false;

    // Search record by roll number
    while (file.read((char*)&s, sizeof(s))) {
        if (s.getRollno() == rollno) {
            cout << "\nRecord Found Successfully ✅\n";
            cout << left << setw(15) << "NAME"
                 << setw(10) << "ROLL NO"
                 << setw(10) << "MARKS"
                 << setw(15) << "DATE OF BIRTH" << endl;
            cout << "---------------------------------------------------\n";
            s.showdata();
            found = true;
            break;
        }
    }

    // If no matching record found
    if (!found)
        cout << "❌ Record not found!\n";

    file.close();
}
