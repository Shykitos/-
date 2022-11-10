// Lab_02.cpp
// < Шикітки Миколи >
// Лабораторна робота 2
// Лінійні програми
// Варіант 34
#include <iostream>
#include <cmath> // sin(), cos()
int main()
{
using namespace std;
float a;
cout << "Введіть a : ";
cin >> a;
float z1 = (cos(a) + sin(a)) / (cos(a) - sin(a));
float z2 = (sin(2*a)+1)/(cos(2*a));
cout << "\nz1 = " << z1 << '\n' << "z2 = " << z2 << endl;
return 0;
}
