#include<iostream>
#include<cmath>
#include "Node.cpp"
using namespace std;

node * takeInput()
{
    int data;
    cin>>data;
    node* head= NULL;
    node* tail= NULL;
    while( data != -1)
    {
        node* newNode = new node(data);
        if(head == NULL)
        {
            head = newNode;
            tail= head;
        }

        else
        {
            // LINE 29 TO 31 IN "3_takeInput" was consuming alot of operations....so we used "tail" to avoid that and write a better code...the tail after each iteration points to the next node...instead of running a while loop from start each time...
            tail->next = newNode; 
            tail= tail->next;
        }
        cin>>data;
    }
    return head;
}

void print(node *head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data <<endl;
        temp = temp->next;
    }
}

 
int main(){

    node * head = takeInput();
    print(head);
    

    return 0;
}