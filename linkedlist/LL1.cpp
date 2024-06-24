#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newHead = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
int main()
{
    Node *a = new Node(5);
    Node *b = new Node(6);
    Node *c = new Node(7);
    Node *d = new Node(8);
    Node *e = new Node(9);
    cout << endl;
    a->next = b;
    b->next = c;
    b->next = c;
    c->next = d;
    d->next = e;
    display(a);

    Node *newHead = reverseLinkedList(a);
    cout << endl;

    display(newHead);

    return 0;
}