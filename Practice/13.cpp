#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

// Min-Heap
class priorityQueue
{
    vector<int> vi;

    public:

    void push(int k)
    {
        vi.push_back(k);
        int ci= vi.size()-1;

        while(ci >0)
        {
            int pi= (ci-1)/2;
            if(vi[ci] < vi[pi])
            {
                swap(vi[ci], vi[pi]);
                ci=pi;
            }
            else break;
        }
    }

    int top()
    {
        if(vi.size()==0) return INT_MAX;
        return vi[0];
    }

    int size() {return vi.size();}
    bool isEmpty() { return vi.size()==0;}

    int pop()
    {
        if(vi.size()==0) return INT_MAX;
        int k= vi[0];
        vi[0]= vi[vi.size()-1];
        vi.pop_back();
        int pi= 0;

        while(1)
        {
            int minDex= pi;
            int lci= 2*pi+1;
            int rci= 2*pi+2;
            if(lci < vi.size() && rci < vi.size())
            {
                if(vi[lci]<= vi[rci] && vi[lci] < vi[pi]) minDex=lci;
                if(vi[lci]> vi[rci] && vi[rci] < vi[pi]) minDex=rci;
            }

            else if(lci < vi.size())
            {
                if(vi[lci] < vi[pi]) minDex=lci;
            }

            if(pi== minDex) break;
            swap(vi[pi], vi[minDex]);
            pi= minDex;
        }
        return k;
    }
};

int main(){


    priorityQueue pq;
    pq.push(5);
    pq.push(3);
    pq.push(1);
    pq.push(9);
    pq.push(11);
    pq.push(1);
    pq.push(4);
    pq.push(19);
    pq.push(5);
    pq.push(1);
    pq.push(5);

    // cout<< pq.top() <<endl;
    cout<< "Size is : "<< pq.size() <<endl;
    while(!pq.isEmpty())
    {
        cout<< pq.pop() <<endl;
    }

    return 0;
}

