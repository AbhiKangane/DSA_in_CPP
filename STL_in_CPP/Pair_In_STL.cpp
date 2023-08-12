#include<iostream>
using namespace std;

class Student{
    private :
    string name;
    int roll;

    public:
        void setStudent(string a, int b){
            name = a;
            roll = b;
        }
        void getStudent(){
            cout<<"Name: "<<name;
            cout<<"\nroll no: "<< roll;
        }
};

int main(){
    pair<string,int> p1;
    pair<string,string> p2;
    pair<string, float> p3;
    pair<int, Student> p4;
    // make_pair() used for creating pair
    p1= make_pair("Abhishek", 35);
    p2= make_pair("Abhishek", "Kangane");
    p3= make_pair("Abhishek", 8.2);

    Student s1;
    s1.setStudent("Aishwarya_Roy", 143);    
    p4= make_pair(1, s1);

    cout<<"\nPair 1: \n" ;
    cout<<p1.first<<" "<<p1.second;
    cout<<"\nPair 2: \n" ;
    cout<<p2.first<<" "<<p2.second;
    cout<<"\nPair 3: \n" ;
    cout<<p3.first<<" "<<p3.second;
    cout<<"\nPair 4: \n" ;
    cout<<p4.first<<"\n";
    Student s = p4.second;
    s.getStudent();

    return 0;

}