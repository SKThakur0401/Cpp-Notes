// Question : Given 2 strings "s and t", find if on rotation, can we obtain one string from anohter or not :)

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

bool isRot(string s, string t) 
{
    if(s.size() != t.size()) return false;
    int n=s.size();

    vector<int> starters;
    char curr= s[0];

    for (int i = 0; i < s.size(); i++) 
    {
        if(curr == t[i]) starters.push_back(i);
    }
    
    for (int i = 0; i < starters.size(); i++)
    {
        int cyc = starters[i];

        for(int j=0; j< n; j++)
        {
            if(s[j] != t[cyc]) break;

            cyc= (cyc+1)%n;
            if(j== n-1) return true;
        }
    }
    return false;
}


int main(){

    // string s= "abacd";
    // string t= "cdaba";

    string s= "abcdefg";
    string t= "efghabc";

    cout<< isRot(s,t) <<endl;

    return 0;
}

