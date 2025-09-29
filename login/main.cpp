#include <iostream>
#include <fstream>
using namespace std;

class temp {
    string userName, email, password;
    string searchName, searchPass, searchEmail;
    fstream file;
public:
    void login();
    void signUp();
    void forgot();
} obj;

int main() {
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice: ";
    cin >> choice;
    cin.ignore();

    switch(choice) {
        case '1': obj.login(); break;
        case '2': obj.signUp(); break;
        case '3': obj.forgot(); break;
        case '4': return 0;
        default: cout << "Invalid Selection.." << endl;
    }
}

void temp::signUp() {
    cout << "\nEnter your username: ";
    getline(cin, userName);
    cout << "Enter your Email address: ";
    getline(cin, email);
    cout << "Enter your Password: ";
    getline(cin, password);

    file.open("loginData.txt", ios::out | ios::app);
    file << userName << "*" << email << "*" << password << endl;
    file.close();

    cout << "Sign Up berhasil!" << endl;
}

void temp::login() {
    cout << "----- Login -----" << endl;
    cout << "Masukkan Username anda: ";
    getline(cin, searchName);
    cout << "Masukkan Password anda: ";
    getline(cin, searchPass);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cout << "Belum ada data tersimpan!" << endl;
        return;
    }

    bool found = false;
    while (getline(file, userName, '*') &&
           getline(file, email, '*') &&
           getline(file, password)) {
        if (userName == searchName && password == searchPass) {
            cout << "\nLogin Berhasil!" << endl;
            cout << "Username: " << userName << endl;
            cout << "Email   : " << email << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Login gagal. Username atau Password salah." << endl;
    file.close();
}

void temp::forgot() {
    cout << "\nEnter your username: ";
    getline(cin, searchName);
    cout << "Enter your email address: ";
    getline(cin, searchEmail);

    file.open("loginData.txt", ios::in);
    if (!file) {
        cout << "Data tidak ditemukan!" << endl;
        return;
    }

    bool found = false;
    while (getline(file, userName, '*') &&
           getline(file, email, '*') &&
           getline(file, password)) {
        if (userName == searchName && email == searchEmail) {
            cout << "Akun Ketemu!" << endl;
            cout << "Password kamu adalah: " << password << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Akun tidak ditemukan." << endl;
    file.close();
}