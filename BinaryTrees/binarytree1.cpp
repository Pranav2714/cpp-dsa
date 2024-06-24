#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *right;
    Node *left;

    Node(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};
void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}
int leafNodes(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int left = leafNodes(root->left);
    int right = leafNodes(root->right);
    return left + right;
}
void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->val << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}
void levelOrderPW(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int nodesPresent = q.size();
        while (nodesPresent--)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->val << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

vector<int> topView(Node *root)
{
    vector<int> ans;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    map<int, int> m;
    while (!q.empty())
    {
        int nodesAtCurrLvL = q.size();
        while (nodesAtCurrLvL--)
        {
            pair<Node *, int> p = q.front();
            Node *currNode = p.first;
            int column = p.second;
            q.pop();
            if (m.find(column) == m.end())
            {
                m[column] = currNode->val;
            }
            if (currNode->left)
            {
                q.push(make_pair(currNode->left, column - 1));
            }
            if (currNode->right)
            {
                q.push(make_pair(currNode->right, column + 1));
            }
        }
    }
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    map<int, int> m;
    while (!q.empty())
    {
        int nodesAtCurrLvL = q.size();
        while (nodesAtCurrLvL--)
        {
            pair<Node *, int> p = q.front();
            Node *currNode = p.first;
            int column = p.second;
            q.pop();
            if (currNode->left)
            {
                q.push(make_pair(currNode->left, column - 1));
            }
            if (currNode->right)
            {
                q.push(make_pair(currNode->right, column + 1));
            }
        }
    }
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

void reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    stack<int> st;
    q.push(root);
    while (!q.empty())
    {
        int nodesAtCurrLevel = q.size();
        while (nodesAtCurrLevel--)
        {
            Node *temp = q.front();
            q.pop();
            st.push(temp->val);
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int main()
{
    Node *root = new Node(10);  //                   10
    root->right = new Node(15); //              4          15
    root->left = new Node(4);   //          44    14    69    100
    root->left->left = new Node(44);
    root->left->right = new Node(14);
    root->right->left = new Node(69);
    root->right->right = new Node(100);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    cout << leafNodes(root) << endl;
    cout << "Level Order" << endl;
    levelOrder(root);
    cout << endl;
    levelOrderPW(root);
    cout << endl;
    vector<int> ans = topView(root);
    cout << "Top View" << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "Reverse Level Order :" << endl;
    reverseLevelOrder(root);
    cout << endl;
    cout << "Bottom View" << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}