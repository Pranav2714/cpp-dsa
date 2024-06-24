#include <bits/stdc++.h>
using namespace std;
vector<int> removeSubsequences(vector<int> &a)
{
    int n = a.size();
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.empty() || a[i] != s.top())
        {
            s.push(a[i]);
        }
        else if (a[i] == s.top())
        {
            if (i == n - 1 || a[i] != a[i + 1])
                s.pop();
        }
    }
    vector<int> ans(s.size());
    for (int i = s.size() - 1; i >= 0; i--)
    {
        ans[i] = s.top();
        s.pop();
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 2, 3, 10, 10, 10, 4, 4, 4, 5, 7, 7, 2};
    vector<int> ans = removeSubsequences(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}