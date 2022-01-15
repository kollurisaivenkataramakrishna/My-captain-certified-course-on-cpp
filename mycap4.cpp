#include<iostream>
using namespace std;
int main()
{
    int a[5],i,n;
    cout<<"Enter Elements"<<endl;
    for(i=0;i<5;i++){
        cin>>a[i];
    }
    cout<<"You Entered:"<<endl;
    for(n=0;n<5;n++){
        cout<<a[n];
        cout<<endl;
    }
}