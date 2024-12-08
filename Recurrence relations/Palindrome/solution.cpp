#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream ifst("input.txt");
	ofstream ofst("output.txt");
    char str[7000]{};
    char str2[7000]{};
    int ind{}, ind2{};
    while (!ifst.eof())
    {
        ifst.get(str[ind]);
        ++ind;
    }
    --ind;
    for (int i(ind - 1), k{}; i >= 0; --i, ++k)
    {
        str2[k] = str[i];
    }
    char* answer = new char[ind];
    int** matrica;
    matrica = new int* [ind + 1];
    for (int i{}; i < ind + 1; ++i)
    {
        matrica[i] = new int[ind + 1];
    }
    for (int i{}; i < ind + 1; ++i)
    {
        for (int k{}; k < ind + 1; ++k)
        {
            matrica[i][k] = 0;
        }
    }
    for (int i(1); i < ind + 1; ++i)
    {
        for (int k(1); k < ind + 1; ++k)
        {
            if (str[i -1] == str2[k - 1])
            {
                matrica[i][k] = matrica[i - 1][k - 1] + 1;
            }
            else
            {
                matrica[i][k] = max(matrica[i - 1][k], matrica[i][k - 1]);
            }
        }
    }
    for (int i(ind ), k(ind); i > 0 && k > 0; )
    {
        if (str[i - 1] == str2[k - 1])
        {
            answer[ind2] = str[i - 1];
            ++ind2;
            --i;
            --k;
        }
        else if (matrica[i][k] == matrica[i - 1][k])
        {
            --i;
        }
        else
        {
            --k;
        }
    }
    ofst << ind2 << endl;
    for (int i{}; i < ind2; ++i)
    {
        ofst << answer[i];
    }
}