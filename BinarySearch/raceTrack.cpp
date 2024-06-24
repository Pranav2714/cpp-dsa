#include <bits/stdc++.h>
using namespace std;
bool isPossible(int dist, vector<int> a, int k)
{
    int noOfchild = 1;
    int lastKid = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] - lastKid >= dist)
        {
            noOfchild++;
            lastKid = a[i];
        }
    }
    return (lastKid >= k);
}
int maximalMinima(vector<int> a, int k)
{
    if (k > a.size())
        return -1;
    int st = 1, end = (int)1e9;
    int ans = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isPossible(mid, a, k))
        {
            ans = mid;
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> a = {1, 2, 4, 8, 9};
    int k = 3;
    cout << maximalMinima(a, k) << endl;
    return 0;
}