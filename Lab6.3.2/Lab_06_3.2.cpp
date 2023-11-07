#include <iostream>
#include <iomanip>

using namespace std;

void Add_Array(int* a, const int n, int index = 0)
{
    if (index == n) {
        return;
    }

    a[index] = a[index];
    Add_Array(a, n, index + 1);
}

void Print(int* a, const int n, int index = 0)
{
    if (index == n) {
        cout << setw(4) << endl;
        return;
    }
    cout << a[index] << setw(4);
    if (index == 9) {
        cout << setw(4);
    }
    Print(a, n, index + 1);
}

bool Audit(int* a, const int n, int index = 1)
{
    if (index == n) {
        return true;
    }

    if (a[index] > a[index - 1]) {
        return false;
    }

    return Audit(a, n, index + 1);
}

int FindMin(int* a, const int n, int index = 0, int minVal = INT_MAX)
{
    if (index == n) {
        return minVal;
    }

    if (a[index] < minVal) {
        minVal = a[index];
    }

    return FindMin(a, n, index + 1, minVal);
}

template<typename T>
void Add_Array_T(T* a, const int n, int index = 0)
{
    if (index == n) {
        return;
    }

    a[index] = a[index];
    Add_Array_T(a, n, index + 1);
}

template <typename T>
void PrintT(T* a, const int n, int index = 0)
{
    if (index == n) {
        cout << setw(4) << endl;
        return;
    }

    cout << a[index] << setw(4);
    if (index == 9) {
        cout << "    ";
    }
    PrintT(a, n, index + 1);
}

template <typename T>
bool AuditT(T* a, const int n, int index = 1)
{
    if (index == n) {
        return true;
    }

    if (a[index] > a[index - 1]) {
        return false;
    }

    return AuditT(a, n, index + 1);
}

template <typename T>
T FindMinT(T* a, const int n, int index = 0, T minVal = std::numeric_limits<T>::max())
{
    if (index == n) {
        return minVal;
    }

    if (a[index] < minVal) {
        minVal = a[index];
    }

    return FindMinT(a, n, index + 1, minVal);
}

int main()
{
    const int n = 10;
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    cout << "Non-Template Results:" << endl;

    Add_Array(a, n);

    cout << "ARRAY = " << endl;
    Print(a, n);

    bool condition = Audit(a, n);

    cout << " Condition = " << condition << endl;

    int minNonTemplate = FindMin(a, n);
    cout << "Minimum Value in the array = " << minNonTemplate << endl;

    int b[n] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    cout << "Template Results:" << endl;

    Add_Array_T(b, n);

    cout << "ARRAY = " << endl;
    PrintT(b, n);

    bool templateCondition = AuditT(b, n);

    cout << " Condition = " << templateCondition << endl;

    int minTemplate = FindMinT(b, n);
    cout << "Minimum Value in the array = " << minTemplate << endl;

    return 0;
}