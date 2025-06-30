// CREATING OUR OWN CLASS "priorityQueue"

// Folder - "Practice"   "13.cpp" has a more refined code for this..

#include<iostream>
#include<vector>
using namespace std;

class priorityQueue
{
    vector<int> pq;

    public:
 
    int getSize() {return pq.size();}

    bool isEmpty() {return pq.size()==0;}

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex= pq.size()-1;
        while(childIndex>0)
        {
            int parentIndex= (childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex])
            {
                int temp= pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else
            {
                break;
            }
            childIndex=parentIndex;
        }
    }

    int getMin() {return pq[0];}

    int remove()
    {
        int temp= pq[0];
        pq[0]=pq[pq.size()-1];

        pq.pop_back();
        int pi=0;
        while(1)
        {
            int lci= 2*pi +1;
            int rci= 2*pi +2;
            int minDex;       // This is to store the index of "lci" or "rci" ... whichever is holding the minimum value... As u know... the minimum value amongst the values present at "lci" , "rci" or "pi" should be present at "0_th" index.. so that's why this variable " minDex "

            if(lci < pq.size() && rci < pq.size())    //to ensure "lci" & "rci" r not out of bounds
            {
                if(pq[lci]<=pq[rci] && pq[lci]<pq[pi]) minDex=lci;
                if(pq[lci]>pq[rci] && pq[rci]<pq[pi]) minDex=rci;
                if(pq[pi]<pq[lci] && pq[pi]<pq[rci]) return temp;
            }

            else if(lci < pq.size())
            {
                if(pq[lci]<pq[pi]) minDex=lci;
                else {return temp;}
            }

            else if(rci < pq.size())        // THIS IS NOT REQUIRED, COZ IF "rci is less than pq.
                                            // size", then lci will also obviously be lesser...so the first "if" statement will execute and not this, this is meaningless!
            {
                if(pq[rci]<pq[pi]) minDex=rci;
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

};                        //  HERE WE CREATED A "MIN-HEAP", WE ALSO CALL THIS "HEAP-SORT" (IT DELETES VALUES IN ASCENDING ORDER.. WHICH MEANS SMALLEST FIRST COZ ITS A "MIN-HEAP")


int main(){


    priorityQueue somu;

    // somu.insert(10);
    // somu.insert(20);
    // somu.insert(30);
    // somu.insert(40);
    // somu.insert(50);
    // somu.insert(60);
    // somu.insert(70);



    somu.insert(5);
    somu.insert(3);
    somu.insert(9);
    somu.insert(11);
    somu.insert(4);
    somu.insert(19);
    somu.insert(5);
    somu.insert(5);
    cout<< "Size of PRIORITY QUEUE : " <<somu.getSize() <<endl;
    cout<<somu.remove()<<endl;
    cout<<somu.remove()<<endl;
    cout<<somu.remove()<<endl;
    cout<<somu.remove()<<endl;
    cout<<somu.remove()<<endl;

    // cout<< somu.remove() <<endl;
    return 0;
}