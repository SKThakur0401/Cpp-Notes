#include<iostream>
using namespace std;
int main(){
    float a=3.14;
    long double ld=3.14;
    long long int lli = 498198392833829;
    cout<<"Size of float \'a\' is : "<<sizeof(a)<<endl;
    cout<<"Size of long double is : "<<sizeof(ld)<<endl;
    cout<<"Size of float is : "<<sizeof(90.1f)<<endl;    // IF YOU TYPE THE DESIRED NUMBER AND THEN APPEND "f" or "F" to it.... then it becomes a float
    cout<<"Size of float is : "<<sizeof(90.1F)<<endl;
    cout<<"Size of long double is : "<<sizeof(90.1l)<<endl;  //IF YOU TYPE THE DESIRED NUMBER AND THEN APPEND "l" or "L" to it... then it becomes a long double
    //NOTE : BY DEFAULT ITS A "DOUBLE"
    cout<<"Size of long double is : "<<sizeof(90.1L)<<endl;
    cout<<"Size of long long int is : "<<sizeof(lli)<<endl;

    int count= 5;
    cout<< count/float(4) <<endl;
    return 0;
}