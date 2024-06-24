#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterEle(vector<int> &a)
{
    int n = a.size();
    stack<int> s;
    vector<int> ans(n, -1);
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && a[i] > a[s.top()])
        {
            ans[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    { // not mandatory if we've already initialised the vector by -1
        ans[s.top()] = -1;
        s.pop();
    }
    return ans;
}
vector<int> previousGreaterEle(vector<int> &a)
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
            ans[s.top()] = a[i];
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
    return ans;
}
int main()
{
    vector<int> v = {4, 3, 2, 6, 1};
    vector<int> result = nextGreaterEle(v);
    // vector<int> result = previousGreaterEle(v);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}