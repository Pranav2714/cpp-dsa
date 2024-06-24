#include <bits/stdc++.h>
using namespace std;
bool checkOneToOne(string &s1, string &s2)
{
    unordered_map<char, char> m;
    for (int i = 0; i < s1.size(); i++)
    {
        if (m.find(s1[i]) != m.end())
        {
            if (m[s1[i]] != s2[i])
                return false;
        }
        else
        {
            m[s1[i]] = s2[i];
        }
    }
    return true;
}
bool checkIsomorphism(string &s1, string &s2)
{
    if (s1.length() != s2.length())
        return false;

    bool s1s2 = checkOneToOne(s1, s2);
    bool s2s1 = checkOneToOne(s2, s1);

    return s1s2 && s2s1;
}
int main()
{
    cout << "Enter string s1" << endl;
    string s1;
    cin >> s1;
    cout << "Enter string s2" << endl;
    string s2;
    cin >> s2;
    cout << (checkIsomorphism(s1, s2) ? "is Isomorphic" : "Not isomorphic") << endl;
    return 0;
}