#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class temp {
    string userName, Email, password;
    string searchName, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signUp();
    void forgetPassword();
};

void temp::signUp() {
    cin.ignore(); // Add this line to ignore any previous newline characters
    cout << "\n Enter Your User Name :";
    getline(cin, userName);
    cout << "\n Enter Your Email Address :";
    getline(cin, Email);
    cout << "\n Enter Your PassWord : ";
    getline(cin, password);

    file.open("loginDataa.txt", ios::out | ios::app);
    file << userName << "*" << Email << "*" << password << endl;
    file.close();
}

void temp::login() {
    cin.ignore(); // Add this line to ignore any previous newline characters
    string searchName, searchPass;
    cout << "--------------Login-----------" << endl;
    cout << "Enter Your User Name : " << endl;
    getline(cin, searchName);
    cout << "Enter Your Password : " << endl;
    getline(cin, searchPass);

    file.open("loginDataa.txt", ios::in);
    
    while (getline(file, userName, '*')) {
        getline(file, Email, '*');
        getline(file, password, '\n');

        if (userName == searchName && password == searchPass) {
            cout << "Login Successful .. Welcome " << endl;
            cout << "\nUserName :: " << userName << endl;
            cout << "\n Email :: " << Email << endl;
            file.close();
            return;
        }
    }

    cout << "\n Invalid Credential !!!!" << endl;
    file.close();
}

void temp::forgetPassword() {
    cin.ignore(); // Add this line to ignore any previous newline characters
    cout << "Enter your user name ::" << endl;
    getline(cin, searchName);
    cout << "\n Enter your Email :: ";
    getline(cin, searchEmail);

    file.open("loginDataa.txt", ios::in);

    while (getline(file, userName, '*')) {
        getline(file, Email, '*');
        getline(file, password, '\n');

        if (userName == searchName && Email == searchEmail) {
            cout << "\n Account Found : ";
            cout << "Your Password is : " << password << endl;
            file.close();
            return;
        }
    }

    cout << "\n Account Not Found" << endl;
    file.close();
}

int main() {
    temp obj; // create an object of the class
    char choice;

    do {
        cout << "\n 1- Login";
        cout << "\n 2- Sign-Up";
        cout << "\n 3- Forgot Password";
        cout << "\n 4- Exit";
        cout << "\n Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                obj.login();
                break;
            case '2':
                obj.signUp();
                break;
            case '3':
                obj.forgetPassword();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Selection...!" << endl;
        }
    } while (choice != '4');

    return 0;
}
