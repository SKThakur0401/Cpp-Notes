#include<iostream>
#include<vector>

using namespace std;

class comPQ{

    public:
    bool operator()(int a, int b){
        return a*a > b*b;
    }
};

int main(){

    priority_queue<int, vector<int>, comPQ > pq;

    pq.push(1); pq.push(-2);
    pq.push(3); pq.push(-4);
    pq.push(5); pq.push(-6);

    while(!pq.empty()){
        cout<< pq.top() <<endl;
        pq.pop();
    }
}

