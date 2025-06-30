#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<int> pq;
    
    pq.push(10); 
    pq.push(15);
    pq.push(191);
    pq.push(21);
    pq.push(52); 
    pq.push(29);
    pq.push(32);
    cout<<pq.top()<<endl;

    while(!pq.empty())
    {
        cout<< pq.top() <<" SIZE IS : "<<pq.size()<<endl;
        pq.pop();
    }

    return 0;
}

