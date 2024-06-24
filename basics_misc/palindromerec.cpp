#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int num , int *temp){
    if(num>=0 && num<=9) {
        int lastdigit = (*temp)%10;
        (*temp)/=10;
        return(num==lastdigit);
    }
    bool result = (isPalindrome(num/10,(temp)) && (num%10==((*temp)%10)));
    (*temp/=10);
    return result;
    }
int main(){
        int num= 12321;
        int anotherNum=num;
        int *temp=&anotherNum;
        cout<<isPalindrome(num,temp);
    return 0;

}