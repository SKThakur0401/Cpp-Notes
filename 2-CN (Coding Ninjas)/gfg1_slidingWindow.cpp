// QUESTION : Count frequency of anagrams
// Given a word and a text, return the count of the occurrences of anagrams of the word in the text(For eg: anagrams of word for are for, ofr, rof etc.))



#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

int counter(string s, string a)
{
    // vector<int> anagram(a.size());
    int ans=0;
    unordered_map<char, int> um;
    unordered_map<char, int> memo;

    for (int i = 0; i < a.size(); i++)
    {
        memo[a[i]]+=1;
        // memo[a[i]]=2;
    }



    for (int i = 0; i < a.size(); i++)
    {
        if(memo.count(s[i]))
        {
            um[s[i]]++;
        }
    }

    // unordered_map<char ,int> memo= um;
    
    int flag=1;
    for(int i=0; i< a.size(); i++)
    {
        if(!(um.count(a[i]) && um[a[i]] == memo[a[i]])) {flag=0; break;}
    }

    ans+=flag;

    for(int i= a.size(); i< s.size(); i++)
    {
        if(memo.count(s[i]) == 0) {um[s[i - a.size()]]--; continue;}
        if(s[i- a.size()] == s[i]) {ans+=flag; continue;}
        um[s[i - a.size()]]--;

        if(memo.count(s[i])) um[s[i]]++;

        flag=1;
        for(int i=0; i< a.size(); i++)
        {
            if(!(um.count(a[i]) && um[a[i]] == memo[a[i]])) {flag=0; break;}
        }

        ans+=flag;
    }
    return ans;
}


int main(){

    string s; cin>>s;
    string a; cin>>a;

    cout<< "No. of anagrams is : "<< counter(s,a) <<endl;
    

    return 0;
}


