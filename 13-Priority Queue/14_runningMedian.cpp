#include<iostream>
#include<queue>
#include<vector>
using namespace std;
 
void Median(int arr[],int n)
{
    priority_queue <int, vector<int>, greater<int> > pq2;
    priority_queue <int, vector<int>, less<int> > pq1;
    int i=0;
    while(i<n)
    {
        if(pq1.empty() || pq1.top()> arr[i])
        {
            pq1.push(arr[i]);
        }
        else
        {
            pq2.push(arr[i]);
        }
        int n=5;

        // if(pq1.size() - pq2.size() >1)       // This gives the last output incorrect by (-1)
        if(pq1.size() > pq2.size() + 1)         // same as line above but correct answer!!!

        {
            int a= pq1.top();
            pq2.push(a);
            pq1.pop();
        }
        // if(pq2.size() - pq1.size() >1)          // this line is giving Segmentation fault
        if(pq2.size() > pq1.size() + 1)      // this means the same as line above but no error!
        {
            int a= pq2.top();
            pq1.push(a);
            pq2.pop();
        }

        if(pq1.size() == pq2.size())
        {
            cout<< (pq1.top() + pq2.top())/2 <<endl;
        }
        if(pq1.size()> pq2.size())
        {
            cout<< pq1.top() <<endl;
        }
        if(pq1.size()< pq2.size())
        {
            cout<< pq2.top() <<endl;
        }
        i++;
    }
}

int main(){

    // int n; cin>>n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>arr[i];
    // }
    int n=6;
    int arr[]={6,2,1,3,7,5};

    Median(arr,n);

    return 0;
}
