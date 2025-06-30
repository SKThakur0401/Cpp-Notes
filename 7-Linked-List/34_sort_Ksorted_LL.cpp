// A "k-sorted LINKED-LIST" is an LINKED-LIST whose elements are "atmost" 'k' units away from their rightful position.
// WE HAVE ALSO SOLVED THIS QUESTION FOR "K-SORTED ARRAYS" 


#include<iostream>
#include<queue>
using namespace std;


class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

node* takeInput()
{
    int data; cin>>data;
    node* head=NULL;
    node* tail=NULL;
    while(data != -1)
    {
        node* newNode= new node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=head;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}


void print(node * head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout <<endl;
}

void Ksort(node* &head,int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    node* temp=head;
    for (int i = 0; i < k+1; i++)
    {
        pq.push(temp->data);
        temp=temp->next;
    }

    node* t=head;
    while(temp !=NULL)
    {
        t->data= pq.top();
        pq.pop();
        pq.push(temp->data);
        temp=temp->next;
        t=t->next;
    }
    while(t!=NULL && !pq.empty())
    {
        t->data= pq.top();
        t=t->next;
        pq.pop();
    }
}

int main(){

    node* head= takeInput();
    Ksort(head,2);
    print(head);
    
    
    return 0;
}
