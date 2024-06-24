#include <bits/stdc++.h>
using namespace std;

stack<int> pushElementAtBottom(stack<int> &input, int x)
{

    stack<int> temp; // copy values in another stack to get the reverse order
    while (!input.empty())
    {
        int curr = input.top();
        input.pop();
        temp.push(curr);
    }

    temp.push(x); // this is where the element got inserted at the bottom

    while (!temp.empty())
    { // getting back to original sequence along with the new element added at the bottom
        int curr = temp.top();
        temp.pop();
        input.push(curr);
    }

    return input;
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

void insertAtIdx(stack<int> &st, int idx, int x)
{
    stack<int> temp;
    int n = st.size();
    int count = 0;
    while (count < n - idx)
    {
        int curr = st.top();
        st.pop();
        temp.push(curr);
        count++;
    }
    st.push(x);
    while (!temp.empty())
    {
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
}

void insertAtIdxRec(stack<int> &s1, int idx, int x)
{
    if (s1.size() == idx)
    {
        s1.push(x);
        return;
    }
    int curr = s1.top();
    s1.pop();
    insertAtIdxRec(s1, idx, x);
    s1.push(curr);
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    printStack(st);
    int x;
    cout << "enter element" << endl;
    cin >> x;
    cout << "Enter index" << endl;
    int idx;
    cin >> idx;
    // stack<int> res = pushElementAtBottom(st, x);
    insertAtIdxRec(st, idx, x);
    printStack(st);

    return 0;
}