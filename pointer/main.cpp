#include <iostream>

using namespace std;

void swipe(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    // int a = 10;
    // int *b = &a;
    // *b = 100;

    // cout << "Mem adress of a : " << &a << endl;
    // cout << "Nilai a Adalah : " << a << endl;

    // // cout << "Mem adress of b : " << &b << endl;
    // cout << "Nilai b Adalah : " << *b << endl;
    // return 0;

    int a = 10;
    int b = 20;
    
    swipe(&a, &b);

    cout << "Mem adress of a : " << &a << endl;
    cout << "Nilai a Adalah : " << a << endl;

    cout << "Mem adress of b : " << &b << endl;
    cout << "Nilai b Adalah : " << b << endl;
    return 0;
}