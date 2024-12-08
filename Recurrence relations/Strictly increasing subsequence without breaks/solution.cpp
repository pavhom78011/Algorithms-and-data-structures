#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int amount{}, num{};
    vector<int> numbers;
    vector<int> sequence;
    ifst >> amount;
    while (ifst >> num)
    {
        numbers.push_back(num);
    }
    for (auto num : numbers)
    {
        auto it = lower_bound(sequence.begin(), sequence.end(), num);
        if (it == sequence.end())
        {
            sequence.push_back(num);
        }
        else
        {
            *it = num;
        }
    }
    ofst << sequence.size();
}