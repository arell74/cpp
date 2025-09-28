#include <iostream>

using namespace std;

int penjumlahan(int a, int b) {
        return a + b;
    }

int pengurangan(int a, int b) {
    return a - b;
}

int perkalian(int a, int b) {
    return a * b;
}

int pembagian(int a, int b) {
    return a / b;
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
    // int tambah = penjumlahan(49, 51);
    // int kurang = pengurangan(86, 87);
    // int kali = perkalian(74, 80);
    // int bagi = pembagian(100, 6);

    // log(tambah);
    // log(kurang);
    // log(kali);
    // log(bagi);

    // perkondisian
    int rapot = 90;
    
    if(rapot >= 90) {
        cout << "Anda jenius coyy";
    } else if(rapot > 70) {
        cout << "Tingkatkan lagi belajarnya lee";
    } else {
        cout << "Duh main game bae sih..";
    }

    return 0;
}