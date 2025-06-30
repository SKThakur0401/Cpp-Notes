#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverse(queue<int> q)
{
    if(q.size()==1) return q;

    int x= q.front(); q.pop();
    
    q= reverse(q);

    q.push(x);
    return q;
}


int main(){

    queue<int> q;


    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // q= reverse(q);

    while(!q.empty())
    {
        cout<< q.front() <<endl; q.pop();
    }

    return 0;
}

