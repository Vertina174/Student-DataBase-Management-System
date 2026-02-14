
/*
Note that this Version is using a student_data.txt file
 for storing, fetching and updating students data.
*/
#include<iostream>// For Input and Output Operations
#include<fstream>// For File Handling Operations
#include<iomanip>// For Manipulating the Output Format(e.g setw, left)
#include<cstring>// For String Handling Operations(e.g memset, memcpy)
using namespace std;

const int size=15;//Size of Each line in the DataBase name[10 bytes]+space[1 byte]+age[2 bytes]+1 for \r and +1 for \n
bool isempty(){ //Checking Weather the DataBase is Empty or Not
    ifstream file("student_data.txt");
    if(file.peek()==EOF) return true;
    else return false;
    file.close();
}
void add(){ //Adding Student Data in the bottom of the DataBase
    
    ofstream file("student_data.txt", ios::app);// For Adding Student Data, the file will be opened in append mode
    
    cout<<"Enter Student's First Name: ";
    string name;
    cin>>name;
    cout<<"Enter Student Age: ";
    int age;
    cin>>age;
    if(name.size()<10) file<<left<<setw(10)<<name; //Validating the length of the Student's Name, it should be less than 10 characters
    else{
        cout<<"First Name Length Exceed 10 characters, Please Try a Different Name!!!";
        file.close();
        return;
    }
    
    (age<9) ? file<<" "<<'0'<<age<<endl:file<<" "<<age<<endl;//Validating the Student's Age for one OR Two digits

file.close();
}
void view(){// Viewing Entire DataBase in One go
    if(isempty()){// Checking Weather the DataBase is Empty or Not before viewing
        cout<<"DataBase is Empty!!!";
        return;
    }
    ifstream file("student_data.txt");// For Viewing Student Data, the file will be opened in read mode
    string line;
    int i=1;// This variable will be used for showing Student I'd or index in the DataBase
    while(getline(file,line)){
        cout<<i++<<"-> "<<line<<endl;
    }
file.close();
}
void update(){//Updating the Information of a Single Already Existing Student Using a student I'd
    if(isempty()){// if DataBase is Empty, No Student to Update
        cout<<"\nDataBase is Empty!!!";
        return;
    }
    fstream file("student_data.txt", ios::in | ios::out | ios::binary);// For Updating Student Data, the file will be opened in read and write mode in binary format for stricty and random access
    int index;
    string line;
    cout<<"\nEnter Student I'd: ";
    cin>>index;
    bool status=false;
    int temp=index;
    while(getline(file,line)){// Searching for the Student in the DataBase using Student I'd or index
        
        if(--temp==0){
            status=true;
            cout<<line;
            char buffer[13];
            int age;
            cout<<"\nEnter Student's New Name: ";
            cin>>line;
            int offset=(index-1)*size;
            if(line.size()<10){// Validating the length of the Student's Name, it should be less than 10 characters
                memset(buffer, ' ',10);
                memcpy(buffer, line.c_str(), line.size());// this will store the string of name in a array, rest of the bytes will be padded with space characters
                buffer[10]=' ';//mannualy adding space character at 11th byte for separating name and age in the DataBase 
            }
            else{
                cout<<"Student's name can only be less than 10 characters long, Please try Again!!!";
                file.close();
                return;
            }
            cout<<"\nEnter Student's Age: ";
            cin>>age;
            if(age<9){//Validating the Student's Age for one OR Two digits
                buffer[11]='0';
                buffer[12]=age+'0';
                file.seekp(offset,ios::beg);
                file.write(buffer,13);
                file.close();
                return;
            }
            else{
                buffer[11]=(age/10)+'0';
                buffer[12]=(age%10)+'0';
                file.seekp(offset,ios::beg);
                file.write(buffer,13);
                file.close();
                return;

            }
        }
        
    }
    if(!status){// If the given Student I'd or index is not found in the DataBase
        cout<<"\nStudent Not in DataBase!!!\n";
        file.close();
        return;
    }
    file.close();
}
void clear(){// Clearing the Entire DataBase
    string choice_validation;
    cout<<"Type CONFIRM to proceed: ";
    cin>>choice_validation;
    if(choice_validation!="CONFIRM"){
        cout<<"Wrong Input Try Again";
        return;
    }
    ofstream file("student_data.txt");

    file.close();

    }
void menu(){// Displaying the Available Modification Option in the DataBase
    cout<<"\n1. Add a Student";
    cout<<"\n2. View Record of All Students";
    cout<<"\n3. update a Student's Record";
    cout<<"\n4. Clear DataBase";
    cout<<"\n0. Exit the Program\n";
    
}
void choice(){// This function will be used for taking the User's Choice for the Modification Option in the DataBase
    bool status=true;
while(status){
    int choice;
    menu();
    cin>>choice;
    switch(choice){
        case 0:{
            system("cls");
            status=false;// Exiting the Program
            break;
        }
        case 1:{
            system("cls");
            add();
            break;
        }
        case 2:{
            system("cls");
            view();
           break;
        }
        case 3:{
            system("cls");
            update();
            break;
        }
        case 4:{
            system("cls");
            clear();
            break;
        }
        default :{
            system("cls");
            cout<<"Invalid Input!!!";
            break;
        }
    }
}
}
int main()
{
    system("cls");
    choice();
return 0;
}