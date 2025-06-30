// A BASIC CODE THAT FINDS "INDEX" OF AN ELEMENT IN THE LINKED LIST

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

int finder(int element, node* head)
{
    int ind=0;
    node*temp= head;
    while(temp != NULL)
    {
        if(temp->data == element)
        {return ind;}
        temp=temp->next;
        ind++;
    }
    return -1;
}

int main(){

    node* head = takeInput();
    cout<< "Enter Num whose index you want :";
    int data;
    cin>>data;
    cout<<"Index of required element is : "<< finder(data,head)<<endl;

    return 0;
}