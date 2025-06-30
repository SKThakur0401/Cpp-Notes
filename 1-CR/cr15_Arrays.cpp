#include<iostream>
using namespace std;

int main(){
    int demon[2][3]={{8,9,10} , {6,5,4}};   //MAKING A 2D ARRAY...THINK OF IT AS A MATRIX OF "2 X 3"
    for(int i=0;i<2;i++){                   //PRINTING THE ELEMENTS OF THAT "2D" ARRAY
        for(int j=0;j<3;j++){
    cout<<demon[i][j]<<endl;}}


    int marks[6];                     //ARRAY FULL OF USER GIVEN INPUTS :)
    for(int i=0;i<6;i++){
        cout<<"Enter your marks in " <<i+1<<"th Subject : ";
        cin>>marks[i];                //WE TOOK INPUT AND INSERTED IT IN ARRAY "marks"
    }
}