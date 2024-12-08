#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
static int FindSet(int a, vector<int>& components)
{
	if (a == components[a])
	{
		return a;
	}
	return components[a] = FindSet(components[a], components);
}
static void Union(int a, int b, vector<int>& sizes, vector<int>& components, int& something)
{
	a = FindSet(a, components);
	b = FindSet(b, components);
	if (a != b)
	{
		--something;
	}
	if (sizes[a] < sizes[b])
	{
		components[a] = b;
	}
	else if (sizes[a] > sizes[b])
	{
		components[b] = a;
	}
	else
	{
		components[a] = b;
		sizes[b] += 1;
	}
}
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	int cities{}, request{}, something{};
	ifst >> cities >> request;
	vector<pair<int, int>> pairs;
	vector<int> components(cities + 1);
	vector<int> sizes(cities + 1, 1);
	pair<int, int> pair;
	something = cities;
	while (ifst >> pair.first)
	{
		ifst >> pair.second;
		pairs.push_back(pair);
	}
	for (int i{}; i < cities + 1; ++i)
	{
		components[i] = i;
	}
	for (auto p : pairs)
	{
		Union(p.first, p.second, sizes, components, something);
		ofst << something << endl;
	}
}