//          ----CONVERT HEXAMDECIMAL TO DECIMAL NUMBER----


#include<iostream>
#include<cmath>
using namespace std;

int binToDec(int n) 
{
    int k=1,ans=0;
    while(n>0)
    {
        ans+= (n%10)*k;
        k*=2;
        n/=10;
    }
    return ans;
}

int octToDec(int n)
{
    int k=1, ans=0;
    while(n>0)
    {
        ans+=(n%10)*k;
        k*=8;
        n/=10;
    }
    return ans;
}



int hexToDec(string s)
{
    int ans=0, k=1;
    for (int i = s.size()-1 ; i >= 0; i--)
    {
        if (s[i]>='0' && s[i] <='9')
        {
            ans+=(s[i] - '0')*k;
        }

        else
        {
            ans+=(s[i]-'a'+10)*k;
        }
        k*=16;
    }

    return ans;
}

string decToBin(int n)          //USING STRINGS :)  YOU CAN ALSO DO IT USING INTEGER RETURN :)
{
    string s="";
    while(n>0)
    {
        if(n%2 == 1){s.insert(0,"1");}
        if(n%2 == 0){s.insert(0,"0");}
        n/=2;
    }
    return s;
}


int decToOct(int n)
{
    int ans=0, k=1;
    while(n>0)
    {
        ans+=(n%8)*k;
        n/=8;
        k*=10;
    }
    return ans;
}


string decToHex(int n)
{
    string s="";
    while(n>0)
    {
        int k= n%16;

        // string ap= to_string(k);
        // s.insert(0,ap);
        if(k==0){s.insert(0,"0");}
        if(k==1){s.insert(0,"1");}
        if(k==2){s.insert(0,"2");}
        if(k==3){s.insert(0,"3");}
        if(k==4){s.insert(0,"4");}
        if(k==5){s.insert(0,"5");}
        if(k==6){s.insert(0,"6");}
        if(k==7){s.insert(0,"7");}
        if(k==8){s.insert(0,"8");}
        if(k==9){s.insert(0,"9");}

        // char a= 55+k;
        // string apk= to_string(a);
        // s.insert(0,apk);

        if(k==10){s.insert(0,"A");}
        if(k==11){s.insert(0,"B");}
        if(k==12){s.insert(0,"C");}
        if(k==13){s.insert(0,"D");}
        if(k==14){s.insert(0,"E");}
        if(k==15){s.insert(0,"F");}

        n/=16;
    }
    return s;
}



string decToHex_Revamped(int n)     //BETTER VERSION OF "decToHex"
{
    string s="";
    while(n>0)
    {
        int k= n%16;
        if(k<=9)
        {
            string ans = to_string(k);
            s.insert(0,ans);
        }
        else
        {
            char c= 55+k;       //READ "cn42" to get a clearer picture
            string st="";
            st+=c;
            s.insert(0,st);
        }
        n/=16;
    }
    return s;
}



int main(){
    // cout<< hexToDec(s) <<endl;


    string n;
    cout<< "Enter a number : ";
    cin>>n;


    cout<< binToDec(n) <<endl;
    cout<< octToDec(n) <<endl;

    string s;
    cout<< "Enter a string (to convert hexadecimal to others) : ";
    cin>>s;
    cout<< hexToDec(s) <<endl;

    cout<< decToBin(n) <<endl;

    cout<< decToOct(n) <<endl;
    cout<< decToHex(n) <<endl;

    return 0;
}