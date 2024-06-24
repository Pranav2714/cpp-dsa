#include <bits/stdc++.h>
using namespace std;
void printStack(stack<int> res)
{
    while (!res.empty())
    { // printing elements
        int curr = res.top();
        res.pop();
        cout << curr << endl;
    }
}
void delFromBottomRec(stack<int> &s)
{
    if (s.size() == 1)
    {
        s.pop();
        return;
    }
    int curr = s.top();
    s.pop();
    delFromBottomRec(s);
    s.push(curr);
}
void delFromBottom(stack<int> &s)
{
    stack<int> temp;
    while (s.size() != 1)
    {
        int curr = s.top();
        s.pop();
        temp.push(curr);
    }
    s.pop();
    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}
void delAnyFromBottom(stack<int> &s, int idx)
{
    stack<int> temp;
    int count = 0;
    int n = s.size();
    while (count < n - idx - 1)
    {
        int curr = s.top();
        s.pop();
        temp.push(curr);
        count++;
    }
    s.pop();
    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        s.push(curr);
    }
}
void delAnyFromBottomRec(stack<int> &s, int idx)
{
    while (s.size() == idx + 1)
    {
        s.pop();
        return;
    }
    int curr = s.top();
    s.pop();
    delAnyFromBottomRec(s, idx);
    s.push(curr);
}
int main()
{
    stack<int> s;
    s.push(5);
    s.push(0);
    s.push(6);
    s.push(7);
    s.push(10);
    // delFromBottom(s);
    int idx;
    cin >> idx;
    delAnyFromBottomRec(s, idx);
    printStack(s);
    return 0;
}