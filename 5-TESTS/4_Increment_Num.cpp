// GOOD QUESTION FOR TESTING KNOWLEDGE AS WELL AS APPLICATION SKILLS...

// Chapter TEST
// Problem Statement: Next Number
// Problem Level: MEDIUM
// Problem Description:
// Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).
// Note: You don't need to print the elements, just update the elements and return the head of updated LL.
// Input Constraints:
// 1 <= Length of Linked List <=10^6.

// Input format :
// Line 1 : Linked list elements (separated by space and terminated by -1)

// Output Format :
// Line 1: Updated linked list elements

// Sample Input 1 :
// 3 9 2 5 -1

// Sample Output 1 :
// 3 9 2 6

// Sample Input 2 :
// 9 9 9 -1

// Sample Output 1 :
// 1 0 0 0




#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int data):data(data) {}
};

node* takeInput()
{
    cout<< "Enter data : ";
    int data;
    cin>>data;
    node* head=NULL;
    node* tail=NULL;
    while(data != -1)
    {
        node* newNode= new node(data);
        if(head== NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}

void print(node* head)
{
    while (head != NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

node* reverse(node* head)
{
    if(head==NULL || head->next==NULL){return head;}

    node* sA = reverse(head->next);
    node* tail= head->next;
    tail->next=head;
    head->next=NULL;
    return sA;
}

node* increment(node* head)
{
    head=reverse(head);
    head->data= (head->data + 1)%10;
    node* temp= head;
    while(temp->data == 0   && temp!=NULL)
    {
        temp=temp->next;

        if(temp->next==NULL && temp->data ==9)      // To handle the case where an extra node is needed to be added e.g.   "999" increases to "1000" ...so extra node needed
        {
            node* newNode= new node(0);
            temp->next=newNode;
        }
        
        temp->data= (temp->data+1)%10;
    }
    head=reverse(head);
    return head;
}

int main()
{
    node* head= takeInput();

    head=increment(head);
    print(head);
}