#include<iostream>
using namespace std;
int main(){
    int x,y=1,z=1;
    cout<<"Enter ur fav num : ";
    cin>>x;
    while(y<=x){
        z*=y;
        y++;
    }
    cout<<"Factorial of fav num is : "<<z<<endl;
    return 0;
}