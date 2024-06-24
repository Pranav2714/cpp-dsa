#include <bits/stdc++.h>
using namespace std;

int postfixEval(string &str)
{
    stack<int> val;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        char ch = str[i];
        if (ch >= '0' && ch <= '9')
        {
            val.push(ch - '0');
        }
        else
        {
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                int op1 = val.top();
                val.pop();
                int op2 = val.top();
                val.pop();
                if (ch == '+')
                    val.push(op1 + op2);

                else if (ch == '-')
                    val.push(op1 - op2);

                else if (ch == '/')
                    val.push(op1 / op2);

                else if (ch == '*')
                    val.push(op1 * op2);
            }
        }
    }
    return val.top();
}
int main()
{
    string str = "-9/*+5346";
    int ans = prefixEval(str);
    cout << ans;
    return 0;
}