#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int editDistance(string s, string t)    // time complexity : O(2^n)
{
    // if(s.empty() && t.empty()) return 0;
    // if(s.empty())
    // {
    //     s.push_back(t[0]);
    //     return 1+ editDistance(s.substr(1), t.substr(1));
    // }
    // if(t.empty())
    // {
    //     t.push_back(s[0]);
    //     return 1+ editDistance(s.substr(1), t.substr(1));
    // }


    // Everything that's commented out above-^ , can be condensed into this "1" if statement below!!
    if(s.size()==0 || t.size()==0)
    {
        return max(s.size() , t.size());
    }


    if(s[0]== t[0]) return editDistance(s.substr(1), t.substr(1));

    else
    {

        int c1 = editDistance(s, t.substr(1));

        int c2= editDistance(s.substr(1), t);

        int c3 = editDistance(s.substr(1), t.substr(1));

        return 1 + min(c1, min(c3,c2));
    }
}


int MEMO_solution(string s, string t, int** arr)
{
    if(s.size()==0 || t.size()==0)
    {
        return arr[s.size()][t.size()] = max(s.size() , t.size());
    }
    if(arr[s.size()][t.size()] != -1) return arr[s.size()][t.size()];

    if(s[0]== t[0]) return MEMO_solution(s.substr(1), t.substr(1), arr);

    else
    {

        int c1 = MEMO_solution(s, t.substr(1),  arr);

        int c2= MEMO_solution(s.substr(1), t,  arr);

        int c3 = MEMO_solution(s.substr(1), t.substr(1),  arr);

        return arr[s.size()][t.size()] = 1 + min(c1, min(c3,c2));
    }
}

int MEMO_editDistance(string s, string t)   // Both time and space complexities are : O(m*n)
{
    int ss =s.size()+1;
    int ts =t.size()+1;
    int ** arr= new int*[ss];
    for (int i = 0; i < ss; i++)
    {
        arr[i]= new int[ts];
    }
    for (int i = 0; i < ss; i++)
    {
        for (int j = 0; j < ts; j++)
        {
            arr[i][j]= -1;
        }
    }

    return MEMO_solution(s, t, arr);
}



int DP_editDistance(string s, string t)
{
    int ss= s.size()+1;
    int st= t.size()+1;
    int ** arr= new int*[ss];
    for (int i = 0; i < ss; i++)
    {
        arr[i]= new int[st];
    }
    // Initialising the 0th row and column, (corresponding to the "if" on line-24 )
    for (int i = 0; i < ss; i++)
    {
        arr[i][0]= i;
    }

    for (int i = 1; i < st; i++)
    {
        arr[0][i]= i;
    }
    // ------------------------- ------------------------- -------------------------
    ss--; st--;
    // So, we have already filled answers for either of the "s" and "t" being "0 /empty" , now we have to start filling others, here the "(i,j)" index would represent the situation where "s" has "i" size and "t" has "j" size.... so we r initiating it with "i=1 & j=1", so with both "i" and "j" with "one element each" .... now that one element has to be the last element!!!!... since this is "bottom-up approach"... it has to perform in reverse order when compared to recursion... so for "accessing" the elements in order "from-last-to-first" , we did "s[ss-i] && t[st-j]" ... in order to access element in "from-last-to-first" order... if the last element of both strings are same...then answer is same as one block above and left, s.substr(1),t.substr(1) think... it's all logical...
    for (int i = 1; i <= ss; i++)
    {
        for (int j = 1; j <= st; j++)
        {
            if(s[ss- i]== t[st- j]) arr[i][j]= arr[i-1][j-1];

            else
            {
                int w1= arr[i-1][j];
                int w2= arr[i-1][j-1];
                int w3= arr[i][j-1];

                arr[i][j]= 1 + min(w1,min(w2,w3));
            }
        }
    }
    return arr[ss][st];
}

int main(){
    string s, t;
    cin>>s>>t;


    cout<< MEMO_editDistance(s,t) <<endl;
    cout<< DP_editDistance(s,t) <<endl;
    cout<< editDistance(s,t) <<endl;        //Funfact: Try giving a large input... u will see that the above 2 will return output but this will not... due to the horrible time complexity this has ;)

    return 0;
}

