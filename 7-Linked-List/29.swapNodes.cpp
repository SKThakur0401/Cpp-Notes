// SWAPPING 2 NODES... AT INDEX "a" and "b" ....note: we r going to swap node itself..and not just the element inside the node

// SOLUTION:
// TO DO THIS, WE R GOING TO NEED 4 POINTER VARAIBLES.... "p1,c1, p2,c2" where c1 and c2 are (current-1 and current-2) nodes corresponding to indexes "a and b" ... and "p1  p2" their corresponding "previous"...

// HERE, WE NEED TO HANDLE 4 CASES... NOW SEE THE SOLN IF STILL COULDN'T SOLVE THIS


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

int main(){

    node* head = takeInput();
    head = swap(1,4, head);
    head = swap(0,2, head);
    print(head);

    return 0;
}