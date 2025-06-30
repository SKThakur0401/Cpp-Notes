#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void heapIt(vector<int>& vi, int pi){
    int mcx = pi; int n= vi.size();
    int lci = 2*pi+1;
    int rci = 2*pi+2;

    if(lci < n && vi[lci] > vi[mcx]) mcx = lci;
    if(rci < n && vi[rci] > vi[mcx]) mcx = rci;
    if(mcx != pi){
        swap(vi[mcx], vi[pi]);
        heapIt(vi, mcx);
    }
}

void heapify(vector<int> & vi){
    int n = vi.size();
    int nonLeafCount = (n-1)/2;

    for(int i = nonLeafCount; i >= 0 ; i--){
        heapIt(vi, i);
    }
}

bool isMaxHeap(vector<int> & vi, int n, int pi = 0){
    int lci = 2*pi+1;
    int rci = 2*pi+2;

    if(lci < n && vi[lci] > vi[pi]) return false;
    if(rci < n && vi[rci] > vi[pi]) return false;
    if(rci >= n) return true;
    return isMaxHeap(vi, n, lci) && isMaxHeap(vi, n, rci);
}

int main(){

    vector<int> vi;

    vi.push_back(10);
    vi.push_back(5);
    vi.push_back(3);
    // vi.push_back(1);
    // vi.push_back(9);

    // heapify(vi);

    // for(int i=0 ; i< vi.size(); i++){
    //     cout<< vi[i] <<endl;
    // }

    cout<< isMaxHeap(vi, vi.size()) <<endl;
    

    return 0;
}

