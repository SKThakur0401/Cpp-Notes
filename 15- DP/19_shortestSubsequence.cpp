#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int shortestSub(string s, string v)
{
    if(s.empty()) return 0;
    if(v.empty()) return 0;

    int w1= shortestSub(s.substr(1), v);
    int i;
    for (i = 0; i <= v.size(); i++)
    {
        if(i== v.size()) return w1;
        if(v[i]== s[0]) break;
    }
    
    int w2= 1+shortestSub(s.substr(1), v.substr(i+1));

    return min(w1,w2);
}

int main(){


    string s,v;
    cin>>s>>v;

    cout<< shortestSub(s,v) <<endl;

    return 0;
}

