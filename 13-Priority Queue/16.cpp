// { Driver Code Starts
//Initial Template for C++

#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
 

 // } Driver Code Ends
//User function Template for C++



class Solution
{
    public:
    //Function to merge k sorted arrays.
    stack<int> mergeKArrays(vector<vector<int> > arr, int K)
    {
        //code here
        stack<int> st;
        priority_queue <pair<int,int>, vector< pair<int,int> > , less<pair<int,int> > > pq;
        for(int i=0;i<K; i++)
        {
            pair<int,int> pi(arr[i][arr[i].size()-1]  ,i);
            pq.push(pi);
            arr[i].pop_back();
        }
        
        while(!pq.empty())
        {
            st.push((pq.top()).first);
            
            int reqdV= (pq.top()).second;
            pq.pop();
            
            if(!arr[reqdV].empty())
            {
                pair<int,int> pi( arr[reqdV][arr[reqdV].size() - 1 ] ,reqdV);
                pq.push(pi) ;
                arr[reqdV].pop_back();
            }
        }
        
        // vector<int> ans;
        // while(!st.empty())
        // {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        
        return st;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int> > arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	stack<int> output = obj.mergeKArrays(arr, k);
        // cout<< output.size() <<endl;
    	// printArray(output, k*k);

        cout<< output.size() <<endl;

        int n= output.size();

        for (int i = 0; i < n; i++)
        {
            cout<< output.top() <<endl;
            output.pop();
        }
        

        
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends