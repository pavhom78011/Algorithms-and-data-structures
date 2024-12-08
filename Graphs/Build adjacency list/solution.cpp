#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
	int n{}, m{}, first{}, second{};
	ifst >> n >> m;
	vector<vector<int>> vec;
	for (int i{}; i < n; ++i)
	{
		vector<int> v;
		vec.push_back(v);
	}
	while (ifst >> first >> second)
	{
		vec[first - 1].push_back(second);
		vec[second - 1].push_back(first);
	}
	for (int i{}; i < vec.size(); ++i)
	{
		ofst << vec[i].size() << " ";
		for (int k{}; k < vec[i].size(); ++k)
		{
			ofst << vec[i][k] << " ";
		}
		ofst << endl;
	}
}