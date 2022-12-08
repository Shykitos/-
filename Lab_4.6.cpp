#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double P, S;
	int n, k;

	P = 1;
	n = 1;

	while (n<=10)
	{
		S = 0;
		k = 1;
		while (k<=n)
		{
			S += cos(k);
            k++;
		}
		P *= (sin(n)+S)/(1+cos(n));
		n++;
	}
	cout << P << endl;

	P = 1;
	k = 1;
	do {
		S = 0;
		k = 1;
		do {
			S += cos(k);
			k++;
	   } while (k<=n);
	   P *= (sin(n)+S)/(1+cos(n));
	   n++;
	 }

while (n<=10);
cout << P << endl;

P = 1;
for (n=1; n<=10; n++)
{
	S = 0;
	for (k=1; k<=n; k++)
	{
		S += cos(k);
        k++;
	}
	P *= (sin(n)+S)/(1+cos(n));
}
cout << P << endl;

P = 1;
for (n=10; n>=1; n--)
{
	S = 0;
	for (k=n; k>=n; k--)
	{
		S += cos(k);
	}
	P *= (sin(n)+S)/(1+cos(n));
}
cout << P << endl;

return 0;
}