// HERE WE R GOING TO ROTATE A "LL"   n no. of times....one rotation means ---> the last element moves the first and all elements are pushed one index ahead... we made "rotate" and "rotatePro" which takes "n" as argument...ie total no. of rotations

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

node* rotate(int n , node* head)
{

    for (int i = 0; i < n; i++)
    {
        node* tail = head;
        while(  (tail->next)->next !=NULL)
        {
            tail= tail->next;
        }
        (tail->next)->next = head;          //UNDERSTAND THIS CODE CYCLE...
        head= (tail->next);
        tail->next =NULL;
    }
    return head;
}


int len(node* head)             // CALCULATES TOTAL NO. OF ELEMENTS IN A LINKED-LIST(A BASIC PROGRAM)
{
    node* tail = head;
    int len=1;
    while (tail->next != NULL)
    {
        tail= tail->next;
        len++;
    }
    return len;
}

node* rotatePro(int n, node* head)          // A MORE OPTIMISED CODE FOR ROTATION :)
{
    node* tail = head;
    int len=1;
    while(tail->next != NULL)
    {
        tail = tail->next;
        len++;
    }
    
    int fk = len -n;
    node* temp=head;
    for (int i = 0; i < fk-1; i++)
    {
        temp=temp->next;
    }
    node* a= (temp->next);
    temp->next= NULL;
    tail->next= head;
    head= a;

    return head;
}


int main(){


    node* head = takeInput();
    cout<< "Enter Number of rotations : ";
    int n;      cin>>n;

    head = rotatePro(n,head);
    print(head);

    // cout<< len(head) <<endl;

    return 0;
}