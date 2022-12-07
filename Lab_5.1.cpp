#include <iostream>
#include <cmath>
using namespace std;
double f(const double a, const double x)
int main()
{
	double x;
	cout << "x = "; cin >> x;
	double c =(2*f*(1+x*x)+f*f*(x))/(1+f*f*f*(sqrt(abs(1-x*x))));
	cout << "c = " << c << endl;
	return 0;
}
double f(const double a, const double x)
{
	return ((1+x+((x*x)/2))/(1+abs(x)));
}
