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

int len(node* head)
{
    if(head == NULL){return 0;}
    return 1 +len(head->next);
}

node* swap(int a, int b , node* head)
{
    if((a==0 || b==0)         &&      abs(a-b) == 1)
    {
        node* c2 = head->next;
        head->next= c2->next;
        c2->next=head;
        head=c2;
        return head;
    }
    
    else if(abs(a-b) == 1)
    {
        int a1 = min(a,b);
        node* temp = head;
        for (int i = 0; i < a1 -1; i++)
        {
            temp=temp->next;
        }
        node* p1 = temp;
        node* c1 = temp->next;
        node* c2 = temp->next->next;
        c1->next = c2->next;
        p1->next=c2;
        c2->next= c1;
        return head;
    }

    else if(a==0 || b==0)
    {
        node* temp= head;
        int b1 = max(a,b);
        for (int i = 0; i < b1 -1; i++)
        {
            temp=temp->next;
        }
        node* p2 = temp;
        node* c2 = temp->next;
        node* c1 = head;
        node* n1 = head->next;

        p2->next= c1;
        c1->next= c2->next;
        c2->next=n1;
        head= c2;
        return head;
    }

    else
    {
        node* temp =head;
        int a1 = min(a,b);
        int b1 = max(a,b);
        int i=0;
        while(i< a1-1)
        {
            temp=temp->next; i++;
        }
        node* p1 = temp;
        node* c1 = temp->next;

        while(i< b1-1)
        {
            temp=temp->next; i++;
        }
        node* p2 = temp;
        node* c2 = temp->next;
        
        node* alpha = c2->next;

        p1->next= c2;
        c2->next= c1->next;
        p2->next = c1;
        c1->next= alpha;

        return head;
    }
}

node* bubbleSort(node* head)
{
    // node* temp=head;
    int l = len(head);

    for (int i = l-1; i >= 0; i--)
    {
        node* temp= head;
        for (int j = 0; j < i; j++)
        {
            if((temp->data) > (temp->next->data))
            {
                head= swap(j,j+1,head);
            }
            else
            {
                temp=temp->next;
            }
        }
    }
    return head;
}


node* Bsort(node* head)
{
    int l= len(head);
    for (int i = l-1; i < 0; i--)
    {
        node* temp= head;

        node* prevptr= NULL;
        node* nextptr= temp->next;
        for (int j = 0; j < i; j++)
        {

            if (temp->data > temp->next->data)
            {
                if (temp== head)
                {
                    temp->next= nextptr->next;
                    nextptr->next=temp;
                    prevptr= nextptr;
                    head=nextptr;
                    nextptr= temp->next;
                }
                else
                {
                    nextptr= temp->next;
                    temp->next=nextptr->next;
                    nextptr->next=temp;

                    prevptr->next=nextptr;
                    prevptr= prevptr->next;
                }
            }
            else
            {
                if(temp== head)
                {
                    prevptr= temp;
                    temp=temp->next;
                    nextptr=nextptr->next;
                }
                else
                {
                    nextptr=temp->next;
                    prevptr=prevptr->next;
                    temp=temp->next;
                    nextptr=nextptr->next;
                }
            }
        }
    }
    return head;
}

int main(){

    node* head= takeInput();
    head = Bsort(head);
    print(head);

    return 0;
}
