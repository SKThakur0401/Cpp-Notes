
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void slidingWindow(int arr[], vector<int> nge, int n, int k)
{
    int i=0;
    while(i <= n-k)
    {
        int ans= arr[i];

        for (int j=i; j < i+k; j++)
        {
            if(nge[j]== -1)
            {
                ans=arr[j]; 
                break;
            }
            if(arr[j]== nge[i])
            {
                ans= nge[i];
                nge[i]=nge[j];
            }
        }

        cout<<ans<<" ";
        i++;
    }
}


int main(){

        int arr[]={8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
        int n= sizeof(arr)/sizeof(arr[0]);
        vector<int> vi;
	    stack<int> st;
	    st.push(arr[n-1]);
        vi.push_back(-1);
	    
	    for(int i=n-2;i>=0;i--)
	    {
	        while(!st.empty() && arr[i]> st.top()) st.pop();

	        // if(i==0) vi.push_back(-1);
	        if(st.empty()) 
	        {
	            st.push(arr[i]);
                vi.push_back(-1);
	            continue;
	        }
            vi.push_back(st.top());
	        st.push(arr[i]);
	    }
        vector<int> nge;
        for (int i = vi.size()-1; i>=0; i--)
        {
            cout<< vi[i]<<" ";
            nge.push_back(vi[i]);
        }
        cout <<endl;
        cout <<endl;
        int k=4;
        slidingWindow(arr, nge, n, k);

    return 0;
}

