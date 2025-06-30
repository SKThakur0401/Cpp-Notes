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
    node* tail = head;
    int len=1;
    while (tail->next != NULL)
    {
        tail= tail->next;
        len++;
    }
    return len;
}

void append(node* tail,int element)
{
    node* newNode = new node(element);
    tail->next = newNode;
}

void merge(node* & h1, node* h2)    //This is not the optimised code for merging!
{
    node* newNode= new node(-69);       //INTERESTING :) ...TO AVOID THE TEDIOUS BASE CASE OF "head=NULL" and "tail=NULL"   , we initiated a random value "-69" ... and later we deleted it moved head to next element of "LL".... bcoz of this, we didn't have to handle base case in "append" function,, where "tail=NULL" ... n my code became shorter
    node* head= newNode;
    node* tail= newNode;
    while(h1 != NULL  &&  h2 != NULL)
    {
        // node* newNode = new node
        if(h1->data < h2->data)
        {
            append(tail, h1->data);
            h1=h1->next;
            tail=tail->next;
        }


        else if(h1->data > h2->data)
        {
            append(tail, h2->data);
            h2= h2->next;
            tail=tail->next;
        }
        else if(h1->data == h2->data)
        {
            append(tail, h1->data);
            h1=h1->next;
            tail=tail->next;
            append(tail, h2->data);
            h2= h2->next;
            tail=tail->next;
        }
    }
    while(h1 != NULL)
    {
        append(tail, h1->data);
        h1=h1->next;
        tail=tail->next;
    }

    while(h2 != NULL)
    {
        append(tail, h2->data);
        h2=h2->next;
        tail=tail->next;
    }
    node* a = head;
    head= head->next;
    delete [] a;
    h1 = head;
}




node* sortedMerge(node* a, node* b) //This is the optimised code for merging 2 linked lists
    {
    // base cases
    if (a == NULL) {
        return b;
    }
 
    else if (b == NULL) {
        return a;
    }
 
    node* result = NULL;
 
    // pick either `a` or `b`, and recur
    if (a->data <= b->data)
    {
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
 
    return result;
}

    

void Msort(node* & head)
{
    if(head->next == NULL){return;}     //"head->next" will be null..exactly when 
                                        // there's one element left in linked-list
    int l= len(head);
    node*temp=head;
    for (int i = 0; i < (l-1)/2; i++)
    {
        temp=temp->next;
    }
    node* h2 = temp->next;
    temp->next = NULL;
    Msort(head);
    Msort(h2);
    head= sortedMerge(head,h2);
}

int main(){

    node* head = takeInput();
    Msort(head);        //since we called "head" by reference... whatever changes 
                        // "Msort" function makes to the head...will be reflected on the real "head"

    print(head);

    return 0;
}