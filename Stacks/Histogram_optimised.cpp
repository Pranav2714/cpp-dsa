#include <bits/stdc++.h>
using namespace std;
int findMaxrectangle(vector<int> &v)
{
    int n = v.size();
    int ans = INT_MIN;
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && v[i] < v[s.top()])
        {
            int ele = v[s.top()];
            s.pop();
            int nsi = i;
            int psi = (s.empty()) ? -1 : s.top();
            ans = max(ans, ele * (nsi - psi - 1));
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int ele = v[s.top()];
        s.pop();
        int nsi = n;
        int psi = (s.empty()) ? -1 : s.top();
        ans = max(ans, ele * (nsi - psi - 1));
    }
    return ans;
}

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3, 0, 2, 1, 5, 6, 2, 3};
    int ans = findMaxrectangle(v);
    cout << ans;
    return 0;
}