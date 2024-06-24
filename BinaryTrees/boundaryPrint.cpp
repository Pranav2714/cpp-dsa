#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *constructTreeFromBFS(vector<string> &arr)
{
    Node *root = new Node(stoi(arr[0]));
    int n = arr.size();
    queue<Node *> q;
    q.push(root);
    for (int i = 1; i < n - 1; i += 2)
    {
        Node *temp = q.front();
        q.pop();
        if (arr[i] != "")
        {
            Node *l = new Node(stoi(arr[i]));
            q.push(l);
            temp->left = l;
        }
        if (arr[i + 1] != "")
        {
            Node *r = new Node(stoi(arr[i + 1]));
            q.push(r);
            temp->right = r;
        }
    }
    return root;
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

void printLeftBoundary(Node *root)
{
    if (root == NULL)
        return;
    if (root->right == NULL && root->left == NULL)
        return;
    cout << root->val << " ";
    if (root->left != NULL)
        printLeftBoundary(root->left);
    else
        printLeftBoundary(root->right);
}
void printRightBoundary(Node *root)
{
    if (root == NULL)
        return;
    if (root->right == NULL && root->left == NULL)
        return;

    if (root->right != NULL)
        printRightBoundary(root->right);
    else
        printRightBoundary(root->left);
    cout << root->val << " ";
}
void printBottomBoundary(Node *root)
{
    if (root == NULL)
        return;
    if (root->right == NULL && root->left == NULL)
    {
        cout << root->val << " ";
        return;
    }

    printBottomBoundary(root->left);
    printBottomBoundary(root->right);
}
void printBoundary(Node *root)
{
    printLeftBoundary(root);
    printBottomBoundary(root);
    printRightBoundary(root->right);
}
int main()
{
    vector<string> arr = {"1", "2", "3", "4", "5", "", "6", "7", "", "8", "", "9", "10", "", "11", "", "12", "", "13", "", "14", "15", "16", "", "17", "", "", "18", "", "19", "", "", "", "20", "21", "22", "23", "", "24", "25", "26", "27", "", "", "28", "", ""};
    Node *root = constructTreeFromBFS(arr);
    levelOrderPW(root);
    cout << endl;
    printBoundary(root);

    return 0;
}