// Question:
// Next greater element on the right
// U are given an array of integer, for every integer, print the next greater integer on its right.

// e.g. int arr[]= {16, 17, 4, 3, 5, 2};
// here answer---> {17, -1, 5, 5,-1,-1};
// REASON:
// here, for arr[0], the immediate greater element(on right is 17, so we put "17");
// here, for arr[1], the immediate greater element is nothing so we put "-1";
// here, for arr[2], the immediate greater element(on right is 5, so we put "5");
// here, for arr[3], the immediate greater element(on right is 5, so we put "5");
// here, for arr[4], the immediate greater element is nothing so we put "-1";
// here, for arr[5], is the last element so there's no element on it's right that could be greater, so we put "-1";
 

// Try to remember the most optimum (O(n)) technique/solution.

// Technique
// TAKE A STACK AND START INSERTING ELEMENTS FROM BEHIND, WHEN U ENTER AN ELEMENT, REMOVE ALL ELEMENTS FROM TOP WHICH ARE LESSER THAN THE ELEMENT WHICH U R GOING TO INSERT, THEN STORE THE TOP ELEMENT IN AN EXTRA "VECTOR"... AND NOW, PUSH THE ELEMENT WHICH U WERE GONNA PUSH!
// IF THE STACK BECOMES EMPTY BCOZ THE ELEMENT U R GOING TO INSERT IS VERY BIG... THIS MEANS THE ELEMENT U R GOING TO INSERT IS THE BIGGEST TILL NOW! SO U RETURN "-1" BCOZ THERE'S NO NUMBER GREATER THAN THAT!, SEE THE CODE IF STILL COULDN'T UNDERSTAND.


#include<iostream>
#include<stack>
#include<vector>
using namespace std;




int main(){

        // int arr[]= {16, 17, 4, 3, 5, 2};
        int arr[]={1, 2, 3, 1, 4, 5, 2, 3, 6};
        int n= sizeof(arr)/sizeof(arr[0]);

        vector<int> vi;
	    stack<int> st;
	    st.push(arr[n-1]);
        vi.push_back(-1);
	    
	    for(int i=n-2;i>=0;i--)
	    {
	        while(!st.empty() && arr[i]> st.top()) st.pop();

	        if(st.empty())
	        {
	            st.push(arr[i]);
                vi.push_back(-1);
	            continue;
	        }
	        // cout<<st.top()<<" ";     // Since this will return the ans in reverse order, we better store the data in a vector and then print it in reverse order!
            vi.push_back(st.top());
	        st.push(arr[i]);
	    }

        // Now, "vi" contains the answer, lets print it in reverse,

        for (int i = vi.size()-1; i>=0; i--)
        {
            cout<< vi[i]<<" ";
        }
        

    return 0;
}

