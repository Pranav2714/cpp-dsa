#include <bits/stdc++.h>
using namespace std;
vector<int> prevSmallerIdx(vector<int> &v)
{
    int n = v.size();
    stack<int> s;
    vector<int> ans(n, -1);
    reverse(v.begin(), v.end());
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && v[i] < s.top())
        {
            ans[s.top()] = n - i - 1;
            s.top();
        }
        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    reverse(v.begin(), v.end());
    return ans;
}
vector<int> nextSmallerIdx(vector<int> &v)
{
    int n = v.size();
    stack<int> s;
    vector<int> ans(n, -1);
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && v[i] < s.top())
        {
            ans[s.top()] = n - i - 1;
            s.top();
        }
        s.push(i);
    }
    return ans;
}
int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};
    vector<int> prev = prevSmallerIdx(v);
    vector<int> next = nextSmallerIdx(v);
    int ans = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        ans = max(ans, (v[i] * (next[i] - prev[i] - 1)));
    }
    cout << ans;
    return 0;
}