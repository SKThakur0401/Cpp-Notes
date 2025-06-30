#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;



// int countSubsequences(vector < int >  a, int n, int p, int cp=-1) {
//     // Write your code here.
//     int w1=0; int w2=0;
//     if(a.size()==0 && cp<= p && cp!= -1) return 1;
//     if(a.size()==0 && cp<= p && cp== -1) return 0;
//     if(cp > p) return 0;
//     if(a.empty()) return 0;
//     int temp= a[a.size()-1];
//     a.pop_back();
//     w1= countSubsequences(a, n, p, cp);
//     if(cp== -1) cp= temp;
//     else cp*=temp;
//     w2= countSubsequences(a, n, p, cp);
//     return w1+w2;
// }







int countSubsequences(vector < int >  a, int n, int p, int cp=-1) {
    // Write your code here.
    int w1=0; int w2=0;
    if(a.size()==0 && cp<= p && cp!= -1) return 1;
    if(a.size()==0 && cp<= p && cp== -1) return 0;
    if(cp > p) return 0;
    if(a.empty()) return 0;
    int temp= a[a.size()-1];
    a.pop_back();
    w1= countSubsequences(a, n, p, cp);
    if(cp== -1) cp= temp;
    else cp*=temp;
    w2= countSubsequences(a, n, p, cp);
    return w1+w2;
}

int countSubsequencer(vector< int > a, int n, int p)
{
    
}


int main(){

    int n; cin>>n;
    int p; cin>>p;
    vector<int> vi(n);
    for (int i = 0; i < n; i++)
    {
        cin>>vi[i];
    }
    cout<< countSubsequences(vi, n, p) <<endl;

    return 0;
}
