#include <iostream>
#include <fstream>
using namespace std;

class temp {
    string userName,email,password;
    fstream file;
    public:
    void login();
    void signUp();
    void forgot();
}obj;

int main() {
    char choice;
    cout << "\n1- Login";
    cout << "\n2- Sign Up";
    cout << "\n3- Forgot Password";
    cout << "\n4- Exit";
    cout << "\nEnter Your Choice: ";
    cin >> choice;

    switch(choice) {
        case '1':

        break;
        case '2':

        break;
        case '3':

        break;
        case '4':

        break;
        default:
            cout << "Invalid Selection..";
    }
}

void temp :: signUp(){
        cout << "\nEnter your username: ";
        getline(cin, userName);
        cout << "\nEnter your Email address: ";
        getline(cin, email);
        cout << "\nEnter your Password: ";
        getline(cin, password);

        file.open("loginData.txt", ios :: out | ios :: app);
        file<<userName<<"*"<<email<<"*"<<password<<endl;
        file.close();
}

void temp :: login() {
    string searchName, searchPass;
    cout << "----- Login -----";
    cout << "Masukkan Username anda: ";
    getline(cin,searchName);
    cout << "Masukkan Password anda: ";
    getline(cin,searchPass);

    file.open("loginData.txt", ios :: in);
    getline(file,userName), '*';
    getline(file,email), '*';
    getline(file,password), '*';
    getline(file,userName), '*';

    while(!file.eof()){
        if(userName == searchName);
            if(password == searchPass) {
                cout << "\nLogin Berhasil!";
                cout << "\nUsername: " << userName<<endl;
                cout << "\nemail: " << email<<endl;
            } else {
                cout << "Password salah coba lagi!";
            }
    }

    getline(file,userName), '*';
    getline(file,email), '*';
    getline(file,password), '*';
    getline(file,userName), '*';
}