# include<iostream>
using namespace std;
class time
{
        int m,s,h;
        public:
                void get(int p,int q,int r)
                {
                        h=p;
                        m=q;
                        s=r;
                }
                void display()
                {
                        cout<<"Time is "<<h<<":"<<m<<":"<<s; 
                }
};
int main()
{
        int p,q,r;
        time t;
        
        cout<<"Enter hour:";
        cin>>p;
        cout<<"Enter minute:";
        cin>>q;
        cout<<"Enter seconds:";
        cin>>r;
        t.get(p,q,r);
        t.display();
}