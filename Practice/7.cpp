// Sample Input:
// 1123 

// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void suck(string n, string output= "")
{
    if(n.empty()) {cout<< output <<" ";}
    else{
    string st = output;
    st += char(n[0]- '1' + 'a');
    suck(n.substr(1), st);

        if(n.size() >= 2 && stoi(n.substr(0,2)) <= 26)
        {
            st = output;
            // st+= char((n[0]+ n[1])- '1' + 'a');
            st+= char(stoi(n.substr(0,2)) -1 + 'a');
            suck(n.substr(2), st);
        }
    return;
    }
}

int main(){

    string n; cin>>n;

    // string* output = new string[20];

    // int n = solve(n, output);

    // for (int i = 0; i < n; i++)
    // {
    //     cout<< output[i] <<" ";
    // }
    // cout <<endl;
    string output = "";
    suck(n, output);

    return 0;
}

