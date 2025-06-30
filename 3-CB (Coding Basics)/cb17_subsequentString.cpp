// TO FIND ALL THE SUB-SET (ASSUMING STRING IS A SET OF CHARACTERS :)  ... HERE THE EXACT WORD IS SUBSEQUENT-STRINGS
// e.g.  for "abc" ---> _ c b bc a ac ab abc


#include<iostream>
#include<cmath>
using namespace std;
 
int subs(string s, string output[])
{
    if(s.empty()){output[0]=""; return 1;}

    string smallS= s.substr(1);
    int smallSizeOutput = subs(smallS,output);
    for (int i = 0; i < smallSizeOutput; i++)
    {
        output[i+smallSizeOutput]= s[0]+output[i];
    }
    return 2* smallSizeOutput;
}

int main(){

    string output[100];
    string s;
    cout<<"Enter variable : ";
    cin>>s;
    int count = subs(s,output);

    for (int i = 0; i < count; i++)
    {
        cout<<output[i]<<endl;
    }

    return 0;
}