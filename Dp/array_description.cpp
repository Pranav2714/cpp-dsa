#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

bool isValid(int x, int m)
{
    return x >= 1 && x <= m;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<long long> v(n);
    vector<vector<long long>> dp(n, vector<long long>(m + 1, 0));

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 1; i <= m; i++)
    {
        if (v[0] == 0 || v[0] == i)
        {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v[i] != 0 && v[i] != j)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int prev = j - 1; prev <= j + 1; prev++)
            {
                if (isValid(prev, m))
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][prev]) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        ans = (ans + dp[n - 1][i]) % MOD;
    }

    cout << ans << endl;
    return 0;
}
