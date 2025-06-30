#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int fac(int n){ return (n==0)? 1 : n* fac(n-1);}

int solve(string s, string *output)
{
    if(s.size() ==1)
    {
        output[0] = s;
        return 1;
    }

    int smallAns = solve(s.substr(1), output);

    for (int i = smallAns; i < smallAns*(smallAns+1); i++)
    {
        output[i] = output[i% smallAns];
    }


    for (int i = 0; i < smallAns*(smallAns+1); i++)
    {
        int x= i/smallAns;
        string ans= "";

        for (int j = 0; j < x; j++)
        {
            ans+=output[i][j];
        }
        ans+= s[0];
        for (int j = x; j < smallAns; j++)
        {
            ans+=output[i][j];
        }
        output[i] = ans;
    }
    return smallAns*(smallAns+1);
}

int main(){


    string s; cin>>s;

    // string * output = new string[7];
    string * output = new string[fac(s.size())];

    int n = solve(s, output);

    for (int i = 0; i < n; i++)
    {
        cout<< output[i] <<" ";
    }
    cout <<endl;

    return 0;
}

