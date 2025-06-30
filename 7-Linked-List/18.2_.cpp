// SAME AS THE PREVIOUS CODE... JUST THE RETURN TYPE IS CHANGED TO VOID... AND AFTER DOING THAT WE HAVE TO "CALL BY REFERENCE" TO STORE THE RETURN VALUE IN SOMETHING,,, SO I DECIDED TO MAKE "h1" as a reference pointer.... and at the last line where we previously returned "head" ... now we will do "h1 = head" ...since "h1" is a reference popinter, changes will be reflected in the "h1" of the main function.
 
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

void append(node* tail,int element)
{
    node* newNode = new node(element);
    tail->next = newNode;
}


void merge(node*& h1, node* h2)
{
    node* newNode= new node(-69);
    node* head= newNode;
    node* tail= newNode;
    while(h1 != NULL  &&  h2 != NULL)
    {
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


int main(){

    node* h1 = takeInput();
    node* h2 = takeInput();

    merge(h1,h2);       //since, "h1" is the reference variable...after this line the 
                        // value of "head" of the merge linked-list ... will be stored in "h1" bcoz we wrote "h1=head"
    print(h1);

    return 0;
}