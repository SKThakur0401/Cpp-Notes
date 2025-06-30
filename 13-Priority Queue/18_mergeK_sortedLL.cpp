// QUESTION:
// U HAVE BEEN GIVEN "K" SORTED LINKED LISTS, U NEED TO CREATE A NEW LINKED LIST AND STORE THE ELEMENTS OF THESE LL'S IN A SORTED FASHION IN ANOTHER LINKED LIST.

// SOLUTION:
// THINK OF THE CODE URSELF,
// JUST SEE THE CODE FROM LINE-54 TO 96, AND U R GOOD TO GO!!


// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;
 
// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           priority_queue<pair<int,int> , vector<pair<int, int> >, greater<pair<int,int> > > pq;
           
           Node* head=NULL;
           Node* tail=NULL;
           
           for(int i=0; i<K; i++)
           {
               pair<int,int> pi (arr[i]->data, i);
               pq.push(pi);
               arr[i]=arr[i]->next;
           }
           
           while(!pq.empty())
           {
               pair<int,int> x = pq.top();
               pq.pop();
               
               if(head==NULL)
               {
                   head= new Node(x.first);
                   tail=head;
               }
               else
               {
                   tail->next= new Node(x.first);
                   tail=tail->next;
               }
               
               if(arr[x.second]!=NULL)
               {
                   pair<int,int> pi(arr[x.second]->data, x.second);
                   pq.push(pi);
                   arr[x.second]=arr[x.second]->next;
               }
           }
           
           return head;
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends