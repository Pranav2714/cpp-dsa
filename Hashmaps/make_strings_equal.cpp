#include <bits/stdc++.h>
using namespace std;
bool canMakeEqual(vector<string> &v)
{
    int n = v.size();
    unordered_map<char, int> umpp;
    for (auto str : v)
    {
        for (auto ch : str)
        {
            umpp[ch]++;
        }
    }
    for (auto itr : umpp)
    {
        if (itr.second % n != 0)
            return false;
        else
            return true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << (canMakeEqual(v) ? "YES" : "NO") << endl;
    return 0;
}