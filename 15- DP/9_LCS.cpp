// Important question of DP
// LCS : longest continuous subsequence
// A subsequence is a part of the string which contains some characters(not necessarily adjacent characters!), but characters in the same order of occurence!
// e.g. string :"abcdef" --->  "ace", "ab", "aef", "cf", "bd" are all subsequenes

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int LCS(string s, string t)             // Time complexity- O(2^n)
{
    if(s.empty() || t.empty()) return 0;

    if(s[0] == t[0]) return 1 + LCS(s.substr(1), t.substr(1));

    int lcs1 = LCS(s.substr(1),t);
    int lcs2 = LCS(s,t.substr(1));
    // int lcs3 = LCS(s.substr(1),t.substr(1));     //This call would have been redundant! , since if the code goes thru lcs1 and then then "that" string when goes thru "lcs2", it would have been the same thing like "lcs3"... so no point in considering it separately to increase time complexity... "with lcs3, time complexity of this code would have been of order --> O(3^n) "

    return max(lcs1, lcs2);
}




int MEMO_solution(string s, string t, int** arr)
{
    if(s.empty() || t.empty()) return arr[s.size()][t.size()] = 0;

    if(arr[s.size()][t.size()] != -1) return arr[s.size()][t.size()];



    if(s[0] == t[0])return arr[s.size()][t.size()]= 1 + MEMO_solution(s.substr(1), t.substr(1),arr);

    int lcs1 = MEMO_solution(s.substr(1), t , arr);
    int lcs2 = MEMO_solution(s, t.substr(1) , arr);


    return arr[s.size()][t.size()] = max(lcs1, lcs2);
}



int MEMO_LCS(string s, string t)        // Both Time& Space complexities are : O(M*N)
{
    int** arr= new int*[s.size()+1];
    for (int i = 0; i < s.size()+1; i++)
    {
        arr[i]= new int[t.size()+1];
    }

    for (int i = 0; i < s.size()+1; i++)
    {
        for (int j = 0; j < t.size() +1; j++)
        {
            arr[i][j]= -1;
        }
    }

    return MEMO_solution(s, t, arr);
}


int DP_LCS(string s, string t)
{
    int** arr= new int*[s.size()+1];
    for (int i = 0; i < s.size()+1; i++)
    {
        arr[i]= new int[t.size()+1];
    }
    // Filling the first Row and column with 0's    // See the base case of recursive solution!!!!
                                                    // Its the same as that!!
    for (int i = 0; i < s.size(); i++)
    {
        arr[i][0]=0;
    }
    for (int i = 1; i < t.size(); i++)
    {
        arr[0][i]=0;
    }   
    // -------------------------------------------

    for (int i = 1; i < s.size()+1; i++)
    {
        for (int j = 1; j < t.size()+1; j++)
        {
            if(s[s.size()- i] == t[t.size()- j])
            {
                arr[i][j]= 1 + arr[i-1][j-1];
            }

            else
            {
                arr[i][j]= max(arr[i-1][j], max(arr[i-1][j-1], arr[i][j-1]));
            }
        }
    }

    return arr[s.size()][t.size()];
}

int main(){

    string s,t;
    cin>>s>>t;

    // cout<< LCS(s,t) <<endl;
    cout<< MEMO_LCS(s,t) <<endl;
    cout<< DP_LCS(s,t) <<endl;
    

    return 0;
}

