#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v)
    {
        this->val = v;
        this->left = this->right = NULL;
    }
};
TreeNode *insertIntoTree(TreeNode *root, int val, int &successor)
{
    if (root == NULL)
    {
        return new TreeNode(val);
    }
    if (val < root->val)
    {
        successor = root->val;
        root->left = insertIntoTree(root->left, val, successor);
    }
    else if (val > root->val)
    {

        root->right = insertIntoTree(root->right, val, successor);
    }
    return root;
}
void replaceWithNextGreatestInteger(vector<int> &v)
{

    TreeNode *root = NULL;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        int successor = -1;
        root = insertIntoTree(root, v[i], successor);
        v[i] = successor;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    replaceWithNextGreatestInteger(v);
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}