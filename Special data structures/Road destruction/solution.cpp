#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
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
    if (a != b) {
        --something;
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
}

int main() 
{
    ifstream ifst("input.txt");
    ofstream ofst("output.txt");
    int cities{}, request{}, something{}, destroy{};
    ifst >> cities >> request >> destroy;
    vector<pair<int, int>> pairs(request);
    vector<int> components(cities + 1);
    vector<int> sizes(cities + 1, 1);
    vector<int> earthquakes(destroy);
    vector<bool> destructions(request, false);
    pair<int, int> pair;
    something = cities;
    for (int i{}; i < request; ++i) 
    {
        ifst >> pairs[i].first >> pairs[i].second;
    }
    for (int i{}; i < destroy; ++i) 
    {
        ifst >> earthquakes[i];
        destructions[earthquakes[i] - 1] = true;
    }
    for (int i{}; i < cities + 1; ++i) 
    {
        components[i] = i;
    }
    for (int i = 0; i < request; ++i) 
    {
        if (!destructions[i]) 
        {
            Union(pairs[i].first, pairs[i].second, sizes, components, something);
        }
    }
    string str("");
    for (int i = destroy - 1, connect = false; i >= 0; --i) 
    {
        if (connect) 
        {
            str += "1";
            continue;
        }
        if (something > 1) 
        {
            str += "0";
        }
        else 
        {
            str += "1";
            connect = true;
        }
        Union(pairs[earthquakes[i] - 1].first, pairs[earthquakes[i] - 1].second, sizes, components, something);
    }
    reverse(str.begin(), str.end());
    ofst << str;
}