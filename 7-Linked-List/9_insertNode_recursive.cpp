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
}

node* insert(int index, int element, node* head)
{
    if(index == 0)
    {
        node* newNode = new node(element);
        newNode->next = head;

        head = newNode;
        return head;
    }

    else
    {
        node* temp=head;
        int i=0;
        while(i < index-1       &&      temp != NULL)
        {
            temp= temp->next;
        }
        node* newNode = new node(element);
        newNode->next = temp->next;
        temp->next= newNode;
        return head;
    }
    
}


node* recursive_insert(int index,int element,node* head, node*tail)     // same insert func...working recursively

    if(index ==0)
    {
        node* newNode = new node(element);
        newNode->next= head;
        head = newNode;
        return head;
    }
    if(index ==1)
    {
        node* newNode= new node(element);
        newNode->next = tail->next;
        tail->next = newNode;
        return head;
    }
    else
    {
        if(tail != NULL)        // TO HANDLE "SEGMENTATION FAULT ERROR"
        {recursive_insert(index-1,element,head,tail->next);}
    }
} 

int main(){

    node* head= takeInput();
    head = recursive_insert(0,69, head,head);
    head = recursive_insert(3,169, head,head);
    head = recursive_insert(43,269, head,head);     //THIS LINE WILL NOT GIVE SEGMENTATION ERROR COZ WE 
                                                    // HANDLED IT :)... n so it will be ignored
    print(head);
    
    return 0;
}