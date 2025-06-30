#include<iostream>
#include<queue>
using namespace std;


int main(){

    priority_queue<int> pq;
    queue< pair<int,bool> > q;
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        pq.push(arr[i]);
        // pair<int,bool> pi(arr[i],0);
        // q.push(arr[i]);
    }
    int k; cin>>k;
    for (int i = 0; i < n; i++)
    {
        if(i==k)
        {
            pair<int,bool> pi(arr[i],true);
            q.push(pi);
            continue;
        }
        pair<int,bool> pi(arr[i],false);
        q.push(pi);
    }
    
    int time=0;
    // for (int i = 0; i < k; i++)
    // {
    //     if(arr[i]== pq.top())
    //     {
    //         pq.pop();
    //         time++;
    //     }
    // }
    while(1)
    {
        if(q.front().first== pq.top())
        {
            time++;
            if(q.front().second == true) break;
            pq.pop();
            q.pop();
        }
        else
        {
            pair<int,bool> a= q.front();
            q.pop();
            q.push(a);
        }
        
    }

    cout<<time<<endl;
    

    return 0;
}