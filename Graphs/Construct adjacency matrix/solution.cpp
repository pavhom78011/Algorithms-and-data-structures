#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	int n{}, m{}, one{}, two{};
	ifst >> n >> m;
	int** matrica = new int* [n];
	for (int i{}; i < n; ++i)
	{
		matrica[i] = new int[n];
		for (int k{}; k < n; ++k)
		{
			matrica[i][k] = 0;
		}
	}
	while (ifst >> one >> two)
	{
		matrica[one - 1][two - 1] = 1;
		matrica[two - 1][one - 1] = 1;
	}
	for (int i{}; i < n; ++i)
	{
		for (int k{}; k < n; ++k)
		{
			ofst << matrica[i][k] << " ";
		}
		ofst << endl;
	}
}