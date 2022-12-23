#include <iostream>

#include <cmath>

#include <time.h>

using namespace std;

int Sum(int mas[], const int n, int i);
int Kil(int mas[], const int n, int i);
int Zam(int mas[], const int n, int i);

void Create(int mas[], const int n, const int Low, const int High, int i)
{
	mas[i] = Low + rand() % (High - Low + 1);
	if (i < n - 1)
		Create(mas, n, Low, High, i + 1);
}

void Print(int mas[], const int n, int i)
{
	cout << mas[i] << " ";
	if (i < n - 1)
		Print(mas, n, i + 1);
}

int Sum(int mas[], const int n, int i)
{
	if (mas[i] > 0 || (i % 2) != 0)
	{
		if (i < n)
			return mas[i] + Sum(mas, n, i + 1);
		else
			return 0;
	}
	else
		return Sum(mas, n, i + 1);
}

int Kil(int mas[], const int n, int i)
{
	if (mas[i] > 0 || (i % 2) != 0)
	{
		if (i < n)
			return 1 + Kil(mas, n, i + 1);
		else
			return 0;
	}
	else
		return Kil(mas, n, i + 1);
}

int Zam(int mas[], const int n, int i)
{
	if (i == n)
		return 0;
	if (mas[i] > 0 || (i % 2) != 0)
		mas[i] = 0;
	return Zam(mas, n, i + 1);
}

int main()
{
	srand((unsigned)time(NULL));

	const int k = 23;
	int a[k];

	int Low = -25;
	int High = 80;

	Create(a, k, Low, High, 0);

	cout << "a[ ";
	Print(a, k, 0);
	cout << "]" << endl;

	cout << "Sum = " << Sum(a, k, 0) << endl;
	cout << "k = " << Kil(a, k, 0) << endl;

	Zam(a, k, 0);
	
	cout << "a[ ";
	Print(a, k, 0);
	cout << "]" << endl;

	return 0;
}
