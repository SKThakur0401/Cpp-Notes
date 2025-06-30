// STL PRIORITY QUEUE & AND HOW TO USE IT IS DISCUSSED HERE :), LEARN IT BY HEART

// "MIN - HEAP" : MINIMUM ELEMENT AT THE TOP (MINIMUM WILL BE POPPED OUT FIRST)
// "MAX - HEAP" : MAXIMUM ELEMENT AT THE TOP (MAXIMUM WILL BE POPPED OUT FIRST)

//  priority_queue<int, vector<int>, greater<int> > pq;


// ----------CONFUSING THING------------------
// ALWAYS REMEMBER: "greater" means "min- heap"     
// ALWAYS REMEMBER: "lesser" means  "max- heap"     (THE DEFAULT IN-BUILT 'PRIORITY-QUEUE')



// INFERENCE
// So the "priority_queue" in STL, can take 3 parameters,
// first : data-type of elements to be stored
// Second: In which data-structure u will hold those elements...(can be vector , dequeue ..etc)
// Third : Which type of "priority_queue" u want? the default is "max-heap" you can keep/continue using max heap if you put the third parameter as   "less<int>"  ... but if you want a "min-heap", make the third parameter "greater<int>"



// COMPARATORS IN PRIORITY QUEUE

// JUST LIKE IN THE CASE OF SORTING, WE CAN MAKE "COMPARATOR" FUNCTION HERE... so instead of giving the third parameter as " greater<int> " or " lesser<int> " .... we can simply give the third parameter as our comparator name.


#include<iostream>
#include<queue>
using namespace std;

// bool comPQ(pair<int,int> a, pair<int,int> b)
// {
//     return a.first < b.first;       //NOTE !!!!   THE COMPARATOR FOR PRIORITY QUEUE WORKS THE OPPOSITE OF "SORTING COMPARATOR" .. THIS WILL NOT CREATE A "MIN-HEAP"!! .... IT WILL MAKE A    " MAX - HEAP " WHERE TOP ELEMENT IS THE GREATEST
// }

class comPQ
{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second > b.second;
    }
};

int main()
{
    priority_queue<pair<int,int>, vector<pair<int, int> >, comPQ >pq;

    for (int i = 0; i < 5; i++)
    {
        int f,s; cin>>f>>s;
        pair<int,int> pi(f,s);

        pq.push(pi);
    }

    cout <<endl;
    cout <<endl;
    cout <<endl;

    while(!pq.empty())
    {
        cout<< pq.top().first <<"  "<<pq.top().second<<endl;
        pq.pop();
    }
}
