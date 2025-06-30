#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void checkDivisibility(int n)       // My code, not at all a good one!
{
    while((n & 1) == 0)
    {
        n = n>>1;
    }

    if(n==1) cout<< 1 <<endl;
    else cout<< 0 <<endl;
}

void checkDivisibilityPro(int n)
{
    if((n & (n-1)) == 0) cout<<1<<endl;
    if((n & (n-1)) != 0) cout<<0<<endl;
}

int main(){

    int n; cin>>n;

    checkDivisibility(n);
    checkDivisibilityPro(n);
    
    return 0;
}

