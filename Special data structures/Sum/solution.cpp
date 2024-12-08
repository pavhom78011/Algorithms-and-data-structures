#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct MyStruct
{
	string str;
	long long a;
	long long b;
};
static long long FindSum(long long a, long long b, vector<long long> &fenwick)
{
	--b;
	long long sum1{};
	for (; b >= 0;)
	{
		sum1 += fenwick[b];
		b = (b & (b + 1)) - 1;
	}
	if (a)
	{
		--a;
		long long sum2{};
		for (; a >= 0;)
		{
			sum2 += fenwick[a];
			a = (a & (a + 1)) - 1;
		}
		return sum1 - sum2;
	}
	else
	{
		return sum1;
	}
}
static void Add(long long index, long long num, vector<long long> &fenwick)
{
	for (; index < fenwick.size();)
	{
		fenwick[index] += num;
		index = index | (index + 1);
	}
}
int main()
{
	long long numofelements{}, numofrequests{}, something{};
	cin >> numofelements;
	vector<long long> numbers(numofelements), fenwick(numofelements);
	MyStruct a;
	for (int i{}; i < numofelements; ++i)
	{
		cin >> numbers[i];
	}
	for (int i{}; i < numofelements; ++i)
	{
		for (int k(i); k < numofelements;)
		{
			fenwick[k] += numbers[i];
			k = k | (k + 1);
		}
	}
	cin >> numofrequests;
	for (int i{}; i < numofrequests; ++i)
	{
		cin >> a.str >> a.a >> a.b;
		if (a.str == "FindSum")
		{
			cout << FindSum(a.a, a.b, fenwick) << endl;
		}
		else if (a.str == "Add")
		{
			Add(a.a, a.b, fenwick);
		}
	}
}