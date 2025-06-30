#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void answer(int n, int i)
{
    int x = (1<<(i)) -1;
    
    cout<< (n & x) << endl;
}


int main(){

    int n, i; cin>>n>>i;
    answer(n,i);

    return 0;
}

