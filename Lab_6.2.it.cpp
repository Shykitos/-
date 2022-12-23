#include <iostream>

#include <iomanip>

using namespace std;
void Print(int* a, int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = i;
        cout << setw(4) << a[i];
    }
    cout << endl;
}
int Sum(int* a, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 1)
            S += i;
    return S;
}

int main()
{
    int n;
    cout << "  " << "n = ";
    cin >> n;
    int* a = new int[n];
    Print(a, n);
    cout << "  " << "S = " << Sum(a, n) << endl;
    delete[] a;
    return 0;
}


