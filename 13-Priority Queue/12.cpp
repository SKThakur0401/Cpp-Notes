// HERE, WE R GOING TO CREATE A "PRIORITY_QUEUE" WITH MULTIPLE THINGS, i.e., priority-factor as well as some other data!!! (Data will come out in order of priority factor)

//      priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

// The line above will create a priority queue, which takes "pair" as input, and these pairs, are stored in a vector(in the back-end), we r gonna make it a "min-heap" so "greater"

// Now NOTE: COMPILER IS GOING TO INTERPRET THE FIRST ARGUMENT OF THE PAIR AS THE "PRIORITY-FACTOR"

// So, the elements will be poped out based on "first" of the various pairs, if "first" of a pair is smallest, it will be pop-ed out first!!

#include<iostream>
#include<queue>
#include<vector>
using namespace std;



int main()
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
 
    pair<int,int> pi(59,100);
    pair<int,int> qi(21,200);
    pair<int,int> ri(63,300);
    pair<int,int> si(56,400);
    pair<int,int> ti(73,500);

    pq.push(pi);
    pq.push(qi);
    pq.push(ri);
    pq.push(si);
    pq.push(ti);

    cout<< pq.top().second <<endl;

    pq.pop();
    cout<< pq.top().second <<endl;

    pq.pop();
    cout<< pq.top().second <<endl;

    pq.pop();
    cout<< pq.top().second <<endl;

    pq.pop();
    cout<< pq.top().second <<endl;

    return 0;
}

