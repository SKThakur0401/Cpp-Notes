#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


bool isIn(string s, vector<string>& vs)
{
    // for(string i : vs)
    // {
    //     if(i== s) return true;
    // }

    for(int i=0; i< vs.size(); i++)
    {
        if(s == vs[i]) return true;
    }
    return false;
}

void solve(string s, vector<string> &dictionary, vector<string>& ans, string output= "")
{
    if(s.size() == 0)
    {
        cout<< "Yes size becomes 0" <<endl;
        ans.push_back(output.substr(0,output.size()-1));
        return;
    }

    for(int i=1; i<= s.size(); i++)
    {
        if(isIn(s.substr(0,i), dictionary))
        {
            output+= s.substr(0,i) + " ";

            solve(s.substr(i), dictionary, ans, output);

            output= output.substr(0, output.size()-i-1);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here

    vector<string> ans;

    solve(s, dictionary, ans);

    return ans;
}

int main()
{
    cout<< "Start : " <<endl;
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;

        vector<string> dictionary;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin>>s;
            dictionary.push_back(s);
        }

        string st; cin>>st;

        vector<string> ans= wordBreak(st, dictionary);
        
        cout<< ans.size() <<endl;
    }
}
