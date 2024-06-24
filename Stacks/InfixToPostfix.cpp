#include <bits/stdc++.h>
using namespace std;
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
string infixToPrefix(string &str)
{
    stack<string> val;
    stack<char> op;
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
                if (op.empty() || ch == '(' || op.top() == '(')
                {
                    op.push(ch);
                }
                else if (ch == ')')
                {
                    while (op.top() != '(')
                    {
                        char oprt = op.top();
                        op.pop();
                        string op1 = val.top();
                        val.pop();
                        string op2 = val.top();
                        val.pop();
                        s += op2 + op1 + oprt;
                        val.push(s);
                        s = "";
                    }
                    op.pop();
                }
                else if (!op.empty() && (precedence(op.top()) >= precedence(ch)))
                {
                    char oprt = op.top();
                    op.pop();
                    string op1 = val.top();
                    val.pop();
                    string op2 = val.top();
                    val.pop();
                    s += op2 + op1 + oprt;
                    val.push(s);
                    s = "";
                    op.push(ch);
                }
                else if (!op.empty() && (precedence(op.top()) < precedence(ch)) && val.size() != 1)
                {
                    op.push(ch);
                }
            }
        }
    }
    while (!op.empty() && val.size() > 1)
    {
        char oprt = op.top();
        op.pop();
        string op1 = val.top();
        val.pop();
        string op2 = val.top();
        val.pop();
        s += op2 + op1 + oprt;
        val.push(s);
        s = "";
    }
    return val.top();
}
int main()
{
    string str = "9-(5+3)*4/6";
    string ans = infixToPrefix(str);
    cout << ans;
    return 0;
}