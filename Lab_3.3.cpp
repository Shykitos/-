// Lab_03_3.cpp
// < Шикітки Миколи >
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 34
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
 double x; // вхідний аргумент
 double y; // результат обчислення виразу

 cout << "x = "; cin >> x;

 // розгалуження в повній формі
 if (x<=-4)
 y = -2;
 else
 if (-4<x && x<=0)
 y = 1./4.*x;
 else
 if (0<x && x<=2)
 y = x*x;
 else
 if (2<x && x<=10)
 y = (10-x)/2;
 else
 y = -(x-10)/2;
 cout << endl;
 cout << "y = " << y << endl;
 cin.get();
 return 0;
} 