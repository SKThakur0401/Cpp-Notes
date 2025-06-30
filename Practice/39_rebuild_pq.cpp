#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class priorityQueue{
    public:
    vector<int> vi;
    public:

    bool isEmpty(){
        return vi.size() == 0;
    }

    int getSize(){
        return vi.size();
    }


    void insert(int x){
        vi.push_back(x);
        int ci = vi.size()-1;
        
        while(ci > 0){
            int pi = (ci-1)/2;

            if(vi[pi] > vi[ci]) {
                swap(vi[pi], vi[ci]);
                ci = pi;
            }
            else break;
        }
    }


    int pop(){
        int returnable = vi[0];
        vi[0] = vi[vi.size()-1];
        vi.pop_back();

        int pi =0;
        int n = vi.size();

        while(true){
            int lci = 2*pi + 1;
            int rci = 2*pi + 2;

            if(lci < n && rci < n){
                if(vi[lci] <= vi[rci] && vi[lci] < vi[pi]) {
                    swap(vi[lci], vi[pi]);
                    pi = lci;
                }

                else if(vi[rci] < vi[lci] && vi[rci] < vi[pi]){
                    swap(vi[rci], vi[pi]);
                    pi = rci;
                }
                
                else if(vi[lci] >= vi[pi] && vi[rci] >= vi[pi]){
                    break;
                }
            }

            else if(lci < n){
                if(vi[lci] < vi[pi]){
                    swap(vi[lci], vi[pi]);
                    pi = lci;
                }
            }
            else break;
        }
        return returnable;
    }

    int remove(){
        if(vi.empty()) return -1;
        int temp = vi[0];
        vi[0] = vi[vi.size()-1];
        vi.pop_back();
        int n= vi.size();
        int pi = 0;

        while(true){
            int mcx = pi;
            int lci = 2*pi+1;
            int rci = 2*pi+2;

            if(lci < n && vi[mcx] > vi[lci]) mcx = lci;
            if(rci < n && vi[mcx] > vi[rci]) mcx = rci;

            if(pi == mcx) break;
            swap(vi[pi], vi[mcx]);
            pi = mcx;
        }
        return temp;
    }
};

int main(){

    priorityQueue pq;
    pq.insert(1);
    pq.insert(19);
    pq.insert(2);
    pq.insert(6);
    pq.insert(25);
    
    cout<< "Start!" <<endl;
    while(!pq.isEmpty()){
        cout<< pq.remove() <<"  CurrSize- "<<pq.getSize()<<endl;
    }
    cout<<"DONE!";
    return 0;
}

