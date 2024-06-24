#include <bits/stdc++.h>
using namespace std;
bool checkAnagrams(string &s1, string &s2)
{
    if (s1.size() != s2.size())
        return false;
    unordered_multimap<char, int> ummp;
    for (auto c : s1)
    {
        ummp.insert(make_pair(c, 1));
    }
    for (auto c : s2)
    {
        ummp.insert(make_pair(c, 1));
    }
    int sum = 0;
    for (auto itr : ummp)
    {
        sum += itr.second;
    }
    if (sum % 2 != 0)
        return false;
    else
        return true;
}
bool checkAnagrams2(string &s1, string &s2)
{
    if (s1.size() != s2.size())
        return false;
    unordered_map<char, int> ump;
    for (auto c : s1)
    {
        ump[c]++;
    }
    for (auto c : s2)
    {
        ump[c]--;
    }

    for (auto itr : ump)
    {
        if (itr.second != 0)
            return false;
    }

    return true;
}
int main()
{
    cout << "Enter string 1" << endl;
    string s1;
    cin >> s1;
    cout << "Enter string 2" << endl;
    string s2;
    cin >> s2;
    cout << (checkAnagrams(s1, s2) ? "True" : "False") << endl;
    cout << (checkAnagrams(s1, s2) ? "Are Anagrams" : "Not Anagrams") << endl;
    return 0;
}