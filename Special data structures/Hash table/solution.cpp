#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int m{}, c{}, n{}, num{};
    ifst >> m >> c >> n;
    vector<int> numbers(m, -1);
    for (int i{}; i < n; ++i)
    {
        ifst >> num;
        int k{};
        for (;;)
        {
            int ind = ((num % m) + c * k) % m;
            if (numbers[ind] == -1)
            {
                numbers[ind] = num;
                break;
            }
            else
            {
                ++k;
            }
            if (numbers[ind] == num)
            {
                break;
            }
        }
    }
    for (auto t : numbers)
    {
        ofst << t << " ";
    }
}