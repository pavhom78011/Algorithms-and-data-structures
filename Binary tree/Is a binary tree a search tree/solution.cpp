#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;
struct MyStruct
{
	int key{};
	int numofstring{};
	char LeftOrRight = ' ';
	long long min = numeric_limits<long long>::min();
	long long max = numeric_limits<long long>::max();
};
int main()
{
	ifstream ifst("bst.in");
	ofstream ofst("bst.out");
	int amount{}, num{};
	ifst >> amount;
	vector<MyStruct> a;
	MyStruct b;
	ifst >> b.key;
	a.push_back(b);
	while (ifst >> num)
	{
		b.key = num;
		ifst >> b.numofstring;
		ifst >> b.LeftOrRight;
		a.push_back(b);
	}
	for (int i(1); i < a.size(); ++i)
	{
		if (a[i].LeftOrRight == 'L')	
		{
			a[i].min = a[a[i].numofstring - 1].min;
			a[i].max = a[a[i].numofstring - 1].key;
			if (a[i].key >= a[i].max || a[i].key < a[i].min)
			{
				ofst << "NO";
				return 0;
			}
		}
		else if (a[i].LeftOrRight == 'R')
		{
			a[i].min = a[a[i].numofstring - 1].key;
			a[i].max = a[a[i].numofstring - 1].max;
			if (a[i].key < a[i].min || a[i].key >= a[i].max)
			{
				ofst << "NO";
				return 0;
			}
		}
	}
	ofst << "YES";
}