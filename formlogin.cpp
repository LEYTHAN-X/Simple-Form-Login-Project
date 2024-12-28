#include <iostream>
#include <fstream>
using namespace std;
class temp{
    string userName,Email,password;
    string searchName,searchPass,searchEmail;
    fstream file;
    public:
        void login();
        void signup();
        void forgot();
}obj;
int main(){
    int choice;
    cout<<"\n1-> Login";
    cout<<"\n2-> Sign-Up";
    cout<<"\n3-> Forget Password";
    cout<<"\n4-> Exit";
    cout<<"\nEnter your choice :";
    cin>>choice;
    switch(choice){
        case 1:
            obj.login();
        break;

        case 2:
            obj.signup();
        break;
        
        case 3:
            obj.forgot();
        break;

        case 4:
            return 0;
        break;

        default:
            cout<<"Invalid selection...!";
    }
    return 0;
}
void temp :: signup(){
    cin.ignore(); 
    cout<<"\nEnter yor user name :";
    getline(cin,userName);
    cout<<"\nEnter your Email Address :";
    getline(cin,Email);
    cout<<"\nEnter your Password :";
    getline(cin,password);

    file.open("logindata.txt",ios :: out | ios :: app);
    file<<userName<<"*"<<Email<<"*"<<password<<endl;
    file.close();
}
void temp :: login(){
    cin.ignore(); 
    // string searchName,searchPass;
    cout<<"---------------LOGIN---------------"<<endl;
    cout<<"Enter your user name :"<<endl;
    getline(cin,searchName);
    cout<<"Enter your Password :"<<endl;
    getline(cin,searchPass);

    file.open("loginData.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName==searchName){
            if(password==searchPass){
                cout<<"\nAccount Login Succesful...!";
                cout<<"\nUsername :"<<userName<<endl;
                cout<<"\nEmail :"<<Email<<endl;
            }
            else{
                cout<<"Password is Incorrect...!";
            }
        }
        getline(file,userName,'*');
        getline(file,Email,'*');
        getline(file,password,'\n');
    }
    file.close();
}
void temp :: forgot(){
    cin.ignore(); 
    cout<<"\nEnter Your UserNmae :";
    getline(cin,searchName);
    cout<<"\nEnter your email Address :";
    getline(cin,searchEmail);
    file.open("logindata.txt",ios :: in);
    getline(file,userName,'*');
    getline(file,Email,'*');
    getline(file,password,'\n');
    while(!file.eof()){
        if(userName==searchName){
            if(Email==searchEmail){
                cout<<"\nAccount Found...!"<<endl;
                cout<<"Your Password :"<<password<<endl;
                exit(0);
            }
            else{
                cout<<"Not Found...!\n";
                exit(0);
            }
        }
        else{
            cout<<"\nNot Found...!\n";
            exit(0);
        }
    }
    file.close();
}