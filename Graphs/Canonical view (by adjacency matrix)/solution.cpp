#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	int n{};
	ifst >> n;
	int** matrica = new int* [n];
	int* massiv = new int[n] {};
	for (int i{}; i < n; ++i)
	{
		matrica[i] = new int[n];
	}
	for (int i{}; i < n; ++i)
	{
		for (int k{}; k < n; ++k)
		{
			ifst >> matrica[i][k];
			if (matrica[i][k])
			{
				massiv[k] = i + 1;
			}
		}
	}
	for (int i{}; i < n; ++i)
	{
		ofst << massiv[i] << " ";
	}
}