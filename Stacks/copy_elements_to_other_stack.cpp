#include <bits/stdc++.h>
using namespace std;
stack<int> copyStack(stack<int> &input)
{

    stack<int> temp; // copy values in another stack to get the reverse order
    while (!input.empty())
    {
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    stack<int> res;
    while (!temp.empty())
    { // copying again in the result to get back to original sequence
        int curr = temp.top();
        temp.pop();
        res.push(curr);
    }

    return res;
}
void copyStackRec(stack<int> &s1, stack<int> &res)
{
    if (s1.empty())
        return;
    int curr = s1.top();
    s1.pop();
    copyStackRec(s1, res);
    res.push(curr);
}
int main()
{
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);

    // stack<int> ans = copyStack(st);
    stack<int> res;
    copyStackRec(st, res);
    while (!res.empty())
    { // printing elements
        int curr = res.top();
        res.pop();
        cout << "|  " << curr << "  |" << endl;
    }

    return 0;
}