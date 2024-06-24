#include <bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;
    int k = 3;
    int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> ans;
    for (int i = 0; i < n - k + 1; i++)
    {
        int j = i;
        k = 3;
        while (j < i + k)
        {
            if (dq.empty())
            {
                dq.push_back(a[j]);
            }
            else
            {
                while (!dq.empty() && a[j] > dq.back())
                {
                    dq.pop_back();
                }
                dq.push_back(a[j]);
            }
            j++;
        }
        ans.push_back(dq.front());
        dq.clear();
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}