#include <bits/stdc++.h>
using namespace std;
vector<int> sliding_maximum(vector<int> &v, int k)
{
    vector<int> ans;
    int n = v.size();
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && v[i] > v[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(v[dq.front()]);
    for (int i = k; i < n; i++)
    {
        if (dq.front() == i - k)
            dq.pop_front();
        while (!dq.empty() && v[i] > v[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(v[dq.front()]);
    }
    return ans;
}

int main()
{
    int k = 3;
    vector<int> v = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = sliding_maximum(v, k);
    for (int i = 0; i < v.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}