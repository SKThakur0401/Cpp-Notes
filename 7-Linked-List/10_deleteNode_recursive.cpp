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

node* delRec(int index,node* temp , node* head)
{
    if(index ==0)
    {
        node* a = head;
        head= head->next;
        delete [] a;
        return head;
    }

    else if(index == 1)
    {
        node* a= temp->next;
        temp->next = (temp->next)->next;
        delete [] a;
        return head;
    }

    else
    {
        delRec(index-1,temp->next,head);
    }
}

int main(){

    // node* head = takeInput();
    // head =delRec(0,head,head);
    // head =delRec(1,head,head);
    // head =delRec(2,head,head);
    // print(head);

    return 0;
}