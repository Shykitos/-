#include <iostream>

#include <iomanip>

#include <time.h>

using namespace std;

int main()
{
	double x, y;

	srand((unsigned) time(NULL));

	for (int i=0; i<10; i++)
	{
		cout << "x = "; cin >> x;
		cout << "y = "; cin >> y;

		if ((y >= -R && y <= R && x >= -R && x <= R)||
			(x*x+y*y <= R*R) ||
			(y>=-R && y<=x-R && y<=-x-R))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	cout << endl << fixed;
	for (int i=0; i<10; i++)
	{
		x = R*rand()/RAND_MAX-R;
		y = R*rand()/RAND_MAX-R;

		if ((y>=-R && y<=R && x>=-R && x<=R)||
			(x*x+y*y<=R*R) ||
			(y>=-R && y<=x-R && y<=-x-R))
			cout << setw(8) << setprecision(4) << x << "  "
			     << setw(8) << setprecision(4) << y << "  " << "yes" << endl;
		else
			cout << setw(8) << setprecision(4) << x << "  "
			     << setw(8) << setprecision(4) << y << "  " << "no" << endl;
	}
	return 0;
}
