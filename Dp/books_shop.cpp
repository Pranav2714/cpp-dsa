#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> cost(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= cost[i - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i - 1]] + pages[i - 1]);
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}