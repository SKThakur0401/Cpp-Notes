// Subsequent Strings

#include<iostream>
#include<cmath>
using namespace std;

int pow(int x,int n)
{
    return (n==0)? 1: x* pow(x,n-1);
}

int subing(string s, string output[])
{
    if(s.size()==0)
    {
        output[0]="";
        return 1;
    }

    int smallSizeOutput= subing(s.substr(1), output);

    for (int i = 0; i < smallSizeOutput; i++)
    {
        output[smallSizeOutput+i]= s[0]+ output[i];
    }
    return 2*smallSizeOutput;
}


int main(){

    string s= "abc";
    int n= pow(2,s.size());
    string output[n];
    subing(s,output);

    for (int i = 0; i < pow(2,s.size()); i++)
    {
        cout<<output[i]<<"  ";
    }
    
    return 0;
}

