#include <bits/stdc++.h>
using namespace std;
string getSmallestString(string s, int k)
{
    int n = s.size();
    if (k == 0)
        return s;
    vector<char> alpha(27);
    alpha[1] = 'a';
    for (int i = 2; i < 27; i++)
    {
        alpha[i] = char(alpha[i - 1] + 1);
    }
    string res = "";
    for (int i = 0; i < n; i++)
    {
        char temp;
        int count = INT_MAX;
        for (int j = 1; j < n; j++)
        {
            if (s[i] - alpha[j] <= count)
            {
                temp = alpha[j];
                count = min(count, s[i] - alpha[j]);
            }
        }
        res += temp;
    }
    return res;
}

int main()
{
    string s;
    int k;
    cin >> s;
    cin >> k;
    string ans = getSmallestString(s, k);
    cout << ans << endl;
    return 0;
}
