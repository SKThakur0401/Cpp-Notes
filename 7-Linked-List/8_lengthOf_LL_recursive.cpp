// TO FIND LENGTH OF "LL" USING RECURSION..LENGTH = NUMBER OF ELEMENTS


#include<iostream>
#include "Node.cpp"
using namespace std;
 
node* takeInput()
{
    int data;
    cin>>data;
    node* head= NULL;
    node* tail= NULL;
    while(data != -1)
    {
        node *newNode = new node(data);
        if(head == NULL){head = newNode; tail= newNode;}
        else
        {
            tail->next=newNode;
            tail= newNode;
        }
        cin>>data;
    }
    return head;
}

int len(node * head)
{
    node* temp = head;
    if(temp ==NULL){return 0;}
    return 1 + len(temp->next) ;
}

int main(){

    node* head = takeInput();
    cout<< len(head) <<endl;

    return 0;
}