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

    node(int data): data(data) {}

    // ~node()
    // {
    //     if(this->next) delete this->next;
    // }
};

node* takeInput()
{
    node* head= NULL;
    node* tail= NULL;

    int data; cin>>data;

    while( data != -1)
    {
        node* newNode= new node(data);

        if(!head)
        {
            head= newNode;
            tail= newNode;
        }

        else
        {
            tail->next= newNode;
            tail= newNode;
        }

        cin>>data;
    }
    return head;
}

void printLL(node* head)
{
    while(head)
    {
        cout<< head->data <<endl;
        head=head->next;
    }
}

node* insert(int element, int index, node* head)
{
    if(index==0)
    {
        node* newNode= new node(element);
        newNode->next= head;
        head=newNode;
        return head;
    }

    else
    {
        int i=1; node* temp= head;
        while(i < index && temp)
        {
            i++;
            temp=temp->next;
        }

        if(temp)
        {
            node* newNode= new node(element);
            newNode->next= temp->next;
            temp->next= newNode;
        }
        return head;
    }
    return head;
}


node* revamp(int m, int n, node* head)
{
    node* temp= head;

    while( temp )
    {
        int i=1;
        while(i < m && temp)
        {
            temp= temp->next; i++;
        }

        if(!temp) return head;

        node* temp2= temp;
        i=0;
        while (i<n && temp2)
        {
            node* a= temp2;
            temp2= temp2->next; i++;
            delete [] a;
        }
        
        if(!temp2)
        {
            temp->next= NULL;
            return head;
        }

        else if(temp2)
        {
            temp->next= temp2->next;
            temp=temp->next;
        }
        
    }
    return head;
}

int main(){

    node* head= takeInput();

    head= revamp(3,2, head);

    printLL(head);
    

    return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 -1