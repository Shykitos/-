#include <iostream>

#include <iomanip>

using namespace std;
void Print(int* a, const int size, int i)
{
    a[i] = i;
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}
int Sum(int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 == 1)
            return i + Sum(a, size, i + 1);
        else
            return Sum(a, size, i + 1);
    }
    else
        return 0;
}

int main()
{
    int n;
    cout << "  " << "n = ";
    cin >> n;
    int* a = new int[n];
    Print(a, n, 0);
    cout << "  " << "S = " << Sum(a, n, 0) << endl;
    delete[] a;
    return 0;
}
