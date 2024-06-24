#include <bits/stdc++.h>
using namespace std;
string postfixToInfix(string &str)
{
    stack<string> val;
    string s = "";
    for (int i = str.length(); i >= 0; i--)
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
                s += "(" + op1 + ch + op2 + ")";
                val.push(s);
                s = "";
            }
        }
    }
    return val.top();
}
int main()
{
    string str = "-9/*+5346";
    string ans = postfixToInfix(str);
    cout << ans;
    return 0;
}