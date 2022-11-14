// Lab_04.3.cpp
// < Шикітки Миколи >
// Лабораторна робота 4.3
// Функція з параметрами
// Варіант 34
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double x, xp, xk, dx, F, a, b, c;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << fixed;
    cout << "-------------------------------" << endl;
    cout << "|" << setw(5) << "F" << "     |"
        << setw(7) << "x" << "      |" << endl;
    cout << "-------------------------------" << endl;
    x = xp;
    while (x <= xk)
    {
        if (x + c < 0 && a != 0)
            F = -a * x * x - b;
        else
            if (x + c > 0 && a == 0)
                F = (x - a) / (x - c);
            else
                F = x / c + c / x;
        cout << "|" << setw(7) << setprecision(2) << F
            << "     |" << setw(10) << setprecision(3) << x
            << "     |" << endl;
        x += dx;
    }
    cout << "-------------------------------" << endl;
    return 0;
}
