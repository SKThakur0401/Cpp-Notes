// For min-heap

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

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



void heapify(int arr[], int n, int i)
{
    int minDex=i;
    int lci = 2*i+1;
    int rci = 2*i+2;

    if(lci <n && arr[lci] < arr[minDex]) minDex= lci;

    if(rci <n && arr[rci] < arr[minDex]) minDex= rci;

    if(minDex != i)
    {
        swap(arr[minDex], arr[i]);
        heapify(arr,n, minDex);
    }
}

int main(){

    int arr[]= {1,4,51,5,2,43,2,4,5,125};

    int n= sizeof(arr)/sizeof(arr[0]);
    int last_non_LeafNode= (n/2) -1;

    for (int i = last_non_LeafNode; i >=0; i--)
    {
        heapify(arr, n, i);
    }
    
    return 0;
}

