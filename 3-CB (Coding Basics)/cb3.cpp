//MIRROR PATTERNS

#include<iostream>
#include<cmath>
using namespace std;


int main(){

 
    int n=4;
    for (int i = 0; i < n; i++)
    {

        for (int a = 0; a < n-i-1; a++)
        {
            cout<< " ";
        }
        for (int b = 0; b < i+1; b++)
        {
            cout<< b+1;
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;

//  int n=4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout<< j+1<<" ";
        }
        cout <<endl;
    }
    cout <<endl;

    return 0;
}