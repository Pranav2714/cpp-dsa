#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 1, 2, 1, 3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    int sum = 0;
    for (auto itr : mpp)
    {
        if (itr.second > 1)
        {
            sum += itr.first;
        }
    }
    cout << sum << endl;
    return 0;
}