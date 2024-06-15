#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class temp
{
    string username, email, password;
    fstream file;
public:
    void login();
    void signup();
    void forgot();
} obj;

int main()
{
    char choice;
    while (true) {
        cout << "\n1 - Login";
        cout << "\n2 - Signup";
        cout << "\n3 - Forgot Password";
        cout << "\n4 - Exit";
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        cin.ignore();  // to ignore the newline character left in the buffer

        switch (choice)
        {
        case '1':
            obj.login();
            break;
        case '2':
            obj.signup();
            break;
        case '3':
            obj.forgot();
            break;
        case '4':
            return 0;
        default:
            cout << "Invalid Selection";
        }
    }
}

void temp::signup() {
    cout << "\nEnter Your Name: ";
    getline(cin, username);
    cout << "Enter Your Email Address: ";
    getline(cin, email);
    cout << "Enter Your Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << username << "*" << email << "*" << password << endl;
    file.close();

    cout << "Signup successful!" << endl;
}

void temp::login() {
    string searchName, searchPass;
    cout << "------------LOGIN---------" << endl;
    cout << "Enter your username: ";
    getline(cin, searchName);
    cout << "Enter your Password: ";
    getline(cin, searchPass);

    bool found = false;

    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, username, '*');
            getline(file, email, '*');
            getline(file, password, '\n');

            if (username == searchName) {
                if (password == searchPass) {
                    cout << "\nAccount Login successful..!";
                    cout << "\nUsername: " << username << endl;
                    cout << "Email: " << email << endl;
                    found = true;
                    break;
                }
                else {
                    cout << "Password is incorrect" << endl;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << "Username not found" << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void temp::forgot() {
    cout << "\nEnter Your Username: ";
    getline(cin, username);
    cout << "Enter Your Email Address: ";
    string searchEmail;
    getline(cin, searchEmail);

    bool found = false;

    file.open("loginData.txt", ios::in);
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, username, '*');
            getline(file, email, '*');
            getline(file, password, '\n');

            if (username == username && email == searchEmail) {
                cout << "\nAccount Found.." << endl;
                cout << "Your password: " << password << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "\nAccount not found" << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}
