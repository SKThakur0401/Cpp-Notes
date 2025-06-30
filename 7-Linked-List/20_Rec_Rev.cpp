// rec_rev means "recursive reversing" of linked list

// REVERSING THE LINKED LIST USING RECURSION
// THIS CODE HAS TIME COMPLEXITY OF " O(n^2) "

// IT COULD HAVE BEEN "O(n)" if we could have avoided the use of "while loop"
// THE NEXT FILE (21) ....CONTAINS CODE FOR THE OPTIMISED SOLUTION FOR THIS

#include<iostream>
#include "Node.cpp"
using namespace std;
 


node* takeInput()
{
    int data; cin>>data;
    node* head = NULL;
    node* tail = NULL;
    while(data != -1)
    {
        node* newNode = new node(data);
        if(head== NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;;
            tail= newNode;
        }
        cin>>data;
    }
    return head;
}


void print (node* head)
{
    node* temp= head;
    while(temp != NULL)
    {
        cout<< temp->data <<"  ";
        temp= temp->next;
    }
    cout <<endl;
}

node* reverseLL(node* head)
{
    if(head== NULL || head->next == NULL)
    {return head;}

    node* smallAns= reverseLL(head->next);
    node* temp= smallAns;
    while(temp->next != NULL){temp=temp->next;}

    temp->next=head;
    head->next = NULL;
    return smallAns;
}

int main(){

    node* head = takeInput();
    head=reverseLL(head);
    print(head);

    return 0;
}
