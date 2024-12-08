#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	int n{}, from{}, to{};
	ifst >> n;
	int* massiv = new int[n] {};
	while (ifst >> from >> to)
	{
		massiv[to - 1] = from;
	}
	for (int i{}; i < n; ++i)
	{
		ofst << massiv[i] << " ";
	}
}