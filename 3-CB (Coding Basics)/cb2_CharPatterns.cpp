//CHARACTER PATTERNS :


#include<iostream> 
#include<cmath>
using namespace std;


int main(){

 
    int n=4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< char(65+j)<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;


    // int n=4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< char(65+j+i)<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;


    // int n=4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<< char(65+i)<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;

    // int n=4;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<< char(65+i+j)<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;


    // int n=4;
    // n=5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<< char(65+n-1-i+j)<<"";
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;

    

    return 0;
}