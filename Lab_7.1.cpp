// Lab_7_1.cpp
// < Шикітки Миколи >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків/стовпчиків матриці.
// Варіант 34
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** R, const int rowCount, const int colCount, const int Low,const int High);
void Print(int** R, const int rowCount, const int colCount);
void Sort(int** R, const int rowCount, const int colCount);
void Change(int** R, const int row1, const int row2, const int colCount);
void Filter(int** R, const int rowCount, const int colCount, int& S, int& k);


int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int rowCount = 8;
	int colCount = 6;
	int** R = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		R[i] = new int[colCount];
	Create(R, rowCount, colCount, Low, High);
	Print(R, rowCount, colCount);
	Sort(R, rowCount, colCount);
	Print(R, rowCount, colCount);
	int S = 0;
	int k = 0;
	Filter(R, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(R, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] R[i];
	delete[] R;
	return 0;
}
void Create(int** R, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			R[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** R, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << R[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** R, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
			if ((R[0][i1] > R[0][i1 + 1])
				||
				(R[0][i1] == R[0][i1 + 1] &&
					R[1][i1] < R[1][i1 + 1])
				||
				(R[0][i1] == R[0][i1 + 1] &&
					R[1][i1] == R[1][i1 + 1] &&
					R[2][i1] > R[2][i1 + 1]))
				Change(R, i1, i1 + 1, rowCount);
}
void Change(int** R, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = R[j][col1];
		R[j][col1] = R[j][col2];
		R[j][col2] = tmp;
	}
}
void Filter(int** R, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (R[i][j] > 0 && !(i % 3 == 0 || j % 3 == 0))
			{
				S += R[i][j];
				k++;
				R[i][j] = 0;
			}
}
