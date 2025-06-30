#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class comp
{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if(a.second== b.second) return a.first < b.first;
        return a.second > b.second;
    }
};

int main(){


    priority_queue<pair<int,int>, vector<pair<int,int> >, comp > pq;

    pair<int,int> a(1,5);
    pair<int,int> b(3,23);
    pair<int,int> c(532,11);
    pair<int,int> d(12,24);
    pair<int,int> e(19,24);
    pair<int,int> f(199,214);
    pair<int,int> g(123,2114);

    pq.push(a);
    pq.push(b);
    pq.push(c);
    pq.push(d);
    pq.push(e);
    pq.push(f); 
    pq.push(g);

    while(!pq.empty())
    {
        cout<< pq.top().first <<"    "<< pq.top().second<<endl;
        pq.pop();
    }
    
    return 0;
}

