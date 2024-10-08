#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Creating or opening a file to store user credentials
    ofstream file;
    file.open("database.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Unable to open the file.\n";
    }
}

// Function to check if login credentials are correct
bool loginUser() {
    string username, password, u, p;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    ifstream file("database.txt");
    if (file.is_open()) {
        while (file >> u >> p) {
            if (u == username && p == password) {
                file.close();
                return true; // Successful login
            }
        }
        file.close();
    } else {
        cout << "Unable to open the file.\n";
    }
    return false; // Failed login
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            if (loginUser()) {
                cout << "Login successful!\n";
            } else {
                cout << "Login failed! Invalid username or password.\n";
            }
            break;
        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}
