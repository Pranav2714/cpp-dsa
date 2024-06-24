#include <bits/stdc++.h>
using namespace std;
vector<int> findPairSum(vector<int> &v, int target)
{
    int n = v.size();
    vector<int> ans(2);
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(target - v[i]) != m.end())
        {
            ans[0] = (m[target - v[i]]);
            ans[1] = (i);
            return ans;
        }
        else
        {
            m[v[i]] = i;
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 4, 5, 11, 13, 10, 2};
    int target;
    cin >> target;
    vector<int> ans = findPairSum(v, target);
    if (ans.size() == 2)
    {
        cout << "Pair found at indices: " << ans[0] << " and " << ans[1] << endl;
    }
    else
    {
        cout << "Pair not found." << endl;
    }
    return 0;
}