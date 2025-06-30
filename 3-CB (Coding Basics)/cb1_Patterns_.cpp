/*
    IN PATTERN MAKING KEEP 3 THINGS IN MIND

1.  NUMBER OF ROWS
2.  NUMBER OF COLUMNS IN (i-th) ROW (TELL NUMBER OF COLUMNS IN i-th COLUMN, IN TERMS OF "i")
3.  WHAT TO PRINT ,(LIKE "*" IN MANY CASES)
4.  YOU WILL MAINLY HAVE 3 THINGS , " n , i , j "
*/


//NOTE: RUN THIS CODE AND SEE ALL THE OUTPUT, AND TRY TO PRINT SOME OF THESE OUTPUTS FOR REVISION :)

#include<iostream>
#include<cmath>
using namespace std;


int main(){

    int n=5;
    for (int i = 0; i < n; i++)
    {
        cout <<endl;
        for (int j = 0; j <=i; j++)
        {
            cout<<"*";
        }
        
    }
    cout <<endl;

    int x=4;
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout<< i<<" ";
        }
        cout <<endl;
        
    }
    cout <<endl;
    cout <<endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout<< j+1<<" ";
        }
        cout <<endl;
        
    }

    cout <<endl;
    cout <<endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout<< x-j<<" ";
        }
        cout <<endl;
        
    }
    cout <<endl;
    cout <<endl;

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<< j+1<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;


    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            cout<< j+1+i<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;


    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<< ((i*i)-i+2)/2  + j<<" ";
        }
        cout <<endl;
    }
    cout <<endl;
    cout <<endl;
    
    
    
    

    return 0;
}