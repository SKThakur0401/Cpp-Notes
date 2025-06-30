#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * next;

    node(int data)
    {
        this->data = data;
    }
};

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

node* retainDelete(int m, int n, node*head)
{
    node* temp= head;
    while(temp != NULL)
    {
        int i=0;
        while(i<m-1 && temp != NULL)
        {
            temp=temp->next;
            i++;
        }
        node* temp2 = temp;
        int j=0;
        while (j<n    && temp2 != NULL)
        {
            temp2=temp2->next;
            j++;
        }
        if(temp2 != NULL)
        {
            temp->next= temp2->next;    // 1 2 3 4 5 6 7 8 9 10
            temp=temp->next;
        }
        else
        { 
            return head;
        }
        
    }
    return head;
}

node* swap(int a, int b, node* head)
{
    if(abs(a-b)==1 && min(a,b)==0)
    {
        node* temp= head->next;
        head->next= temp->next;
        temp->next= head;
        head= temp;
        return head;
    }
    else if(min(a,b)==0)
    {
        int b1= max(a,b);
        node* temp=head; int i;
        while(i< b1   &&  temp!=NULL)
        {
            temp=temp->next;    i++;
        }
        node* n1= head->next;
        node* c2= temp->next;
        node* n2= temp->next->next;
        temp->next=head;
        head->next=n2;
        c2->next= n1;
        head= c2;
        return head;
    }

    else if (abs(a-b)==1)
    {
        int a1= min(a,b);
        int i=0;
        node* temp = head;
        while(i< a1-1 && temp!= NULL)
        {
            temp=temp->next;    i++;
        }
        if (temp!= NULL)
        {
            node* c1= temp->next;
            node* c2= temp->next->next;
            c1->next= c2->next;
            c2->next= c1;
            temp->next=c2;
            return head;
        }
        
    }

    else
    {
        int a1= min(a,b);
        int b1= max(a,b);
        node* temp= head;
        int i=0;
        while(i < a1-1    &&  temp!= NULL)
        {
            temp=temp->next; i++;
        }
        node* p1= temp;
        node* c1= temp->next;
        while(i<b1-1    &&  temp!=NULL)
        {
            temp=temp->next; i++;
        }
        if(temp != NULL)
        {
            node* p2= temp;
            node* c2= temp->next;
            

            node* alpha= c2->next;
            p1->next=c2;
            c2->next= c1->next;
            p2->next= c1;
            c1->next=alpha;
            return head;
        }
    }
}

node* reverse(node* head)
{
    if(head == NULL || head->next == NULL)  //here we get segmentation fault if we write the two statements in oppose order... "head==NULL" and "head->next==NULL" ...bcoz if we write in opposite order... even in the case where head is null... program will try to comprehend "head->next==NULL" first... where it will try to find "head->next" which will straight away give segmentation fault...so we should always write "head==NULL" first and then using "or" write "head->next==NULL" ... obviously..... in an "or" connected statements...if the first statement is "true"... the compiler doesn't even reads the second option and returns true....(bcoz it being true or false doesn't matter) .... here in our case.... since it did not try to comprehend "head->next" ....it protected us from segmentation fault :)
    {
        return head;
    }

    node* sA = reverse(head->next);

    node* tail = head->next;
    tail->next=head;
    head->next =NULL;
    return sA;
}


node* reversek(int k, node* head)
{
    int i=0;
    node* temp= head;
    while(i<k-1 && temp!= NULL)
    {
        temp=temp->next; i++;
    }
    if(temp == NULL){node* h = reverse(head); return h;}
    node* h2= temp->next;
    temp->next = NULL;
    node* tail= head;
    head = reverse(head);
    h2 = reversek(k,h2);
    tail->next= h2;

    return head;
}

int main(){
    
    node* head= takeInput();
    // cout<< "Enter k : " <<endl;
    // int k; cin>>k;
    head = reversek(3,head);
    // head= reverse(head);
    print(head);

    return 0;
}