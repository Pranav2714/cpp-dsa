#include <bits/stdc++.h>
using namespace std;

int postfixEval(string &str)
{
    stack<int> val;
    for (int i = 0; i < str.length(); i++)
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
                    val.push(op2 + op1);

                else if (ch == '-')
                    val.push(op2 - op1);

                else if (ch == '/')
                    val.push(op2 / op1);

                else if (ch == '*')
                    val.push(op2 * op1);
            }
        }
    }
    return val.top();
}
int main()
{
    string str = "953+4*6/-";
    int ans = postfixEval(str);
    cout << ans;
    return 0;
}