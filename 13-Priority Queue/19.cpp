// { Driver Code Starts
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          int index[k];
          for(int i=0;i<k;i++) index[i]=1;
          priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
          
          int largest=INT_MIN;
          for(int i=0; i<k; i++)
          {
                pair<int,int> pi(KSortedArray[i][0],i);
                pq.push(pi);
                if(KSortedArray[i][0]> largest) largest=KSortedArray[i][0];
          }
          pair<int,int> ans(pq.top().first , largest);
          int minRange= largest- pq.top().first;
          
          while(1)
          {
              pair<int,int> pi= pq.top();
              pq.pop();
              
              pair<int,int> inp(KSortedArray[pi.second][index[pi.second]], pi.second);
              pq.push(inp);
              
              if(largest < KSortedArray[pi.second][index[pi.second]])
              {
                  largest = KSortedArray[pi.second][index[pi.second]];
              }
              
              int range= largest - pq.top().first;
              if(range< minRange)
              {
                minRange= range;
                //   ans(pq.top().first, largest);
                ans.first= pq.top().first;
                ans.second=largest;
              }
              
              index[pi.second]++;
              if(index[pi.second]==n) break;
          }
          return ans;
    }
    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends

// 3 5
// 1 3 5
// 7 8 9
// 2 4 6
// 2 3 8
// 5 7 11