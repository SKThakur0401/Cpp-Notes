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


node* reverseProMax(node* head)
{
    if(head== NULL || head->next == NULL)       // try swapping the 2 statements which are on either sides of "or" ... interesting u will get segmentation fault error...think why :)       .... answer is in "00_REVISION_2" FILE.
    {return head;}

    node* smallAns= reverseProMax(head->next);

    node* tail= head->next;
    tail->next= head;
    head->next=NULL;

    return smallAns;
}


int main(){

    node* head= takeInput();
    node* rh1= reverseProMax(head);
    print(rh1);
    print(head);

    return 0;
}



// Node* reverse(Node* head)
// {
//     if(head== NULL || head->next == NULL)
//     return head;
//     Node* smallAns= reverse(head->next);
//     Node* tail= head->next;
//     tail->next= head;
//     head->next=NULL;
//     return smallAns;
// }

