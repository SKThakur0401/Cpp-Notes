// "dupify" is a function which deletes all duplicate elements in a linked list(GIVEN: THE "LL" IS SORTED)

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

node* dupify(node* head)
{
    node* temp=head;
    while(temp->next != NULL)
    {
        if(temp->data == (temp->next)->data )
        {
            node* a= temp->next;
            temp->next = temp->next->next;
            delete [] a;
        }
        else{temp= temp->next;}
    }
    return head;
}


int main(){

    node* head = takeInput();
    head = dupify(head);
    print(head);

    return 0;
}