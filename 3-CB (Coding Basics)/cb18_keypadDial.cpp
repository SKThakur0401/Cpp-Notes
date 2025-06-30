// Keypad dial question
// 2-"abc"  3-"def"  4-"ghi"  5-"jkl"  6-"mno"  7-"pqrs"  8-"tuv"  9-"wxyz"
// e.g.  23 will have the following permutations possible---> ad,ae,af , bd,be,bf , cd,ce,cf
 

#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

int dp(string s, string output[])   // Note: This solution does not cover all cases...This is not complete... it can only handle cases numbers till "6"..... see the last function "dial"
{
    string a= "abcdefghijklmno";
    if(s.size() == 1)
    {
        int p = s[0]- '0';
        output[0]=  a[(p-2)*3+0];
        output[1]=  a[(p-2)*3+1];
        output[2]=  a[(p-2)*3+2];
        return 3;
    }
    string smallS = s.substr(1);
    int size= dp(smallS , output);
    for (int i = 0; i < size*3; i++)
    {
        output[i] = output[i%(size)];
    }
    for (int i = 0; i < size*3; i++)
    {
        int p = s[0] - '0';
        int k= i/(size);
        output[i]= a[((p-2)*3) + k] + output[i];
    }
    return 3* (size);
}



// int dp_with_Better_Base_Case(string s, string output[])
// {
//     string a= "abcdefghijklmno";
//     if(s.empty())
//     {
//         output[0]="";
//         return 1;
//     }
//     string smallS = s.substr(1);
//     int size= dp(smallS , output);
//     for (int i = 0; i < size*3; i++)
//     {
//         output[i] = output[i%(size)];
//     }
//     for (int i = 0; i < size*3; i++)
//     {
//         int p = s[0] - '0';
//         int k= i/(size);
//         output[i]= char(((p-2)*3) + k + 97)  + output[i];
//     }
//     return 3* (size);
// }



int dial(int n, string output[])        // Advice: Instead of trying to understand this code... write your own code for the problem.... (after solving/revising the "subsequentString" problem)
// Important : See how we can use strings and integer properties... converting an int to a string then finding out its size.... or converting an int to string then picking out a sub-string and converting it back to integer :).... these things will be helpful!!!
{
    string sarr[]= {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    if(to_string(n).size() == 1)
    {
        for (int i = 0; i < sarr[n-2].size(); i++) // Could have made a better/smaller base case... 
                                                // the one with no elements....not a biggie, u can make urself... just see the base case above...improved base case... and implement that for this :)
        {
            output[i]=sarr[n-2][i];
        }
        return sarr[n-2].size();
    }

    int smallSizeOutput = dial( stoi(to_string(n).substr(1)) , output);

    for (int i = 0; i < smallSizeOutput; i++)
    {
        for (int j = 0; j < sarr[stoi(to_string(n).substr(0,1)) -2].size() ; j++)
        {
            output[i+ smallSizeOutput*j]= sarr[stoi(to_string(n).substr(0,1)) -2][j] + output[i].substr(output[i].size()- to_string(n).size()+1);
        }
    }
    return sarr[stoi(to_string(n).substr(0,1)) -2].size() * smallSizeOutput;
}



int main(){
    string s;
    cin>>s;

    // int s;
    // cin>>s;
    string output[180];
 int count = dp(s, output);  // This cannot handle numbers ranging from 7 to 9...#Incomplete soln


    // int count= dial(s,output);
    for (int i = 0; i < count; i++)
    {
        cout<<output[i]<<" ";
    }
    cout<<endl;







    int c;
    cin>>c;
    string arr[180];
    int cou= dial(c,arr);   //This can handle all cases!!

    for (int i = 0; i < cou; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}