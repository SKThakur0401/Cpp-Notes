// QUESTION: A number is represented as a linked list, with its each node having its each digit, we will take 2 linked lists as input...(i.e. two nos.) and return a third linked list representing the sum of those two nos. in the same way...
// e.g.  :  LL1 : 3->4->5
//          LL2 : 4->5

// Answer(resultant) LL   : 3->9->0    

#include<iostream>
using namespace std;


class node
{
    public:
    int data;
    node* next;
    public:
    node(int da){this->data= da;}
};

node* takeInput()
{
    int data;
    cin>>data;
    node* head= NULL;
    node* tail= NULL;
    while(data != -1)
    {
        node *newNode = new node(data);
        if(head == NULL){head = newNode; tail= newNode;}
        else
        {
            tail->next=newNode;
            tail= newNode;
        }
        cin>>data;
    }
    return head;
}

void print(node * head)
{
    node* temp= head;
    while(temp != NULL)
    {
    cout<< temp->data <<" ";
    temp=temp->next;
    }
}



node* reverse(node* head)
{
    if(head== NULL || head->next == NULL)
    {return head;}

    node* smallAns= reverse(head->next);

    node* tail= head->next;
    tail->next= head;
    head->next=NULL;

    return smallAns;
}



node* sigma(node* h1, node* h2)
{
    node* t1= h1;
    node* t2= h2;
    t1= reverse(t1);
    t2= reverse(t2);
    node* ans=NULL;
    node* tai=NULL;
    int carry =0;
    while(t1 != NULL && t2 !=NULL)
    {
        int n= t1->data + t2->data + carry;
        carry= n/10;

        if(ans==NULL)
        {
            node* newNode= new node(n%10);
            ans=newNode;
            tai=newNode;
        }
        else
        {
            
            tai->next= new node(n%10);
            tai=tai->next;
        }

        t1=t1->next; t2=t2->next;
    }

    while(t1 != NULL)
    {
        int n= t1->data + carry;
        carry= n/10;
        tai->next= new node(n%10);
        tai=tai->next;
        t1=t1->next;
    }

    while(t2 != NULL)
    {
        int n= t2->data + carry;
        carry= n/10;
        tai->next= new node(n%10);
        tai=tai->next;
        t2=t2->next;
    }
    if(carry == 1)
    {
        tai->next= new node(1);
    }
    ans= reverse(ans);
    return ans;
}


int main()
{
    cout<< "Enter first linked list(U know how to give input) :" <<endl;
    node* h1= takeInput();

    cout<< "Enter second linked list(U know how to give input) :" <<endl;
    node* h2= takeInput();

    node* head= sigma(h1,h2);

    print(head);

    return 0;
}