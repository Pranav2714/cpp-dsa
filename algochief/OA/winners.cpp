#include <bits/stdc++.h>
using namespace std;

int solve(string &str)
{
    int n = str.length();
    int wp = 0, bp = 0;
    for (int i = 1; i < n; i++)
    {
        if (str[i] == str[i - 1] == 'w' && str[i] == str[i + 1] == 'w')
        {
            wp++;
        }
        if (str[i] == str[i - 1] == 'b' && str[i] == str[i + 1] == 'b')
        {
            bp++;
        }
    }
    if (wp > bp)
        return 1;
    else
        return 2;
}

int main()
{
    string str;
    cin >> str;
    cout << solve(str) << endl;
    return 0;
}