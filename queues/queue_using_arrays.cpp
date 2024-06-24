#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int front;
    int back;
    vector<int> v;

public:
    Queue()
    {
        this->front = -1;
        this->back = -1;
    }

    void enqueue(int val)
    {
        if (this->front == -1 && this->back == -1)
        {
            this->front++;
            this->back++;
        }
        v.push_back(val);
        this->back++;
    }

    void dequeue()
    {
        if (this->front == -1)
        {
            cout << "Empty" << endl;
            return;
        }
        else if (this->front == this->back)
        {
            this->front = this->back = -1;
            v.clear();
        }
        else
        {
            this->front++;
        }
    }
    void getSize()
    {
        cout << this->v.size() << endl;
    }
    void getFront()
    {
        cout << v[this->front] << endl;
    }
};
int main()
{
    Queue *q = new Queue();
    q->enqueue(4);
    q->enqueue(6);
    q->enqueue(7);
    q->enqueue(8);
    q->getFront();
    q->dequeue();
    q->getFront();
    q->dequeue();
    q->getFront();
    q->dequeue();
    q->getFront();
    return 0;
}