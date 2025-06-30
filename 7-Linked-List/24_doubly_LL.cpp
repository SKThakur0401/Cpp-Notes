// HERE, WE HAVE MADE A CLASS "nodeD" . Representing doubly linked list

// HERE, WE HAVE WRITTEN VARIOUS CODES LIKE "takeInput" , "insert" , "print" , "del" etc..... FOR A DOUBLY LINKED-LIST ....THESE ARE MINOR VARIATIONS FROM THEIR "SINGLY" COUNTERPARTS...

// try to do it urself... useful for revising singly LL also..

#include<iostream>
using namespace std;

class nodeD
{
    public:
    nodeD* prev;
    int data;
    nodeD* next;
    nodeD(int data): data(data){};
};

nodeD* takeInput()
{
    int data;
    cin>>data;
    nodeD* head=NULL;
    nodeD* tail=NULL;
    while(data != -1)
    {
        nodeD* newNode = new nodeD(data);
        if(head==NULL)
        {
            head= newNode;
            tail= newNode;
        }
        else
        {
            tail->next= newNode;
            newNode->prev=tail;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}

void print(nodeD* head)
{
    nodeD* temp = head;
    while(temp != NULL)
    {
        cout<< temp->data <<" ";
        temp=temp->next;
    }
    cout <<endl;
}

void printrev(nodeD* head)      //PRINTS THE "LL" IN REVERSE ORDER(FROM TAIL TO HEAD)...SINCE IT CARRIES AN EXTRA NODE ("prev") ... its as easy to travel backwards as it is forwards :)
{
    nodeD* tail= head;
    while(tail->next != NULL){tail=tail->next;}
    while(tail != NULL)
    {
        cout<< tail->data <<" ";
        tail=tail->prev;
    }
    cout <<endl;
}


nodeD* insert(int index, int element, nodeD *head)
{
    if(index == 0)
    {
        nodeD* newNode= new nodeD(element);
        newNode->next= head;
        head->prev=newNode;
        head= head->prev;
        return head;
    }
    else
    {
        nodeD* temp = head;
        int i=0;
        while(i<index-1     &&      temp != NULL)
        {
            temp=temp->next;
            i++;
        }
        if(temp != NULL)
        {
            nodeD* newNode= new nodeD(element);
            newNode->next= temp->next;
            newNode->prev= temp;
            temp->next->prev = newNode;
            temp->next= newNode;
            return head;
        }
    }
}

nodeD* del(int index,nodeD*head)
{
    if(index==0)
    {
        nodeD* a= head;
        head= head->next;
        head->prev= NULL;
        delete [] a;
        return head;
    }
    else
    {
        nodeD* temp= head;
        int i=0;
        while(i<index-1   &&  temp != NULL)
        {
            temp=temp->next;
            i++;
        }
        nodeD* a = temp->next;
        temp->next->next->prev = temp;
        temp->next = a->next;
        delete [] a;
        return head;
    }
}

int main(){

    nodeD* head= takeInput();

    print(head);
    printrev(head);
    head=insert(0,69,head);
    head=insert(3,69,head);

    print(head);

    head= del(3,head);
    head= del(3,head);
    head= del(0,head);

    print(head);
    return 0;
}