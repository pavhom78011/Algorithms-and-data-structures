#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	int amount{}, something{};
	vector<int> numbers = { 0 };
	ifst >> amount;
	while (ifst >> something)
	{
		numbers.push_back(something);
	}
	for (int i(1); i <= numbers.size() / 2; ++i)
	{
		if (2 * i < numbers.size())
		{
			if (numbers[i] > numbers[2 * i])
			{
				ofst << "No";
				return 0;
			}
		}
		if ((2 * i + 1) < numbers.size())
		{
			if (numbers[i] > numbers[2 * i + 1])
			{
				ofst << "No";
				return 0;
			}
		}
	}
	ofst << "Yes";
}