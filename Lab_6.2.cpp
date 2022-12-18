#include <iostream>

#include <iomanip>


using namespace std;

void Output(int* list, const int size, int i);
void Calculate(int* list, const int size, int& count, int i);
void Filling(int* list, const int size, const int Min, const int Max, int i);

int main()
{

    srand((unsigned)time(NULL));

    const int n = 30;
    int c[n] = { 1 };

    int Min = -20;
    int Max = 20;

    int count = 0;

    cout << "rec" << endl;
    cout << endl;

    Filling(c, n, Min, Max, 0);
    cout << "Masive: "; Output(c, n, 0);

    Calculate(c, n, count, 0);
    cout << "Count: " << setw(4) << count << endl;
}

void Filling(int* list, const int size, const int Min, const int Max, int i) {
    if (i < size)
    {
        list[i] = rand() % (Max - Min + 1) + Min;
        return Filling(list, size, Min, Max, ++i);
    }
}

void Calculate(int* list, const int size, int& count, int i) {
    if (i < size) {
        if ((list[i] %2) != 0) {
            count++;
        }

        Calculate(list, size, count, ++i);
    }
}

void Output(int* list, const int size, int i)
{
    if (i < size) {
        cout << setw(4) << list[i];
        return Output(list, size, ++i);
    }
    cout << endl;
}
