#include<iostream>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
using namespace std;
int total=0;
class student{
private:
    string name,course,uid,mail_id,contact,address,father,mother;

public:
    void menu();
    void enter();
    void display();
    void edit();
    void search();
    void delete();

    };
void student::menu(){
menu_start:
    _start:
int a,q,e;
char x;
system("cls");
cout<<"\t\t*******************************************"<<endl;
cout<<"\t\t|     BASIC STUDENT MANAGEMENT SYSTEM     |"<<endl;
cout<<"\t\t*******************************************"<<endl;
cout<<"\t\t\t 1.Enter New Record"<<endl;
cout<<"\t\t\t 2.Display Record"<<endl;
cout<<"\t\t\t 3.Edit Record"<<endl;
cout<<"\t\t\t 4.Search Record"<<endl;
cout<<"\t\t\t 5.Delete Record"<<endl;
cout<<"\t\t\t 6. EXIT"<<endl;
cout<<"\t\t*******************************************"<<endl;
cout<<"\t\t|   ENTER YOUR CHOICE(1,2,3,4,5,6)  :    |"<<endl;
cout<<"\t\t*******************************************"<<endl;
cout<<"Enter your choice :"<<endl;
cin>>a;


switch(a){
case 1:do{
enter();
total++;
cout<<"\t\tWant to Enter another student details(Y|N) ?"<<endl;
cin>>x;

}while(x == 'y'|| x=='Y');
break;
case 2:
display();
    cout<<"\t\t YOUR DATA DISPLAYED..."<<endl;
    cout<<"\t\tEnter 1 to exit..."<<endl;
    cin>>q;
    if(q==1){
        menu();
    }
    else{
        cout<<"invalid choice....try again...";

    }
break;
case 3: edit();
cout<<"\t\tEnter 1 to exit..."<<endl;
    cin>>e;
    if(e==1){
        menu();
    }
    else{
        cout<<"invalid choice....try again...";

    }
break;
case 4:search();break;
case 6:exit(0);



default:
    cout<<"Invalid Choice.....Try again.....!!!"<<endl;




}

goto menu_start;
}
void student::enter(){
    fstream file;
  int b;
cout<<"---------------------------------------------------------------------------------------------"<<endl;
cout<<"-----------------------------------------ADD  STUDENT DETAILS--------------------------------"<<endl;
cout<<"Enter student Name :";
cin>>name;
cout<<"Enter Course  :";
cin>>course;
cout<<"Enter UID number :";
cin>>uid;
cout<<"Enter Father Name :";
cin>>father;
cout<<"Enter Mother Name :";
cin>>mother;
cout<<"Enter E-mail ID :";
cin>>mail_id;
cout<<"Enter Contact Number :";
cin>>contact;
cout<<"Enter Address :";
cin>>address;
file.open("studentRecord.txt",ios::app | ios :: out);
file<<" "<<name<<" "<<course<<" "<<uid<<" "<<father<<" "<<mother<<" "<<mail_id<<" "<<contact<<" "<<address<<endl;
file.close();

}

void student::display(){
system("cls");
int k=1;
fstream file;
cout<<"---------------------------------------------------------------------------------------------"<<endl;
cout<<"--------------------------------------- STUDENT RECORD TABLE --------------------------------"<<endl;
file.open("studentRecord.txt",ios::in);
if(!file){
    cout<<"No Data is Present....!!!!";
    file.close();}
else {
    file>>name>>course>>uid>>father>>mother>>mail_id>>contact>>address;
while(k<=total){
cout<<"\n\t\t\tSTUDENT NUMBER :"<<k++<<endl;
cout<<"\t\t\tSTUDENT NAME :"<<name<<endl;
cout<<"\t\t\tCOURSE :"<<course<<endl;
cout<<"\t\t\tSTUDENT'S UID :"<<uid<<endl;
cout<<"\t\t\tSTUDENT'S FATHER NAME :"<<father<<endl;
cout<<"\t\t\tSTUDENT'S MOTHER NAME :"<<mother<<endl;
cout<<"\t\t\tSTUDENT'S E-MAIL ID :"<<mail_id<<endl;
cout<<"\t\t\tCONTACT NUMBER :"<<contact<<endl;
cout<<"\t\t\tADDRESS :"<<address<<endl;



};
if(total==0){
    cout<<"\n\n\t\t\tNO DATA IS PRESENT...!!!"<<endl;
}


} file.close();}

