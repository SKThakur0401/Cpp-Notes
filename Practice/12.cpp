#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;


class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this->data= data;
        next=NULL;
    }

    ~node()
    {
        delete next;
    }
};

void print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout <<endl;
}

node* takeInput()
{
    int data; cin>>data;
    node* head= NULL; node* tail=NULL;

    while(data != -1)
    {
        node* newNode= new node(data);

        if(head== NULL)
        {
            head= newNode;
            tail= newNode;
        }

        else
        {
            tail->next= newNode;
            tail=tail->next;
        }
        cin>>data;
    }

    return head;
}

node* insert(int ind, int data, node* head)
{
    if(ind==0)
    {
        node* newNode= new node(data);
        newNode->next= head;
        return newNode;
    }

    else
    {
        node* temp =head;
        for(int i=0; i< ind-1; i++)
        {
            temp=temp->next;
            if(temp== NULL) break;
        }

        if(!temp) return head;
        node* newNode= new node(data);
        newNode->next= temp->next;
        temp->next= newNode;
        return head;
    }
}

node* del(int ind, node* head)
{
    if(ind==0)
    {
        node* temp = head->next;
        head->next= NULL;
        delete head;

        return temp;
    }

    else
    {
        int i=0; node* temp= head;
        while(i < ind-1 && temp != NULL)
        {
            temp=temp->next;
            i++;
        }

        if(!temp) return head;
        node* fk = temp->next;
        temp->next = fk->next;
        fk->next= NULL;
        delete fk;

        return head;
    }
}

node* reverse(node* head)
{
    node* prev= NULL;
    node* curr= head;
    node* nex;

    while(curr)
    {
        nex= curr->next;
        curr->next= prev;

        prev= curr;
        curr= nex;
    }
    return prev;
}

node* merge(node*h1, node* h2)
{
    if(h1 == NULL) return h2;
    if(h2== NULL) return h1;
    node* result;
    if(h1->data <= h2->data)
    {
        result = h1;
        result->next = merge(h1->next, h2);
    }

    if(h1->data > h2->data)
    {
        result = h2;
        result->next = merge(h1, h2->next);
    }
    return result;
}

void msort(node*& head)
{
    if(head->next==NULL) return;

    node* slow= head;
    node* fast= head;
    while(fast->next && fast->next->next)
    {
        slow= slow->next;
        fast= fast->next->next;
    }
    node* h2 = slow->next;
    slow->next= NULL;
    msort(h2);
    msort(head);
    // msort(h2);

    head = merge(head, h2);
}


node* recrev(node* head)
{
    if(head==NULL || head->next==NULL) return head;

    node* tail= head->next;
    head->next= NULL;
    node* smallAns = recrev(tail);
    tail->next= head;

    return smallAns;
}

node* mn(int m, int n, node* head)
{
    node* temp= head;
    int mi= m;
    int ni= n;
    m--;
    while(m && temp)
    {
        temp=temp->next; m--;
    }
    if(!temp) return head;
    node* cont = temp;
    while(n && cont)
    {
        cont= cont->next;
        n--;
    }
    if(!cont)
    {
        temp->next= NULL;
        return head;
    }
    temp->next= cont->next;

    temp->next = mn(mi, ni, temp->next);

    return head;
}


int main(){

    // node* h = takeInput();

    // h = insert(2,69, h);
    // h = insert(2,68, h);
    // h = insert(2,67, h);
    // h = del(2, h);
    // // h = del(2, h);
    // h = del(2, h);

    // print(h);
    // h = reverse(h);

    // print(h);

    node* h = takeInput();
    // msort(h);
    int m,n; cin>>m>>n;
    h = mn(m,n,h);

    print(h);

    

    return 0;
}



