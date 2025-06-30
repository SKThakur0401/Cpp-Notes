// { Driver Code Starts
//Initial template for C++

#include <iostream>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        //code here
        sort(a,a+n);
        sort(b,b+m);
        int i=0; int j=0;
        int count=0;
        while(i<n && j<m)
        {
            if(a[i]==b[j])
            {
                count++;
                i++;j++;
            }
            else if(a[i]>b[j])
            {
                count++;
                j++;
            }
            else if(a[i]<b[j])
            {
                count++;
                i++;
            }
        }
        while(i<n)
        {
            count++; i++;
        }
        while(j<m)
        {
            count++; j++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
