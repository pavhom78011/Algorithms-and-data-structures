#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	int n{}, label(1);
	ifst >> n;
	int** matrica = new int* [n];
	int* massiv = new int[n] {};
	queue<int> q;
	massiv[0] = 1;
	q.push(0);
	for (int i{}; i < n; ++i)
	{
		matrica[i] = new int[n];
	}
	for (int i{}; i < n; ++i)
	{
		for (int k{}; k < n; ++k)
		{
			ifst >> matrica[i][k];
		}
	}
	for (int i{}; i < n; ++i)
	{
		if (!massiv[i])
		{
			massiv[i] = ++label;
			q.push(i);
		}
		while (!q.empty())
		{
			int t = q.front();
			q.pop();
			for (int i{}; i < n; ++i)
			{
				if (matrica[t][i] && massiv[i] == 0)
				{
					massiv[i] = ++label;
					q.push(i);
				}
			}
		}
	}
	for (int i{}; i < n; ++i)
	{
		ofst << massiv[i] << " ";
	}
}