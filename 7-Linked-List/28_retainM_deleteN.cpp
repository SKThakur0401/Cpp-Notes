// IN A LINKED LIST, RETAIN FIRST "M" ELEMENTS, THEN DELETE THE NEXT "N" THEN AGAIN RETAIN NEXT "M" AND DELETE NEXT "N" GO ON DOING THIS TILL THE LL ENDS...
// SAMPE  INPUT : 1 2 3 4 5 6 7 8 9 10 11 12 13 -1
// SAMPE OUTPUT : 1  2  6  7  11  12  



#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * next;

    node(int data)
    {
        this->data = data;
    }
};


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

node* revamp(int m , int n, node*head)
{
    node* temp= head;
    while(temp != NULL)
    {
        int i=0;
        while(i< m-1  &&  temp!= NULL)
        {
            temp=temp->next;
            i++;
        }
        if(temp == NULL){return head;}

        int j=0;
        node* temp2 = temp->next;
        while(j<n  &&  temp2 !=NULL)
        {
            node* a =temp2;
            temp2= temp2->next;
            delete [] a;
            j++;
        }
        if(temp2 == NULL){temp->next= NULL;return head;}

        temp->next =temp2;
        temp=temp->next;
    }
}

int main(){

    node* head= takeInput();
    head =revamp(2,3,head);
    print(head);

    return 0;
}

