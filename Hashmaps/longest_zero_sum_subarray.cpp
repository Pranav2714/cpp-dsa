#include <bits/stdc++.h>
using namespace std;
int findSubarrayLength(vector<int> &v)
{
    int prefix = 0;
    unordered_map<int, int> m;
    int maxlen = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        prefix += v[i];
        if (prefix == 0)
        {
            maxlen++;
        }
        if (m.find(prefix) != m.end())
        {
            maxlen = max(maxlen, i - m[prefix]);
        }
        else
        {
            m[prefix] = i;
        }
    }
    return maxlen;
}
vector<int> findSubarray(vector<int> &v)
{

    int prefix = 0;
    unordered_map<int, int> m;
    int maxlen = INT_MIN;
    int stidx;
    for (int i = 0; i < v.size(); i++)
    {
        prefix += v[i];
        if (prefix == 0)
        {
            maxlen++;
        }
        if (m.find(prefix) != m.end())
        {
            maxlen = max(maxlen, i - m[prefix]);
            stidx = m[prefix] + 1;
        }
        else
        {
            m[prefix] = i;
        }
    }
    vector<int> ans(maxlen);
    int k = 0;
    for (int i = stidx; i <= maxlen; i++)
    {
        ans[k++] = v[i];
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << findSubarrayLength(v) << endl;
    vector<int> ans = findSubarray(v);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}