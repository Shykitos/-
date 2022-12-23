#include <iostream>

#include <iomanip>

#include <time.h>
using namespace std;
template <typename T >
void Create(T* a, const T n, const T Low, const T High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Create(int* a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}


template <typename T >
void Print(T* a, const T n)
{
    for (int i = 0; i < n; i++)
        cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    cout << endl;
}


void Print(int* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    cout << endl;
}



template <typename T >
const T& Sum(T* a, const T n)
{
    int S = 0;

    for (int i = 0; i < n; i++)
        S += a[i];
    return S;
}
int Sum(int* a, const int n)
{
    int S = 0;

    for (int i = 0; i < n; i++)
        if ((a[i] > 0 && (a[i] % 2) != 0) || (a[i] < 0))
        S += a[i];
    return S;
}
int main()
{
    srand((unsigned)time(NULL));
    const int n = 10;
    int a[n];
    int Low = 1;
    int High = 20;
    Create(a, n, Low, High);
    Print(a, n);
    cout << "S = " << Sum(a, n) << endl;
    return 0;
}
