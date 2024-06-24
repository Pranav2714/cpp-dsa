#include <bits/stdc++.h>
using namespace std;
bool isbalanced(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        // if (ch == ')' || ch == '}' || ch == ']')
        else
        {
            if (ch == ')' && st.top() == '(' && !st.empty())
            {
                st.pop();
            }
            else if (ch == '}' && st.top() == '{' && !st.empty())
            {
                st.pop();
            }
            else if (ch == ']' && st.top() == '[' && !st.empty())
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}
int main()
{
    string s1 = "}{";
    cout << isbalanced(s1);
    return 0;
}