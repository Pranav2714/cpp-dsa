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
int infixEval(string &str)
{
    stack<int> val;
    stack<char> op;
    for (int i = 0; i < str.length(); i++)
    {

        char ch = str[i];
        if (ch >= '0' && ch <= '9')
            val.push(ch - '0');

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
                        int op1 = val.top();
                        val.pop();
                        int op2 = val.top();
                        val.pop();
                        if (oprt == '+')
                            val.push(op2 + op1);

                        else if (oprt == '-')
                            val.push(op2 - op1);

                        else if (oprt == '/')
                            val.push(op2 / op1);

                        else if (oprt == '*')
                            val.push(op2 * op1);
                    }
                    op.pop();
                }
                else if (!op.empty() && (precedence(op.top()) >= precedence(ch)))
                {
                    char oprt = op.top();
                    op.pop();
                    int op1 = val.top();
                    val.pop();
                    int op2 = val.top();
                    val.pop();
                    op.push(ch);

                    if (oprt == '+')
                        val.push(op2 + op1);

                    else if (oprt == '-')
                        val.push(op2 - op1);

                    else if (oprt == '/')
                        val.push(op2 / op1);

                    else if (oprt == '*')
                        val.push(op2 * op1);
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
        int op1 = val.top();
        val.pop();
        int op2 = val.top();
        val.pop();
        if (oprt == '+')
        {
            val.push(op2 + op1);
        }
        else if (oprt == '-')
        {
            val.push(op2 - op1);
        }
        else if (oprt == '/')
        {
            val.push(op2 / op1);
        }
        else if (oprt == '*')
        {
            val.push(op2 * op1);
        }
    }
    return val.top();
}
int main()
{
    string str = "9-(5+3)*4/6";
    int ans = infixEval(str);
    cout << ans;
    return 0;
}