// Find index of the element u ask for... in a linked-list .... if that element is not there...return -1

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


int find(int element, node* head)
{
    int i=0;
    while(head->data != element)
    {
        if(head->next == NULL){return -1;}
        head=head->next;    i++;
    }
    return i;
}

int main(){

    node*head= takeInput();
    cout<< find(69,head) <<endl;

    return 0;
}