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
    // static Node *constructTreeFromBFS(vector<string> &arr)
    // {
    //     Node *root = new Node(stoi(arr[0]));
    //     int n = arr.size();
    //     queue<Node *> q;
    //     q.push(root);
    //     for (int i = 1; i < n - 1; i += 2)
    //     {
    //         Node *temp = q.front();
    //         q.pop();
    //         if (arr[i] != "")
    //         {
    //             Node *l = new Node(stoi(arr[i]));
    //             q.push(l);
    //             temp->left = l;
    //         }
    //         if (arr[i + 1] != "")
    //         {
    //             Node *r = new Node(stoi(arr[i + 1]));
    //             q.push(r);
    //             temp->right = r;
    //         }
    //     }
    //     return root;
    // }
    // void levelOrderPW(Node *root)
    // {
    //     if (root == NULL)
    //         return;
    //     queue<Node *> q;
    //     q.push(root);
    //     while (!q.empty())
    //     {
    //         int nodesPresent = q.size();
    //         while (nodesPresent--)
    //         {
    //             Node *temp = q.front();
    //             q.pop();
    //             cout << temp->val << " ";
    //             if (temp->left != NULL)
    //             {
    //                 q.push(temp->left);
    //             }
    //             if (temp->right != NULL)
    //             {
    //                 q.push(temp->right);
    //             }
    //         }
    //         cout << endl;
    //     }
    // }
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

int main()
{
    vector<string> arr = {"1", "2", "3", "4", "5", "", "6", "", "7", "", "", "8", "", "", "", "9", ""};
    Node *root = constructTreeFromBFS(arr);
    levelOrderPW(root);
    return 0;
}