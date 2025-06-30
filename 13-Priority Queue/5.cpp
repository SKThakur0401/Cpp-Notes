#include<iostream>
#include<vector>
using namespace std;


class priorityQueue
{
    vector<int> pq;

    public:
 
    int getSize() {return pq.size();}
    bool isEmpty() {return pq.size()==0;}

    int getMin()
    { 
        if(pq.size()==0)
        {
            cout<< "Queue Empty!!" <<endl;
            return 0;
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int ci= pq.size()-1;
        while(ci>0)
        {
            int pi= (ci-1)/2;
            if(pq[ci]<pq[pi])
            {
                int temp= pq[ci];
                pq[ci]=pq[pi];
                pq[pi]=temp;
            }
            else {break;}
            ci=pi;
        }
    }

    int remove()
    {
        int temp=pq[0];
        pq[0]=pq[pq.size()-1];

        pq.pop_back();
        int pi=0;
        while(1)
        {
            int lci= 2*pi +1;
            int rci= 2*pi +2;
            int minDex;

            if(lci >=pq.size()) return temp;

            else if(lci < pq.size() && rci < pq.size())
            {
                if(pq[lci]<pq[rci] && pq[lci]<pq[pi]) minDex=lci;
                if(pq[lci]>pq[rci] && pq[rci]<pq[pi]) minDex=rci;
                if(pq[pi]<pq[lci] && pq[pi]<pq[rci]) return temp;
            }

            else if(lci < pq.size())
            {
                if(pq[lci]<pq[pi]) minDex=lci;
                else {return temp;}
            }

            else {break;}
            int temp= pq[pi];
            pq[pi]=pq[minDex];
            pq[minDex]=temp;
            pi=minDex;
        }
        return temp;
        }
    }
};              //  HERE WE CREATED A "MIN-HEAP", WE ALSO CALL THIS "HEAP-SORT" (IT DELETES VALUES IN ASCENDING ORDER.. WHICH MEANS SMALLEST FIRST COZ ITS A "MIN-HEAP")



int main(){


    

    return 0;
}