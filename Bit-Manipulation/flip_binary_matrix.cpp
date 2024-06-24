#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> v = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    for (int i = 0; i < v.size(); i++)
    {
        reverse(v[i].begin(), v[i].end());
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            v[i][j] ^= 1;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}