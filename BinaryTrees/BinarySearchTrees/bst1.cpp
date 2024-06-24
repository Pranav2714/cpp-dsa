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
Node *findMinVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *deleteNode(Node *root, int val)
{
    if (root == NULL) // base ecase
        return NULL;
    if (root->val == val)
    {
        if (root->right == NULL && root->left == NULL) // 0 chlidren
        {
            delete (root);
            return NULL;
        }
        // 1 child
        else if (root->right == NULL && root->left != NULL)
        {
            Node *temp = root->left;
            delete (root);
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete (root);
            return temp;
        }
        else if (root->left != NULL && root->right != NULL)
        {
            int miniVal = findMinVal(root->right)->val;
            root->right = deleteNode(root->right, miniVal);
            root->val == miniVal;
            return root;
        }
    }
    if (root->val > val)
    {
        root->left = deleteNode(root->left, val);
        return root;
    }
    else if (root->val < val)
    {
        root->right = deleteNode(root->right, val);
        return root;
    }
}
Node *insertInBSTrec(Node *root, int val)
{
    Node *newNode = new Node(val);
    if (root == NULL) // base case
    {
        root = newNode;
        return root;
    }

    if (root->val > val)
    {
        root->left = insertInBSTrec(root->left, val);
    }
    else if (root->val < val)
    {
        root->right = insertInBSTrec(root->right, val);
    }
}
Node *insertInBSTitr(Node *root, int val)
{
    Node *newNode = new Node(val);
    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    Node *nodeptr = root;
    Node *parentptr = root;

    while (nodeptr != NULL)
    {
        parentptr = nodeptr;
        if (val > nodeptr->val)
        {
            nodeptr = nodeptr->right;
        }
        else if (val < nodeptr->val)
        {
            nodeptr = nodeptr->left;
        }
    }
    if (val > parentptr->val)
    {
        parentptr->right = newNode;
    }
    else
        parentptr->left = newNode;

    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}
void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
bool search(Node *root, int val)
{
    // base case
    if (root == NULL)
        return false;
    if (root->val == val)
        return true;
    if (root->val > val)
        return search(root->left, val);
    else
        return search(root->right, val);
}
Node *inorderSuccessor(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *inorderPredecessor(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

int main()
{
    cout << "Enter value of root Node" << endl;
    int val;
    cin >> val;
    Node *root = new Node(val);
    // insertInBSTitr(root, 3);
    // insertInBSTitr(root, 5);
    // insertInBSTitr(root, 6);
    // insertInBSTitr(root, 4);
    // insertInBSTitr(root, 2);
    Node *newNode = new Node(1);
    insertInBSTrec(root, newNode->val);
    insertInBSTrec(root, 5);
    insertInBSTrec(root, 3);
    insertInBSTrec(root, 6);
    insertInBSTrec(root, 4);
    insertInBSTrec(root, 2);
    inorder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl
         << "is element present : " << search(root, 5) << endl;
    // deleteNode(root, 6);
    // inorder(root);
    // cout << endl;
    // preOrder(root);
    // cout << endl;
    // postOrder(root);
    cout << "Inorder Successor " << inorderSuccessor(root->right)->val << endl;
    cout << "Inorder Predecessor " << inorderPredecessor(root->left)->val << endl;
    return 0;
}