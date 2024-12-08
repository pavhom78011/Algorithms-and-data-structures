#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> mosquitoes;
    vector<int> nums;
    vector<int> way;
    int n{};
    cin >> n;
    for (int i{}, k{}; i < n; ++i)
    {
        cin >> k;
        mosquitoes.push_back(k);
    }
    switch (n)
    {
    case 1:
        cout << mosquitoes[0] << endl;
        cout << "1";
        return 0;
    case 2:
        cout << "-1";
        return 0;
    case 3:
        cout << mosquitoes[0] + mosquitoes[2] << endl;
        cout << "1" << " " << "3";
        return 0;
    case 4:
        cout << mosquitoes[0] + mosquitoes[3] << endl;
        cout << "1" << " " << "4";
        return 0;
    case 5:
        cout << mosquitoes[0] + mosquitoes[2] + mosquitoes[4] << endl;
        cout << "1" << " " << "3" << " " << "5";
        return 0;
    default:
        break;
    }
    nums.push_back(mosquitoes[0]);
    nums.push_back(mosquitoes[1]);
    nums.push_back(mosquitoes[0] + mosquitoes[2]);
    nums.push_back(mosquitoes[0] + mosquitoes[3]);
    nums.push_back(mosquitoes[0] + mosquitoes[2] + mosquitoes[4]);
    for (int i = 5; i < n; ++i)
    {
        if (nums[i - 3] + mosquitoes[i] >= nums[i - 2] + mosquitoes[i])
        {
            nums.push_back(nums[i - 3] + mosquitoes[i]);
        }
        else
        {
            nums.push_back(nums[i - 2] + mosquitoes[i]);
        }
    }
    way.push_back(n);
    int i = n - 1;
    for (; i >= 5;)
    {
        if (nums[i - 3] > nums[i - 2])
        {
            way.push_back(i - 3 + 1);
            i -= 3;
        }
        else if (nums[i-3] < nums[i - 2])
        {
            way.push_back(i - 2 + 1);
            i -= 2;
        }
        else if (nums[i - 3] == nums[i - 2] && i > 5 && nums[i - 6] > nums[i - 5])
        {
            way.push_back(i - 3 + 1);
            i -= 3;
        }
        else
        {
            way.push_back(i - 2 + 1);
            i -= 2;
        }
    }
    if (i == 4)
    {
        way.push_back(3);
    }
    way.push_back(1);
    cout << nums.back() << endl;
    auto it = way.end() - 1;
    for (; it != way.begin(); --it)
    {
        cout << *it << " ";
    }
    cout << way[0];
}