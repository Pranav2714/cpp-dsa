#include <bits/stdc++.h>
using namespace std;
string postfixToInfix(string &str)
{
    stack<string> val;
    string s = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch >= '0' && ch <= '9')
        {
            s += ch;
            val.push(s);
            s = "";
        }
        else
        {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
            {
                string op1 = val.top();
                val.pop();
                string op2 = val.top();
                val.pop();
                s += "(" + op2 + ch + op1 + ")";
                val.push(s);
                s = "";
            }
        }
    }
    return val.top();
}
int main()
{
    string str = "953+4*6/-";
    string ans = postfixToInfix(str);
    cout << ans;
    return 0;
}