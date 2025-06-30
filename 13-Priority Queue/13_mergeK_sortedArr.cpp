#include<iostream>
#include<queue>
#include<vector>
using namespace std;
 
vector<int> merge(queue<pair<int,int> > arr[], int k)
{
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater< pair<int,int> > > pq;

    vector<int> vi;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i].front());
        arr[i].pop();
    }

    while(!pq.empty())
    {
        pair<int,int> ans= pq.top();
        pq.pop();
        vi.push_back(ans.first);

        if( !arr[ans.second].empty())
        {
            pq.push(arr[ans.second].front());
            arr[ans.second].pop();
        }
    }
    return vi;
}

int main(){

    int k; cin>>k;

    queue<pair<int,int> > arr[k];

    for (int i = 0; i < k; i++)
    {
        int n; cin>>n;
        queue<pair<int,int> > a;

        for (int j = 0; j < n; j++)
        {
            int x; cin>>x;
            pair<int,int> pi(x,i);
            // pi.first= x;
            // pi.second=k;
            a.push(pi);
        }
        arr[i]=a;
    }

    vector<int> vi = merge(arr,k);
    
    for (int i = 0; i < vi.size(); i++)
    {
        cout<<vi[i]<<" ";
    }
    cout <<endl;
    return 0;
}