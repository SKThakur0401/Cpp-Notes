//FIBONACCI SERIES
#include<iostream>
#include<cmath>
using namespace std;

int fibo(int n){            //RETURNS Nth   TERM OF FIBONACCI SERIES USING "RECURSION"
    if(n==1){return 1;}
    else if(n==2){return 1;} 
    else{return fibo(n-1) + fibo(n-2) ;}
}

 
int fibonacci(int n)        //RETURNS Nth   TERM OF FIBONACCI SERIES
{
    int t1=1, t2=1, nex;

    if(n==1 || n==2){return 1;}

    else
    {   
        for (int i = 0; i < n-2; i++)
        {
            nex=t1 + t2;
            t1= t2;
            t2= nex;
        }
        return nex;
    }
}



int main(){

    for (int i = 1; i < 10; i++)
    {
        cout<< fibo(i) <<endl;
        cout<< fibonacci(i) <<endl;
    }
    

    return 0;
}