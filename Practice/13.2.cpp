#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class priorityQueue
{
    public:
    vector<int> vi;

    void push(int k)
    {
        vi.push_back(k);
        int ci= vi.size()-1;

        while(ci>0)
        {
            int pi= (ci-1)/2;
            if(vi[pi] < vi[ci])
            {
                swap(vi[pi], vi[ci]);
                ci= pi;
            }

            else break;
        }
    }

    int size() {return vi.size();}
    bool empty(){return vi.size()==0;}
    int top() {return vi[0]; }
    int pop()
    {
        if(vi.size()==0) return 0;
        int ans= vi[0];

        vi[0]= vi[vi.size()-1];
        vi.pop_back();
        int n= vi.size();
        int pi=0;

        while(1)
        {
            int maxDex;
            int lci= 2*pi+1;
            int rci= 2*pi+2;

            if(lci < n && rci < n)
            {
                if(vi[lci] >= vi[rci] && vi[lci] > vi[pi]) maxDex= lci;
                else if(vi[rci] > vi[lci] && vi[rci] > vi[pi]) maxDex= rci;
                else maxDex=pi;
            }

            else if(lci < n)
            {
                if(vi[lci] > vi[pi]) maxDex= lci;
                else maxDex=pi;
            }

            if(maxDex== pi) break;

            swap(vi[maxDex], vi[pi]);
            pi= maxDex;
        }
        return ans;
    }
};


bool isMaxHeap(int arr[], int n, int pi=0)
{
    int lci=2*pi+1;
    int rci=2*pi+2;

    if(lci <n && rci < n)
    {
        if(arr[pi] < arr[lci] || arr[pi] < arr[rci]) return false;

        bool lans= isMaxHeap(arr, n, lci);
        bool rans= isMaxHeap(arr, n, rci);
        return lans && rans;
    }

    else if(lci < n)
    {
        if(arr[pi] < arr[lci]) return false;
        bool lans= isMaxHeap(arr, n, lci);
        return lans;
    }

    return true;
}

void heapify(int arr[], int n, int pi)
{
    int maxDex= pi;
    int lci = 2*pi+1;
    int rci = 2*pi+2;

    if(lci< n && arr[lci] > arr[pi])
    {
        maxDex= lci;
    }

    if(rci< n && arr[rci] > arr[maxDex])
    {
        maxDex= rci;
    }
    
    if(maxDex != pi)
    {
        swap(arr[maxDex], arr[pi]);

        // heapify(arr, n, maxDex);
    }
}


int main(){

    int arr[]={9,32,246,3,99,636,125,2,5,25,24,2452};
    int n= sizeof(arr)/sizeof(arr[0]);
    int last_non_LeafNode= (n/2) -1;            // All leaf nodes are already heaps! (bcoz they don't have any children...they don't have any criteria to fulfill.... so we need to start checking from the first NON-LEAF node!)


    for (int i = last_non_LeafNode; i >=0; i--)
    {
        heapify(arr,n,i);
    }

    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] <<" ";
    }
    cout <<endl;
    
    cout<< isMaxHeap(arr,n) <<endl;

    return 0;
}


