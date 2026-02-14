
/*
Note that this Version is using a student_data.txt file
 for storing, fetching and updating students data.
*/
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
const int size=15;
bool isempty(){
    ifstream file("student_data.txt");
    if(file.peek()==EOF) return true;
    else return false;
    file.close();
}
void update(){
    if(isempty()){
        cout<<"DataBase is empty!!!";
        return; 
    }
    fstream file("student_data.txt", ios::in | ios::out | ios::binary);
    cout<<"Enter Student I'd: ";
    int index;
    cin>>index;
    string line;
    int temp=index;
    bool status=false;
    while(getline(file,line)){
        if(--temp==0){
            status=true;
            
            cout<<line;
            cout<<"\nEnter Student's New Name: ";
            cin>>line;
            if(line.size()<11){
                int offset=(index-1)*size;
                char buffer[13];// This buffer will contain new [Name(10 bytes)+sapce(1 byte)+age(2 bytes)]

            }
            else{
                cout<<"\nStudent new Name Exceed 10 Character limit, Please Try a Different Name: ";
                return;
            }
            cout<<"\nEnter Student's Age: ";
            int age;
            cin>>age;

        }
        if(!status){
            cout<<"Student Not Found in DataBase!!!";
            return;
        }
    }
    file.close();
}
int main()
{
    system("cls");

    return 0;
}