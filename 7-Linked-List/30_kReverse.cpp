// IN A GIVEN LINKED-LIST REVERSE "FIRST 'k' elements together" .... then the next "k" elements together and so on

// Sample Input 1 :
// 1 2 3 4 5 6 7 8 9 10 -1
// 4

// Sample Output 1 :
// 4 3 2 1 8 7 6 5 10 9

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


node* reverse(node* head)
{
    if(head == NULL || head->next == NULL){return head;}

    node* sA = reverse(head->next);

    node* tail = head->next;
    tail->next=head;
    head->next =NULL;
    return sA;
}

node* kReverse(int k, node* head)
{
    node* temp = head;
    int i=0;
    while(i< k-1    &&  temp!= NULL)
    {
        temp=temp->next;
        i++;
    }
    if(temp == NULL){head = reverse(head); return head;}
    node* th = temp->next;          // th  means "temporary head"
    temp->next =NULL;
    node* tail = head;
    head = reverse(head);
    // node*tail =head;
    // while(tail->next != NULL){tail=tail->next;}

    th = kReverse(k, th);
    tail->next =th;

    return head;
}

int main(){

    node* head= takeInput();
    cout<< "Enter how many nodes to reverse at once : ";
    int k; cin>>k;
    head = kReverse(k, head);

    print(head);

    return 0;
}