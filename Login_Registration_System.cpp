#include <iostream>
#include <fstream>
using namespace std;

// Login Function
void login()
{
    string username;
    string password;

    string storedUsername;
    string storedPassword;

    bool found = false;

    cout << "\n===== LOGIN =====" << endl;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while(file >> storedUsername >> storedPassword)
    {
        if(username == storedUsername && password == storedPassword)
        {
            found = true;
            break;
        }
    }

    file.close();

    if(found)
    {
        cout << "\nLogin Successful!" << endl;
    }

    else
    {
        cout << "\nInvalid Credentials!" << endl;
    }
}

// Signup Function
void signup()
{
    string username;
    string password;
    string confirmPassword;

    string storedUsername;
    string storedPassword;

    bool exists = false;

    int userCount = 0;

    cout << "\n===== SIGN UP =====" << endl;

    cout << "Enter Username: ";
    cin >> username;

    // Check Duplicate Username + Count Users
    ifstream readFile("users.txt");

    while(readFile >> storedUsername >> storedPassword)
    {
        userCount++;

        if(username == storedUsername)
        {
            exists = true;
        }
    }

    readFile.close();

    if(exists)
    {
        cout << "\nUsername Already Exists!" << endl;
        return;
    }

    cout << "Create Password: ";
    cin >> password;

    cout << "Confirm Password: ";
    cin >> confirmPassword;

    if(password == confirmPassword)
    {
        ofstream writeFile("users.txt", ios::app);

        writeFile << username << " " << password << endl;

        writeFile.close();

        cout << "\nRegistration Successful!" << endl;

        cout << "Total Registered Users: " << userCount + 1 << endl;

        // Open Login After Signup
        login();
    }

    else
    {
        cout << "\nPassword Does Not Match!" << endl;
    }
}

int main()
{
    int choice;

    cout << "===== LOGIN & REGISTRATION SYSTEM =====" << endl;

    cout << "\n1. Sign Up" << endl;
    cout << "2. Login" << endl;

    cout << "\nEnter Your Choice: ";
    cin >> choice;

    if(choice == 1)
    {
        signup();
    }

    else if(choice == 2)
    {
        login();
    }

    else
    {
        cout << "\nInvalid Choice!" << endl;
    }

    return 0;
}
