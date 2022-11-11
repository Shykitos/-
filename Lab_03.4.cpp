// Lab_03_4.cpp
//<Шикітки Миколи>
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 34
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double R1;
	double R2;
	double x;
	double y;

	cout << "R1 = "; cin >> R1;
	cout << "R2 = "; cin >> R2;
	cout << "x = "; cin >> x;
	cout << "y = "; cin >> y;

	if ((R1 > R2 && x>0 && y>0 && x*x+y*y<=R2*R2 || x<0 && y<0 && R1<R2 && x*x+y*y<=R1*R1))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	cin.get();
	return 0;
}