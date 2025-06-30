#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class student
{
    static int totalStudent;

    public:
    int age;
    int rollNo;
    // static int totalStudent;
    // char* name;

    // student(int age, int rollNo, char* name)
    // {
    //     this->age= age;
    //     this->rollNo= rollNo;
    //     this->name= new char[strlen(name)+1];
    //     strcpy(this->name, name);
    //     // this->name= name;
    // }

    student(int age, int rollNo)
    {
        totalStudent++;
        this->age=age;
        this->rollNo=rollNo;
    }

    student(){
        totalStudent++;
    }

    static void getStuCount(int pass)
    {
        if(pass== 123) cout<< totalStudent <<endl;
        else cout<< "Wrong password! try again" <<endl;
    }

    bool operator==(student const &s2)
    {
        return (rollNo == s2.rollNo && age== s2.age);
    }
};

int student::totalStudent=0;


class numbers
{
    int n;
    public:
    
}


int main(){

    // char name[]= "Nisha";
    // student s1(18, 2020, name);
    // name[0]= 'M';

    // cout<< s1.name <<endl;

    student s1;
    student s2(19,2020);
    student s3(18,2023);
    student s4(19,2020);
    student s5;

    // cout<< s2.totalStudent <<endl;
    // student::getStuCount(123);

    bool b= (s4==s2);

    cout<< b <<endl;
    cout<< b <<endl;

    return 0;
}

