// Chapter Assignment
// Problem Statement: Return Permutations - String
// Problem Level: HARD
// Problem Description:
// Given a string S, find and return all the possible permutations of the input string.
// Note 1 : The order of permutations is not important.
// Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
// Input Format :
// String S

// Output Format : 
// All permutations (in different lines)

// Sample Input : 
// abc

// Sample Output :
// abc
// acb
// bac
// bca
// cab
// cba
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

// HERE, WE R GONNA DO IT IN 2 WAYS, 1st way is what I did when I was solving it for the first time, second way is what I thought of on 25-July-2022

#include<iostream>
#include<cmath>
using namespace std;


// METHOD-1
void func(string s,string current)      // This function also works fine!! it is the first way to solve this problem, we have done here "2-ways", the second way is "solve" function :)
{
    if(s.size()==2)
    {
        cout<< current + s <<" ";
        string revs="";
        for (int i = 0; i < s.size(); i++)
        {
            revs=s.substr(i,1) + revs ;
        }
        cout<< current+ revs <<" ";
        current="";
    }

    else if(s.size()>2)
    {
        for (int i = 0; i < s.size(); i++)
        {
            current= current + s.substr(i,1);
            string sl= s;
            sl.erase(i,1);
            func(sl,current);
            current.erase(current.size()-1,1);      //This line is to get current back to it's original value..... ie. to undo the changes, made in "line-23"
        }
    }
}


// METHOD-2


// THOUGHT PROCESS : When we solve for a single char say "a" , then only one permutation, "a" , but when we do for "ab" , then we make 2 "a" and put "b" on either sides of "a" to get the 2 permutations! , Now, for "abc" , we take permutations of "ab" , and put "c" on all possible places of all permutations of "ab", now "3" possible places to put "c" and 2 "permutations" of "ab" are there, so!, 6 outputs! , for "abcd", we do all possible permutations of "abc" which is 6, and put "d" in all possible places in those, which are "4 places", so 6*4 = 24 ways, and so on.. :)
int fac(int n){ return (n==0)? 1 : n* fac(n-1);}      // Just a casual function to return factorial

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

    cout<< "Enter a string : ";
    string s;
    cin>>s;
    string current="";
    func(s,current);

    cout <<endl;
    // The code below is for doing the same thing in second way,

    string * output = new string[fac(s.size())];

    int n = solve(s, output);

    for (int i = 0; i < n; i++)
    {
        cout<< output[i] <<" ";
    }
    cout <<endl;

    return 0;
}



// # A TEDIOUS AND COMPLEX WAY, HOWEVER, CONCEPTUAL :) NOTE: IT WORKS ONLY FOR "3" CHARACTERS WAALA CASE


// NOTE: char arr[]="saumya" ;      string st= arr;  ---> This is allowed!!! however, vice-versa is not true...ie. u can't store a string in a character array


// #include<iostream>

// using namespace std;

// void permu(char s[], char current)
// {
    // string q = s;
    // if(q.size() == 2)
    // {
    //     s[q.size()] = current;
    //     cout<< s<< " ";
    //     char temp = s[1];
    //     s[1]= s[0];
    //     s[0]= temp;
    //     cout<< s<<" " ;
    // }
    // else if(q.size() >2)
    // {
    //     for (int i = 0; i < q.size(); i++)
    //     {
    //         char current = s[i];
    //         string sl = s;
    //         sl.erase(i,1);
    //         char fk[sl.size()];
    //         for (int j = 0; j < sl.size() ; j++)
    //         {
    //             fk[j]= sl[j];
    //         }
            
    //         permu(fk, current);
//         }
//     }
    
// }

// int main(){
//     cout<< "Enter string : ";
//     char s[4];
//     cin>>s;
//     char current = 'a';
//     permu(s,current);

//     return 0;
// }

