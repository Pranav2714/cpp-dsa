#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node()
    {
        this->data = -1;
        this->next = NULL;
    }
};
class Stack
{
    int capacity;
    Node *head;
    int currSize;

public:
    Stack(int c)
    {
        this->capacity = c;
        this->currSize = 0;
        this->head = NULL;
    }
    void push(int data)
    {
        if (isFull())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        Node *newnode = new Node(data);
        if (this->head == NULL)
        {
            head = newnode;
        }
        else
        {
            newnode->next = this->head;
            this->head = newnode;
        }
        this->currSize++;
    }

    bool isEmpty()
    {
        if (this->head == NULL)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (this->currSize == this->capacity)
            return true;
        else
            return false;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "stack underflow!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        currSize--;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "stack underflow!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    void printTop()
    {
        if (isEmpty())
        {
            cout << "stack underflow!" << endl;
            return;
        }
        cout << endl
             << head->data << endl;
    }
};

int main()
{
    Stack *s = new Stack(5);
    s->push(5);
    s->push(4);
    s->push(3);
    s->push(2);
    s->push(1);
    s->pop();
    s->display();
    s->push(1);
    s->pop();
    cout << endl;
    s->push(69);
    s->display();
    s->printTop();
    return 0;
}