void student::edit(){
    int found=0;
    string roll;
system("cls");
fstream file,file1;
cout<<"---------------------------------------------------------------------------------------------"<<endl;
cout<<"--------------------------------------- STUDENT MODIFY TABLE --------------------------------"<<endl;
file.open("studentRecord.txt",ios::in);
if(!file){
    cout<<"\n\n\t\t\tNo Data is Present"<<endl;
    file.close();
}
else{
    cout<<" Enter the UID of student whose Data you want to edit : "<<endl;
    cin>>roll;
    file1.open("Record.txt",ios::in | ios::app);
    file1<<name<<uid<<father<<mother<<mail_id<<contact<<address;
    while(!file.eof()){
        if(roll!=uid){
            file1<<" "<<name<<" "<<uid<<" "<<father<<" "<<mother<< "  " <<mail_id<< " "<<contact<<" "<<address;
            }
        else{
cout<<"\t\t\tEnter student Name :";
cin>>name;
cout<<"\t\t\tEnter Course  :";
cin>>course;
cout<<"\t\t\tEnter UID number :";
cin>>uid;
cout<<"\t\t\tEnter Father Name :";
cin>>father;
cout<<"\t\t\tEnter Mother Name :";
cin>>mother;
cout<<"\t\t\tEnter E-mail ID :";
cin>>mail_id;
cout<<"\t\t\tEnter Contact Number :";
cin>>contact;
cout<<"\t\t\tEnter Address :";
cin>>address;
file1<<" "<<name<<" "<<uid<<" "<<father<<" "<<mother<< "  " <<mail_id<< " "<<contact<<" "<<address;
found++;
        }
file1<<" "<<name<<" "<<uid<<" "<<father<<" "<<mother<< "  " <<mail_id<< " "<<contact<<" "<<address;
if(found==0){
    cout<<"\n\t\t\t STUDENT UID NOT FOUND...!!!"<<endl;
}
  break;  }
}
file1.close();
file.close();
remove("studentRecord.txt");
rename("Record.txt","studentRecord.txt");


}

void student::search(){
system("cls");
int found=0;
fstream file;
file.open("studentRecord.txt",ios::in);
if(!file){
    cout<<"---------------------------------------------------------------------------------------------"<<endl;
cout<<"--------------------------------------- STUDENT SEARCH TABLE --------------------------------"<<endl;
cout<<"\n\t\tNo Data Is Present...!!!";
}
else{
    string  rollno;
     cout<<"---------------------------------------------------------------------------------------------"<<endl;
cout<<"--------------------------------------- STUDENT SEARCH TABLE --------------------------------"<<endl;
cout<<"\n\n\t\t\tEnter the UID of the student which you want to search :"<<endl;
cin>>rollno;
file>>name>>uid>>father>>mother>>mail_id>>contact>>address;
while(!file.eof()){
    if(rollno==uid){
       cout<<"\t\t\tSTUDENT NAME :"<<name<<endl;
cout<<"\t\t\tCOURSE :"<<course<<endl;
cout<<"\t\t\tSTUDENT'S UID :"<<uid<<endl;
cout<<"\t\t\tSTUDENT'S FATHER NAME :"<<father<<endl;
cout<<"\t\t\tSTUDENT'S MOTHER NAME :"<<mother<<endl;
cout<<"\t\t\tSTUDENT'S E-MAIL ID :"<<mail_id<<endl;
cout<<"\t\t\tCONTACT NUMBER :"<<contact<<endl;
cout<<"\t\t\tADDRESS :"<<address<<endl;
found++;
    }
    file>>name>>uid>>father>>mother>>mail_id>>contact>>address;
}
if(found==0){
    cout<<"\n\t\tNO Data Is Present...!!!";
}
file.close();
}

void student::delete(){
system("cls");
int f,found=0;
fstream  file,file1;
cout<<"---------------------------------------------------------------------------------------------"<<endl;
cout<<"--------------------------------------- STUDENT DELETED DETAILS --------------------------------"<<endl;
file.open("studentRecord.txt",ios::in);
if(!file){
    cout<<"\n\t\t No data found...!!!";
}
else{
   cout<<"\n\n\t\t\tEnter the UID of the student which you want to Delete :"<<endl;
   cin>>f;
file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (f != uid)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

}

}
main(){
    student project;
    project.menu();
    return 0;
}
