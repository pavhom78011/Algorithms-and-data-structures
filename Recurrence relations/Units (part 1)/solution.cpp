#include <iostream>
using namespace std;
int main()
{
    long long n{}, k{}, mod(10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7);
    cin >> n;
    cin >> k;
    int line1[1000]{};
    line1[0] = 1;
    line1[1] = 1;
    for (int i{2}; i < n + 1; ++i)
    {
        int* nextline = new int[i + 1];
        nextline[0] = 1;
        nextline[i] = 1;
        for (int y{1}; y < i; ++y)
        {
            nextline[y] = (line1[y - 1] + line1[y]) % mod;
        }
        for (int k{}; k <= i; ++k)
        {
            line1[k] = nextline[k];
        }
    }
    cout << line1[k];
}