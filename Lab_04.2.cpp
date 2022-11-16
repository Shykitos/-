// Lab_04.2.cpp
// < Шикітки Миколи >
// Лабораторна робота 4.2
// Табуляція функції, заданої формулою: з однією змінною
// Варіант 34
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
 double x, xp, xk, dx, A, B, y;
 cout << "xp = "; cin >> xp;
 cout << "xk = "; cin >> xk;
 cout << "dx = "; cin >> dx;
 cout << fixed;
 cout << "---------------------------" << endl;
 cout << "|" << setw(5) << "x" << " |"
 << setw(7) << "y" << " |" << endl;
 cout << "---------------------------" << endl;
 x = xp;
 while (x <= xk)
 {
 A = 2*x*x;
 if (x<=-0.1)
 B = 5*(sin(3*x));
 else
 if (x>=1.2)
 B = tan(x+2);
 else
 B =atan((x+1)/4);
 y = A - B;
 cout << "|" << setw(7) << setprecision(2) << x
 << " |" << setw(10) << setprecision(3) << y
 << " |" << endl;
 x += dx;
 }
 cout << "---------------------------" << endl;
 return 0;
}