#include <bits/stdc++.h>
using namespace std;

void solve(string &s)
{
    if (s.length() <= 1)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < s.length()/2; i++)
    {
        if (s[i] != 'a')
        {
            s[i] = 'a';
            cout << s << endl;
            return;
        }
    }
    s[s.length() - 1] = 'b';
    cout << s << endl;
    return;
}

int main()
{
    string palindrome;
    cin >> palindrome;
    solve(palindrome);
}