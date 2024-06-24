#include<bits/stdc++.h>
using namespace std;
void sortByPW(vector<double> &w,vector<double> &p,vector<double> &pByw)
{
    int n=p.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(pByw[j]<pByw[j+1])
            {
                swap(pByw[j],pByw[j+1]);
                swap(p[j],p[j+1]);
                swap(w[j],w[j+1]);
            }
        }
    }

}
void printArray(vector<double> a)
{

    for(double ele: a)
    {
        cout<<ele<<" ";
    }
    cout<<endl;
}
void knpsck(vector<double> &w,vector<double> &p,vector<double> &pByw)
{
    int n = pByw.size();
    double weightK;
    cout<<"Enter Weight of Knapsack"<<endl;
    cin>>weightK;
    double rem=weightK;
    vector<double>x(n,0.0);
    int i=0;
    for(; i<n; i++)
    {
        if(w[i]<rem)
        {
            x[i]=1;
            rem-=w[i];
        }
        else break;
    }
    if(i<n)
    {
            x[i]=rem/w[i];
        
    }
    double profit=0;
    for(int k=0; k<n; k++)
    {
        profit+=x[k]*p[k];
    }
    cout<<"Profit is"<<endl;
    cout<<profit<<endl;

    for(int j=0; j<n; j++)
    {
        cout<<x[j]<<" ";
    }
    cout<<endl;
    cout<<"X array"<<endl;
    printArray(x);

}
int main()
{
    cout<<"Enter number of Objects"<<endl;
    int n;
    cin>>n;
    vector<double> w(n);
    vector<double> p(n);
    vector<double> pByw(n);
    for(int i=0; i<n; i++)
    {
        cout<<"Enter weight of object "<<i+1<<endl;
        cin>>w[i];
        cout<<"Enter profit of object "<<i+1<<endl;
        cin>>p[i];
        pByw[i]=p[i]/w[i];
    }
    sortByPW(w,p,pByw);
    cout<<"weights"<<endl;
    printArray(w);
    cout<<"Profit"<<endl;
    printArray(p);
    cout<<"Profit By weight"<<endl;
    printArray(pByw);
    cout<<endl;
    knpsck(w,p,pByw);


    return 0;
}