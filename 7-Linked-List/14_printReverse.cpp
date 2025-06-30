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

void revprint(node* head)
{
    node* temp = head;
    int l = len(head);
    int arr[l];
    for (int i = 0; i < l; i++)
    {
        arr[l-i-1] = temp->data;
        temp= temp->next;
    }
    for (int i = 0; i < l; i++)
    {
        cout<< arr[i] <<" ";
    }

    cout <<endl;
}

void revPrintPro(node* head)
{
    if(head->next == NULL){cout<<head->data;}
    else
    {
        revPrintPro(head->next);
        cout<<" "<<head->data;
    }
}

int main(){

    node* head = takeInput();
    revprint(head);

    revPrintPro(head);

    return 0;
}