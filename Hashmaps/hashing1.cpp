#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;  //pre-compute
    }
    // for (auto it : mpp)  //iterating the map
    // {
    //     cout << it.first << "->" << it.second << endl;
    // }
    int q;
    cin >> q;
    while (q--)
    {
        char x;
        cin >> x;
        cout << mpp[x] << endl; //fetch
    }
    return 0;
}