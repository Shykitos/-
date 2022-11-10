// Lab_03_1.cpp
// < Шикітки Миколи >
// Лабораторна робота 3.1
// Лінійні програми
// Варіант 34
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
double x;
double y;
double A;
double B;
cout << "x= ", cin >> x;
A=2*(x*x);
if (x<=-0.1)
B=5*(sin(3*x));
if (-0.1<x && x<1.2)
B=atan((x+1)/4);
if (x>=1.2)
B=tan(x)+2;
y=A-B;
cout<<"1)y= "<<y<<endl;
if (x<=-0.1)
B=5*(sin(3*x));
else
if (-0.1<x && x<1.2)
B=atan((x+1)/4);
else
B=tan(x)+2;
y=A-B;
cout<<"2)y= "<<y<<endl;
cin.get();
return 0;
}
