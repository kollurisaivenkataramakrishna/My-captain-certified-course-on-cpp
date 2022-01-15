#include<iostream>
//program to find whether you're eligible to vote or not
using namespace std;
int main(){
    int age;
    cout<<"Enter your age:"<<endl;
    cin>>age;
    cout<<"your age:"<<age<<endl;
    if(age>=18){
        cout<<"you're eligible to vote";

    }
    else{
        cout<<"you're not eligible to vote";
    }
    return 0;
}