// Making "takeInput" , "len" , "print" function for CIRCULAR-SINGLY LIKNKED_LIST

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
    tail->next = head;
    return head;
}

int len(node* head)
{
    node* tail = head->next;
    int len=1;
    while (tail != head)
    {
        tail= tail->next;
        len++;
    }
    return len;
}

void print (node* head)
{
    node* temp= head->next;
    while(temp != head)
    {
        cout<< temp->data <<" ";
        temp= temp->next;
    }
    cout<< temp->data <<" ";
    cout <<endl;
}


int main(){

    node* head= takeInput();
    cout<< len(head) <<endl;
    print(head);        // SINCE IT IS IN A CIRCLE...DOESN'T MATTER WHICH NODE WE CONSIDER AS HEAD...CAUSE ALL ARE SAME...

    return 0;
}