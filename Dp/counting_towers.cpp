#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

/* TYPES  */
#define ll long long
#define lli long long int
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvl vector<vector<long long>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<long, long>>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define umll map<long long, long long>
#define si set<int>
#define sc set<char>
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define forn() for (auto i = 0; i < n; i++)

/* PRINTS */
#define printv(a)             \
    {                         \
        for (auto u : a)      \
            cout << u << " "; \
        cout << endl;         \
    }
#define printm(a)                                \
    {                                            \
        for (auto u : a)                         \
            cout << u.ff << " " << u.ss << endl; \
    }
#define print(x) cout << x << '\n';
void _print(ll t) { cout << t << '\n'; }
void _print(int t) { cout << t << '\n'; }
void _print(string t) { cout << t << '\n'; }
void _print(char t) { cout << t << '\n'; }
void _print(double t) { cout << t << '\n'; }

/* UTILS */
/* #define read(type) readInt<type>()*/
#define test   \
    int tc;    \
    cin >> tc; \
    while (tc--)
ll min(ll a, int b)
{
    if (a < b)
        return a;
    return b;
}
ll min(int a, ll b)
{
    if (a < b)
        return a;
    return b;
}
ll max(ll a, int b)
{
    if (a > b)
        return a;
    return b;
}
ll max(int a, ll b)
{
    if (a > b)
        return a;
    return b;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
string to_upper(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 'a' - 'A';
    return a;
}
string to_lower(string a)
{
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 'a' - 'A';
    return a;
}
bool prime(ll a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i <= round(sqrt(a)); ++i)
        if (a % i == 0)
            return 0;
    return 1;
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

vector<int> preSum(vector<int> a)
{
    vector<int> prefix(a.size());
    prefix[0] = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    return prefix;
}

/* clang-format on */

/* Main()  function */

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void solve()
{

    int n;
    cin >> n;
    vvl dp(n + 1, vll(2, 0));
    dp[n - 1][1] = 1;
    dp[n - 1][0] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i][0] = (4 * dp[i + 1][0] + dp[i + 1][1]) % MOD;
        dp[i][1] = (dp[i + 1][0] + dp[i + 1][1] + dp[i + 1][1]) % MOD;
    }

    cout << (dp[0][1] + dp[0][0]) % MOD << endl;
}

int main()
{
    fastio();
    test
    solve();
    return 0;
}