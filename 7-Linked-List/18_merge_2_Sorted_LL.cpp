// GIVEN 2 SORTED "LL", MERGE THEM INTO A SINGLE "SORTED" LINKED-LIST

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

void append(node* tail,int element)
{
    node* newNode = new node(element);
    tail->next = newNode;
}


node* merge(node* h1, node* h2)
{
    node* newNode= new node(-69);       //INTERESTING :) ...TO AVOID THE TEDIOUS BASE CASE OF "head=NULL" and "tail=NULL"   , we initiated a random value "-69" ... and later we deleted it moved head to next element of "LL".... bcoz of this, we didn't have to handle base case in "append" function,, where "tail=NULL" ... n my code became shorter
    node* head= newNode;
    node* tail= newNode;
    while(h1 != NULL  &&  h2 != NULL)
    {
        // node* newNode = new node
        if(h1->data < h2->data)
        {
            append(tail, h1->data);
            h1=h1->next;
            tail=tail->next;
        }


        else if(h1->data > h2->data)
        {
            append(tail, h2->data);
            h2= h2->next;
            tail=tail->next;
        }
        else if(h1->data == h2->data)
        {
            append(tail, h1->data);
            h1=h1->next;
            tail=tail->next;
            append(tail, h2->data);
            h2= h2->next;
            tail=tail->next;
        }
    }
    while(h1 != NULL)
    {
        append(tail, h1->data);
        h1=h1->next;
        tail=tail->next;
    }

    while(h2 != NULL)
    {
        append(tail, h2->data);
        h2=h2->next;
        tail=tail->next;
    }
    node* a = head;
    head= head->next;
    a->next=NULL;       // IN CASE WE CREATED OUR DESTRUCTOR THAT CAN DELETE ENTIRE LINKED LIST AND NOT JUST ONE NODE :)
    delete [] a;
    return head;
}


int main(){

    node* h1 = takeInput();
    node* h2 = takeInput();

    node* head= merge(h1,h2);
    print(head);

    return 0;
}