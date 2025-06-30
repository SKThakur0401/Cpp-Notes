#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int lcs(string s, string t, string &output)
{
    if(s.size()==0 || t.size()==0) return 0;

    if(s[0] == t[0])
    {
        output+= s[0];
        return 1+ lcs(s.substr(1), t.substr(1), output);
    }
    string o1,o2; o1=output; o2= output;
    int lcs1 = lcs(s.substr(1), t, o1);
    int lcs2 = lcs(s, t.substr(1), o2);

    if(lcs1>= lcs2) output=o1;
    if(lcs1< lcs2) output=o2;
    return max(lcs1, lcs2);
}

void curate(int** memo, string &output, int r, int c, string s, string t)
{
    if(r==0 || c==0) return;
    int mrc = memo[r][c];

    if(mrc > memo[r-1][c-1]  &&  mrc > memo[r-1][c] && mrc > memo[r][c-1])
    {
        output = s[r-1] + output;

        curate(memo, output, r-1, c-1, s, t);
        return;
    }

    else if(mrc== memo[r-1][c])
    {
        curate(memo, output, r-1, c, s,t);
        return;
    }

    else if(mrc == memo[r][c-1])
    {
        curate(memo, output, r, c-1, s,t);
        return;
    }

    else {curate(memo, output, r-1, c-1, s, t);}
}

int memo_lcs(string s, string t, int** memo)
{
    if(s.size()==0 || t.size()==0) return memo[s.size()][t.size()] = 0;

    if(memo[s.size()][t.size()] != -1) return memo[s.size()][t.size()];

    if(s[0] == t[0])
    {
        return memo[s.size()][t.size()] = 1+ memo_lcs(s.substr(1), t.substr(1), memo);
    }

    int lcs1 = memo_lcs(s.substr(1), t, memo);
    int lcs2 = memo_lcs(s, t.substr(1), memo);

    return memo[s.size()][t.size()] = max(lcs1, lcs2);
}


int memoii(string s, string t, string &output)
{
    int** memo = new int*[s.size()+1];
    for (int i = 0; i < s.size()+1; i++)
    {
        memo[i] = new int[t.size()+1];

        for (int j = 0; j < t.size()+1; j++)
        {
            memo[i][j]= -1;
            if(i==0 || j==0) memo[i][j] =0;
        }
    }

    int ans = memo_lcs(s,t, memo);

    curate(memo, output, s.size(), t.size(), s, t);
    return ans;
}

string dp(string s, string t)
{
    int** memo = new int*[s.size()+1];
    for (int i = 0; i < s.size()+1; i++)
    {
        memo[i] = new int[t.size()+1];

        for (int j = 0; j < t.size()+1; j++)
        {
            memo[i][j]= -1;
            if(i==0 || j==0) memo[i][j] =0;
        }
    }

    for (int i = 1; i < s.size()+1 ; i++)
    {
        for (int j = 1; j < t.size()+1; j++)
        {
            if(s[i-1] == t[j-1])
            {
                memo[i][j] = 1  + memo[i-1][j-1];
            }
            else
            {
                memo[i][j] = max(memo[i-1][j] , memo[i][j-1]);
            }
        }
    }

    string output = "";
    curate(memo, output, s.size(), t.size(), s, t);

    // cout<< output <<endl;
    return output;
}

int main(){

    string s,t; cin>>s>>t;

    string output= "";

    // cout<< lcs(s,t, output) <<endl;
    cout<< dp(s,t) <<endl;
    // cout<< memoii(s,t, output) <<endl;
    cout<< output <<endl;
    return 0;
}

