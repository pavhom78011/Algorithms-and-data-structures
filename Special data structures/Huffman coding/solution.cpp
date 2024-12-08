#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream ifst("huffman.in");
	ofstream ofst("huffman.out");
	long long amount{}, sum{}, x{}, y{};
	ifst >> amount;
	long long* vec1 = new long long[amount];
	long long* vec2 = new long long[amount];
	for (int i{}; i < amount; ++i)
	{
		ifst >> vec1[i];
		vec2[i] = 100000000000000000;
	}
	for (int i{}; i < amount - 1; ++i)
	{
		if (x < amount - 1)
		{
			if (vec2[y] + vec2[y + 1] <= vec1[x] + vec2[y] && vec2[y] + vec2[y + 1] <= vec1[x] + vec1[x + 1])
			{
				vec2[i] = vec2[y] + vec2[y + 1];
				sum += vec2[y] + vec2[y + 1];
				y += 2;
			}
			else if (vec1[x] + vec2[y] <= vec1[x] + vec1[x + 1] && vec1[x] + vec2[y] <= vec2[y] + vec2[y + 1])
			{
				vec2[i] = vec1[x] + vec2[y];
				sum += vec1[x] + vec2[y];
				++x;
				++y;
			}
			else if (vec1[x] + vec1[x + 1] <= vec1[x] + vec2[y] && vec1[x] + vec1[x + 1] <= vec2[y] + vec2[y + 1])
			{
				vec2[i] = vec1[x] + vec1[x + 1];
				sum += vec1[x] + vec1[x + 1];
				x += 2;
			}
		}
		else if (x == amount - 1)
		{
			if (vec2[y] + vec2[y + 1] <= vec1[x] + vec2[y])
			{
				vec2[i] = vec2[y] + vec2[y + 1];
				sum += vec2[y] + vec2[y + 1];
				y += 2;
			}
			else if (vec1[x] + vec2[y] <= vec2[y] + vec2[y + 1])
			{
				vec2[i] = vec1[x] + vec2[y];
				sum += vec1[x] + vec2[y];
				++x;
				++y;
			}
		}
		else if (x > amount - 1)
		{
			vec2[i] = vec2[y] + vec2[y + 1];
			sum += vec2[y] + vec2[y + 1];
			y += 2;
		}
	}
	ofst << sum;
}