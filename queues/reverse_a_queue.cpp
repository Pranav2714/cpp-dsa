#include <bits/stdc++.h>
using namespace std;
void reverseQ(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(55);
    q.push(66);
    q.push(77);
    q.push(88);
    q.push(99);
    q.push(100);
    reverseQ(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}