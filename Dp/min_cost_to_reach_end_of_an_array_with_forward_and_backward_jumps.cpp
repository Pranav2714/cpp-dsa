#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> dp(n + 1, -1);
    dp[0] = v[0];
    dp[1] = v[1] + dp[0] + v[2];
    for (int i = 2; i < n - 1; i++)
    {
        dp[i] = min(dp[i - 2] + v[i], dp[i - 1] + v[i] + v[i + 1]);
    }
    dp[n - 1] = min(dp[n - 2], dp[n - 3] + v[n - 1]);

    cout << dp[n - 1] << endl;
    return 0;
}