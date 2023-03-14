#include <iostream>

#include <iomanip>

#include <time.h>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low,
    const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

void SearchMaxDiagonal(int** a, const int N, int i, int& max, int& k)
{
    if (a[i][i] > max)
    {
        max = a[i][i];
        k = i;
    }
    if (i < N - 1)
        SearchMaxDiagonal(a, N, i + 1, max, k);
}

int main()
{
    srand((unsigned)time(NULL));
    int N;
    cout << "N = "; cin >> N;
    cout << endl;

    int** a = new int* [N];
    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    int Low = -23, High = 21;
    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);

    int k = -1, max = a[0][0];
    SearchMaxDiagonal(a, N, 0, max, k);

    if (k > -1)
        cout << "The maximum element of the main diagonal is " << max
        << " and its row is " << k << endl;
    else
        cout << "There are no elements on the main diagonal" << endl;
}
