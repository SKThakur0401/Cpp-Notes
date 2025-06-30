#include<iostream>
#include<cmath>
using namespace std;

void saveData(string name, int age, string grades){
    cout<<"Hello : "<<name<<", Your age is : "<<age<<endl<<"& to be honest, your grades are : "<<grades<<endl<<"There is scope for improvement :)"<<endl;
}

int main(){

    saveData("Somu",19,"B+");
    saveData("Jesu",17,"C-");
    saveData("Rohan",19,"A");


    
    cout<<sizeof(2.43+8.57)<<endl;

    return 0;
}