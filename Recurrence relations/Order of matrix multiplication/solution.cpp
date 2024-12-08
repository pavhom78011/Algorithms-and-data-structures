#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	int amount{}, something{}, ind{};
	vector<vector<int>> matrix;
	vector<int> vec;
	ifst >> amount;
	while (ifst >> something)
	{
		vec.push_back(something);
		++ind;
		if (ind % 2 == 0)
		{
			matrix.push_back(vec);
			vec.clear();
		}
	}
	int** matrica;
	matrica = new int* [matrix.size()];
	for (int i{}; i < matrix.size(); ++i)
	{
		matrica[i] = new int[matrix.size()];
	}
	for (int i{}; i < matrix.size(); ++i)
	{
		for (int k{}; k < matrix.size(); ++k)
		{
			matrica[i][k] = 0;
		}
	}
	for (int i{}; i < matrix.size() - 1; ++i)
	{
		matrica[i][i + 1] = matrix[i][0] * matrix[i][1] * matrix[i + 1][1];
	}
	for (int k(2); k < matrix.size(); ++k)
	{
		for (int i = 0; i < matrix.size() - k; ++i)
		{
			for (int q(i), w(i + k), t(i); t < i + k; ++t)
			{
				int y = matrica[i][t] + matrica[t + 1][i + k] + matrix[i][0] * matrix[t][1] * matrix[i + k][1];
				if (matrica[i][i + k] == 0 || matrica[i][i + k] > y)
				{
					matrica[i][i + k] = y;
				}
			}
		}
	}
	ofst << matrica[0][matrix.size() - 1];
}