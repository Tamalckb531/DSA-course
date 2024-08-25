#include <iostream>
using namespace std;

int main()
{
    //? Basics
    // int a = 5;
    // char b = 'a';
    // cout << a << endl;
    // int *c = &a; //? This means : a reference variable c pointing towards a int type variable a. It will store the address of a.
    // char *d = &b;
    // cout << c << endl; // will print address of a
    // //? pointer always take 8 bite storage
    // cout << sizeof(c) << endl;
    // cout << sizeof(d) << endl;
    // cout << &c << endl; // will print address of c
    // cout << *c << endl; // Dereference operator : print value inside the address store by c. Or print value of a .

    //? creating null pointer -> init with 0
    // int *ptr = 0;

    //? Question 1:
    // int a = 5;
    // int *ptr = &a;
    // cout << a << endl;
    // cout << &a << endl;
    // // cout << *a << endl; -> will show error as it doesn't store address
    // // cout << ptr << endl;
    // // cout << &ptr << endl;
    // // cout << *ptr << endl;
    // ptr = ptr + 1; // It will now locate in a different address increasing the bite store in it
    // cout << ptr << endl;
    // cout << &ptr << endl;
    // cout << *ptr << endl;

    //? Pointers with array
    int arr[] = {10, 20, 30, 40};
    int *ptr = arr;

    cout << *ptr << endl;
    cout << *(ptr + 1) << endl;
    cout << *ptr + 1 << endl;

    cout << "Hello world!";
    cout << endl;
    return 0;
}