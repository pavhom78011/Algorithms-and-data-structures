#include <iostream>
using namespace std;
static int BinarySearch(int n, int *massiv, int request)
{
    int begin{};
    for (int i{}; begin < n; ++i)
    {
        int middle = (begin + n) / 2;
        if (massiv[middle] == request)
        {
            return 1;
        }
        else if (massiv[middle] > request)
        {
            n = middle;
        }
        else if (massiv[middle] < request)
        {
            begin = middle + 1;
        }
    }
    return 0;
}
static int GreaterOrEqual(int n, int* massiv, int request)
{
    int begin{};
    for (int i{}; begin < n; ++i)
    {
        int middle = (begin + n) / 2;
        if (massiv[middle] >= request)
        {
            n = middle;
        }
        else if (massiv[middle] < request)
        {
            begin = middle + 1;
        }
    }
    return begin;
}
static int Greater(int n, int* massiv, int request)
{
    int begin{};
    for (int i{}; begin < n; ++i)
    {
        int middle = (begin + n) / 2;
        if (massiv[middle] > request)
        {
            n = middle;
        }
        else if (massiv[middle] <= request)
        {
            begin = middle + 1;
        }
    }
    return begin;
}
int main()
{
    int n{}, requests{};
    cin >> n;
    int *massiv = new int[n];
    for (int i{}; i < n; ++i)
    {
        cin >> massiv[i];
    }
    cin >> requests;
    int* query_numbers = new int[requests];
    for (int i{}; i < requests; ++i)
    {
        cin >> query_numbers[i];
    }
    for (int i{}, b{}, l{}, r{}; i < requests; ++i)
    {
        b = BinarySearch(n, massiv, query_numbers[i]);
        l = GreaterOrEqual(n, massiv, query_numbers[i]);
        r = Greater(n, massiv, query_numbers[i]);
        cout << b << " " << l << " " << r << endl;
    }
}