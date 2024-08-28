#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define ll long long
#define vi vector<int>
#define INF 1e18
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(2, vector<int>(m));

    v[0][0] = 0;
    v[1][0] = 1;
    int j = 1;
    while (j < m)
    {
        v[0][j] = 1;
        if (j + 1 < m)
            v[0][j + 1] = 1;
        if (j + 2 < m)
            v[0][j + 2] = 0;
        if (j + 3 < m)
            v[0][j + 3] = 0;
        j += 4;
    }
    j = 1;
    while (j < m)
    {
        v[1][j] = 0;
        if (j + 1 < m)
            v[1][j + 1] = 0;
        if (j + 2 < m)
            v[1][j + 2] = 1;
        if (j + 3 < m)
            v[1][j + 3] = 1;
        j += 4;
    }
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (flag)
            {
                if (i % 2 == 0)
                    cout << v[0][j] << " ";
                else
                    cout << v[1][j] << " ";
            }
            else
            {
                if (i % 2 == 0)
                    cout << v[1][j] << " ";
                else
                    cout << v[0][j] << " ";
            }
        }
        cout << endl;
        if (i % 2 == 1 && i != 0)
            flag = !flag;
    }
    cout << endl;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
