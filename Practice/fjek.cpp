#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
    int n= nums.size();
    vector<int> nge(n);
    
    stack<int> st;
    st.push(n-1);
    nge[n-1]= 20000;
    
    for(int i=n-2; i>=0; i--)
    {
        while(!st.empty() || nums[st.top()] < nums[i]) st.pop();
        
        nge[i]= (st.empty())? 20000 : st.top();
        
        st.push(i);
    }
    
//         for(int i=0; i<n; i++)
//         {
//             cout<<nge[i]<<" ";
//         }
    
//         while(!st.empty()) st.pop();
    
//         vector<int> pge(n);
//         st.push(0);
//         pge[0]= INT_MIN;
    
//         for(int i=1; i<n; i++)
//         {
//             while(!st.empty() || nums[st.top()] <= nums[i]) st.pop();
        
//             nge[i]= (st.empty())? INT_MIN : st.top();
        
//             st.push(i);
//         }
    // vector<int> ans;
    // for(int i=0; i<= n-k; i++)
    // {
    //     int fk=i;
    //     while(nge[fk] < i+k)
    //     {
    //         fk= nge[fk];
    //     }
    //     ans.push_back(nums[fk]);
    // }
    return nge;
    // vector<int> vi; return vi;
}


int main(){
    int n; cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin>>nums[i];
    }
    int k; cin>>k;

    vector<int> ans = maxSlidingWindow(nums,k);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    

    return 0;
}

