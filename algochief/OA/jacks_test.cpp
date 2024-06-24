#include <iostream>
#include <set>
#include <string>
using namespace std;

void solve(string s)
{
    set<string> st;
    string word;
    int start = 0;

    for (int i = 0; i <= s.length(); ++i)
    {
        if (i == s.length() || s[i] == ' ')
        {
            word = s.substr(start, i - start);
            if (!word.empty() && st.find(word) == st.end())
            {
                st.insert(word);
                cout << word << " ";
            }
            start = i + 1;
        }
    }
}

int main()
{
    string s;
    getline(cin, s);
    solve(s);
    return 0;
}
