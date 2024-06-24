#include<bits/stdc++.h>
using namespace std;
class B{
    public:
    int a;
    int b;

    void operator+ (B *obj){
          int val1=this->a;
          int val2=obj->b;
          cout<<val1-val2<<endl;
    }

};
int main(){

        B obj1;
        B *obj2 = new B;
        obj1.a=5;
        obj1.b=100;
        obj2->b=5;
        obj1+obj2;
      
    return 0;
}