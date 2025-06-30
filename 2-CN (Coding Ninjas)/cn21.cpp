//---   RECURSION FUNCTION FOR "pow(x,n) ---->  x^n"    ---

#include<iostream>
#include<cmath>
using namespace std;

long long pow(long long x, int n) {     // power function "BRUTE FORCE APPROACH"
    if(n==0){return 1;}

    else{return x * pow(x,n-1)   ;}
}
 
long long powPro(long long x, int n)       // Optimised version of "pow", use this whenever required
{
    if(n==0) return 1;
    return (n%2==0)? powPro(x*x, n/2) : x * powPro(x*x, (n-1)/2);
}

int main(){
    long long x;
    int n;
    cout<< "Enter x^n : " <<endl;
    cin>>x>>n;
    cout<< powPro(x,n) <<endl;
    cout<< pow(x,n) <<endl;

    return 0;
}