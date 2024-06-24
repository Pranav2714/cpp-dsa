#include <bits/stdc++.h>
using namespace std;
bool checkIdentity(vector<int> &v1, vector<int> &v2, int a1, int b1, int min, int max)
{
    int i;
    for (i = a1; i < v1.size(); i++)
    { // finding the first value within the range for tree v1
        if (v1[i] > min && v1[i] < max)
            break;
    }
    int j;
    for (j = b1; j < v2.size(); j++)
    {
        if (v2[j] > min && v2[j] < max) // finding the first value within the range for tree v2
            break;
    }
    if (i == v1.size() && j == v2.size())
        return true; // if no value was found within the range

    // if we found the value in either of the arrays
    if ((i == v1.size() && j != v2.size()) || (i != v1.size() && j == v2.size()))
        return false;

    if (v1[i] != v2[j])
        return false; // if the values found are equal or not

    // recursively checking for left and right subtree
    return checkIdentity(v1, v2, a1 + 1, b1 + 1, min, v1[i]) && checkIdentity(v1, v2, a1 + 1, b1 + 1, v1[i], max);
}
bool areIdentialBSTs(vector<int> &v1, vector<int> &v2)
{
    return checkIdentity(v1, v2, 0, 0, INT_MIN, INT_MAX);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v1(n);
    vector<int> v2(n);
    cout << "Enter vector v1" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    cout << "Enter vector v2" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    if (areIdentialBSTs(v1, v2))
        cout << " The BSTs are identical" << endl;
    else
        cout << " The BSTs are not identical" << endl;
    return 0;
}