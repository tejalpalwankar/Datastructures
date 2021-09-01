#include <iostream>
using namespace std;

// // ye bolra hai muje double pointer dedo mai tumahre double pointer ko increase karunga.But isme p mai uski copy ban gayi and uske copy mai changes hore hai toh apna pointer change nai hoga
// // void increment1(int **p){
// //     p = p + 1;
// // }

// // // abhi ye jaake pointer ka address change karega.
// // // ** = 730
// // // * = 900 -> 904 toh uska address change hoga
// // // toh changes reflect hojayege
// // void increment1(int **p){
// //     *p = *p + 1;
// // }

// // // changes reflect honge
// // void increment1(int **p){
// //     **p = **p + 1;
// // }

// int main()
// {
//     // int i = 10;
//     // int *p = &i;
//     // int **p2 = &p;

//     // cout << p2 << endl;
//     // cout << &p << endl;

//     // cout << p << endl;
//     // cout << *p2 << endl;
//     // cout << &i << endl;

//     // cout << i << endl;
//     // cout << *p << endl;
//     // cout << **p2 << endl;

//     int a[10];

//     // dono same hai
//     cout << a << endl;
//     cout << &a[0] << endl;

//     a[0] = 10;
//     a[1] = 20;

//     // address of 1st elee
//     cout << *a << endl;
//     cout << *(a + 1) << endl;

//     int *p = &a[0];

//     cout << a << endl;
//     cout << p << endl;

//     cout << &a << endl;
//     cout << &p << endl;

//     cout << sizeof(p) << endl;
//     cout << sizeof(a) << endl;

//     // p = p + 1;
//     // p = a + 1;
// // 

