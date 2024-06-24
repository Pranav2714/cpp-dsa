#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node *head;
    Node *tail;
    int size = 0;
    int val;

    Queue()
    {
        this->head = this->tail = NULL;
    }
    void enqueue(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            this->head = this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    void dequeue()
    {
        if (this->head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
        {
            Node *temp = this->head;
            this->head = this->head->next;
            temp->next = NULL;
            if (this->head == NULL)
                this->tail = NULL;
            delete temp;
            this->size--;
        }
    }

    void front()
    {
        if (this->head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        else
            cout << this->head->val << endl;
    }

    void getSize()
    {
        cout << this->size;
    }
};

int main()
{
    Queue *q = new Queue();
    q->enqueue(55);
    q->enqueue(33);
    q->enqueue(44);
    q->enqueue(22);
    q->dequeue();
    q->front();
    q->getSize();
    return 0;
}