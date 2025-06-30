#include<iostream>
#include<unordered_map>

using namespace std;

void antiDupe(string &s)
{
    unordered_map<char,bool> om;
    int n= s.size();
    int x=0;
    for (int i = 0; i < n; i++)
    {
        if(om.count(s[x]))
        {
            s.erase(x,1);
        }
        else
        {
            om[s[x]]=1;
            x++;
        }
    }
}

int main(){
    string s; cin>>s;
    antiDupe(s);
    cout<< s <<endl;

    return 0;
}