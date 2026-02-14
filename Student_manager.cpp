/*
Note that this Version is using a linked list which is temporary and will
 be deleted after every use
*/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
//Variable container class for linked list/DataBase
class Node{
    public:
    
    string name;     
    int age;
    Node* next;
    Node(string s_name,int s_age){//Node Constructure will be called for passing values(e,g name, age)
        name=s_name;
        age=s_age;
        next=NULL;
    }

};
//Student Class to perform operations on Variable Container class
class student{
    Node* head;
    Node* tail;
    public:
student(){
        head=tail=NULL;
    }
//Checking Weather the DataBase is empty or Not
    bool isempty(){
if(head==NULL){
    cout<<"Student DataBase is Empty!!!";
    return true;
}
return false;
}
//Adding Student at the End of the DataBase 
void addStudent(){
        string s_name;
        int s_age;
        cout<<"Enter Student Name: ";
        cin>>s_name;
        cout<<"Enter Student Age: ";
        cin>>s_age;
        Node* newNode= new Node(s_name,s_age);
        if(head==NULL){
            head=tail=newNode;
            return;
        }
       tail->next=newNode;
       newNode->next=NULL;
       tail=newNode;
     
    }
//Searching for a single Student Using Student I'd
    void search(){
     if(isempty()) return;// Checking weather DataBase is Empty before searching
    int id;
    cout<<"Enter Student I'd: ";
    cin>>id;
    Node* temp=head;
        int index=1;
        while(temp!=NULL){
        if(index==id){
             cout<<index;
            cout<<"-> Name: "<<temp->name;
            cout<<" Age: "<<temp->age<<endl;
            return;
        }
            temp=temp->next;
            index++;
      
        }
        cout<<endl<<" Student Not in DataBase";
    }
// Updating the Information of a Single Already Existing Student Using a student I'd
    void update(){
if(isempty()) return;// Checking Weather DataBase is Empty or Not

    Node* temp=head;
        string s_name;
        int s_age,index=1,id;
        cout<<"Enter Student I'd: ";
        cin>>id;
        bool status=false;
        while(temp!=NULL){//Checking Weather the given I'd Exists in the DataBase or Not!!!
            if(index>id) break;
            if(id==index){
            cout<<endl<<index;
            cout<<"-> Name: "<<temp->name;
            cout<<", Age: "<<temp->age<<endl;
            status=true;
                break;
        }
        temp=temp->next;
        index++;
        }
        if(!status){
            cout<<"Student Not found in DataBase";
            return;
        }
        else{
        cout<<"Enter Student New Name: ";
        cin>>s_name;
        
        cout<<"Enter Student New Age: ";
        cin>>s_age;
        
            temp->name=s_name;
            temp->age=s_age;
            cout<<"Updation Has Been Done!!!";
            return;
        }
    
    }
//Deleting Information a Single Already Existing Student Using a Student I'd
    void Delete(){
 if(isempty()) return;// Checking Weather DataBase is Empty or Not!!!
 int id,index=1;
 cout<<"Enter Student I'd";
 cin>>id;
 bool status=false;
 Node* temp=head;

 
 while(temp!=NULL){
    if(id==index){
        cout<<endl<<index;
        cout<<"-> Name: "<<temp->name;
        cout<<", Age: "<<temp->age;
        cout<<endl;
        status=true;
    }
    index++;
    temp=temp->next;
 }
if(!status){
    cout<<"Student Not Found in DataBase";
    return;
}
temp=head;
index=2;
while(temp!=NULL){
if(index==id){
    Node* temp2=temp->next;
    temp=temp->next->next;
    delete temp2;
}
}
}
//Viewing Entire DataBase in One go
    void view(){
if(isempty()) return;
   
    Node* temp=head;
        int i=1;
        while(temp!=NULL){
        
            cout<<i;
            cout<<"-> Name: "<<temp->name;
            cout<<" Age: "<<temp->age;
            temp=temp->next;
            i++;
            cout<<endl<<endl;
        }
    }
//Displaying the Available Modification Option in the DataBase
void menu(){
          
     cout << "\n1. Add Student";
    cout << "\n2. View Students";
    cout << "\n3. Search Student";
    cout << "\n4. Update Student";
    cout << "\n5. Delete Student";
    cout << "\n0. Exit\n";
}
};
int main()
{
    system("cls");
student s;
int choice=-1,status=1;

while(status){
    s.menu();

cin>>choice;
    switch(choice){
    case 0:{
        system("cls");
        status=0;
        break;
    }
    case 1: {
        system("cls");
    s.addStudent();
    system("cls");
    break;
    }
    case 2:{
        system("cls");
        s.view();
        break;
    }
    case 3:{
        system("cls");
        s.search();
        break;
    }
    case 4:{
        system("cls");
        s.update();
        break;
    }
     default:{
        cout<<"Invalid Selection";
       break;
    }
}}

    return 0;
}