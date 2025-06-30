#include<iostream>
#include<cmath>
using namespace std;

void encoder(string & s)
{
    string x;
    for (int i = 0; i < s.size(); i++)
    {
        x=s[i]+x;
    }
    s=x;
    for (int i = 0; i < s.size(); i++)
    {
        if(i%2 == 0){s[i]+=2;}
        else{s[i]-=2;}
    }
    cout<<"The encoded Content is -->   "<<s<<endl;
}



void decoder(string & s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if(i%2 == 0){s[i]-=2;}
        else{s[i]+=2;}
    }
    string x;
    for (int i = 0; i < s.size(); i++)
    {
        x=s[i]+x;
    }
    s=x;
    cout<<"The Decoded Content is -->   "<<s<<endl;
}


int main(){

    cout <<endl;
    
    string s;
    cout<<"Enter string : ";
    getline(cin,s);
    cout<<"Enter The Operation You Want  encode(e)  OR   decode(d)    : ";
    char ans;
    cin>>ans;

    if(ans== 'd'){decoder(s);}
    if(ans== 'e'){encoder(s);}
    cout <<endl;
    cout <<endl;

    cout<<"Enter The Operation You Want  encode(e)  OR   decode(d)    : ";
    
    cin>>ans;
    cout <<endl;
    cout <<endl;
    if(ans== 'd'){decoder(s);}
    if(ans== 'e'){encoder(s);}
    cout <<endl;
    cout <<endl;
    cout <<endl;

    return 0;
}

