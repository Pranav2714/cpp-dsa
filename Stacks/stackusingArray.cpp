#include<bits/stdc++.h>
using namespace std;
class Stack{
      int *arr;
      int top;
      int capacity;
      public:
      Stack(int c){
        this->capacity=c;
        arr = new int[c];
        this->top=-1;
      }
      void push(int val){
           if(isFull()) {
            cout<<"Stack overflow!"<<endl;
            return;
           }
            arr[++top]=val;
      }
      void peek(){
        if(isEmpty()) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        cout<<endl<<arr[top]<<endl;
      }
      void display(){
        if(isEmpty()) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
      }
      bool isFull(){
        if(top==capacity-1) return true;
        return false;
      }
      bool isEmpty(){
        if(top==-1) return true;
        return false;
      }
      void pop(){
         if(isEmpty()) {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
      }
};
int main(){
    Stack *s = new Stack(10);
    s->push(5);
    s->push(4);
    s->push(3);
    s->push(2);
    s->push(1);
    s->display();
    s->peek();
    s->pop();
    s->display();
    s->peek();
    return 0;
}