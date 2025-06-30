#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


int main(){

    int n; cin>>n;
    int c= n & (-n);
    cout<< n-c <<endl;

    return 0;
}

