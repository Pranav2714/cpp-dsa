#include <bits/stdc++.h>
using namespace std;
void pushElementAtBottomRec(stack<int> &s1, int x)
{
    if (s1.empty())
    {
        s1.push(x);
        return;
    }
    int curr = s1.top();
    s1.pop();
    pushElementAtBottomRec(s1, x);
    s1.push(curr);
}

void reverseStackRec(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int curr = st.top();
    st.pop();
    reverseStackRec(st);
    pushElementAtBottomRec(st, curr);
}

void reverseStack(stack<int> &st)
{
    stack<int> temp;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    stack<int> temp2;
    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        temp2.push(curr);
    }
    while (!temp2.empty())
    {
        int curr = temp2.top();
        temp2.pop();
        st.push(curr);
    }
}

void printStack(stack<int> res)
{
    while (!res.empty())
    { // printing elements
        int curr = res.top();
        res.pop();
        cout << curr << endl;
    }
}
int main()
{
    stack<int> st;
    st.push(5);
    st.push(11);
    st.push(66);
    st.push(100);
    st.push(88);

    reverseStackRec(st);
    printStack(st);

    return 0;
}