#include <iostream>
using namespace std;
int main()
{
    int n{};
    cin >> n;
    int* X = new int[n];
    int* Y = new int[n];
    int* answer1 = new int[n];
    int* answer2 = new int[n];
    int** matrica;
    matrica = new int* [n + 1];
    for (int i{}; i < n + 1; ++i)
    {
        matrica[i] = new int[n + 1];
    }
    for (int i{}; i < n; ++i)
    {
        cin >> X[i];
    }
    for (int i{}; i < n; ++i)
    {
        cin >> Y[i];
    }
    for (int i{}; i < n; ++i)
    {
        answer1[i] = -1;
        answer2[i] = -1;
    }
    for (int i{}; i < n + 1; ++i)
    {
        matrica[0][i] = 0;
        matrica[i][0] = 0;
    }
    for (int i(1); i < n + 1; ++i)
    {
        for (int k(1); k < n + 1; ++k)
        {
            if (X[i - 1] == Y[k - 1])
            {
                matrica[i][k] = matrica[i - 1][k - 1] + 1;
            }
            else
            {
                matrica[i][k] = max(matrica[i - 1][k], matrica[i][k - 1]);
            }
        }
    }
    cout << matrica[n][n];
    for (int i(n), k(n), m{}; i > 0 && k > 0;)
    {
        if (X[i - 1] == Y[k - 1])
        {
            answer1[m] = i - 1;
            answer2[m] = k - 1;
            ++m;
            --i;
            --k;
        }
        else
        {
            if (matrica[i][k] == matrica[i - 1][k])
            {
                --i;
            }
            else if (matrica[i][k] == matrica[i][k - 1])
            {
                --k;
            }
        }
    }
    cout << '\n';
    for (int i = n - 1; i >= 0; --i)
    {
        if (answer1[i] != -1)
        {
            cout << answer1[i] << " ";
        }
    }
    cout << '\n';
    for (int i = n - 1; i >= 0; --i)
    {
        if (answer2[i] != -1)
        {
            cout << answer2[i] << " ";
        }
    }
}