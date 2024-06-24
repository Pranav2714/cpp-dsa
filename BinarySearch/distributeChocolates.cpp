#include <bits/stdc++.h>
using namespace std;
bool isDivisionPossible(vector<int> &a, int maxChocolateAllowed, int m)
{
    int noOfStudents = 1;
    int noOfchocolates = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > maxChocolateAllowed)
            return false;
        if (noOfchocolates + a[i] <= maxChocolateAllowed)
        {
            noOfchocolates += a[i];
        }
        else
        {
            noOfStudents++;
            noOfchocolates = a[i];
        }
    }
    return noOfStudents <= m;
}

int maxChocolatesDist(vector<int> &a, int m)
{
    if (a.size() < m)
        return -1;

    int st = 1;
    int end = 1e9;
    int ans = 0;

    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (isDivisionPossible(a, mid, m))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> a = {5, 3, 1, 4, 2};
    int m = 3;
    cout << maxChocolatesDist(a, m) << endl;
    return 0;
}