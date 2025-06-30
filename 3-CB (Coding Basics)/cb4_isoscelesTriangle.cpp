//ISOSCELES TRIANGLE
#include<iostream>
#include<cmath>
using namespace std;


int main(){
 
 
    int n=4;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout<< " ";
        }
        for (int a = 0; a < i; a++)
        {
            cout<< a+1;
        }
        for (int b = 0; b < i-1; b++)
        {
            cout<< i-1-b;
        }
        
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;
    cout <<endl;


    // int n=8;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout<< " ";
        }
        for (int a = 0; a < i; a++)
        {
            cout<< a+i;
        }
        for (int b = 0; b < i-1; b++)
        {
            cout<< i-1-b+i-1;
        }
        
        cout <<endl;
    }
    

    return 0;
}