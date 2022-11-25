// Lab_04.1.cpp
// < Шикітки Миколи >
// Лабораторна робота 4.1
// Цикли
// Варіант 34
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int k, N, i;
	double S;
	cout << "N = "; cin >> N;
cout << "k = "; cin >> k;
	S = 0;
	i = k;
	while (i <= k)
	{
		S += (k/i)+(i/N);
		i++;
	}
	cout << S << endl;
	S = 0;
	i = k;
	do {
		S += (k/i)+(i/N);
		i++;
	} while (i <= N);
	cout << S << endl;
	S = 0;
	for (i=k; i <= N; i++)
	{
		S += (k/i)+(i/N);
	} 
	cout << S << endl;
	S = 0;
	for (i = N; i >= k; i--)
	{
		S +=(k/i)+(i/N);
	} 
	cout << S << endl;
	return 0;
}
