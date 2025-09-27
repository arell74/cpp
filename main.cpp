#include <iostream>

using namespace std;

int penjumlahan(int a, int b) {
        return a + b;
    }

void log(int result) {
    cout << "Hasil akhirnya adalah: " << result << endl;
}

int main() {
    // cout << "hello world" << endl;
    // int umur = 18;
    // const double tinggi = 189.5;

    // umur = 20;

    // cout << "my umur is " << umur << " dan " << "my tinggi is " << tinggi;

    // int x = 49;
    // int y = 51;
    // int z = x + y;

    // cout << "Hasil dari x + y adalah " << z;

    // tugas 2
    // int a = 5;
    // int b = 15;
    // int c = a + b;
    // cout << "Penjumlahan antara " << a << " dengan nilai " << b << " adalah " << c;

    

    //function
    int hasil1 = penjumlahan(49, 51);
    int hasil2 = penjumlahan(86, 87);

    log(hasil1);
    log(hasil2);

    return 0;
}