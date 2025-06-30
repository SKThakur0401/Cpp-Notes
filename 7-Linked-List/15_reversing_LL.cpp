// "Reversing the linked list Iteratively"
// "THE RECURSIVE METHOD OF REVERSING A LINKED LIST" IS IN FILE: 20,21,22 ....IT'S RECOMMENDED TO CHECK THAT OUT JUST AFTER THIS


// ITERATIVE REVERSAL OF LL SOLUTION:
// We are going to use "3 node pointers" ... 'previous' 'current' and 'next'

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

node* reverse(node* head)       //THIS CODE WHEN USED...WILL REVERSE THE LINKED-LIST ITSELF
{
    node* previous =NULL;
    node* current =head;
    node* nex;
    while(current != NULL)
    {
        nex= current->next;
        current->next = previous;
        previous= current;
        current= nex;
    }
    head= previous;
    return head;
}

int main(){

    node* head= takeInput();
    print(head);

    head=reverse(head);
    print(head);

    return 0;
}