#include <bits/stdc++.h>
using namespace std;
vector<int> findStockSpan(vector<int> &a)
{
    int n = a.size();
    reverse(a.begin(), a.end());
    stack<int> s;
    vector<int> ans(n, -1);
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && a[i] > a[s.top()])
        {
            ans[s.top()] = n - i - 1;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    { // not mandatory if we've already initialised the vector by -1
        ans[s.top()] = -1;
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    reverse(a.begin(), a.end());
    return ans;
}
int main()
{
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = findStockSpan(v);
    for (int i = 0; i < res.size(); i++)
    {
        cout << i - res[i] << " ";
    }
    return 0;
}